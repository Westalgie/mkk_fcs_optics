class t55a_base: Tank_F {
    class Turrets: Turrets
    {
        class MainTurret: MainTurret
        {
            class CommanderOptics;
            class Loader: CommanderOptics {};
        };
    };
};

class mkk_t55_wst_base: t55a_base {
    class Turrets: Turrets
    {
        class MainTurret: MainTurret
        {
            class OpticsIn
            {
                class Periscope
                {
                    opticsDisplayName = "PERISCOPE";
                    initAngleX = 0;
                    minAngleX = -30;
                    maxAngleX = 30;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    initFov = "0.233";
                    minFov = "0.233";
                    maxFov = "0.233";
                    gunnerOpticsModel = QPATHTOF(data\models\WST_Optics_Gunner2_Empty_Circle.p3d);
                    visionMode[] = {"Normal","NVG"};
                    gunnerOpticsEffect[] = {};
                };
                class Narrow: Periscope
                {
                    opticsDisplayName = "NARROW";
                    initFov = "0.233/6";
                    minFov = "0.233/6";
                    maxFov = "0.233/6";
                };
            };
            turretInfoType = QGVAR(RscWeaponT55_FCS);
        };
    };
};

class mkk_t55a_wst_base: t55a_base {
    displayName = "$STR_t55a";
    class Turrets: Turrets
    {
        class MainTurret: MainTurret
        {
            class OpticsIn
            {
                class Periscope
                {
                    opticsDisplayName = "PERISCOPE";
                    initAngleX = 0;
                    minAngleX = -30;
                    maxAngleX = 30;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    initFov = "0.233";
                    minFov = "0.233";
                    maxFov = "0.233";
                    gunnerOpticsModel = QPATHTOF(data\models\WST_Optics_Gunner2_Empty_Circle.p3d);
                    visionMode[] = {"Normal","NVG"};
                    gunnerOpticsEffect[] = {};
                };
                class Narrow: Periscope
                {
                    opticsDisplayName = "NARROW";
                    initFov = "0.233/6";
                    minFov = "0.233/6";
                    maxFov = "0.233/6";
                };
            };
            stabilizedInAxes = 3;
            turretInfoType = QGVAR(RscWeaponT55A_FCS);
        };
    };
};

class t55_r: mkk_t55_wst_base
{
    side = 0;
    scope = 2;
    faction = "mkk_russian_side";
};

class t55_b: mkk_t55_wst_base
{
    side = 1;
    scope = 2;
    faction = "mkk_cdf_side";
    hiddenSelectionsTextures[] = {"mkk_t55a\data\body_cdf_co.paa","mkk_t55a\data\turret_cdf_co.paa","mkk_t55a\data\gun_cdf_co.paa"};
};

class t55_g: mkk_t55_wst_base
{
    side = 2;
    scope = 2;
    faction = "mkk_resistance_side";
    hiddenSelectionsTextures[] = {"mkk_t55a\data\body_chdkz_co.paa","mkk_t55a\data\turret_chdkz_co.paa","mkk_t55a\data\gun_chdkz_co.paa"};
};

class t55a_r: mkk_t55a_wst_base
{
    side = 0;
    scope = 2;
    faction = "mkk_russian_side";
};

class t55a_b: mkk_t55a_wst_base
{
    side = 1;
    scope = 2;
    faction = "mkk_cdf_side";
    hiddenSelectionsTextures[] = {"mkk_t55a\data\body_cdf_co.paa","mkk_t55a\data\turret_cdf_co.paa","mkk_t55a\data\gun_cdf_co.paa"};
};

class t55a_g: mkk_t55a_wst_base
{
    side = 2;
    scope = 2;
    faction = "mkk_resistance_side";
    hiddenSelectionsTextures[] = {"mkk_t55a\data\body_chdkz_co.paa","mkk_t55a\data\turret_chdkz_co.paa","mkk_t55a\data\gun_chdkz_co.paa"};
};