Una función es una colección **reusable** de instrucciones ejecutadas de manera secuencial designada para realizar alguna tarea específica.

La sintaxis más básica de una función definida por el usuario es la siguiente:
```
Tipo_de_output Nombre_de_la_función() // Este es el encabezado de la función (le avisa al compilador que la función existe)
{
    // Este es el cuerpo de la función (le dice al compilador lo que la función hace)
}
```
El nombre de una función es conocido como su _identificador_.



# 'Llamar' funciones
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
El programa (como cualquiera en C++) inicia su ejecución en la función _main_.
Cuando 'llamamos' a la función _imprime_ debemos poner un par de paréntesis al final de su nombre, si no lo hacemos el programa no compilará y si lo hace, no llamará a la función.

Como llamamos a una función, la ejecución de _main_ fue momentáneamente suspendida y la ejecución del programa salta hasta la línea que dice _imprime_ (más arriba en el código) y ejecuta la tarea dentro del cuerpo de la función, una vez que termina (en este caso, sólo imprime la línea: _Estamos en imprime()_), volvemos a _main_ y seguimos con las líneas que falten (en este caso, sólo se imprime la última línea: _Termina main()_).

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

## Llamar funciones más de una vez
