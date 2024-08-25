#include <iostream>

void operacion(double x, double y, char z)
{
    if (z == '+')
        std::cout << "El resultado de " << x << " + " << y
                  << " es: " << x + y << '\n';
    else if (z == '-')
        std::cout << "El resultado de " << x << " - " << y
                  << " es: " << x - y << '\n';
    else if (z == '*')
        std::cout << "El resultado de " << x << " * " << y
                  << " es: " << x * y << '\n';
    else if (z == '/')
        std::cout << "El resultado de " << x << " / " << y
                  << " es: " << x / y << '\n';
}

int main()
{
    std::cout << "Dame tu primer número: ";
    double x{};
    std::cin >> x;

    std::cout << "Dame tu segundo número: ";
    double y{};
    std::cin >> y;

    std::cout << "Dame uno de los siguientes símbolos para\n"
              << "realizar una operación: +, -, * ó /: ";
    char z{};
    std::cin >> z;

    operacion(x, y, z);

    return 0;
}


