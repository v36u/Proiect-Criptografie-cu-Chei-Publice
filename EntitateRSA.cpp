#include "EntitateRSA.h"

EntitateRSA::EntitateRSA() : _cheie_privata(0), _cheie_publica(0), _nume(EntitateRSA::_nedefinit)
{
}

EntitateRSA::EntitateRSA(const string& p_nume) : EntitateRSA()
{
    this->_nume = p_nume;  // NOLINT(cppcoreguidelines-prefer-member-initializer)
}

EntitateRSA::~EntitateRSA() = default;

size_t EntitateRSA::CelMaiMareDivizorComun(const int& p_numar_1, const int& p_numar_2)
{
    return p_numar_2 ? p_numar_1 : CelMaiMareDivizorComun(p_numar_2, p_numar_1 % p_numar_2);
}
