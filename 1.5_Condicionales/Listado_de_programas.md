1. 'primos.cpp' es un programa que le pide al usuario un entero en el intervalo [0, 9] y le dice si éste es primo o no.

2. Supongamos que tenemos el siguiente código:
```
#include <iostream>

bool sePuedeSubir()
{
    std::cout << "¿Cuál es tu estatura? (en cm): ";

    double estatura{}; // hay gente traumada que puede darnos su
                     // estatura hasta con milímetros.
    std::cin >> estatura;

    if (estatura >= 140.0)
        return true;
    else
        return false;
}

int main()
{

    if (sePuedeSubir())
        std::cout << "Te puedes subir, ¡yupi!\n";
    else
        std::cout << "Mi pequeño amigo Lannister, lo siento pero no" 
                  << " puedes subir.\n";

    return 0;
}
```
y queremos acortarlo un poco haciendo cambios mínimos. El programa 'cambio.cpp' trae un ejemplo de como podríamos hacerlo.

Como 'moraleja': Nunca necesitamos de una declaración `if` de la forma:
```
if (condición)
  return true;
else
  return false;
```
Lo anterior siempre puede ser reemplazado por la instrucción: `return condición` (como podemos ver al comparar el código anterior y el propuesto en 'cambio.cpp').

3. 'cuatro_operaciones.cpp' es un programa que le pide al usuario dos números y uno de los símbolos de las 4 operaciones básicas para operar con ellos. Además de usar condicionales, este programa nos da un ejemplo de la utilidad de las variables tipo `char` ([a estas variables ya las vimos](../1.1_Variables_y_tipos_de_datos/0_Introducción.md)).

4. 'aceleracion.cpp' es un programa que dada la altura de un edificio en metros, da la altura de una pelota dejada caer desde su piso más alto durante los primeros 5 segundos. Además de dar usar condicionales, este es un ejemplo de un programa 'largo' que se apoya de varias funciones que se llaman entre sí.
