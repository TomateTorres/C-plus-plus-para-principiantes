/*
El siguiente programa imprime:
        1
      2 1
    3 2 1
  4 3 2 1
5 4 3 2 1
Mediante ciclos anidados.
*/

#include <iostream>

int main()
{
    int ext{ 1 }; // Empieza en 1 para el primer número de cada 
                  // línea.
    
    while (ext <= 5) // Controla el número de filas (del 1 al 5).
    {
        int espacios { 5 - ext }; // Calcula los espacios en blanco
                                  // al inicio de cada fila, por 
                                  // 'espacio' nos referimos al lugar
                                  // que ocuparía cada número faltante
                                  // con su respectivo espacio en blanco
                                  // (o sea: '5 ' por ejemplo).
        
        while (espacios > 0) // Este ciclo controla los espacios en
                             // blanco al inicio de cada fila.
        {
            std::cout << "  "; // Imprime dos espacios por cada 
                               // iteración.
            --espacios; // Pre-decremento para reducir el número de 
                        // espacios (podemos usar pos-decremento, no
                        // importa).
        }

        int interior{ ext }; // Controla los números en cada fila, 
                             // que empiezan desde el valor de `ext`
        
        while (interior > 0) // Nos vamos moviendo por la fila.
        {
            std::cout << interior-- << ' '; // Imprime el número
                                            // y luego lo decrementa
        }

        std::cout << '\n'; // Al final de cada fila, imprime un 
                           // salto de línea
        ++ext; // Incrementa `ext` para pasar a la siguiente fila
    }

    return 0;
}
