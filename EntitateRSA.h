#pragma once

#include <string>
using std::string;
using std::to_string;

#include <unordered_set>
using std::unordered_set;

#include <random>
using std::random_device;
using std::mt19937;

#include <iostream>
using std::cout;
using std::cin;
using std::ostream;

#include <cmath>
using std::fmod;
using std::pow;

#include <stdexcept>
using std::logic_error;

// ReSharper disable once CppInconsistentNaming
class EntitateRSA
{
    static const string NEDEFINIT;
    static const size_t LIMITA_INFERIOARA_NUMAR_ALEATOR;
    static const size_t LIMITA_SUPERIOARA_NUMAR_ALEATOR;

    static random_device _generator_seed; // https://www.cplusplus.com/reference/random/random_device/
    static mt19937 _generator_numere_aleatorii; // https://www.cplusplus.com/reference/random/mt19937/

    size_t _cheie_privata;
    size_t _cheie_publica;
    unsigned long long _produs_numere_prime;
    string _nume;

    enum TipCheie
    {
        Privata,
        Publica
    };

    static size_t GetCelMaiMareDivizorComun(const size_t&, const size_t&);

    static size_t GenerareNumarRandom();

    static bool EstePrim(const size_t&);

    static size_t GenerareNumarPrimRandom();

    size_t GenerareCheiePrivata(const unsigned long long&);

    size_t GenerareCheiePublica(const unsigned long long&) const;

    size_t GetCheieFolosita(const TipCheie&) const;

    unsigned long long EncriptareDecriptare(const unsigned long long&, const TipCheie&) const;

public:
    EntitateRSA();
    explicit EntitateRSA(const string&);
    ~EntitateRSA();

    void GenerareChei();

    size_t EncriptareDecriptarePrivata(const size_t&) const;
    size_t EncriptareDecriptarePublica(const size_t&) const;

    friend ostream& operator<<(ostream& p_stream, const EntitateRSA& p_entitate);
};
