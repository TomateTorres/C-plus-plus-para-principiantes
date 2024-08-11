En el _README.md de esta sección, ya vimos que la sintaxis más básica de una función definida por el usuario es:
```
Tipo_de_output Nombre_de_la_función() // Este es el encabezado de la función (le avisa al compilador que la función existe)
{
    // Este es el cuerpo de la función (le dice al compilador lo que la función hace)
}
```

Aunque mencionamos la existencia de funciones tipo `void` y vimos un ejemplo, no hemos dicho que significa esto. Vamos a explorar a este tipo de funciones.

**Ojo:** El que una función sea de tipo `void` no significa que ésta no hace nada, sólo quiere decir que para efectos de C++, lo que sea que está haciendo no se guarda en una variable de ningún tipo.

## Valores de retorno de tipo void
Estrictamente hablando, una función no está obligada a devolver un valor al ser llamada. Para decirle a la computadora que una función no va a devolver un valor, debemos definirla como tipo `void`. Veamos un ejemplo:
```
#include <iostream>

// 'void' significa que la función no va a devolver un valor al ser llamada
void diHola()
{
    std::cout << "¡Buenos días estrellitas, " 
                 "la Tierra les dice hola! \n";

    // Esta función no devuelve un valor, así que no es necesario
    // agregar una línea con la instrucción 'return'.
}

int main()
{
    diHola(); // llamamos a la función diHola(), ningún valor es devuelto.

    return 0;
}
```
`diHola()` es una función que imprime un mensaje para el usuario, pero no necesita devolver nada a quien la llama (en este caso, la función `main()`). Entonces, le damos el tipo `void` a la función `diHola()` al definirla.

Una función que no regresa valores es llamada _función que no devuelve valores_ (_'non-value returning function'_ en inglés) o _función vacía_ (_'void function'_).

Como vimos en nuestro ejemplo, las funciones vacías regresan de manera automática al llamador (en el caso de nuestro ejemplo, `main()`) una vez que terminan su ejecución, no es necesario agregarles la instrucción `return`.

Podemos agregar la instrucción al final del código de una función vacía, pero esto es redundante:
```
#include <iostream>

// 'void' significa que la función no va a devolver un valor al ser llamada
void diHola()
{
    std::cout << "¡Buenos días estrellitas, " 
                 "la Tierra les dice hola! \n";

    // Esta función no devuelve un valor, así que no es necesario
    // agregar una línea con la instrucción 'return'.
    return; // Le dice al compilador que vuelva al llamador (en este caso 
            // main()), pero esto es redundante porque esto ya iba a pasar 
            // de todos modos. Nuestro código sigue funcionando bien, pero
            // tenemos una línea que no sirve para nada.
}

int main()
{
    diHola(); // llamamos a la función diHola(), ningún valor es devuelto.

    return 0;
}
```

Las funciones vacías no se pueden usar en expresiones que requieren algún valor, para entender la razón consideremos el siguiente ejemplo:
```
#include <iostream>

int main()
{
    std::cout << 5; // ok: 5 es una literal que enviamos a la consola
                    // para ser impresa
    std::cout << ;  // error de compilación: no dimos ningún valor.

    return 0;
}
```
El código anterior produce un error porque para el segundo `std::cout` no hubo ningún valor provisto.

Ahora consideremos el siguiente programa:
```
#include <iostream>

// 'void' significa que la función no va a devolver un valor al ser llamada
void diHola()
{
    std::cout << "¡Buenos días estrellitas, " 
                 "la Tierra les dice hola! \n";

    // Esta función no devuelve un valor, así que no es necesario
    // agregar una línea con la instrucción 'return'.
}

int main()
{
    diHola(); // llamamos a la función diHola(), ningún valor es devuelto.

    std::cout << diHola(); // aquí ocurre un error al compilar.
    return 0;
}
```
`std:cout` no sabe cómo recibir algo de tipo `void` (como es el caso de la función `diHola()`), por lo que el compilador marca que hay un error en esta línea.

Puede parecer tentador querer 'arreglar' el error obtenido arriba cambiando la definición de la función `diHola()` para pedirle que ahora nos de un valor. Sin embargo, esto resulta aún peor porque pedirle a una función vacía que nos regrese un valor **siempre** produce un error al compilar.

O sea, hacer esto:
```
void diHola()
{
    std::cout << "¡Buenos días estrellitas, " 
                 "la Tierra les dice hola! \n";

    return 5; // '5' puede ser cambiado por cualquier otro valor, es sólo 
              // con fin ilustrativo.
}
```
no va a resolver nuestros problemas, sólo agregará otro error a nuestro programa.

