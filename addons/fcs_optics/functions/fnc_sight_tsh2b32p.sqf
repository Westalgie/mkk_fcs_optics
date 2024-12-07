#include "script_component.hpp"
/*
    fn_MKK_SIGHT_TSH_2B_32P
    T-55A sight simulation
    by Westalgie

    based of
    
    rhs_fnc_sight_bmp2
    BPK-1-42 simulation
    Handles optical devices switching with weaponary changing depe


    script is fired only once & is destroyed together with display
    a: reyhard
*/

if(not( isNull (uiNamespace getVariable ["MKK_T55A_Ctrl",displayNull]))) exitWith{};

// remove additional handler if it's present
if( not ( (uiNamespace getVariable ["mkk_tsh_2_32_eh",-1]) isEqualTo -1))then{
    (findDisplay 46) displayRemoveEventHandler ["KeyDown", uiNamespace getVariable "mkk_tsh_2_32_eh"];
    (findDisplay 46) displayRemoveEventHandler ["KeyUp", uiNamespace getVariable "mkk_tsh_2_32_eh_up"];
    //systemChat format[" %1 reload passed",(uiNamespace getVariable ["rhs_hatch_handler_eh",-1])];
};

uiNamespace setVariable ["MKK_T55A_Ctrl",_this select 0];

rhs_key_opn_cmp_GLB        = (profileNamespace getVariable ["rhs_key_opn_cmp","Binocular"]);
rhs_key_rng_up_GLB        = (profileNamespace getVariable ["rhs_key_rng_up","ZeroingUp"]);
rhs_key_rng_dwn_GLB        = (profileNamespace getVariable ["rhs_key_rng_dwn","ZeroingDown"]);
rhs_key_lase_tgt_GLB    = (profileNamespace getVariable ["rhs_key_lase_tgt","LockTarget"]);
rhs_key_dmp_lead_GLB    = (profileNamespace getVariable ["rhs_key_dmp_lead","Throw"]);
rhs_key_nxt_rnd_GLB        = (profileNamespace getVariable ["rhs_key_nxt_rnd","CarHandBrake"]);


