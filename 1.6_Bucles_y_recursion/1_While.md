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

Así como es posible hacer 'ciclos nulos' (que nunca se ejecutan), también es posible hacer ciclos infinitos.

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

Una **variable de bucle** (*loop variable*) es una variable que sirve para controlar cuántas veces un ciclo es ejecutado. En uno de los ejemplos, la variable `contador` cumplía esta función, de este modo `contador` es una variable de bucle. Lo más común es que este tipo de variables sean de tipo `int`, pero no es inusual encontrarnos con otros tipos (como `char`).

Con frecuencia se usan nombres simples para las variables de bucle (siendo `i`, `j`, `k` los nombres más comunes). Sin embargo, es mejor nombrar a nuestras variables de bucle de manera en que sea más o menos claro cuál es su función (esto es buena práctica para todo tipo de variable); por ejemplo, si necesitamos una variable de bucle que nos ayude a movernos por los índices de una lista, lo más adecuado sería ponerle un nombre como `indice` o `index`.

Las variables de bucle más comunes son aquellas que sirven de contadores (la variable `contador` en algunos de los ejemplos anteriores cumplía esta función), ya que estas nos permiten mantener un registro de las veces que se ha ejecutado nuestro ciclo.

## Hacer algo cada `N` iteraciones
Cada vez que un ciclo se ejecuta, decimos que iteró una vez.

A menudo, queremos hacer algo cada 2, 3, 4 ó N iteraciones. Esto se puede hacer mediante el uso del operador residuo (`%`) aplicado a nuestro contador:
```
#include <iostream>

// Vamos a iterar por todos los enteros del 1 al 50
int main()
{
    int contador{ 1 }; // Empezamos en 1
    while (contador <= 50) // Iteramos hasta llegar al 50
    {
    
        if (contador < 10) // Del 1 al 9
        {
            std::cout << '0'; // Imprimimos primero un '0'
        }

        std::cout << contador << ' '; // El número y un en el que
                                      // vamos y un espacio ' '

        if (contador % 10 == 0) //Si el número en el que vamos es 
                                // divisible entre 10,
        {
            std::cout << '\n'; // Hacemos un salto de línea
        }

        // Incrementamos en 1 al `contador`
        ++contador;
    }

    return 0;
}
```
En el programa anterior, usamos el operador `%` para hacer un salto de línea cada 10 números, de este modo en terminal se imprime:
```
01 02 03 04 05 06 07 08 09 10 
11 12 13 14 15 16 17 18 19 20
21 22 23 24 25 26 27 28 29 30
31 32 33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48 49 50
```

## Bucles anidados
Al igual que en funciones y declaraciones condicionales, es posible anidar bucles.

Veamos un ejemplo de un programa que imprime la carita `ლ(́◉◞౪◟◉‵ლ)` en forma de un rectángulo de medidas dadas por el usuario:
```
#include <iostream>

int main() 
{
    int filas{}, columnas{}; // Esta es una manera más compacta
                             // de declarar dos (o más) variables
                             // de un mismo tipo.

    // Pedimos al usuario las dimensiones del cuadrado
    std::cout << "Introduce el número de filas: ";
    std::cin >> filas;
    std::cout << "Introduce el número de columnas: ";
    std::cin >> columnas;

    int contFilas {1};  // Inicializamos el contador de filas

    // Ciclo para las filas
    while (contFilas <= filas) 
    {
        int contColumnas {1};  // Inicializamos el contador de 
                               // columnas
                               // NOTA: Esta variable se crea al
                               // inicio de cada iteración del
                               // ciclo exterior y se destruye al
                               // final de ésta.

        // Bucle para las columnas
        while (contColumnas <= columnas) 
        {
            // Imprimir carita
            std::cout << " ლ(́◉◞౪◟◉‵ლ) ";
            ++contColumnas;  // Incrementamos el contador de columnas
        }

        // Salto de línea después de cada fila
        std::cout << '\n';
        ++contFilas;  // Incrementamos el contador de filas
    } // `contColumnas` es destruida aquí, eso permite que conforme 
      // bajamos por las filas, podamos imprimir el número de columnas
      // deseado.

    return 0;
}
```

Supongamos que los datos dados por el usuario son: `filas == 5` y `columnas == 3`.
1. Primero, tenemos un ciclo exterior (`contFilas` es su variable de bucle) que iterará un total de 5 veces (pues queremos 5 filas de caritas). 
2. En la primera iteración del ciclo exterior, `contFilas == 1`. Al ejecutar e ciclo exterior, entramos a su cuerpo y en él nos encontramos con un segundo ciclo `while` con variable de bucle `contColumnas`  (que ya fue definida e inicializada con valor 1 para cuando entramos al segundo bucle).
3. Dentro del segundo ciclo pasa lo siguiente: Se imprime la carita ` ლ(́◉◞౪◟◉‵ლ) ` y se incrementa en uno a la variable `contColumnas`. De este modo, se imprimen tantas caritas como el número de columnas deseado (en este caso 3).
4. Salimos del segundo ciclo (el que controla las columnas), se imprime un salto de línea y se incrementa en uno a `contFilas`. Así, hemos terminado con la primer línea de caritas y nos movemos a la segunda. Para este momento, la variable `contColumnas` ha sido destruida pues llegamos al final del bloque de código donde fue definida (el del primer ciclo).
5. En la segunda iteración del ciclo exterior, `contFilas == 2`. La variable `contColumnas` es (nuevamente) creada e inicializada con el valor 1.
6. Se vuelven a imprimir las 3 caritas correspondientes.
7. El proceso se repite hasta terminar con las 5 filas.

El output obtenido es:
```
Introduce el número de filas: 5
Introduce el número de columnas: 3
 ლ(́◉◞౪◟◉‵ლ)  ლ(́◉◞౪◟◉‵ლ)  ლ(́◉◞౪◟◉‵ლ)
 ლ(́◉◞౪◟◉‵ლ)  ლ(́◉◞౪◟◉‵ლ)  ლ(́◉◞౪◟◉‵ლ)
 ლ(́◉◞౪◟◉‵ლ)  ლ(́◉◞౪◟◉‵ლ)  ლ(́◉◞౪◟◉‵ლ)
 ლ(́◉◞౪◟◉‵ლ)  ლ(́◉◞౪◟◉‵ლ)  ლ(́◉◞౪◟◉‵ლ)
 ლ(́◉◞౪◟◉‵ლ)  ლ(́◉◞౪◟◉‵ლ)  ლ(́◉◞౪◟◉‵ლ)
```
