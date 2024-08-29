Una función es una colección **reusable** de instrucciones ejecutadas de manera secuencial designada para realizar alguna tarea específica.

La sintaxis más básica de una función definida por el usuario es la siguiente:
```
Tipo_de_output Nombre_de_la_función() // Este es el encabezado de la función (le avisa al compilador que la función existe)
{
    // Este es el cuerpo de la función (le dice al compilador lo que la función hace)
}
```
El nombre de una función es conocido como su _identificador_.

En el encabezado de la función tenemos: `Tipo_de_output Nombre_de_la_función()`. A las funciones podemos ponerles el nombre que más nos guste (respetando las reglas para nombrar variables, ver: [Reglas importantes.](../1.1_Variables_y_tipos_de_datos/0_Introducción.md)
), pero idealmente se espera que éste nos de información sobre lo que la función hace. Cuando definimos una función tenemos que saber qué tipo de output nos devolverá; por ejemplo, una función que suma enteros nos debe devolver un entero, entonces un posible encabezado sería `int suma()`, el nombre es libre, pero el `Tipo_de_output` no puede ser distinto de `int`. 



## 'Llamar' funciones
Un ejemplo de un programa que muestra como 'llamar' a una función en C++:
```
#include <iostream> // para std::cout

// Vamos a definir una función llamada imprime()
void imprime() // imprime() es la función que llamaremos en este ejemplo.
               // Por el momento, no hay que preocuparnos sobre qué es 
               // el tipo 'void'.
{
    std::cout << "Estamos en imprime()\n";
    //La función imprime la línea anterior.
}

// Iniciamos el programa que se va a ejecutar con main()
int main()
{
    std::cout << "Empezamos main()\n";
    imprime(); // Se interrumpe main() llamando a imprime().  main() es la función que la llama.
    std::cout << "Termina main()\n"; // esta instrucción se ejecuta cuando imprime() termina.

    return 0;
}
```
El programa (como cualquiera en C++) inicia su ejecución en la función `main()`.
Cuando 'llamamos' a la función `ìmprime` debemos poner un par de paréntesis al final de su nombre, si no lo hacemos el programa no compilará y si lo hace, no llamará a la función.

Como llamamos a una función, la ejecución de `main()` fue momentáneamente suspendida y la ejecución del programa salta hasta la línea que dice _imprime_ (más arriba en el código) y ejecuta la tarea dentro del cuerpo de la función, una vez que termina (en este caso, sólo imprime la línea: _Estamos en imprime()_), volvemos a `main()` y seguimos con las líneas que falten (en este caso, sólo se imprime la última línea: _Termina main()_).

Como `main()` ha llamado a la función `imprime()` decimos que `main()` es el _llamador_ de `imprime()`.

Las funciones también pueden ser llamadas más de una vez y podemos definir funciones que llamen a otras funciones. 

A diferencia de otros lenguajes de programación (Python por ejemplo), C++ no permite definir funciones anidadas (no se puede definir una función dentro de otra función).
Por ejemplo, esto no es legal:
```
#include <iostream>

int main()
{
    void foo() // Esto está mal: esta función está dentro de la función main()
    {
        std::cout << "foo!\n";
    }

    foo(); // llamamos a la función foo()
    return 0;
}
```
La forma correcta de escribir el código anterior es:
```
#include <iostream>

void foo() // ya no está anidada dentro de main()
{
    std::cout << "foo!\n";
}

int main()
{
    foo();
    return 0;
}
```

