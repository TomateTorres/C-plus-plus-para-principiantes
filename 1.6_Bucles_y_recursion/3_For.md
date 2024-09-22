En C++, los ciclos `for` se utilizan para repetir un bloque de código un número determinado de veces, y su sintaxis es la siguiente:
```
for (inicialización; condición; expresión-final) {
    // Código a ejecutar en cada iteración
}
```
1. La `inicialización` es la parte donde se inicializa una o más variables usadas en el ciclo. Esto sucede sólo una vez, al principio del ciclo. Generalmente, se utiliza una variable contadora (ej.: `int i{ 0 }`). Las variables definidas en esta parte son destruidas al final de la ejecución del ciclo, así podemos decir que tienen 'alcance de ciclo' (para saber un poco más sobre el alcance de una variable ver: [*Intro a alcance local*](../1.3_Funciones_basicas/3_Intro_a_alcance_local.md)).
2. En la `condición` se especifica la condición que debe cumplirse para que el ciclo continúe ejecutándose. Mientras esta condición sea `true`, el ciclo se ejecutará. Si es `false`, el ciclo termina.
3. La parte de la `expresión-final` se ejecuta al final de cada iteración en el ciclo. Normalmente, se usa para modificar el valor de la variable contadora, por ejemplo, `++i` para aumentar el valor de `i` en 1.

Una vez que la **expresión-final** se ha evaluado, la ejecución regresa al paso **2.** (es decir, se evalúa nuevamente a la condición).

Veamos un ejemplo:
```
#include <iostream>

int main()
{
    for (int i{ 1 }; i <= 10; ++i){
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
```
En el programa anterior:
1. Primero, declaramos a la variable de bucle `i` y la inicializamos con valor 1.
2. Luego, la condición `i <= 10` es evaluada. En la primera iteración `i == 1`, así que la condición evalúa a `true`, así que la instrucción dentro del `for` se ejecuta (se imprime el valor de `i` y un espacio en blanco).
3. Finalmente, se evalúa `++i`, de manera que el valor de `i` aumenta en 1. Al final de la primera iteración `i == 2`. Después de evaluar `++i`, el ciclo vuelve al paso **2.**.

'Saltamos' entre el paso **2.** y **3.** hasta que `i == 11`. En ese momento `i <= 10` evaluará a `false` y saldremos del ciclo.

De este modo, el programa anterior imprimió: `1 2 3 4 5 6 7 8 9 10`.

## Algunas variaciones útiles en la `expresión-final`

Aunque es lo más común, la `expresión-final` no tiene por qué limitarse a sólo incrementar en 1 la variable que estemos usando para contar las iteraciones de nuestro ciclo.

1. Podemos decrementar en vez de incrementar:
```
#include <iostream>

int main()
{
    for (int i{5}; i > 0; --i) {
    std::cout << "Cuenta regresiva: " << i << '\n';
    }

    std::cout << '\n';

    return 0;
}
```
Aquí `i` comienza en 5 y se va reduciendo hasta que la condición `i > 0` deja de cumplirse.

2. Podemos modificar el valor de nuestra variable de bucle en más de una unidad por iteración:

En este programa incrementamos en pasos de 2:
```
#include <iostream>

int main()
{
    for (int i{ 0 }; i <= 10; i += 2) // Incremento de 2 por
                                      // iteración.
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
} // Imprimimos los pares des 0 al 10.
```

Y en este decrementamos en pasos de 3:
```
#include <iostream>

int main() {
    for (int i{10}; i >= 0; i -= 3) {  // Decremento en pasos 
                                        // de 3
        std::cout << "i: " << i << '\n';
    }
    return 0;
} // Imprimimos (un número por fila): 10, 7, 4, 1
```

En general, la `expresión-final` en un ciclo `for` no está limitada a simples incrementos o decrementos. Podemos usarla para realizar:
* Incrementos o decrementos en pasos no unitarios.
* Operaciones complejas como multiplicaciones o llamadas a funciones.
* Actualización de múltiples variables simultáneamente (esto lo veremos en las próximas líneas).
* Control de iteradores en contenedores (esto es útil cuando trabajamos con vectores y matrices).

## Expresiones omitidas

Es posible escribir ciclos `for` que omitan alguna (algunas o todas) de las 3 expresiones en su encabezado.

Por ejemplo, aquí omitimos la `inicialización` y la `expresión-final`:
```
#include <iostream>

int main()
{
    int i{ 0 }; // Definimos e inicializamos `i` como un entero
                // con valor 0.
    for ( ; i < 10; ){ // Omitimos la `inicialización` y la 
                       // `expresión-final`.
        std::cout << i << ' ';
        ++i; // Al incremento de la variable lo pusimos dentro
             // del `for`.
    }

    std::cout << '\n';

    return 0;
}
```
En terminal se imprime: `0 1 2 3 4 5 6 7 8 9`.

Nótese que nosotros hicimos de manera 'manual' la inicialización e incremento de la variable de bucle `i`, en vez de dejarlo en el encabezado del `for`. En este ejemplo, lo hicimos así con finalidad únicamente ilustrativa, pero hay situaciones donde no definir una variable de bucle en la `inicialización` (porque ya la hemos definido previamente) o no incrementarla en la `expresión-final` (porque queremos incrementarla de alguna forma especial) es preferible.

Aunque no es común (y es preferible hacer esto usando un ciclo `while`) es posible hacer **ciclos `for` infinitos:**
```
#include <iostream>

int main()
{
    for (;;) {
    std::cout << "Ciclo infinito" << '\n';
    }


    return 0;
} // 'Ciclo infinito' se imprime para siempre (léase: hasta que
  // matemos el programa de forma manual, se vaya la luz, el universo
  // explote...)
```
Lo anterior es equivalente a:
```
#include <iostream>

int main()
{
    while (true) {
    std::cout << "Ciclo infinito" << '\n';
    }


    return 0;
} 
```

## Ciclos `for` con múltiples contadores

Aunque por lo general los ciclos `for` iteran sobre una sola variable, a veces 
