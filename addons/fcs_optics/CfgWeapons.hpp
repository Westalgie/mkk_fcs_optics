class cfgWeapons
{
    // M1A1 GAS
    class rhs_weap_m256;
    class rhs_weap_m240_abrams_coax;
    class rhs_weap_m256_nofcs: rhs_weap_m256
    {
        ballisticsComputer = "2";
    };
    class rhs_weap_m240_abrams_coax_nofcs: rhs_weap_m240_abrams_coax
    {
        ballisticsComputer = "2";
    };

    // M60A1
    class mkk_m60_m68;
    class mkk_m60_m73;
    class mkk_m60_m85;
    class mkk_m60_m68_nofcs: mkk_m60_m68
    {
        ballisticsComputer = "2";
    };
    class mkk_m60_m73_nofcs: mkk_m60_m73
    {
        ballisticsComputer = "2";
    };
    class mkk_m60_m85_nofcs: mkk_m60_m85
    {
        ballisticsComputer = "2";
    };

    // leopard 1a1
    class mkk_leo_weap_l7a3;
    class mkk_MG3_vehicle;
    class mkk_leo_weap_l7a3_nofcs: mkk_leo_weap_l7a3
    {
        ballisticsComputer = "0";
    };
    class mkk_MG3_nofcs: mkk_MG3_vehicle
    {
        ballisticsComputer = "0";
    };
};