## Funciones que regresan valores
Consideremos un programa que le pida al usuario dos números enteros y le de como resultado la suma entre ellos:
```
#include <iostream>

int main()
{
    int x{}, y{}; //Los números no necesariamente son enteros.
   
    std::cout << "Dame tu primer número: ";
    std::cin >> x;

    std::cout << "Dame tu segundo número: ";
    std::cin >> y;

    int suma{x+y}; 

    std::cout << x << " + " << y << " es: " << suma << ".\n";

    return 0;
}
```
Aunque este programa es sencillo y no necesitamos dividirlo en múltiples funciones, veamos un ejemplo de cómo podríamos implementar una función creada por el usuario para obtener el mismo output:
```
#include <iostream> 

int suma()
{
    std::cout << "Dame tu primer número: ";
    int x{};
    std::cin >> x;

    std::cout << "Dame tu segundo número: ";
    int y{};
    std::cin >> y;

    return x + y;
}

//Aquí empieza el programa ejecutable:
int main()
{
    int num {suma()}; //inicializamos el valor 'num' con el 
                      //valor regresado por suma()
    std::cout << "La suma de los números es: " << num << ".\n";

    return 0;
}
```
Cuando este programa es ejecutado, `main` crea una variable entera llamada `num`. Cuando el programa inicializa `num`, ve que hemos llamado a la función `suma()`, así que va y ejecuta la función para obtener su valor de salida y guardarlo en la variable `num`. La función `suma()` hace lo mismo que el primer programa hacía (le pide al usuario dos números para sumarlos) y, si quisiéramos, podríamos usarla más de una vez dentro de `main()`.

Decimos que una _función regresa un valor_ (en inglés: _value returning function_) si al terminar su ejecución devuelve algún valor de tipo distinto a `void`. Una vez que hemos definido el tipo de una función (`int`, `double`,...), el valor devuelto (llamado: 'valor de retorno') debe ser del mismo tipo que la función, de otro modo nuestro programa tendrá comportamientos inesperados (suponiendo que sí compile). 

Una _función que devuelve valores_ sólo puede dar un sólo valor cada vez que es llamada. Por ejemplo:
```
int suma()
{
    return 3 + 4;
}
```
La función suma sólo devuelve un valor a través de `return` (la suma de 3 y 4). 

El hecho de que, en principio, una función sólo pueda devolvernos un valor, es una limitación porque a veces puede sernos útil que una función devuelva múltiples resultados a la vez (por ejemplo, si queremos codificar una función de $f:\mathbb{R}^2 \to \mathbb{R}^2$ no podemos hacerlo con un solo `return`). Hay maneras de trabajar aún con esta limitación, las veremos más adelante.

El significado del valor devuelto por una función es determinado por el autor de ésta. Algunas funciones devuelven valores de _estados de código_ para inidicar si fueron exitosas o fallaron, algunas devuelven un valor calculado o seleccionado, algunas no devuelven nada...

Considerando lo anterior, es buena práctica comentar en el código de la función para que quien sea que lo lea (que bien podemos ser nosotros mismos en el futuro), sepa qué propósito tiene el valor devuelto por la función. Por ejemplo:
```
// La función le pide al usuario que ingrese un valor.
// El valor devuelto por la función es el entero ingresado por
// el usuario mediante el teclado. 
int obtenValorDeUsuario()
{
 	std::cout << "Dame un entero: ";
	int input{};
	std::cin >> input;

	return input; // Devuelve el valor ingresado por el usuario.
}
```

Más atrás habíamos mencionado que es posible llamar a una función más de una vez al ejecutar un código. Veamos un ejemplo:
```
#include <iostream>

int obtenValorDeUsuario()
{
    std::cout << "Dame un entero: ";
    int input{}; // Aquí se guardará el número que nos de el usuario.
    std::cin >> input;

    return input; // Nos devuelve el valor dado por el usuario.
}

int main() // Inicia nuestro programa ejecutable.
{
    int x{obtenValorDeUsuario()}; // Llamamos a la función por primera
                                  // vez para obtener el primer número.
   
    int y{obtenValorDeUsuario()}; // Llamamos a la función por segunda 
                                  // vez para obtener el segundo número.
    
    std::cout << x << " + " << y << " = " << x + y << '\n';

    return 0; // El programa ha terminado.
}
```
Este programa le pide al usuario dos números enteros para darle el resultado de su suma. En él, llamamos a la función `obtenValorDeUsuario()` dos veces, una para inicializar la variable `x` y otra para inicializar la variable `y`. Esto nos ahorra copiar el código de input de usuario (reduciendo las probabilidades de que nos equivoquemos y el programa haga cosas extrañas) y evita que el programa se vuelva tedioso y complicado si en algún momento queremos sumar más números. 
