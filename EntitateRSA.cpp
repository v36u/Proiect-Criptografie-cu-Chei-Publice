#include "EntitateRSA.h"

EntitateRSA::EntitateRSA() : _cheie_privata(0), _cheie_publica(0), _nume(EntitateRSA::_nedefinit)
{
}

EntitateRSA::~EntitateRSA() = default;

size_t EntitateRSA::CelMaiMareDivizorComun(const int& p_numar_1, const int& p_numar_2)
{
    return p_numar_2 ? p_numar_1 : CelMaiMareDivizorComun(p_numar_2, p_numar_1 % p_numar_2);
}
