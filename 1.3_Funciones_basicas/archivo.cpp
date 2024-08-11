#include <iostream>

void foo() // ya no está anidada dentro de main()
{
    std::cout << "foo!\n";
}

int main()
{
    foo();
    return 0;
}
