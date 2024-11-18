/*
Este programa hace lo mismo que `imprime-vector_con_loop.cpp`
pero utilizando un `template <typename T>`. Esos vienen aquí:
https://www.learncpp.com/cpp-tutorial/function-templates/
*/


#include <iostream>
#include <vector>

template <typename T>
void imprimeVector(const std::vector<T>& vector)
{
    std::cout << "{ "; 
    
    for (std::size_t indice{ 0 }; indice < vector.size(); 
         ++indice)
    {
        std::cout << vector[indice] << " "; 
    }

    std::cout << "}" << '\n';
    
}


int main()
{
    std::vector miVector {4, 6, 7, 3, 8, 2, 1, 9}; 
    // `miVector` es un vector de números enteros.

    imprimeVector(miVector);
    
    return 0;
}
