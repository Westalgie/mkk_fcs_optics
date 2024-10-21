"""
Автоматическое создание чеклиста по логу гита.
Перед запуском выполнить build (для автоматического копирования файлов).
При запуске указать дату прошлого обновления в формате год-месяц-день, например:
python checklist.py 2018-02-18
Если дату не указать, по умолчанию подтягиваются коммиты за последнюю неделю.

Что делает:
 - создаёт "грязный" список обновлений в файле changelog_XXX.txt
 - создаёт сокращённый, отформатированный список обновлений в файле changelog_XXX_short.txt
 - копирует обновлённые файлы в папку update_XXX, если файл был удалён - записывает его в delete.txt там же.
   Чтобы пропустить копирование, запустить скрипт с ключом -nc

XXX означает текущую дату.

"""
import sys
import os
from shutil import copyfile, copytree, rmtree
import datetime
import subprocess
import io

scriptpath = os.path.realpath(__file__)
projectpath = os.path.dirname(os.path.dirname(scriptpath))

os.chdir(projectpath)

now = datetime.datetime.now()
now_str = now.strftime("%Y-%m-%d")
last_week = datetime.datetime.now() - datetime.timedelta(days=7)
git_after = last_week.strftime("%Y-%m-%d") if len(sys.argv)<2 else sys.argv[1]
do_copy = "-nc" not in sys.argv

git_params = ["git",'log', '--after', git_after, '--pretty=%s (%cn)', '--name-only', '--no-merges']

# write dirty log

with io.open("changelog_%s.txt"%now_str, "w", encoding="utf8") as f:
	subprocess.call(git_params, stdout=f)

# beautify

with io.open("changelog_%s.txt"%now_str,encoding="utf8") as f:
    content = f.read().splitlines()

log_lines = []
all_lines = []
for line in content:
    if line.startswith("addons/"):
        addon_name = line.split("/")[1]
        if addon_name not in log_lines[len(log_lines)-1][1]:
            log_lines[len(log_lines)-1][1].append(addon_name)
    elif len(line)>0 and line not in all_lines:
        log_lines.append((line,[]))
        all_lines.append(line)

affected_files = []   # remember the files mentioned in the log
with io.open("changelog_%s_short.txt"%now_str,"w",encoding="utf8") as f:
    for line in log_lines:
        addons_list = ""
        for addon in line[1]:
            if addons_list != "":
                addons_list += ", "
            addons_list+=addon
            if (addon not in affected_files):
                affected_files.append(addon)
        print("%s: %s"%(addons_list,line[0]))
        f.write("* [ ] %s: %s\n"%(addons_list,line[0]))

if do_copy:
	# copy files to the update dir
	update_path = "update_%s"%now_str
	if os.path.exists(update_path):
		rmtree(update_path)
		os.makedirs(update_path)
	else:
		os.makedirs(update_path)

	for file in affected_files:
		print("Copying addons\%s.pbo"%file)
		if os.path.exists("addons\%s.pbo"%file) and os.path.exists("addons\%s"%file):
			copyfile("addons\%s.pbo"%file, "update_%s\%s.pbo"%(now_str,file))
			copytree("addons\%s"%file, "update_%s\%s"%(now_str,file))
		else:
			with io.open(update_path + "\delete.txt","a",encoding="utf8") as f1:
				f1.write("Delete %s\n"%file)
