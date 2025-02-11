class mkk_leopard1_base: Tank_F {};

class mkk_leopard1a1_base: mkk_leopard1_base
{
    displayName = "Leopard 1A1";
    class Turrets: Turrets
    {
        class MainTurret: MainTurret
        {
            class Turrets: Turrets
            {
                class CommanderOptics: CommanderOptics
                {
                    class ViewOptics: ViewOptics
                    {
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
                            initFov = 0.233*2.2;
                            minFov = 0.233*2.2;
                            maxFov = 0.233*2.2;
                            visionMode[] = {"Normal","NVG"};
                            gunnerOpticsModel = "\A3\weapons_f\reticle\optics_binoculars.p3d";
                            gunnerOpticsEffect[] = {};
                        };
                        class Narrow: Wide
                        {
                            initFov = "0.233/6";
                            minFov = "0.233/6";
                            maxFov = "0.233/6";
                        };
                    };
                };
                class Loader: Loader
                {
                    class ViewOptics: ViewOptics
                    {
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
                            initFov = 0.233*2.2;
                            minFov = 0.233*2.2;
                            maxFov = 0.233*2.2;
                            visionMode[] = {"Normal","NVG"};
                            gunnerOpticsModel="\A3\weapons_f\reticle\optics_generic_empty_f.p3d";
                            gunnerOpticsEffect[] = {};
                        };
                        class Narrow: Wide
                        {
                            initFov = "0.233/4";
                            minFov = "0.233/4";
                            maxFov = "0.233/4";
                        };
                    };
                };
            };
            class ViewOptics: ViewOptics
            {
                visionMode[] = {"Normal","NVG"};
            };
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
                    initFov = "0.233*2";
                    minFov = "0.233*2";
                    maxFov = "0.233*2";
                    visionMode[] = {"Normal","NVG"};
                    gunnerOpticsModel = QPATHTOF(data\models\WST_Optics_Gunner_Empty_Circle.p3d);
                    gunnerOpticsEffect[] = {};
                };
                class Narrow: Periscope
                {
                    opticsDisplayName = "NARROW";
                    initFov = "0.233 / 8";
                    minFov = "0.233 / 8";
                    maxFov = "0.233 / 8";
                };
            };
            weapons[] = {"mkk_leo_weap_l7a3_nofcs","mkk_MG3_nofcs"};
            turretInfoType = QGVAR(RscWeaponLeopard1A1_FCS);
        };
    };
    class AnimationSources: AnimationSources
    {
        class user_recoil
        {
            source = "user";
            initPhase = 0;
            animPeriod = 1;
        };
        class muzzle_hide_cannon
        {
            source="reload";
            weapon="mkk_leo_weap_l7a3_nofcs";
        };
        class muzzle_rot_cannon
        {
            source="ammorandom";
            weapon="mkk_leo_weap_l7a3_nofcs";
        };
        class recoil_source
        {
            source="reload";
            weapon="mkk_leo_weap_l7a3_nofcs";
        };
        class muzzle_rot_mg
        {
            source="ammorandom";
            weapon="mkk_MG3_nofcs";
        };
    };
};
class mkk_leopard1a1: mkk_leopard1a1_base
{
    side = 1;
    scope = 2;
    faction = "BWA3_Faction_Fleck";
    crew = "B_Crew_F";
    typicalCargo[] = {"B_Crew_F"};
    hiddenSelectionsTextures[] = {"leopard1\data\body_woodland_co.paa","leopard1\data\armor_woodland_co.paa","leopard1\data\turret_woodland_co.paa","leopard1\data\gun_woodland_co.paa"};
};

class mkk_leopard1a1_r: mkk_leopard1a1_base
{
    side = 0;
    scope = 2;
    faction="mkk_turki_side";
    crew="O_crew_F";
    typicalCargo[]={"O_Soldier_F"};
    hiddenSelectionsTextures[] = {"leopard1\data\body_field2_co.paa","leopard1\data\armor_field2_co.paa","leopard1\data\turret_field2_co.paa","leopard1\data\gun_field2_co.paa"};
};

class mkk_leopard1a1_g: mkk_leopard1a1_base
{
    side = 2;
    scope = 2;
    faction="IND_F";
    crew="I_crew_F";
    typicalCargo[]={"I_Soldier_F"};
    hiddenSelectionsTextures[] = {"leopard1\data\body_aaf_co.paa","leopard1\data\armor_aaf_co.paa","leopard1\data\turret_aaf_co.paa","leopard1\data\gun_aaf_co.paa"};
};