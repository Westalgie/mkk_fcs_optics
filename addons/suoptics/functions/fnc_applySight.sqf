#include "script_component.hpp"

_this select 0 params ["_display", "_turretPath", "_reticles"];

_vehicle = vehicle player;

_shouldClose = [false, true] select (isNull _display || {_vehicle isEqualTo player || {_vehicle unitTurret player isNotEqualTo _turretPath || {!alive _vehicle || {!alive player}}}});

if (_shouldClose) exitWith {
    // _display closeDisplay 1;
    TRACE_1("Remove optics PFH",GVAR(opticPFH));
    [GVAR(opticPFH)] call CBA_fnc_removePerFrameHandler;
};

_mode = ctrlText (_display displayCtrl 154);
_sight =_display displayCtrl 1;
_magazines = _vehicle magazinesTurret [_turretPath, true];

_currentMagIndex = _reticles select 0 findIf {_x in _magazines};
if (_currentMagIndex isEqualTo -1) exitWith {
    
    switch (_mode) do {
        case "PERISCOPE": {_sight ctrlSetText ""};
        case "ZOOM": {_sight ctrlSetText (_reticles select 1 select (_reticles select 2))};
    };
};

_currentMag = _magazines select _currentMagIndex;
_oldMag = _vehicle getVariable [QGVAR(currentMag), ""];
_vehicle setVariable [QGVAR(currentMag), _currentMag];

switch(_mode)do{
    case "PERISCOPE": {
        _sight ctrlSetText "";
    };
    case "ZOOM": {
        // switch optic effect
        if (_currentMag isNotEqualTo _oldMag) then {cutText ["", "BLACK IN", 2]};
        _sight ctrlSetText (_reticles select 1 select _currentMagIndex);
    };
};
_sight ctrlCommit 0.001;
