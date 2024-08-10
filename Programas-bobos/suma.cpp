#include <iostream>  // para std::cout y std::cin

int main()
{
    std::cout << "Da dos números separados por un espacio : ";

    int x{}; // Definimos (e inicializamos) la variable x donde se guardará el primer número.
    int y{}; // Definimos (e inicializamos) la variable y donde se guardará el segundo número.
    std::cin >> x >> y; // Le pedimos al usuario que nos de los números y los guardamos en sus variables.

    std::cout << "Tus números son " << x << " y " << y << '\n';

    return 0;
}
