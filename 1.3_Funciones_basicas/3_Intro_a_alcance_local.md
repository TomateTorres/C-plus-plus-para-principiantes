Una **variable local** es una variable definida dentro del cuerpo de una función.

Recordemos que un parámetro de una función es una variable definida dentro de los paréntesis que van después del nombre de la función, a estos generalmente también se les considera como variables locales.

Como ya hemos visto (ver el ejemplo: *funcion_producto.cpp*) es posible definir diferentes variables con un mismo nombre, el truco para que esto sea legal, es tener cuidado (en unos momentos veremos a qué nos referimos)

El **alcance local** de un **identificador** (un identificador es el nombre de una variable, por ejemplo `x`) determina donde este puede ser visto y usado dentro del código fuente. Cuando éste puede ser visto y usado, decimos que *está en alcance*, en caso contrario decimos que está *fuera de alcance*. Tratar de usar un identificador fuera de alcance nos producirá un error al compilar.

El alcance de una variable local empieza en el momento en el que la definimos dentro de la función (en el cuerpo o dentro del paréntesis después del nombre de ésta) y termina en el corchete final (`}`) de dicha función.

Los conceptos de alcance local y **tiempo de vida de una variable local** están íntimamente relacionados. El último se refiere al tiempo entre la creación y destrucción de una variable local. 

Cuando un objeto es destruido lo único que sucede es que éste se vuelve inválido y si intentamos seguirlo usando el resultado será comportamiento no definido. Una vez que un objeto ha sido destruido, la memoria usada por éste se libera para poder ser usada en otras cosas.

Veamos un ejemplo de un programa que muestra el alcance de una variable `x`:
```
#include <iostream>

int doble(int x) // `x` es creada e inicializada aquí, para
                 // efectos del ejemplo, le vamos a decir 'x de
                 // doble()'
{
    return 2 * x; // se hace algo con 'x de doble' dentro del 
                  // cuerpo de la función (este paso es opcional).
} // 'x de doble()' es destruida aquí

int main()
{
    std::cout << "Dame un entero: ";
    int x{}; // `x` es creada e inicializada aquí (aunque tiene
             // el mismo nombre, esta `x` es distinta a la de la
             // función `doble()`). Le vamos a decir 'x de main()'.
    std::cin >> x; // En 'x de main()' es en donde guardaremos en 
                 // input del usuario.

    std::cout << "El doble de " << x << " es: " << doble(x) << '\n'; 
    // Metemos a 'x de main()' como parámetro en la
    // función `doble()`, el valor de 'x de main()' es
    // copiado a 'x de double()'. Una vez que el código
    // de la función termina de correr, 'x de doble()'
    // es destruida y sólo nos queda el output en pantalla.
    
    return 0;
    
}
```

Más arriba mencionamos que en un mismo código podemos definir variables con el mismo código 'siempre que lo hagamos con cuidado'. EL anterior, es un ejemplo de como esto **sí** se puede hacer, veamos un ejemplo de como **no** se puede usar el mismo nombre para definir variables distintas en un mismo código:

Supongamos que queremos calcular el volumen de un cubo de lado 2, podríamos hacerlo así:
```
#include <iostream>

double volumen_cubo(double longitud_lado)
{
    double volumen = longitud_lado * longitud_lado * longitud_lado;
    return volumen;
}

int main()
{
    double volumen = volumen_cubo(2);
    std::cout << "El volumen del cubo es: " << volumen << '\n';

    return 0;
}
```
La variable `volumen` es definida dos veces, pero no hay problema porque cada definición está dentro de una función diferente (la primera dentro de `volumen_cubo()` y la segunda dentro de `main()`), de esta manera el alcance de la cada una de las variables locales `volumen` no se traslapa. 

Ahora, supongamos que tenemos otro cubo, ahora de lado 4 y queremos saber también su volumen. Podríamos estar tentados a hacer esto:
```
#include <iostream>

double volumen_cubo(double longitud_lado)
{
    double volumen = longitud_lado * longitud_lado * longitud_lado;
    return volumen;
}

int main()
{
    double volumen = volumen_cubo(2);
    std::cout << "El volumen del cubo es: " << volumen << '\n';

    double volumen = volumen_cubo(4);
    std::cout << "El volumen del cubo es: " << volumen << '\n';

    return 0;
}
```

