Hasta ahora, cuando usamos funciones en nuestros programas, hemos sido cuidadosos de definir nuestras funciones en líneas anteriores a su llamador. Lo cual es deseable porque el contenido de los archivos de código es compilado de manera secuencial.

Sin embargo, es válido preguntarse qué pasa si hacemos las cosas en un orden distinto. Consideremos el siguiente código:
```
#include <iostream>

int main()
{
    std::cout << "El doble de 99 es: " << doble(99) << '\n';
    return 0;
}

int doble(int x)
{
    return 2 * x;
}
```
Quisiéramos que el output fuera `El doble de 99 es: 198`. Sin embargo, el programa ni siquiera compila (en VSCode parte del mensaje de error dice: `error: 'doble' was not declared in this scope`). La razón por la que este programa no compila es que (como ya dijimos antes) el código es compilado de manera secuencial, así que cuando el compilador llega a `doble(99)` no sabe qué hacer porque no sabe qué es `doble` (esto lo sabe hasta varias líneas después, cuando ya hemos definido a la función).

En principio, una solución sencilla es cambiar el orden de nuestro código y mandar a la función que llamaremos hasta la parte de arriba del código, como lo hemos hecho hasta ahora. En este programa (y en muchos programas 'sencillos') esta es la mejor solución.

Sin embargo, esto no siempre es conveniente o si quiera posible:
* Si nuestro código es muy largo y tiene muchas funciones, puede ser complicado identificar cuáles funciones llaman a otras (y el orden en que lo hacen) para poder reordenar nuestro código.
* Si tenemos un programa con dos funciones, digamos *f* y *g*, de manera en que *f* llama a *g* y *g* llama a *f* no existe una forma en que podamos reordenar nuestro código de manera que el compilador no se queje.
* Puede que necesitemos llamar a una función que fue definida en otro archivo de código.

En casos 'complicados' la solución es usar una **declaración directa** (en inglés: *forward declaration*). Una declaración directa es una manera de decirle al compilador sobre la existencia de una función antes de definir el cuerpo de la función. Así, cuando el compilador se encuentre con el identificador de la función, entenderá qué es lo que le estamos pidiendo que haga, aún cuando no sepa cómo o dónde está definida la función.

Para escribir una declaración directa, usamos una **declaración de función prototipo** (o simplemente *declaración*; en inglés se encuentra como *function declaration prototype*). Una declaración de función prototipo consiste de:
1. El tipo de retorno de la función.
2. El nombre de la función.
3. Los tipos de parámetros que recibe y el número de estos (es opcional nombrar a los parámetros).
4. Un `;`.

Por ejemplo, para la función `doble()` las declaraciones:
```
int doble(int x);
```
y
```
int doble(int);
```
son igual de válidas. Aunque es preferible dejar los nombres de los parámetros (o sea, `int doble(int x)` es 'mejor' que `int doble(int)`) ya que estos hacen más fácil la lectura del código para nosotros los humanos (además de que la manera más fácil de declarar una función prototipo es copiar y pegar la primera línea de código de la función en cuestión y agregar `;` al final).

Ahora, este es nuestro programa original que no compilaba usando declaración directa para la función `doble()`:
```
#include <iostream>

int doble(int x); //Declaramos a la función en una (o más) línea
                  //antes de su llamador.
int main()
{
    std::cout << "El doble de 99 es: " << doble(99) << '\n';
    return 0;
}

int doble(int x)
{
    return 2 * x;
}
```

Una pregunta que puede surgir es qué pasa si declaramos de manera directa una función, pero al final no la definimos nunca (no hay una sección de código con la función con todo y cuerpo). Como con todo en esta vida: depende. Si declaramos una función a la que nunca llamamos, no importa, el programa correrá sin problemas, aunque probablemente (dependiendo de nuestro IDE y su configuración) recibamos un mensaje de advertencia similar al que aparece cuando declaramos una variable que no se usa.

Donde sí importa es cuando declaramos una función a la que **sí** llamamos, pero no la definimos nunca. Por ejemplo:
```
#include <iostream>

int doble(int x); //Declaramos a la función en una (o más) línea
                  //antes de su llamador.
int main()
{
    std::cout << "El doble de 99 es: " << doble(99) << '\n';
    return 0;
}

// No definimos la función `doble()`
```
Nos aparecerá un error porque nunca definimos `doble()`, entonces el programa no entiende a qué nos referimos cuando le damos la instrucción `doble(99)`.

Lo más común es usar declaraciones directas cuando se trata de funciones. Sin embargo, también las podemos usar con otros identificadores de C++ como variables y tipos, aunque para ellos la sintaxis es un poco distinta.

### Declaraciones y definiciones
