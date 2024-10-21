#include "script_component.hpp"

params ["_display", "_type"];

if (isNull _display) exitWith {};

switch _type do {
    case QGVAR(RscWeaponM1A1_GAS_FCS): {
        GVAR(opticPFH) = [FUNC(applySight), 0.1, [_display, vehicle player unitTurret player, M1A1_MAGS_RETICLES]] call CBA_fnc_addPerFrameHandler;
        TRACE_2("Added optics PFH",_type,GVAR(opticPFH));
    };
    default {TRACE_1("Unknown RSC type",_type)}
};
