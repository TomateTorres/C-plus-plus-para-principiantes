Un **ciclo** (*loop*) es una estructura de control que permite que una sección de código sea ejecutada repetidamente hasta que se cumpla alguna condición. 

Una **estructura de control C++** es una construcción del lenguaje que permite controlar el flujo de ejecución de un programa. stas estructuras permiten tomar decisiones, repetir bloques de código, y ejecutar diferentes partes del código basándose en condiciones. En esencia, determinan cómo y en qué orden se ejecutan las instrucciones de un programa. Por ejemplo, [los condicionales](../1.5_Condicionales/0_Introducción.md) son estructuras de control que permiten tomar decisiones y ejecutar (o no) bloques de código basados en condiciones.

La **recursión** en programación es una técnica donde una función se llama a sí misma para resolver un problema más grande descomponiéndolo en problemas más pequeños del mismo tipo. Un ejemplo clásico de una función recursiva es *el factorial* ya que: dado $n \in \mathbb{N}$...
1. $n! = 1$ si $n=0$
2. $n! = n \cdot (n-1)!$ si $n\geq 1$
Siempre que querramos definir una función recursiva, necesitaremos definir:
* **Caso base:** Este es el punto donde el problema deja de reducirse y podemos resolverlo directamente (en el ejemplo del factorial, el caso base es $n=0$).
* **Paso recursivo:** La función se llama así misma con un conjunto de datos más pequeño o reducido (en el ejemplo del factorial, el paso recursivo es pasar de $n!$ a $n \cdot (n-1)!$)
