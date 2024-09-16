El **ciclo `while`** (también llamado **declaración `while`**)es el más sencillo de los tres tipos de ciclos que tenemos en C++. 

Su definición es bastante similar a la de una declaración `if`:
```
while (condición)
{
    declaración;
}
```

Cuando ejecutamos un `while`, la `condición` es evaluada. Si la `condición` es evaluada como `true`, la `declaración` asociada (o declaraciones asociadas) se ejecuta.

Una vez que la `declaración` ha sido ejecutada, el control vuelve a la parte superior de la declaración `while` y el proceso se repite. Esto quiere decir que mientras la `condición` evalúe a `true`, la declaración `while` seguirá repitiéndose.

Veamos el ejemplo de un programa que imprime todos los enteros del 1 al 10:
```
#include <iostream>

int main()
{
    int contador{ 1 }; // Empezamos en el 1
    while (contador <= 10) // Terminamos en 10
    {
        std::cout << contador << ' '; // Entre cada número 
                                      // ponemos un espacio.
        ++contador; // Incrementamos en 1 el contador, este paso 
                    // es muy importante para asegurarnos de no 
                    // hacer un ciclo infinito.
    }

    std::cout << "¡listo!\n"; // El mensaje se imprime después
                              // del 10.

    return 0;
}
```
En este programa:
1. Primero definimos una variable llamada `contador` y la inicializamos con valor `1`. 
2. Cuando `contador == 1`, la condición `contador <= 10` es `true`, entonces las declaraciones dentro del `while` sí se ejecutan. Siempre que la condición `contador <= 10` es `true`, entramos al bloque `while`
3. Una vez dentro del `while`, se imprime el valor en la variable `contador` (en el primer paso, es `1`) y un espacio ` `. Luego la variable `contador` es incrementada en 1 mediante el operador pre-incremento (`++contador`).
4. El control regresa a la parte superior de la declaración `while` y la condición `contador <= 10` se evalúa nuevamente. Si al evaluarla obtenemos `true`, el paso **3.** se repite.
5. El ciclo se va a ejecutar hasta que `contador == 11`, porque `11 <= 10` es `false`. Así, las declaraciones dentro del ciclo serán ignoradas por el programa y éste saltará hasta la línea `std::cout << "¡listo!\n";`.
