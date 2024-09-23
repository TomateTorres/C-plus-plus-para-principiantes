Un **ciclo** (*loop*) es una estructura de control que permite que una sección de código sea ejecutada repetidamente hasta que se cumpla alguna condición. 

Una **estructura de control en C++** es una construcción del lenguaje que permite controlar el flujo de ejecución de un programa. estas estructuras permiten tomar decisiones, repetir bloques de código, y ejecutar diferentes partes de éste basándose en condiciones. En esencia, determinan cómo y en qué orden se ejecutan las instrucciones de un programa. Por ejemplo, [los condicionales](../1.5_Condicionales/0_Introducción.md) son estructuras de control que permiten tomar decisiones y ejecutar (o no) bloques de código basados en condiciones.

En C++ existen esencialmente tres tipos de bucles:
1. **Bucle `for`:** Se utiliza cuando sabemos el número exacto de veces que queremos repetir un bloque de código.
2. **Bucle `while`:** Se utiliza cuando no sabemos cuántas veces se debe repetir un bloque de código, pero sabemos que debe continuar hasta que una condición se vuelva falsa. Como `while` evalúa la condición antes de ejecutar el bloque de código, si la condición dada es falsa desde el inicio, el bloque de código no se ejecuta ni una sola vez.
3. **Bucle `do-while`:** Es similar al `while`, pero **se ejecuta al menos una vez** aún si la condición es falsa desde el principio porque ejecuta primero el bloque de código y luego evalúa la condición.

Los veremos con detenimiento más adelante.

## Un breve interludio sobre recursión

La **recursión** en programación es una técnica donde una función se llama a sí misma para resolver un problema más grande descomponiéndolo en problemas más pequeños del mismo tipo. Un ejemplo clásico de una función recursiva es *el factorial* ya que: dado $n \in \mathbb{N}$...
1. $n! = 1$, si $n=0$
2. $n! = n \cdot (n-1)!$, si $n\geq 1$

Siempre que querramos definir una función recursiva, necesitaremos definir:
* **Caso base:** Este es el punto donde el problema deja de reducirse y podemos resolverlo directamente (en el ejemplo del factorial, el caso base es $n=0$).
* **Paso recursivo:** La función se llama así misma con un conjunto de datos más pequeño o reducido (en el ejemplo del factorial, el paso recursivo es pasar de $n!$ a $n \cdot (n-1)!$).

Los bucles y la recursión están relacionados en el sentido de que ambos son métodos para repetir la ejecución de un cierto bloque de código. Sin embargo, tienen algunas diferencias:

| Aspecto     | Bucles | Recursión | 
| ----------- | ------- | ------- |
| Estructura  | Control iterativo (`for`, `while`, `do-while`)   | Función que se llama a sí misma |
| Memoria     |   Uso más eficiente de la memoria    | Mayor uso de memoria debido a la pila de llamadas  |
| Legibilidad |   Más legible para iteraciones simples    |  Más legible para problemas de descomposición | 
| Complejidad |   Ideal para tareas repetitivas simples    |  Ideal para problemas recursivos como el cálculo de factorial, Fibonacci, etc. | 
| Riesgo      |  Bucles infinitos si la condición nunca se vuelve falsa    |  Desbordamiento de pila si la recursión no termina correctamente | 

El **desbordamiento de pila** (en inglés: *stack overflow*) es un error que ocurre cuando un programa consume más espacio en la **pila de llamadas** (o sólo *pila*, en inglés: *stack*) de lo que tiene disponible. La pila es una estructura de datos de tamaño finito que se utiliza para almacenar información sobre las funciones activas de un programa: como variables locales, direcciones de retorno, y otros datos necesarios para el control de la ejecución.

Un desbordamiento de pila ocurre a menudo debido a **recursión infinita**, donde una función sigue llamándose a sí misma sin un caso base que termine la recursión. 

## Operadores pre-incremento (`++i`) y pre-decremento (`--i`)

En C++ (y en el mundo de la programación en general) incrementar o decrementar alguna variable entera en una unidad es tan común que dichas acciones tienen sus propios operadores: El **operador incremento (`++`)** y el **operador decremento (`--`)**.

Hay 2 formas de usar al operador `++`: **pre-incremento** y **post-incremento**. De manera análoga tenemos el **pre-decremento** y **post-decremento** para `--`.

Dado que el objetivo de esta sección no es explicar a detalle el funcionamiento de estos dos operadores, vamos a centrarnos solamente en el **pre-incremento (`++i`) y pre-decremento (`--i`)**, que son las variantes relevantes para bucles.

1. El **operador pre-incremento (`++i`):** Dada una variable entera `i`, `++i` incrementa el valor de `i` en 1 antes de que sea utilizada en cualquier otra operación.
```
#include <iostream>

int main()
{
    int x { 5 }; // Definimos la variable `x` y la inicializamos con valor 5
    ++x; // `x` es incrementada en 1

    std::cout << "La variable vale " << x << '\n'; // El valor de `x` es ahora 6
    return 0;
}
```
En el ejemplo anterior, la variable `x` fue incrementada antes de ser impresa en consola.

2. El **operador pre-decremento (`--i`):** De manera muy similar a `++i`, dada una variable entera `i`, `--i` decrementa el valor de `i` en 1 antes de que sea utilizada en cualquier otra operación.
```
#include <iostream>

int main() {
    int a{10}; // `a` es definida e inicializada con valor 10
    int b{--a};  // Primero decrementa `a` a 9, luego asigna 9 a `b`

    std::cout << "a: " << a << '\n';  // `a` es 9
    std::cout << "b: " << b << '\n';  // `b` también es 9

    return 0;
}
```

En el contexto de bucles, los operadores pre-incremento y pre-decremento se utilizan principalmente para manejar contadores, pero también pueden tener usos en la manipulación de índices, parámetros y condiciones.
