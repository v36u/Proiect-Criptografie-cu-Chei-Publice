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
    static const size_t LIMITA_NUMAR_ALEATOR;

    // Pentru a evita coliziuni - șansă extrem de mică, dar de dragul conceptului
    static unordered_set<long double> _chei_private;

    static random_device _generator_seed; // https://www.cplusplus.com/reference/random/random_device/
    static mt19937 _generator_numere_aleatorii; // https://www.cplusplus.com/reference/random/mt19937/

    long double _cheie_privata;
    long double _cheie_publica;
    size_t _produs_numere_prime;
    string _nume;

    enum TipCheie
    {
        Privata,
        Publica
    };

    static size_t CelMaiMareDivizorComun(const size_t&, const size_t&);

    static size_t GenerareNumarRandom();

    static bool EstePrim(const size_t&);

    static size_t GenerareNumarPrimRandom();

    static size_t GenerareCheiePrivata(const size_t&);

    long double GetCheieFolosita(const TipCheie&) const;

    long double Encriptare(const long double& p_mesaj, const TipCheie&) const;

    long double Decriptare(const long double& p_mesaj, const TipCheie&) const;
                                                                  
public:
    EntitateRSA();
    explicit EntitateRSA(const string&);
    ~EntitateRSA();

    void GenerareChei();

    long double EncriptareCuCheiePrivata(const long double&) const;
    long double EncriptareCuCheiePublica(const long double&) const;

    long double DecriptareCuCheiePrivata(const long double&) const;
    long double DecriptareCuCheiePublica(const long double&) const;

    friend ostream& operator<<(ostream& p_stream, const EntitateRSA& p_entitate);
};
