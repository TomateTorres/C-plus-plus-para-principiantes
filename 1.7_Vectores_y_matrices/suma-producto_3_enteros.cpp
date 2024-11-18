/*
El siguiente programa le pide al usuario 3 números enteros y 
calcula la suma y producto de ellos.
Para tal tarea hace uso de std::vector
*/

#include <iostream>
#include <vector>

int main(){

    std::vector<int> vector(3); // Crea un vector de 3 elementos
                                // de tipo entero.
    std::cout << "Introduce 3 números enteros separados por "
              << "espacios: ";

    std::cin >> vector[0] >> vector[1] >> vector[2]; 
    // Guarda los 3 números introducidos por el usuario como 
    // elementos del vector.

    std::cout << "La suma de ellos es: " << vector[0] + vector[1]
                                            + vector[2] << '\n';
    // Se suman los 3 números.
    
    std::cout << "El producto de ellos es: " << vector[0] 
                                                * vector[1]
                                                * vector[2] 
                                             << '\n';
    // Se obtiene el producto de los 3 números.
    
    return 0;
}
