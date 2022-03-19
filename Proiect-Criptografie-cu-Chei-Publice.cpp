#include "EntitateRSA.h"

#include <Windows.h>
#include <fcntl.h>

#pragma execution_character_set("utf-8")

int main()
{
    SetConsoleOutputCP(65001);

    cout << "=+= Program pentru demonstrarea conceptului de encriptare asimetrică - Criptografie cu Chei Publice =+=\n";

    auto bob = new EntitateRSA("Bob");
    bob->GenerareChei();

    auto alice = new EntitateRSA("Alice");
    alice->GenerareChei();

    delete bob;
    delete alice;
    return EXIT_SUCCESS;
}
