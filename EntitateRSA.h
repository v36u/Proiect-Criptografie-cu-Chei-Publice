#pragma once

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;

#include <random>
using std::random_device;
using std::mt19937;

#include <iostream>
using std::cout;

#include <cmath>
using std::fmod;

// ReSharper disable once CppInconsistentNaming
class EntitateRSA
{
    // Pentru a evita coliziuni - șansă extrem de mică, dar de dragul conceptului
    static unordered_set<long double> _chei_private;

    static random_device _generator_seed; // https://www.cplusplus.com/reference/random/random_device/
    static mt19937 _generator_numere_aleatorii; // https://www.cplusplus.com/reference/random/mt19937/

    const string _nedefinit = "NEDEFINIT";

    long double _cheie_privata;
    long double _cheie_publica;
    string _nume;

    static size_t CelMaiMareDivizorComun(const size_t&, const size_t&);

    static size_t GenerareNumarRandom();

    static bool EstePrim(const size_t&);

    static size_t GenerareNumarPrimRandom();

    static size_t GenerareCheiePrivata(const size_t&);

public:
    EntitateRSA();
    explicit EntitateRSA(const string&);
    ~EntitateRSA();

    void GenerareChei();
};
