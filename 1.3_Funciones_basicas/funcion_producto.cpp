/*
El siguiente programa contiene un ejemplo de una función 
que pide dos números al usuario y le da como resultado
el producto entre ellos.
*/

#include <iostream>

double producto(double x, double y) // Definimos nuestra función
                                    // producto, le decimos que
                                    // va a recibir dos variables
                                    // de tipo 'double'.
{
    return x * y; // Este es el resultado de nuestra función, o
                  // sea el producto de los dos números.
}

int main()
{
    std::cout << "Da tu primer número: ";
    double x{};     // En esta variable vamos a guardar el primer
                    // número.
    std::cin >> x;  // Esta línea es la que le da la instrucción
                    // a la computadora de guardar el input del 
                    // usuario.

    std::cout << "Da tu segundo número: ";
    double y{};
    std::cin >> y; 

    std::cout << "El producto de " << x << " y " << y 
              << " es " << producto(x, y) << '\n';

    return 0;       // El programa ha finalizado.
}
