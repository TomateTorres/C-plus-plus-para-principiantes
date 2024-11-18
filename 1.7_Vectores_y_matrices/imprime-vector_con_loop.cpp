/*
El siguiente programa imprime los elementos de un vector dado
utilizando un ciclo `for`.
*/

#include <iostream>
#include <vector>

int main()
{
    std::vector miVector {4, 6, 7, 3, 8, 2, 1, 9}; 
    // `miVector` es un vector de números enteros.

    std::cout << "{ "; // Esta línea sólo es con fin estético 
                       // (queremos que al imprimir en consola,
                       // el vector sí se vea como vector).

    for (std::size_t indice{ 0 }; indice < miVector.size(); 
         ++indice)
    // Inicializamos la variable `indice` en 0 porque es donde 
    // se empiezan a contar los índices en un `std::vector`, 
    // además la incializamos con tipo `std::size_t` porque es
    // el tipo que tienen los índices de un vector (además del
    // tipo que retorna usar `.size()`). 
    // Como los índices van de 0 a tamaño-1 del vector, tomamos
    // como condición de término cuando `indice==miVector.size()-1`.
    {
        std::cout << miVector[indice] << " "; 
        // Vamos imprimiendo cada uno de los elementos de 
        // `miVector` seguido de un espacio.
    }

    std::cout << "}" << '\n'; // Esta línea sólo es con fin 
                              // estético (queremos que al 
                              // imprimir en consola, el 
                              // vector sí se vea como vector).
    
    return 0;
}
