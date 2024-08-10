`<iostream>` es una biblioteca estándar de C++, cuando hacemos un programa que tiene entrada y salida de datos, es necesario incluir esta librería usando el encabezado `#include <iostream>` en la parte superior del código de nuestro programa. El 'io' de _iostream_ viene de input/output (entrada/salida).

## std::cout

`std::cout` es una variable predefinida de la biblioteca `<iostream>` que nos sirve para enviarle información a la consola para que ésta la imprima como texto. 



**Nota:** En algunos programas de este repositorio se utilizan `cout` y `std::cout` casi de manera indistinta. Observemos que:

```
#include <iostream>

int main() {
    std::cout << "Hola, Mundo!" << std::endl;
    return 0;
}
```

Y

```
#include <iostream>
using namespace std;

int main() {
    cout << "Hola, Mundo!" << endl;
    return 0;
}
```

Son códigos que nos dan el mismo output (_Hola, Mundo!_), pero uno de ellos usa `std::cout` y el otro `cout`. 

La primera diferencia que salta a la vista es que para usar `cout` necesitamos previamente haber declarado `using namespace std;` (si usamos `std::cout` nos ahorramos esta línea). Otra diferencia, que no es obvia, es que en proyectos más grandes es común preferir `std::cout` para evitar problemas de ambigüedad si en tu código o en alguna biblioteca que utilices existen otros elementos llamados `cout` en otros espacios de nombres.

En resumen: Aunque por el momento no importa mucho (la mayoría de los programas que haremos en principio serán sencillos), es buena práctica usar `std::cout` por ser más seguro y explícito.


## std::endl y \n

En el programa:
```
#include <iostream> // para std::cout

int main()
{
    std::cout << "¡Hola!";
    std::cout << "Mi nombre es Alex.";
    return 0;
}
```


El output obtenido es `¡Hola!Mi nombre es Alex.`, esto es porque aunque `std::cout << "¡Hola!";` y `Mi nombre es Alex.";` son comandos de output separados, estos no se imprimen en líneas separadas (o con espacios entre ellos) de manera automática en la pantalla de la consola.

Si queremos espacios entre líneas, tenemos que pedírselo a la consola, uno de los comandos para ello es `std::endl`, 'endl' viene de 'end line':
```
#include <iostream> // para std::cout y std::endl

int main()
{
    std::cout << "¡Hola!" << stad::endl; //el cursor se moverá a la siguiente línea.
    std::cout << "Mi nombre es Alex." << std::endl;
    return 0;
}
```


Notemos dos cosas:
* De manera similar a `std::cout` y `cout`, tenemos que `std::endl` y `endl` cumplen la misma función, pero la mejor práctica es usar `std::endl`.
* En el programa anterior, el último `std::endl` no es estrictamente necesario porque el programa termina inmediatamente después, sin embargo usarlo sigue siendo buena práctica ya que algunos sistemas operativos no ponen la siguiente línea de comando en el reglón conssecuente de forma automática.

Por razones que no son importantes para fines de este material (ver: _'std::cout is buffered'_) `std::endl` es un comando que puede volver a nuestro programa ineficiente si lo usamos muchas veces. Por ello es más conveniente usar `\n`.

`\n` mueve el cursor a la siguiente línea de código, veamos un ejemplo:
```
#include <iostream> // for std::cout

int main()
{
    int x{ 5 };
    std::cout << "x es igual a: " << x << '\n'; // podemos ponerlo usando comillas simples (forma convencional)
    std::cout << "Yep." << "\n";                 // podemos ponerlo usando comillas dobles
    std::cout << "¡Eso es todo, amigos!\n";     // podemos ponerlo entre comillas dobles al final de un texto (esta también es convencional)
    return 0;
}
```
Lo anterior imprime:
```
x es igual a: 5
Yep.
¡Eso es todo, amigos!
```
Siempre que `\n` no esté insertado en una línea de texto con comillas dobles (ej.: "HolaMundo\n"), lo convencional es ponerlo como `'\n'`.


## std::cin

El comando `std::cin` ('cin' viene de 'character input') es un comando que sirve para leer entrada del usuario por medio del teclado. A diferencia de `std::cout` que usa el operador de inserción (<<), `std::cin` usa el operador de extracción (>>) para guardar la información dada por el usuario en alguna variable.

Veamos un ejemplo:
```
#include <iostream>  // para std::cout y std::cin

int main()
{
    std::cout << "Da dos números separados por un espacio : ";

    int x{}; // Definimos (e inicializamos) la variable x donde se guardará el primer número.
    int y{}; // Definimos (e inicializamos) la variable y donde se guardará el segundo número.
    std::cin >> x >> y; // Le pedimos al usuario que nos de los números y los guardamos en sus variables.

    std::cout << "Tus números son " << x << " y " << y << '\n';

    return 0;
}
```
Siempre que introduzcamos dos o más valores, estos deberán estar separados por un espacio, tab o nueva línea.

Para pedirle a la consola que acepte el input del usuario, es encesario presionar la tecla _enter_.
