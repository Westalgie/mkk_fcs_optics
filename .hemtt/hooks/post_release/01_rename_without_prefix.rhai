fn extract_substring(file_path) {
    let prefix = "mkk_";
    let suffix = ".pbo";
    let start = file_path.index_of(prefix);

    if start >= 0 {
        start += prefix.len();

        let end = file_path.index_of(suffix);

        // Если ".pbo" найдено, возвращаем подстроку
        if end >= 0 {
            return file_path.sub_string(start, end - start);
        };
    };

    return "";
};

let addons = HEMTT_RFS.join(".hemttout").join("release").join("addons").list();

for addon_path in addons {
    let addon_name = extract_substring(addon_path.file_name());
    if addon_name == "" {continue};
    if !addon_path.move(HEMTT_RFS.join(".hemttout").join("release").join("addons").join(addon_name + ".pbo")) {
        fatal("Failed to remove prefix from addon " + addon_name);
    }
};