// loop handling different optics mode, weapon changing & transition fade effect
["mkk_leopard1a1_sight_handler", "onEachFrame", {
    params["_v","_mode_old","_restricted","_time"];

    private _currentWeapon = _v currentWeaponTurret [0];
    if(_currentWeapon in _restricted) then
    {
        private _weaponsList = _v weaponsTurret [0];
        _weaponsList = _weaponsList - _restricted;

        //hintSilent format["%1 %2",_restricted,(_weaponsList # 0)];
        _v selectWeaponTurret [(_weaponsList # 0),[0]];
    };

    // refresh rate 0.01s
    if(time > _time)then
    {
        _this set [3,time+0.01];

        private _mode = ctrlText (uiNamespace getVariable "MKK_T55A_Ctrl" displayCtrl 154);
        // check if mode was changed
        if(_mode!=_mode_old)then
        {

            // deinitialization part
            if(  ctrlText ( (uiNamespace getVariable "MKK_T55A_Ctrl")  displayCtrl 1000) != "MKK_SIGHT_TSH_2B_32P" ) exitWith {
                // remove event handlers & deinitalize variables
                (findDisplay 46) displayRemoveEventHandler ["KeyDown", uiNamespace getVariable "mkk_tsh_2_32_eh"];
                (findDisplay 46) displayRemoveEventHandler ["KeyUp", uiNamespace getVariable "mkk_tsh_2_32_eh_up"];
                ["mkk_leopard1a1_sight_handler", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
                uiNamespace setVariable ["MKK_T55A_Ctrl",displayNull];
                {uiNamespace setVariable [_x,nil]} forEach ["mkk_tsh_2_32_eh","mkk_tsh_2_32_eh_up"];
                {_x = nil} forEach [rhs_fnc_moveReticle];

                //systemChat "removing EH";
            };

            private _sight = (uiNamespace getVariable "MKK_T55A_Ctrl" displayCtrl 1);
            private _bar = (uiNamespace getVariable "MKK_T55A_Ctrl" displayCtrl 2);
            private _rng = (uiNamespace getVariable "MKK_T55A_Ctrl" displayCtrl 198);
            private _v = vehicle (call rhs_fnc_findPlayer);
            _this set [0,_v];
            //systemChat format["updating vehicle %1",_mode];

            switch(_mode)do{
                case "PERISCOPE" : {
                    {_x ctrlSetTextColor [0.7,0.074,0.02,1]; } forEach [_bar]; //придаем цвет сетки, чтобы ее было можно видеть
                    {_x ctrlSetTextColor [0.7,0.074,0.02,0]; } forEach [_sight]; //придаем цвет сетки, чтобы ее было можно видеть
                    {_x ctrlSetTextColor [0, 0, 0, 0]; } forEach [_rng];
                    _bar ctrlSetText QPATHTOF(data\reticles\WST_tsh_2_32_sight_ca.paa);
                    _sight ctrlCommit 0.001;
                    _bar ctrlCommit 0.001;
                };
                case "NARROW" : {
                    {_x ctrlSetTextColor [0.7,0.074,0.02,1]; } forEach [_bar,_sight];
                    {_x ctrlSetTextColor [0, 0, 0, 1]; } forEach [_rng];
                    _sight ctrlSetText QPATHTOF(data\reticles\WST_tsh_2_32_x8_sight_ca.paa);
                    _bar ctrlSetText QPATHTOF(data\reticles\WST_tsh_2b_32p_x8_bar_ca.paa);
                    _sight ctrlCommit 0.001;
                    _bar ctrlCommit 0.001;
                };
            };
            // fade effect to simulate changing optical devices
            titleCut ["", "black in", 2];
            // update mode param
            _this set [1,_mode];
        };
    };
},[vehicle (call rhs_fnc_findPlayer),"",[""],time]] call BIS_fnc_addStackedEventHandler;

rhs_fnc_moveReticle = 
{
    // exit if play is not in optic mode
    if(cameraView != "GUNNER") exitWith {};

    params["_dir"];

    disableSerialization;

    private _sight    = (uiNamespace getVariable "MKK_T55A_Ctrl" displayCtrl 1);
    private _t        = (ctrlPosition _sight) select 1;
    private _move    = _t+0.003*_dir;
    if((_move <= (0 * (0.025 * safeZoneH) - (5 * (0.01875 * safeZoneH)))) && (_move >= (0 * (0.025 * safeZoneH) - (29 * (0.01875 * safeZoneH))))) then {
        _sight ctrlSetPosition [(ctrlPosition _sight) select 0,_move];
        _sight ctrlCommit 0.005;
    };
};

_id =  (findDisplay 46) displayAddEventHandler ["KeyDown", {
    private _handle=false;
    // reticle range adjustments
    switch(true) do {
        case (inputAction rhs_key_rng_up_GLB > 0): { [1] call rhs_fnc_moveReticle;};
        case (inputAction rhs_key_rng_dwn_GLB > 0): { [-1] call rhs_fnc_moveReticle };
    };
    _handle;
}];

_id2 =  (findDisplay 46) displayAddEventHandler ["KeyUp", {
    private _handle=false;

    if(((actionKeys "nightVision") select 0) isEqualTo (_this select 1)) then
    {
        disableSerialization;
        private _sight = (uiNamespace getVariable "MKK_T55A_Ctrl" displayCtrl 1);
        private _bar = (uiNamespace getVariable "MKK_T55A_Ctrl" displayCtrl 2);
    };
    _handle;
}];
uiNamespace setVariable ["mkk_tsh_2_32_eh",_id];
uiNamespace setVariable ["mkk_tsh_2_32_eh_up",_id2];