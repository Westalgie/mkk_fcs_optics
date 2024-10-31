#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[]= {
            "rhsusf_m1a1aimwd_usarmy_nofcs"
        };
        weapons[]={
            "rhs_weap_m256_nofcs",
            "rhs_weap_m240_abrams_coax"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "mkk_main",
            "mkk_rhs_usaf_fix_m_c",
            "rhsusf_c_m1a1",
            "mkk_m60a3_c"
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
};

#include "Rsc.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgWeapons.hpp"
