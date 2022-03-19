#pragma once

#include <string>

using std::string;

class EntitateRSA
{
    const string _nedefinit = "NEDEFINIT";

    size_t _cheie_privata;
    size_t _cheie_publica;
    string _nume;

    static size_t CelMaiMareDivizorComun(const int&, const int&);

public:
    EntitateRSA();
    ~EntitateRSA();
};
