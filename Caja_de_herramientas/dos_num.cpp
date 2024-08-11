/*
Este programa le pide al usuario dos números, luego le da el
resultado de la suma y la diferencia de estos.
*/


#include <iostream>

int main()
{
    double x{}, y{}; //Los números no necesariamente son enteros.
   
    std::cout << "Dame tu primer número: ";
    std::cin >> x;

    std::cout << "Dame tu segundo número: ";
    std::cin >> y;

    double suma{x+y}; 
    double resta{x-y};

    std::cout << x << " + " << y << " es: " << suma << ".\n";
    std::cout << x << " - " << y << " es: " << resta << ".\n";

    return 0;
}
