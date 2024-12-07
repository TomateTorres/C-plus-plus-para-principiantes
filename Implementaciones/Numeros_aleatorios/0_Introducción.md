La **generación de números aleatorios** (*RNG*, por sus siglas en inglés) es un concepto fundamental tanto en programación, particularmente en videojuegos, programas de modelación estadística y aplicaciones en criptografía. El RNG se utiliza para introducir elementos de incertidumbre, variabilidad o simulación, replicando de manera programada el comportamiento aleatorio que observamos en la vida real.

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
