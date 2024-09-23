/*
'Fizz Buzz' es un juego matemático sencillo utilizado para enseñar
a los niños sobre la divisibilidad. También es comúnmente 
utilizado como pregunta en entrevistas de programación para 
evaluar habilidades básicas.

Las reglas del juego son simples: empezando desde 1 y contando 
hacia arriba, se reemplaza cualquier número divisible solo por 3
con la palabra "Fizz", cualquier número divisible solo por 5 con
la palabra "Buzz", y cualquier número divisible tanto por 3 como
por 5 con la palabra "FizzBuzz".

Este programa implementa el juego dentro de una función llamada 
`fizzbuzz()`, la cual toma un parámetro que indica hasta qué 
número se debe contar. Utiliza un ciclo `for` y una estructura de
control `if-else` (con los `else-if` intermedios necesarios) para
determinar los reemplazos.
*/

#include <iostream>

void fizzbuzz(int num){
    for (int i{1}; i<=num; ++i){ // `i` va desde 1 al número dado
        if ((i % 3 == 0) && (i % 5 == 0)){ // Si el número en que 
                                           // vamos es divisible entre
                                           // 3 y 5
            std::cout << "FizzBuzz\n";
        }
        else if (i % 3 == 0){ // Si el número en el que vamos sólo
                              // es divisible entre 3.
            std::cout << "Fizz\n";
        }
        else if (i % 5 == 0){ // Si el número en el que vamos sólo
                              // es divisible entre 5.
            std::cout << "Buzz\n";
        }
        else{ // Si el número en que vamos no es divisible entre 3
              // y no es divisible entre 5.
            std::cout << i << '\n';
        }
    }
}

int main(){
    int num{};
    std::cout << "¿Hasta qué número quieres contar? ";
    std::cin >> num;
    fizzbuzz(num);

    return 0;
}
