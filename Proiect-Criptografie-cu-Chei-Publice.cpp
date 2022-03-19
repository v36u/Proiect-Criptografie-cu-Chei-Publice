#include "EntitateRSA.h"

#include <Windows.h>
#include <io.h>
#include <fcntl.h>

#pragma execution_character_set("utf-8")

int main()
{
    SetConsoleOutputCP(65001);
    _setmode(_fileno(stdout), _O_U16TEXT);

    auto bob = new EntitateRSA("Bob");
    bob->GenerareChei();

    auto alice = new EntitateRSA("Alice");
    alice->GenerareChei();

    delete bob;
    delete alice;
    return EXIT_SUCCESS;
}
