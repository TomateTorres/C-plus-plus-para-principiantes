La **generación de números aleatorios** (*RNG*, por sus siglas en inglés) es un concepto fundamental en programación, particularmente en videojuegos, programas de modelación estadística y aplicaciones en criptografía. El RNG se utiliza para introducir elementos de incertidumbre, variabilidad o ruido, replicando de manera programada el comportamiento aleatorio que observamos en la vida real.

En los videojuegos, el RNG es un motor esencial para la rejugabilidad, ya que asegura experiencias únicas en cada partida. 

Por ejemplo, juegos como *Enter the Gungeon* dependen profundamente del RNG para generar mazmorras, enemigos, cofres y recompensas de manera procedural. Esto garantiza que cada nivel sea diferente y que los jugadores tengan que adaptarse continuamente a lo inesperado.

![maxresdefault](https://github.com/user-attachments/assets/0cbc8b12-f60b-4ad5-b550-0888b8dea919)

En la vida real, podemos producir aleatoriedad lanzando una moneda, un dado o revolviendo un mazo de cartas. Este tipo de eventos en realidad no son propiamente aleatorios, pero involucran tantas variables físicas (como la gravedad, resistencia al aire, momento...) que se vuelven prácticamente imposibles de predecir o controlar y producen resultados que para fines prácticos sí son aleatorios.

Las computadoras modernas no pueden tomar ventaja de este tipo de eventos ya que ellas viven en un mundo eléctrico controlado donde todo es binario (0 ó 1) y no hay un punto medio. Por su propia naturaleza, las computadoras están diseñadas para producir resultados lo más predecibles posibles: Cuando se le pide a una computadora que realice una operación matemática, lo deseable es obtener el mismo resultado *siempre*.

En consecuencia, las computadoras son generalmente incapaces de generar números verdaderamente aleatorios. En su lugar, los programas que así lo requieran simulan aleatoriedad mediante algoritmos.

## PRNGs

Para simular la aleatoriedad, los programas típicamente usan **generadores de números pseudo-aleatorios** (PRNGs por sus siglas en inglés). Un generador de números pseudo-aleatorios es un algoritmo que genera una secuencia de números que parecen aleatorios, pero en realidad son completamente deterministas porque están basados en un valor inicial llamado **semilla** (*seed*).

### ¿Cómo funciona un PRNG?

1. Semilla inicial:
   1. La **semilla** es el valor de entrada inicial que utiliza el PRNG para generar la secuencia de números. Cambiar la semilla cambia completamente la secuencia resultante.
   2. Dado un PRNG, al correrlo con una misma semilla, éste generará la misma secuencia de números sin importar cuántas veces lo corramos. Esto es lo que lo hace determinista. 
2. Fórmula matemática:
   1. Los PRNGs utilizan funciones matemáticas, como multiplicaciones, divisiones y sumas, para producir la siguiente salida basada en la semilla actual. Un ejemplo simple es el **Generador Congruencial Lineal** (*LCG* por sus siglas en inglés):
   $X_{n+1}=(a \cdot X_n + c)$ mod $m$

   Donde:
   * $X_n$ es el número generado en el paso $n$.
   * $a$, $c$ y $m$ son constantes.
   * $X_0$ es la semilla inicial.

La semilla es esencial para el funcionamiento del PRNG porque:
1. Usar la misma semilla garantiza la misma secuencia de números. Esto es útil en simulaciones o videojuegos, donde necesitamos reproducir escenarios idénticos (como en *Minecraft*, si dos o más jugadores usan una misma semilla, tendrán generado el mismo mundo).
2. Si no se especifica una semilla, los sistemas suelen usar una basada en el reloj del sistema para garantizar una secuencia "impredecible".
3. En programación, podemos fijar una semilla para depurar programas que usan números aleatorios, ya que permite reproducir los mismos resultados.

Existen muchos algoritmos PRNG; por razones en las que no profundizaremos aquí, muchos de ellos son considerados obsoletos bajo estándares modernos. Más adelante en este material sólo profundizaremos en aquellos (en realidad *aquel*) que funciona de manera decente y es sencillo de utilizar. 

## Proporcionar una semilla

Como ya se mencionó anteriormente, la secuencia de "números aleatorios" generada por un PRNG no es aleatoria en lo absoluto (pues queda determinada por su semilla).

Para que un PRNG nos retorne secuencias distintas, su **estado inicial** (configuración interna del algoritmo cuando comienza a generar números pseudo-aleatorios) debe ser variado. El valor (o conjunto de valores) usado para establecer el estado inicial de un PRNG es llamado **semilla aleatoria** (o simplemente *semilla*). Cuando el estado inicial de un PRNG ha sido determinado usando una semilla, decimos que ha sido sembrado (*seeded*). 

Lamentablemente, no podemos usar un PRNG para generar semillas aleatorias. O sea, *es posible* pero no es recomendable. 

Supongamos que tenemos un PRNG1 que hace uso de un PRNG2 para la generación de semillas aleatorias:

1. Si conocemos la semilla o estado interno de PRNG2, podemos predecir las semillas que se generarán para ser usadas en PRNG1... Lo cual nos da las herramientas necesarias para predecir las secuencias generadas por PRNG1.
2. PRNG1 depende completamente de PRNG2. Cualquier defecto que tenga PRNG2 se propaga a PRNG1; por ejemplo, si PRNG2 siempre genera la misma semilla debido a un mal diseño, PRNG1 generará siempre la misma secuencia aún si PRNG1 sí está bien diseñado.

Teóricamente, el número máximo de secuencias únicas que puede generar un PRNG está determinado por el *número de bits en en el estado* de dicho PRNG.

Un **bit** es la unidad más pequeña de información en la computación. Sólo puede tener uno de dos valores posibles: 0 ó 1. Podemos pensar en un bit como un interruptor: puede estar apagado (0) o encendido (1). 

El estado de un PRNG se representa con un conjunto de bits. Por ejemplo: 
* Si un PRNG tiene un estado de 32 bits, significa que puede almacenar 32 interruptores, cada uno siendo 0 ó 1.
* Como cada bit tiene dos valores posibles, el total de combinaciones únicas es $2^{32}$. Este número es el total de secuencias únicas que puede generar el PRNG... *En teoría.*

El número real de secuencias únicas que puede generar un PRNG queda determinado por el número de semillas únicas que le podemos proveer. Por ejemplo, si usamos un algoritmo que sólo puede generar 4 semillas únicas para sembrar un PRNG, éste sólo puede generar (a lo más) 4 secuencias únicas.


## Aleatorización en C++

El encabezado (*header*) `<random>` de la librería estándar de C++ es aquel que nos permite acceder a las capacidades de aleatorización de este lenguaje. Dentro de la biblioteca `random` hay 6 familias de PRNGs disponibles:

1. Linear Congruential Generators (LCG)
2. Mersenne Twister (MT19937)
3. Subtractive Generators
4. Lagged Fibonacci Generators
5. Xorshift Generators
6. PCG (Permuted Congruential Generator)

De ellos, el más destacado es **Mersenne Twister** y es ampliamente utilizado porque:
* Tiene un periodo gigantesco ($2^{19937}-1$), esto para fines prácticos quiere decir que suele garantizar la generación de secuencias largas sin repetición.
* Produce números con distribución uniforme ("todos los números tienen la misma probabilidad de aparecer") y cumple con muchas pruebas estadísticas de calidad.
* Es ideal para simulaciones científicas, videojuegos, y tareas que requieren alta calidad en la aleatoriedad, pero no son críticas en tiempo real o seguridad.

Aunque para los fines de este material Mersenne Twister *está bien*, esto no significa que sea el mejor PRNG. Fuera de la biblioteca estándar, tenemos opciones como:
* La [familia Xoshiro](https://prng.di.unimi.it/) y [Wyrand](https://github.com/wangyi-fudan/wyhash) para PRNGs no criptográficos.
* La [familia Chacha](https://cr.yp.to/chacha.html) para PRNGs criptográficos y no-predecibles.

Aunque estas herramientas no son necesarias por el momento es bueno saber que existen. 
