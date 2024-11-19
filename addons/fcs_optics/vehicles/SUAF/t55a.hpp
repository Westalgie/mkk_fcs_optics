class t55a_base: Tank_F {
    class Turrets: Turrets
    {
        class MainTurret: MainTurret {};
    };
};

class wst_t55: t55a_base {
    side = 1;
    scope = 2;
    faction = "BLU_F";
    crew = "B_Crew_F";
    typicalCargo[] = {"B_Crew_F"};
    editorSubcategory = "EdSubcat_Tanks";
    class Turrets: Turrets
    {
        class MainTurret: MainTurret
        {
            class OpticsIn
            {
                class Wide
                {
                    initAngleX = 0;
                    minAngleX = -30;
                    maxAngleX = 30;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    initFov = "0.233*2.2";
                    minFov = "0.233*2.2";
                    maxFov = "0.233*2.2";
                    gunnerOpticsModel = QPATHTOF(data\models\WST_Optics_Gunner_Empty_Circle);
                    visionMode[] = {"Normal","NVG"};
                    gunnerOpticsEffect[] = {};
                };
                class Narrow2x: Wide
                {
                    initFov = "0.233/7";
                    minFov = "0.233/7";
                    maxFov = "0.233/7";
                };
            };
            turretInfoType = QGVAR(RscWeaponT55_FCS);
            discreteDistance[] = {100};
            discreteDistanceInitIndex = 0;
        };
    };
};