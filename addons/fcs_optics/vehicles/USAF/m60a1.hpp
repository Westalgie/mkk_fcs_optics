class mkk_m60_base: Tank_F {};
class mkk_m60a3_tts_base: mkk_m60_base {};
class mkk_m60a1_base: mkk_m60a3_tts_base
{
    author = "lemfy, Westalgie";
    displayName = "M60A1 RISE (P)";
    class Turrets: Turrets
    {
        class MainTurret: MainTurret
        {
            class OpticsIn
            {
                class Wide
                {
                    opticsDisplayName = "PERISCOPE";
                    initAngleX = 0;
                    minAngleX = -30;
                    maxAngleX = 30;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    initFov = "0.233*2.2";
                    minFov = "0.233*2.2";
                    maxFov = "0.233*2.2";
                    visionMode[] = {"Normal","NVG"};
                    gunnerOpticsModel = QPATHTOF(data\models\WST_Optics_Gunner_Empty_Circle);
                    gunnerOpticsEffect[] = {};
                };
                class Narrow: Wide
                {
                    opticsDisplayName = "ZOOM";
                    initFov = "0.233/8";
                    minFov = "0.233/8";
                    maxFov = "0.233/8";
                };
            };
            turretInfoType = QGVAR(RscWeaponM60A1_FCS);
            discreteDistance[] = {400};
            discreteDistanceInitIndex = 0;
            weapons[] = {"mkk_m60_m68_nofcs","mkk_m60_m73_nofcs","SmokeLauncher_m60"};

            class Turrets: Turrets
            {
                class CommanderOptics: CommanderOptics
                {
                    class ViewOptics: ViewOptics
                    {
                        initFov = 0.4375;
                        maxFov = 0.4375;
                        minFov = 0.03482;
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG"};
                    };
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
                            initFov = "0.233*1.5";
                            minFov = "0.233*1.5";
                            maxFov = "0.233*1.5";
                            visionMode[] = {"Normal","NVG"};
                            gunnerOpticsModel = "\mkk_cup_vehicles\comOptics_M1A1.p3d";
                            gunnerOpticsEffect[] = {};
                        };
                        class Narrow: Wide
                        {
                            initFov = "0.233/2";
                            minFov = "0.233/2";
                            maxFov = "0.233/2";
                        };
                        class Narrow2x: Narrow
                        {
                            initFov = "0.233/7";
                            minFov = "0.233/7";
                            maxFov = "0.233/7";
                        };
                    };
                };
            };
        };
    };
    class AnimationSources: AnimationSources
    {
        class muzzle_hide_cannon
        {
            source = "reload";
            weapon = "mkk_m60_m68_nofcs";
        };
        class muzzle_rot_cannon
        {
            source = "ammorandom";
            weapon = "mkk_m60_m68_nofcs";
        };
        class zaslehrot_coax
        {
            source = "ammorandom";
            weapon = "mkk_m60_m73_nofcs";
        };
    };

    // class MKK_CSW
    // {
    //     enabled = 1;
    //     csw_weapons[] = {
    //         "mkk_m60_m73_nofcs","mkk_m60_m85","mkk_m60_m68_nofcs"
    //     };
    //     class mkk_m60_m73_nofcs {
    //         condition = "!(isTurnedOut _player)";
    //         can_refill = "false";
    //         loadable_magazines[] = weap_m240_loadable_magazines;
    //         weapon_magazines[] = weap_m240_coax_weapon_magazines;
    //         max_magazine_count = 12;
    //         turrets[] = {{0},{0,1}};
    //         weapon_turret[] = {0};
    //         loading_time = 0.5;
    //         unloading_time = 0.5;
    //     };
    //     class mkk_m60_m85 {
    //         condition = "!(isTurnedOut _player)";
    //         can_refill = "true";
    //         loadable_magazines[] = weap_m2_loadable_magazines;
    //         weapon_magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red"};
    //         max_magazine_count = 4;
    //         turrets[] = {{0,0}};
    //         weapon_turret[] = {0,0};
    //         loading_time = 0.5;
    //         unloading_time = 0.5;
    //     };
    //     class mkk_m60_m68_nofcs {
    //         condition = "!(isTurnedOut _player)";
    //         can_refill = "false";
    //         loadable_magazines[] = {"mkk_csw_m60_mag_m774","mkk_csw_m60_mag_m456a2","mkk_csw_m60_mag_m393a2"};
    //         weapon_magazines[] = {"mkk_m60_mag_m774","mkk_m60_mag_m456a2","mkk_m60_mag_m393a2"};
    //         max_magazine_count = 1;
    //         turrets[] = {{0,1}};
    //         weapon_turret[] = {0};
    //         loading_time = 6;
    //         unloading_time = 4;
    //     };
    // };
};

class mkk_m60a1_b: mkk_m60a1_base
{
    side = 1;
    scope = 2;
    faction = "mkk_usa_side";
    editorSubcategory = "mkk_usa_tank";
    crew = "B_Crew_F";
    typicalCargo[] = {"B_Crew_F"};
    hiddenSelectionsTextures[] = {"mkk_m60a3\data\body_woodland_co.paa","mkk_m60a3\data\turret_woodland_co.paa","mkk_m60a3\data\gun_woodland_co.paa","mkk_m60a3\data\armor_woodland_co.paa"};
};
class mkk_m60a1_r: mkk_m60a1_base
{
    side = 0;
    scope = 2;
    faction = "mkk_turki_side";
    editorSubcategory = "mkk_turki_tank";
    crew = "O_crew_F";
    typicalCargo[] = {"O_crew_F"};
};
class mkk_m60a1_g: mkk_m60a1_base
{
    side = 2;
    scope = 2;
    faction = "mkk_PMC_side";
    editorSubcategory = "mkk_usa_tank";
    crew = "I_G_Soldier_F";
    typicalCargo[] = {"I_G_Soldier_F"};
    hiddenSelectionsTextures[] = {"mkk_m60a3\data\body_sand1_co.paa","mkk_m60a3\data\turret_sand1_co.paa","mkk_m60a3\data\gun_sand1_co.paa","mkk_m60a3\data\armor_sand1_co.paa"};
};