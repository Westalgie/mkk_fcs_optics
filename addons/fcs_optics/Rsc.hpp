class RscOpticsText;
class RscOpticsValue;
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
                    colorText[]={0.8,0,0,1};
                    shadow=0;
                    font="EtelkaMonospacePro";
                    text=QPATHTOF(data\reticles\WST_m68_periscope_ca.paa);
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
                    color[] = {1,1,1,1};
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
                    color[] = {1,1,1,1};
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
                    colorText[] = {1,1,1,1};
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
                    colorText[] = {1,1,1,1};
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
                    colorText[] = {1,1,1,1};
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

    class GVAR(RscWeaponM60A1_FCS): RscUnitInfo
    {
        idd=300;
        onLoad = QUOTE([ARR_2(_this select 0,'GVAR(RscWeaponM60A1_FCS)')] call FUNC(onSightOpen));
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
                    colorText[]={0.8,0,0,1};
                    shadow=0;
                    font="EtelkaMonospacePro";
                    text=QPATHTOF(data\reticles\WST_m68_periscope_ca.paa);
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
                    color[] = {1,1,1,1};
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
                    color[] = {1,1,1,1};
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
                    colorText[] = {1,1,1,1};
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
                    colorText[] = {1,1,1,1};
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
                    colorText[] = {1,1,1,1};
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

    class GVAR(RscWeaponLeopard1A1_FCS): RscUnitInfo
	{
		idd=300;
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this call mkk_fcs_optics_fnc_sight_tzf1a";
		controls[]=
		{
            "CA_DistanceText",
            "CA_Distance",
			"CA_IGUI_elements_group"
		};
        class CA_DistanceText: RscOpticsText
        {
			idc = -1;
			style = 2;
			colorText[] = {1,1,1,1};
			shadow = 3;
			colorShadow[] = {100,100,100,95};
			x = "0";
			y = "(SafezoneY+SafezoneH) - 0.05";
			w = "1";
			h = "0.05";
		};
        class CA_Distance: RscOpticsValue
		{
			idc = 198;
			style = 2;
			colorText[] = {0.9,0,0,1};
			shadow = 3;
			colorShadow[] = {100,100,100,95};
			font = "TahomaB";
			x = "0.45 * (SafezoneX+SafezoneW)";
			y = "0.35 * (SafezoneY+SafezoneH)";
			w = "1";
			h = "0.05";
		};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc=170;
			class VScrollbar: VScrollbar
			{
				width=0;
			};
			class HScrollbar: HScrollbar
			{
				height=0;
			};
			x="0 * (0.01875 * SafezoneH) + (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y="0 * (0.025 * SafezoneH) + (SafezoneY)";
			w="53.5 * (0.01875 * SafezoneH)";
			h="40 * (0.025 * SafezoneH)";
			class controls
			{
				class RDS_Sight: RscPicture
				{
					idc=1;
					style="0x30 + 0x800";
					sizeEx="0.038*SafezoneH";
					colorText[]={0.70599997,0.074500002,0.0196,1};
					shadow=0;
					font="EtelkaMonospacePro";
					text="";
					x="13.4 *   (0.01875 * Safezoneh)"; //0.25125
					y="3.66 *   (0.025 * SafezoneH)";   // 0.0915
					w="25.5 *   (0.01875 * SafezoneH)"; // 0.478125
					h="25.5 *   (0.025 * SafezoneH)";   // 0.6375
				};
				class RDS_SightBar: RscPicture
				{
					idc=2;
					style="0x30 + 0x800";
					sizeEx="0.038*SafezoneH";
					colorText[]={0.70599997,0.074500002,0.0196,1};
					shadow=0;
					font="EtelkaMonospacePro";
                    text=QPATHTOF(data\reticles\WST_tzf_1a_sight_ca.paa);
					x="14.3 *   (0.01875 * SafezoneH)";
					y="7.26 *   (0.025 * SafezoneH)";
					w="25.5 *   (0.01875 * SafezoneH)";
					h="25.5 *   (0.025 * SafezoneH)";
				};
                class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 1;
					colorText[] = {1,1,1,1};
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
					text="MKK_SIGHT_TZF_1A";
				};
                class CA_TurretIndicator: RscPicture
				{
					IDC = 206;
					type = 105;
					textSize = "0.02*SafezoneH";
					style = 0;
					color[] = {1,1,1,1};
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
					color[] = {1,1,1,1};
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
					colorText[] = {1,1,1,1};
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
					colorText[] = {1,1,1,1};
					text = "015";
					x = "25.15 * 		(0.01875 * SafezoneH)";
					y = "1.75 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};

    class GVAR(RscWeaponT55_FCS): RscUnitInfo
	{
		idd=300;
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this call mkk_fcs_optics_fnc_sight_tsh232";
		controls[]=
		{
			"CA_IGUI_elements_group"
		};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc=170;
			class VScrollbar: VScrollbar
			{
				width=0;
			};
			class HScrollbar: HScrollbar
			{
				height=0;
			};
			x="0 * (0.01875 * SafezoneH) + (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y="0 * (0.025 * SafezoneH) + (SafezoneY)";
			w="53.5 * (0.01875 * SafezoneH)";
			h="40 * (0.025 * SafezoneH)";
			class controls
			{
				class RDS_Sight: RscPicture
				{
					idc=1;
					style="0x30 + 0x800";
					sizeEx="0.038*SafezoneH";
					colorText[]={0.70599997,0.074500002,0.0196,1};
					shadow=0;
					font="EtelkaMonospacePro";
					text=QPATHTOF(data\reticles\WST_tsh_2_32_sight_ca.paa);
					x = "0 *  (0.01875 * SafeZoneH) - (29 * (0.01875 * SafeZoneH))";
                    y = "0 * (0.025 * SafeZoneH) - (29 * (0.01875 * SafeZoneH))";
                    w = "safeZoneH + (58 * (0.01875 * SafeZoneH))";
                    h = "safeZoneH + (58 * (0.01875 * SafeZoneH))";
				};
				class RDS_SightBar: RscPicture
				{
					idc=2;
					style="0x30 + 0x800";
					sizeEx="0.038*SafezoneH";
					colorText[]={0.70599997,0.074500002,0.0196,1};
					shadow=0;
					font="EtelkaMonospacePro";
                    text="";
					x = "0 *  (0.01875 * SafeZoneH) - (50 * (0.01875 * SafeZoneH))";
                    y = "0 * (0.025 * SafeZoneH) - (50 * (0.01875 * SafeZoneH))";
                    w = "safeZoneH + (100 * (0.01875 * SafeZoneH))";
                    h = "safeZoneH + (100 * (0.01875 * SafeZoneH))";
				};
                class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 1;
					colorText[] = {1,1,1,1};
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
					text="MKK_SIGHT_TSH_2_32";
				};
                class CA_TurretIndicator: RscPicture
				{
					IDC = 206;
					type = 105;
					textSize = "0.02*SafezoneH";
					style = 0;
					color[] = {1,1,1,1};
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
					color[] = {1,1,1,1};
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
					colorText[] = {1,1,1,1};
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
					colorText[] = {1,1,1,1};
					text = "015";
					x = "25.15 * 		(0.01875 * SafezoneH)";
					y = "1.75 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};

    class GVAR(RscWeaponT55A_FCS): RscUnitInfo
	{
		idd=300;
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this call mkk_fcs_optics_fnc_sight_tsh2b32p";
		controls[]=
		{
            "CA_DistanceText",
            "CA_Distance",
			"CA_IGUI_elements_group"
		};
        class CA_DistanceText: RscOpticsText
        {
			idc = -1;
			style = 2;
			colorText[] = {1,1,1,1};
			shadow = 3;
			colorShadow[] = {100,100,100,95};
			x = "0";
			y = "(SafezoneY+SafezoneH) - 0.05";
			w = "1";
			h = "0.05";
		};
        class CA_Distance: RscOpticsValue
		{
			idc = 198;
			style = 2;
			colorText[] = {0, 0, 0 ,1};
			shadow = 3;
			colorShadow[] = {100,100,100,95};
			font = "TahomaB";
			x = "0 * (0.01875 * SafezoneH)";
			y = "0 * (0.025 * SafezoneH) + (7 * (0.01875 * SafeZoneH))";
			w = "1";
			h = "0.05";
		};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc=170;
			class VScrollbar: VScrollbar
			{
				width=0;
			};
			class HScrollbar: HScrollbar
			{
				height=0;
			};
			x="0 * (0.01875 * SafezoneH) + (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y="0 * (0.025 * SafezoneH) + (SafezoneY)";
			w="53.5 * (0.01875 * SafezoneH)";
			h="40 * (0.025 * SafezoneH)";
			class controls
			{
				class RDS_Sight: RscPicture
				{
					idc=1;
					style="0x30 + 0x800";
					sizeEx="0.038*SafezoneH";
					colorText[]={0.70599997,0.074500002,0.0196,1};
					shadow=0;
					font="EtelkaMonospacePro";
					text=QPATHTOF(data\reticles\WST_tsh_2_32_sight_ca.paa);
					x = "0 *  (0.01875 * SafeZoneH) - (29 * (0.01875 * SafeZoneH))";
                    y = "0 * (0.025 * SafeZoneH) - (29 * (0.01875 * SafeZoneH))";
                    w = "safeZoneH + (58 * (0.01875 * SafeZoneH))";
                    h = "safeZoneH + (58 * (0.01875 * SafeZoneH))";
				};
				class RDS_SightBar: RscPicture
				{
					idc=2;
					style="0x30 + 0x800";
					sizeEx="0.038*SafezoneH";
					colorText[]={0.70599997,0.074500002,0.0196,1};
					shadow=0;
					font="EtelkaMonospacePro";
                    text="";
					x = "0 *  (0.01875 * SafeZoneH) - (50 * (0.01875 * SafeZoneH))";
                    y = "0 * (0.025 * SafeZoneH) - (50 * (0.01875 * SafeZoneH))";
                    w = "safeZoneH + (100 * (0.01875 * SafeZoneH))";
                    h = "safeZoneH + (100 * (0.01875 * SafeZoneH))";
				};
                class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 1;
					colorText[] = {1,1,1,1};
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
					text="MKK_SIGHT_TSH_2B_32P";
				};
                class CA_TurretIndicator: RscPicture
				{
					IDC = 206;
					type = 105;
					textSize = "0.02*SafezoneH";
					style = 0;
					color[] = {1,1,1,1};
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
					color[] = {1,1,1,1};
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
					colorText[] = {1,1,1,1};
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
					colorText[] = {1,1,1,1};
					text = "015";
					x = "25.15 * 		(0.01875 * SafezoneH)";
					y = "1.75 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
};
