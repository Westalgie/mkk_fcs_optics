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
            "mkk_avrs"
        };
        author = "Westalgie";
        authors[] = {"Westalgie"};
        VERSION_CONFIG;
    };
};

#include "Rsc.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
