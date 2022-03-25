#include "EntitateRSA.h"

#include <Windows.h>
#include <fcntl.h>

#pragma execution_character_set("utf-8")

void AfisareStareCurentaMesaj(const size_t& p_mesaj)
{
    cout << "\nAcum mesajul arată așa: " << p_mesaj;
}

void TrimitereMesajDeLaOEntitateLaAltaEntitate(const EntitateRSA& p_emitator, const EntitateRSA& p_receptor)
{
    unsigned long long mesaj;
    cout << "\nIntroduceți mesajul care trebuie trimis de la " << p_emitator << " către " << p_receptor <<
        " (număr natural relativ mic, vă rog): ";
    cin >> mesaj;

    mesaj = p_emitator.EncriptareDecriptarePrivata(mesaj);
    cout << '\n' << p_emitator << " encriptează mesajul cu cheia sa privată pentru a se putea dovedi că mesajul ar fi putut să fie scris doar de el.";
    AfisareStareCurentaMesaj(mesaj);
    
    cout << '\n';
    
    mesaj = p_receptor.EncriptareDecriptarePublica(mesaj);
    cout << "\nApoi, " << p_emitator << " encriptează mesajul cu cheia publică a lui " << p_receptor << " pentru a se asigura că doar " << p_receptor << " poate decripta mesajul.";
    AfisareStareCurentaMesaj(mesaj);

    cout << '\n';

    mesaj = p_receptor.EncriptareDecriptarePrivata(mesaj);
    cout << '\n' << p_receptor << " decriptează mesajul cu cheia sa privată. Astfel se confirmă faptul că mesajul este menit să ajungă la " << p_receptor << '.';;
    AfisareStareCurentaMesaj(mesaj);
    
    cout << '\n';

    mesaj = p_emitator.EncriptareDecriptarePublica(mesaj);
    cout << "\nApoi, " << p_receptor << " decriptează mesajul cu cheia publică a lui " << p_emitator << ". Astfel se confirmă faptul că mesajul a putut fi scris doar de " << p_emitator << '.';
    AfisareStareCurentaMesaj(mesaj);
}

int main()
{
    SetConsoleOutputCP(65001);

    cout << "=+= Program pentru demonstrarea conceptului de encriptare asimetrică - Criptografie cu Chei Publice =+=\n";

    auto bob = new EntitateRSA("Bob");
    bob->GenerareChei();

    auto alice = new EntitateRSA("Alice");
    alice->GenerareChei();
    
    cout << '\n';
    
    TrimitereMesajDeLaOEntitateLaAltaEntitate(*bob, *alice);
    
    delete bob;
    delete alice;
    
    // Ca să fie ceva mai clean la finalul execuției
    cout << '\n';
    cin.ignore();
    cin.get();

    return EXIT_SUCCESS;
}
