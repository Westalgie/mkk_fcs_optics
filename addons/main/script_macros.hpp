//#include "\x\cba\addons\main\script_macros_common.hpp" // Included in ACE3's "script_macros.hpp"
//#include "\x\cba\addons\xeh\script_xeh.hpp" // Included in ACE3's "script_macros.hpp"
#include "\z\ace\addons\main\script_macros.hpp"
//#include "script_debug.hpp" // ACE3 debugging framework // Included in ACE3's "script_macros.hpp"


// ACE3 reference macros
#define ACE_PREFIX ace

#define ACEGVAR(module,var) TRIPLES(ACE_PREFIX,module,var)
#define QACEGVAR(module,var) QUOTE(ACEGVAR(module,var))

#define ACEFUNC(var1,var2) TRIPLES(DOUBLES(ACE_PREFIX,var1),fnc,var2)
#define QACEFUNC(var1,var2) QUOTE(ACEFUNC(var1,var2))

#define ACELSTRING(var1,var2) QUOTE(TRIPLES(STR,DOUBLES(ACE_PREFIX,var1),var2))
#define ACECSTRING(var1,var2) QUOTE(TRIPLES($STR,DOUBLES(ACE_PREFIX,var1),var2))

// MKK
#define CHECK(CONDITION) if (CONDITION) exitWith {}
#define CHECKRET(CONDITION,RETURN) if (CONDITION) exitWith {RETURN;}
#define EMPTY_INVENTORY class TransportBackpacks {}; \
class TransportItems {}; \
class TransportMagazines {}; \
class TransportWeapons {}

#ifdef DISABLE_COMPILE_CACHE
    #define PREP_SUB(subfolder,fncName) DFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\subfolder\DOUBLES(fnc,fncName).sqf)
#else
    #define PREP_SUB(subfolder,fncName) [QPATHTOF(functions\subfolder\DOUBLES(fnc,fncName).sqf), QUOTE(DFUNC(fncName))] call CBA_fnc_compileFunction
#endif

// Grad_trenches
#define GRAD_PREFIX grad_trenches
#define GRADGVAR(module,var) TRIPLES(GRAD_PREFIX,module,var)
#define QGRADGVAR(module,var)QUOTE(GRADGVAR(module,var))
