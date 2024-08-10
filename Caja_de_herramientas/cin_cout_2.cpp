#include <iostream>

int main() 
{
    std::cout << "Dame tres números, cada uno separado por un espacio: ";
    int x{}, y{}, z{};
    std::cin >> x >> y >> z;

    std::cout << "Tus números son: " << x << ", " << y << " y "
              << z << ".\n";
    
    return 0;
}
