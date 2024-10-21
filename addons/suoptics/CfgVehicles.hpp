class CfgVehicles
{
    class Land;
    class LandVehicle: Land
    {
        class Turrets;
        class NewTurret;
    };
    class Tank: LandVehicle
    {
        class NewTurret;
        class Sounds;
        class HitPoints;
        class CommanderOptics;
        class Components;
        class ViewOptics;
        class Turrets {
            class MainTurret: NewTurret {};
        };
    };
    class Tank_F: Tank
    {
        class Turrets
        {
            class MainTurret: NewTurret
            {
                class Turrets
                {
                    class CommanderOptics;
                };
            };
        };
        class AnimationSources;
        class ViewPilot;
        class ViewOptics;
        class ViewCargo;
        class HeadLimits;
        class HitPoints: HitPoints
        {
            class HitHull;
            class HitEngine;
            class HitLTrack;
            class HitRTrack;
        };
        class Sounds: Sounds
        {
            class Engine;
            class Movement;
        };
    };
    class MBT_01_base_F : Tank_F {};
    class rhsusf_m1a1tank_base : MBT_01_base_F {};
    class rhsusf_m1a1aimwd_usarmy: rhsusf_m1a1tank_base {};
    class rhsusf_m1a1aimwd_usarmy_nofcs: rhsusf_m1a1aimwd_usarmy
    {
        displayName = "M1A1AIM (GAS)";
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                class OpticsIn
                {
                    class Periscope: ViewOptics
                    {
                        initAngleX = 0;
                        minAngleX = -30;
                        maxAngleX = 30;
                        initAngleY = 0;
                        minAngleY = -100;
                        maxAngleY = 100;
                        initFov = 0.233333;
                        minFov = 0.233333;
                        maxFov = 0.233333;
                        visionMode[] = {"Normal", "NVG"};
                        gunnerOpticsModel = QPATHTOF(data\models\WST_Optics_Gunner_M1A1_Periscope);
                        opticsDisplayName = "PERISCOPE";
                    };
                    class APFSDS: Periscope
                    {
                        opticsDisplayName = "ZOOM";
                        initFov = (0.233333 / 8);
                        minFov = (0.233333 / 8);
                        maxFov = (0.233333 / 8);
                    };
                };
                turretInfoType = QGVAR(RscWeaponM1A1_GAS_FCS);
                discreteDistance[] = {500};
                discreteDistanceInitIndex = 0;
                weapons[] = {"rhs_weap_m256_nofcs","rhs_weap_m240_abrams_coax_nofcs","rhsusf_weap_M250"};
            };
        };
        class AnimationSources: AnimationSources
        {
            class muzzle_hide_cannon
            {
                source = "reload";
                weapon = "rhs_weap_m256_nofcs";
            };

            class muzzle_rot_cannon
            {
                source = "ammorandom";
                weapon = "rhs_weap_m256_nofcs";
            };

            class muzzle_rot_CoaxMG
            {
                source = "ammorandom";
                weapon = "rhs_weap_m240_abrams_coax_nofcs";
            };

            class recoil_source
            {
                source = "reload";
                weapon = "rhs_weap_m256_nofcs";
            };
        };
        class MKK_CSW
        {
            enabled=1;
            csw_weapons[]=
            {
                "RHS_M2_Abrams_Commander",
                "rhs_weap_m240_abrams",
                "rhs_weap_m256_nofcs",
                "rhs_weap_m240_abrams_coax_nofcs"
            };
            class rhs_weap_m256_nofcs
            {
                condition="!(isTurnedOut _player)";
                can_refill="false";
                loadable_magazines[]=
                {
                    "mkk_mag_M829A3",
                    "mkk_mag_M830A1",
                    "mkk_mag_M1069"
                };
                weapon_magazines[]=
                {
                    "mkk_csw_mag_M829A3",
                    "mkk_csw_mag_M830A1",
                    "mkk_csw_mag_M1069"
                };
                max_magazine_count=1;
                turrets[]=
                {
                    {0,1}
                };
                weapon_turret[]={0};
                loading_time=7;
                unloading_time=4;
            };
            class rhs_weap_m240_abrams_coax_nofcs
            {
                condition="!(isTurnedOut _player)";
                can_refill="false";
                loadable_magazines[]=
                {
                    "rhsusf_100Rnd_762x51",
                    "rhsusf_100Rnd_762x51_m80a1epr",
                    "rhsusf_100Rnd_762x51_m61_ap",
                    "rhsusf_100Rnd_762x51_m62_tracer"
                };
                weapon_magazines[]=
                {
                    "mkk_100Rnd_762x51",
                    "mkk_100Rnd_762x51_m80a1epr",
                    "mkk_100Rnd_762x51_m61_ap",
                    "mkk_100Rnd_762x51_m62_tracer"
                };
                max_magazine_count=12;
                turrets[]=
                {
                    {0},
                    {0,1}
                };
                weapon_turret[]={0};
                loading_time=0.5;
                unloading_time=0.5;
            };
        };
    };
};