**Intenta insertar el gif de Michael Scott aquí**
![the-office-no](https://github.com/user-attachments/assets/cba3e606-0fb5-4638-a473-6e7245b79fcd)


Aunque el anterior código sí compila, no nos da el segundo volumen que buscamos porque intentamos volver a usar un mismo identificador (el nombre `volumen`) dentro de una misma función (en este caso la función `main()`)

Lo importante de lo anterior es:
* Es posible (y a veces necesario) usar el mismo identificador para variables que pretendemos que guarden valores diferentes.
* Lo anterior lo podemos hacer sin ningún problema siempre y cuando lo hagamos en bloques de código ajenos (en el contexto de los ejemplos anteriores: dentro de funciones distintas). Un bloque de código es aquel que inicia con un `{` y termina con un `}`.

## Parámetros de funciones vs. Variables locales

Aunque a los parámetros de funciones también se les considera *variables locales*, en la práctica cuando nos referimos a una variable local, nos estamos refiriendo específicamente a algo dentro del cuerpo de una función:
```
int suma(int x, int y) // `x` y `y` son parámetros
{
    int z{ x + y }; `z` es una variable local
    return z;
}
```
Ambos (variables locales y parámetros) pueden usarse dentro del cuerpo de las funciones, puede llegar a ser confuso cuando debe usarse una variable local o un parámetro. Un parámetro debe usarse cuando existe un llamador (que puede ser otra función o directamente `main()`) que pasará algún valor (o valores) con el que queremos que la función haga algo. Cuando lo anterior no pase, es cuando debemos usar una variable local.

Si usamos un parámetro donde debimos haber usado una variable local, tendremos resultados como este:
```
// Este programa le pide un número al usuario y no hace
// absolutamente nada con él.

#include <iostream>

int traeValor(int val) // val es un parámetro de función
{
    std::cin >> val;
    return val;
}

int main()
{
    int num{};
    std::cout << "Dame un número entero: " << traeValor(num) << '\n';

    return 0;
}
```

En el ejemplo anterior, le pusimos un parámetro a la función `traeValor()` a pesar de que su llamador (en este caso, la función `main()`) no necesita pasarle ningún valor. Por esto es que fue necesario definir en `main()` una nueva variable llamada `num` para tener algo que pasar como argumento. El valor de `num` nunca es usado (como la inicializamos con un paréntesis vacío, su valor asignado por default fue 0) y de hecho el valor con el que `val` es inicializado tampoco (igualmente, se le asigna 0 por default) porque inmediatamente guardamos ahí el input del usuario.

Hacer este tipo de cosas (agregar parámetros cuando no vamos a pasarle información a la función) sólo le agrega complejidad innecesaria a nuestros programas.

Una mejor forma de escribir el programa anterior es:
```
// Este programa le pide un número al usuario y no hace
// absolutamente nada con él.

#include <iostream>

int traeValor()
{
    int val{}; //val es una variable local
    std::cin >> val;
    return val;
}

int main()
{
    std::cout << "Dame un número entero: " << traeValor() << '\n';

    return 0;
}
```

## Notas:
* El **tiempo de vida** de una variable local es una 'propiedad de tiempo de ejecución' (en inglés: 'runtime property') porque la creación y destrucción de variables se da cuando el programa está corriendo.
* Los objetos no pueden ser creados e inicializados después de su punto de definición y no pueden ser destruidos antes de cerrar el set de corchetes (`{}`) dentro del que están definidos. C++ le da flexibilidad a los compiladores para que estos determinen cuando debe crearse y destruirse una variable local en pos de optimizar el código, el único requisito es que respeten la especificación anterior.
* Siempre que tengamos que definir una variable local, lo más recomendable es hacerlo lo más cerca posible de donde ésta se va a usar por primera vez.
