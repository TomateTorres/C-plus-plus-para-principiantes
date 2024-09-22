Los ciclos `do-while` en C++ son una variante de los ciclos `while`, pero con una diferencia fundamental: en un ciclo `do-while`, **el bloque de código siempre se ejecuta al menos una vez** antes de que se evalúe la condición. Esto sucede porque la condición se verifica después de ejecutar el bloque de código, lo que asegura que la primera iteración siempre ocurra.

La sintaxis de este tipo de ciclos es:
```
do {
    // Bloque de código a ejecutar
} while (condición);
```

La estructura `do-while` sigue estos pasos:
1. Ejecuta el bloque de código dentro del `do`.
2. Evalúa la condición en el `while`. Si la condición es verdadera, el ciclo se repite. Si es falsa, el ciclo termina.

Veamos un ejemplo:
```
#include <iostream>

int main() {
    int i{ 0 };

    do {
        std::cout << "El valor de i es: " << i << '\n';
        ++i;
    } while (i < 5);

    return 0;
}
```
En terminal se imprime:
```
El valor de i es: 0
El valor de i es: 1
El valor de i es: 2
El valor de i es: 3
El valor de i es: 4
```

En este ejemplo, el bloque de código dentro del `do` se ejecuta y luego se evalúa la condición `(i < 5)`. Mientras la condición sea verdadera, el ciclo continuará.

Como usamos un ciclo `do-while` en vez de un `while`, aún si la condición no se cumple (por ejemplo, si `i == 10`), la declaración dentro del bloque se ejecuta al menos una vez:
```
El valor de i es: 10
```

## ¿Cuándo usar `do-while` y cuándo usar `while`?
Es conveniente usar `do-while` si necesitamos ejecutar el bloque de código al menos una vez, sin importar si la condición es verdadera o falsa desde el principio.

Algunas situaciones donde sería mejor usar un `do-while` en vez de un `while` son:
* **Menús interactivos:** Al mostrar un menú al usuario, se puede usar `do-while` para asegurarnos de que el menú se muestra al menos una vez, y luego repetirlo mientras el usuario quiera continuar.
```
#include <iostream>

int main() {
    char opcion{};
    do {
        std::cout << "Menú: \n";
        std::cout << "a) Opción 1\n";
        std::cout << "b) Opción 2\n";
        std::cout << "x) Salir\n";
        std::cout << "Elige una opción: ";
        std::cin >> opcion;
    } while (opcion != 'x'); // El programa se ejecutará hasta
                             // que el usuario quiera salir.

    std::cout << "Gracias por usar el programa!\n";
    return 0;
}
```
* **Validar la entrada de un usuario:** Asegurándonos de que el usuario ingrese un valor válido, y repetir la solicitud hasta que se cumplan ciertas condiciones. Por ejemplo, supongamos que necesitamos pedirle al usuario que ingrese un número entre 1 y 10:
```
#include <iostream>

int main() {
    int numero{};

    // Ejecutamos el bloque al menos una vez
    do {
        std::cout << "Introduce un número entre 1 y 10: ";
        std::cin >> numero;
    } while (numero < 1 || numero > 10); // Repetir si el número 
                                         // no está en el rango.

    std::cout << "¡Gracias! Has introducido el número " 
              << numero << ".\n";

    return 0;
}
```

En la práctica, no es común ver ciclos `do-while`. Tener a la condición al final del ciclo, oscurece la condición de éste, cosa que puede provocar errores. Lo más recomendable es que (a menos que tengamos una razón específica para preferir un `do-while`) le demos preferencia a los ciclos de tipo `while`.
