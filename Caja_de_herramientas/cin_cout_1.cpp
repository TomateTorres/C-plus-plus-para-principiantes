#include <iostream>
#include <string>

using namespace std; //si quitamos esta línea, el programa deja
                     //deja de reconocer a 'string' como una
                     //variable

int main()
{
    std::cout << "Dime tu signo zodiacal: ";

    string x{}; //Aquí guardaremos el signo zodical del usuario
    std::cin >> x; //Le decimos al programa que guarde el signo
                   //zodiacal del usuario en la variable 'x'.
    std::cout << "Típico de " << x << '\n';
    return 0;
}
