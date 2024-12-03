#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[]= {
            "mkk_m1a1aim_nofcs",
            "mkk_m60a1_b",
            "mkk_m60a1_r",
            "mkk_m60a1_g",
            "mkk_leopard1a1",
            "mkk_leopard1a1_r",
            "mkk_leopard1a1_g",
            "t55_r",
            "t55_b",
            "t55_g",
            "t55a_r",
            "t55a_b",
            "t55a_g"
        };
        weapons[]={
            "rhs_weap_m256_nofcs",
            "rhs_weap_m240_abrams_coax_nofcs",
            "mkk_m60_m68_nofcs",
            "mkk_m60_m73_nofcs",
            "mkk_m60_m85_nofcs",
            "mkk_leo_weap_l7a3_nofcs",
            "mkk_MG3_nofcs"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "mkk_main",
            "mkk_rhs_usaf_fix_m_c",
            "mkk_m60a3_c",
            "leopard1_c",
            "mkk_t55a_c"
        };
        author = "Westalgie";
        authors[] = {"Westalgie"};
        VERSION_CONFIG;
    };
};

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
                    class Loader;
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
    #include "vehicles\USAF\m1a1_gas.hpp"
    #include "vehicles\USAF\m60a1.hpp"
    #include "vehicles\BW\leopard1a1.hpp"
    #include "vehicles\SUAF\t55a.hpp"
};

#include "Rsc.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgWeapons.hpp"
