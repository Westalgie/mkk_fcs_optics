class RscControlsGroup;
class HScrollbar;
class VScrollbar;
class RscPicture;
class RscText;

class RscInGameUI
{
    class RscUnitInfo;

    class GVAR(RscWeaponM1A1_GAS_FCS): RscUnitInfo
    {
        idd=300;
        onLoad = QUOTE([ARR_2(_this select 0,'GVAR(RscWeaponM1A1_GAS_FCS)')] call FUNC(onSightOpen));
        controls[]=
        {
            "CA_IGUI_elements_group"
        };
        class CA_IGUI_elements_group: RscControlsGroup
        {
            idc = 170;
            class VScrollbar: VScrollbar
            {
                width = 0;
            };
            class HScrollbar: HScrollbar
            {
                height = 0;
            };
            x = "0 *   (0.01875 * SafezoneH) +   (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
            y = "0 *   (0.025 * SafezoneH) +   (SafezoneY)";
            w = "53.5 *   (0.01875 * SafezoneH)";
            h = "40 *   (0.025 * SafezoneH)";
            class controls
            {
                class Sight_Reticle: RscPicture
                {
                    idc=1;
                    style="0x30 + 0x800";
                    colorText[]={0.7,0,0,1};
                    shadow=0;
                    font="EtelkaMonospacePro";
                    text="";
                    x = "-0.6 *  (0.01875 * SafeZoneH)";
                    y = "1.1 * (0.025 * SafeZoneH)";
                    w = "safeZoneH";
                    h = "safeZoneH";
                };
                class CA_TurretIndicator: RscPicture
                {
                    IDC = 206;
                    type = 105;
                    textSize = "0.02*SafezoneH";
                    style = 0;
                    color[] = {0.49,0.78,0.46,1};
                    shadow = 3;
                    colorShadow[] = {100,100,100,95};
                    x = "5.25 * 		(0.01875 * SafezoneH)";
                    y = "3.5 * 		(0.025 * SafezoneH)";
                    w = "6 * 		(0.01875 * SafezoneH)";
                    h = "6 * 		(0.025 * SafezoneH)";
                    imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorHull.paa";
                    imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorTurret.paa";
                    imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorObsTurret.paa";
                    imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
                };
                class CA_HorizontalCompass: RscPicture
                {
                    IDC = 207;
                    type = 105;
                    font = "TahomaB";
                    style = 1;
                    color[] = {0.49,0.78,0.46,1};
                    shadow = 3;
                    colorShadow[] = {100,100,100,95};
                    textSize = "0.02*SafezoneH";
                    x = "13.04 * 		(0.01875 * SafezoneH)";
                    y = "3.5 * 		(0.025 * SafezoneH)";
                    w = "27.18 * 		(0.01875 * SafezoneH)";
                    h = "1 * 		(0.025 * SafezoneH)";
                    imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassHull.paa";
                    imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassTurret.paa";
                    imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassObsTurret.paa";
                    imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
                };
                class AzimuthMark: RscPicture
                {
                    IDC = 1012;
                    text = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\AzimuthMark.paa";
                    x = "26.35 * 		(0.01875 * SafezoneH)";
                    y = "3.0 * 		(0.025 * SafezoneH)";
                    w = "0.5 * 		(0.01875 * SafezoneH)";
                    h = "0.5 * 		(0.025 * SafezoneH)";
                    colorText[] = {0.49,0.78,0.46,1};
                    shadow = 3;
                    colorShadow[] = {100,100,100,95};
                };
                class CA_Heading: RscText
                {
                    idc = 156;
                    style = 2;
                    sizeEx = "0.032*SafezoneH";
                    shadow = 3;
                    colorShadow[] = {100,100,100,95};
                    font = "TahomaB";
                    colorText[] = {0.49,0.78,0.46,1};
                    text = "015";
                    x = "25.15 * 		(0.01875 * SafezoneH)";
                    y = "1.75 * 		(0.025 * SafezoneH)";
                    w = "3 * 		(0.01875 * SafezoneH)";
                    h = "1.2 * 		(0.025 * SafezoneH)";
                };
                class CA_OpticsZoom: RscText
                {
                    idc = 180;
                    style = 1;
                    colorText[] = {0.706,0.0745,0.0196,1};
                    sizeEx = "0.038*SafezoneH";
                    shadow = 3;
                    colorShadow[] = {100,100,100,95};
                    font = "TahomaB";
                    text = "4.5";
                    x = "43.85 *   (0.01875 * SafezoneH)";
                    y = "19.6 *   (0.025 * SafezoneH)";
                    w = "0*   (0.01875 * SafezoneH)";
                    h = "0 *   (0.025 * SafezoneH)";
                };
                class CA_OpticsMode: CA_OpticsZoom
                {
                    idc=154;
                };
                class RHS_ControlNumber: CA_OpticsZoom
                {
                    idc=1000;
                    text="MKK_SIGHT_M1A1_GAS";
                };
            };
        };
    };
};
