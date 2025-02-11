class rhsusf_m1a1tank_base : MBT_01_base_F {};
class rhsusf_m1a1aimwd_usarmy: rhsusf_m1a1tank_base {};
class mkk_m1a1aim_nofcs: rhsusf_m1a1aimwd_usarmy
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
                    initFov = 0.233;
                    minFov = 0.233;
                    maxFov = 0.233;
                    visionMode[] = {"Normal", "NVG"};
                    gunnerOpticsModel = QPATHTOF(data\models\WST_Optics_Gunner_M1A1_Periscope.p3d);
                    opticsDisplayName = "PERISCOPE";
                };
                class APFSDS: Periscope
                {
                    opticsDisplayName = "ZOOM";
                    initFov = "0.233/8";
                    minFov = "0.233/8";
                    maxFov = "0.233/8";
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
};
