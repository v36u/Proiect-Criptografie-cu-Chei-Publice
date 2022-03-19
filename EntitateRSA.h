#pragma once

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;

#include <random>
using std::random_device;
using std::mt19937;

// ReSharper disable once CppInconsistentNaming
class EntitateRSA
{

    static unordered_set<size_t> _chei_private; // Pentru a evita coliziuni

    static random_device _generator_seed; // https://www.cplusplus.com/reference/random/random_device/
    static mt19937 _generator_numere_aleatorii; // https://www.cplusplus.com/reference/random/mt19937/

    const string _nedefinit = "NEDEFINIT";

    size_t _cheie_privata;
    size_t _cheie_publica;
    string _nume;

    static size_t CelMaiMareDivizorComun(const size_t&, const size_t&);

    static size_t GenerareNumarRandom();

    static bool EstePrim(const size_t&);

    static size_t GenerareNumarPrimRandom();

public:
    EntitateRSA();
    explicit EntitateRSA(const string&);
    ~EntitateRSA();
};
