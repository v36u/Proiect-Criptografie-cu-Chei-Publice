#include "EntitateRSA.h"

int main()
{
    double p = 13;
    double q = 11;
    double n = p * q;
    
    double phi = (p - 1) * (q - 1);

    double e = 7;

    while (e < phi)
    {
        const auto track = gcd(e, phi);
        if (track == 1)
            break;
        e++;
    }

    double d1 = 1 / e;
    double d = fmod(d1, phi);

    double message = 9;
    double c = pow(message, e); 
    double m = pow(c, d);

    c = fmod(c, n);
    m = fmod(m, n);

    cout << "Original Message = " << message;
    cout << "\n" << "p = " << p;
    cout << "\n" << "q = " << q;
    cout << "\n" << "n = pq = " << n;
    cout << "\n" << "phi = " << phi;
    cout << "\n" << "e = " << e;
    cout << "\n" << "d = " << d;
    cout << "\n" << "Encrypted message = " << c;
    cout << "\n" << "Decrypted message = " << m;

    return EXIT_SUCCESS;
}