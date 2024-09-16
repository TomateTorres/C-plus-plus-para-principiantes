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

## Ciclos `while` que se ejecutan infinitas veces

Observemos que, si en vez de inicializar la variable `contador` como `1`, la hubiéramos inicializado con un valor mayor que `10` (digamos `24`): 
```
#include <iostream>

int main()
{
    int contador{ 24 }; // Empezamos en 24
    while (contador <= 10) // Evalúa como `false`
    {
        std::cout << contador << ' '; // No se ejecuta. 
        ++contador; // No se ejecuta. 
    } // Nos saltamos el bloque completo.

    std::cout << "¡listo!\n"; // Es lo único que se imprime.

    return 0;
}
```
Lo único que nuestro programa habría impreso en terminal es: `¡listo!`.

Lo anterior es porque, si la condición desde el inicio es evaluada como `false`, el bloque asociado no se ejecuta nunca. Entonces, es posible hacer declaraciones `while` que nunca ejecutan sus bloques de código.

Así como es posible hacer 'ciclos nulos' (que nunca se ejecutan), también es posible hacer ciclos `while` infinitos.

Si dentro de la condición del `while` damos una expresión que siempre es evaluada como `true`, entonces el ciclo es ejecutado *para siempre*. A este tipo de ciclos se les llama **ciclos infinitos**.

Veamos un ejemplo:
```
#include <iostream>

int main()
{
    int contador{ 5 }; // Empezamos en 5
    while (contador <= 10) // `5 <= 10` es `true`
    {
        std::cout << contador << ' '; // Se ejecuta para 
                                      // siempre, porque `5 <= 10`
                                      // evalua siempre a `true` 
        // ++contador; // El incremento es un comentario, ya no
                       // se ejecuta. 
    } // El programa nunca avanza más allá de este bloque de código.

    std::cout << "¡listo!\n"; // Nunca se ejecuta.

    return 0; // Nunca se ejecuta.
}
```
Como `contador` inicia con el valor `5` y `5 <= 10` es siempre `true`, el ciclo se ejecuta infinitas veces. Al correr el programa anterior (podemos hacerlo sin miedo, la computadora no explota) se imprime `5 5 5 5 5 5 5 5 5 5 5 5 5 5 ...` hasta que de manera manual obliguemos al programa a detenerse.

### Ciclos `while` infinitos hechos de manera intencional
Si tenemos la explícita intención de crear un ciclo `while` infinito, podemos hacerlo de la siguiente manera:
```
while (true)
{
  // Este ciclo se va a ejecutar para siempre.
}
```
Las únicas formas de salir de un ciclo `while` son:
* Una declaración `return`.
* Una declaración `break`.
* Una declaración `exit`.
* Una declaración `goto`. 
* Uso de excepciones (`throw`)
* El usuario mata directamente al programa.

Veamos un pequeño ejemplo de cómo salir de un ciclo `while` infinito hecho de manera intencional:
```
#include <iostream>

int main()
{

    while (true) // ciclo infinito
    {
        std::cout << "¿Ciclamos otra vez (s/n)? ";
        char c{};
        std::cin >> c;

        if (c == 'n'){ 
            return 0; // Salimos del ciclo si el usuario da por 
                      // input 'n'.
        }
    }

    return 0;
}
```
El programa se ejecutará una y otra vez hasta que el usuario de `n` como input. En ese momento la declaración `if` evaluará `true` (pues `c == n` será verdadera) y el `return 0;` hará que la función `main` salga, y como ésta es la encargada de ejecutar el programa, éste terminará.

Los **ciclos infinitos intencionales** son bastante comunes en ciertos tipos de programas, especialmente aquellos que deben esperar eventos, realizar tareas continuamente o manejar la lógica de un sistema en tiempo real. Por ejemplo, en los videojuegos, el motor gráfico suele usar un ciclo infinito que actualiza el estado del juego y renderiza la pantalla repetidamente. Este ciclo se ejecuta hasta que el jugador cierra el juego.

## Nombrar variables en bucles

Una **variable de bucle** es una variable que sirve
