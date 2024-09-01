Como ya hemos visto, es posible encadenar múltiples declaraciones `ìf`-`else`:
```
/*
Supongamos que estamos aprendiendo Alto Valyrio (porque
aparentemente tenemos demasiado tiempo libre) y hacemos un 
programa que nos ayude a memorizar los primeros 10 números.
*/

#include <iostream>

void imprimeNombreDeNum(int x)
{
    if (x == 1){                    // También podemos poner los `{}` de
        std::cout << "mēre";}       // esta forma para ahorrar espacio.
    else if (x == 2){
        std::cout << "lanta";}
    else if (x == 3){
        std::cout << "hāre";}
    else if (x == 4){
        std::cout << "izula";}
    else if (x == 5){
        std::cout << "tōma";}
    else if (x == 6){
        std::cout << "bȳre";}
    else if (x == 7){
        std::cout << "sīkuda";}
    else if (x == 8){
        std::cout << "jēnqa";}
    else if (x == 9){
        std::cout << "vōre";}
    else if (x == 10){
        std::cout << "ampa";}
    else{
        std::cout << "No sé, es demasiado conocimiento para mí.";}
}

int main()
{
    std::cout << "Dame un número del 1 al 10: ";
    int x{};
    std::cin >> x;
    std::cout << "Tu número en Alto Valyrio es: ";
    imprimeNombreDeNum(x);

    return 0;
}
```
La variable `x` en `imprimeNombreDeNum()` será evaluada en cada una de las condiciones hasta encontrar una que sea verdadera (en caso de que ninguna lo sea, se ejecuta la declaración `else`). En nuestro ejemplo donde sólo hay 10 números, la variable `x` a lo más será evaluada 10 veces, pero si quisiéramos aprender los números en Alto Valyrio del 1 al 1000, la variable `x` podría ser evaluada hasta 1000 veces... Lo cual es muy ineficiente.

Debido a que es común probar la igualdad de una variable o expresión a algún conjunto de valores, C++ proporciona una declaración condicional como alternativa a `if`-`else` llamada **declaración `switch`**. 

El código anterior se vería así si utilizamos una declaración `switch` en vez de la serie de `if`-`else`:
```
#include <iostream>

void imprimeNombreDeNum(int x) {
    switch (x) {
        case 1:
            std::cout << "mēre";
            return;
        case 2:
            std::cout << "lanta";
            return;
        case 3:
            std::cout << "hāre";
            return;
        case 4:
            std::cout << "izula";
            return;
        case 5:
            std::cout << "tōma";
            return;
        case 6:
            std::cout << "bȳre";
            return;
        case 7:
            std::cout << "sīkuda";
            return;
        case 8:
            std::cout << "jēnqa";
            return;
        case 9:
            std::cout << "vōre";
            return;
        case 10:
            std::cout << "ampa";
            return;
        default:
            std::cout << "No sé, es demasiado conocimiento para mí.";
            return;
    }
}

int main() {
    std::cout << "Dame un número del 1 al 10: ";
    int x{};
    std::cin >> x;
    std::cout << "Tu número en Alto Valyrio es: ";
    imprimeNombreDeNum(x);

    return 0;
}
```

En las declaraciones `switch`, la `condición` (en este caso `x`) es evaluada para producir algún valor (en este caso, el número que dio el usuario), si el valor de la expresión es igual al valor después de alguna de las etiquetas (*labels*) `case`, las declaraciones correspondientes a dicha etiqueta son ejecutadas. En caso de que la evaluación de la condición no sea igual a algún valor correspondiente a cualquiera de las etiquetas `case`, se ejecutan las declaraciones correspondientes después de la etiqueta `default` (que hace las veces de `else`).

La declaración `switch`, a diferencia de `if`-`else`, evalúa la expresión una sola vez (lo que la hace más eficiente) y hace más claro para los humanos que leen el código que es la misma expresión la que se prueba para determinar su igualdad en cada caso.

En este caso, `switch` es una opción ideal porque estábamos evaluando la misma variable `x` contra valores constantes.

Las declaraciones `switch` son un poco más complejas que las declaraciones `if`-`else`, vamos a explorarlas por partes para tratar de entenderlas un poco mejor.

### Empezar una declaración `switch`

Empezamos una declaración `switch` usando la palabra clave `switch`, seguida de paréntesis y la expresión condicional que vamos a evaluar dentro de ellos (en el caso del ejemplo anterior, ésta fue `x`). Usualmente, la expresión dentro del paréntesis es una sola variable, pero puede ser cualquier expresión válida.

### Expresiones válidas en una declaración `switch`

En C++, `switch` sólo acepta tipos de datos que pueden evaluarse como enteros o enumeraciones. No podemos usar tipos como `float`, `double` o `string`.

```
// Esto NO es válido en C++:
switch (2.5) {
    case 2.5:
        break;
}
```

Si queremos usar tipos de datos `float`, `double` o `string`, tendremos que usar una declaración `if`-`else`.

Las **enumeraciones** (`enum`) son un tipo de dato definido por el usuario que consiste en un conjunto de constantes con nombre. Se utilizan para representar un grupo de valores enteros que tienen algún significado para nosotros los humanos. Por ejemplo:
```
enum Dia { Lunes, Martes, Miércoles, Jueves, Viernes, Sábado, Domingo };
```

En este ejemplo, hemos definido un `enum` llamado `Dia` que contiene constantes con nombre (`Lunes`, `Martes`, `Miércoles`, ...) que (para nosotros los humanos) representan los días de la semana. Internamente (para la máquina), cada constante de `enum` está asociada con un valor entero, empezando por el `0`. De esta forma:
* `Lunes` es `0` 
* `Martes` es `1`
...
* `Domingo` es `6`

En vista de que más arriba ya vimos un ejemplo de una declaración `switch` que utiliza un tipo de dato entero, veamos uno con enumeraciones:
```
#include <iostream>

enum Dia { Lunes, Martes, Miércoles, Jueves, Viernes, Sábado, Domingo };

void imprimirDia(Dia dia) {
    switch (dia) {
        case Lunes:
            std::cout << "Hoy es Lunes.\n";
            break;
        case Martes:
            std::cout << "Hoy es Martes.\n";
            break;
        case Miércoles:
            std::cout << "Hoy es Miércoles.\n";
            break;
        case Jueves:
            std::cout << "Hoy es Jueves.\n";
            break;
        case Viernes:
            std::cout << "Hoy es Viernes.\n";
            break;
        case Sábado:
            std::cout << "Hoy es Sábado.\n";
            break;
        case Domingo:
            std::cout << "Hoy es Domingo.\n";
            break;
        default:
            std::cout << "Día no válido.\n";
            break;
    }
}

int main() {
    Dia diaActual = Miércoles;  // Asigna el valor de "Miércoles" al `enum`
    /* 
    `Dia` es el nombre del `enum` (podemos estar trabajando con más de uno)
    y `diaActual = Miércoles` es el valor particular que le vamos a asignar
    */
    imprimirDia(diaActual);     // Llama a la función con el `enum` asignado
    return 0;
}
```

Después de `switch(expresión_válida_a_evaluar)`, declaramos un bloque `{}` y usamos etiquetas para definir todos los valores con los que queremos evaluar nuestra expresión. De estos hay dos tipos: `case` y `default`.

### Etiqueta `case`

La etiqueta `case` es declarada usando la palabra clave `case` seguida de una expresión constante. El tipo de expresión constante debe ser del mismo tipo que la condición (ya sea de tipo `int` o `enum`).

Si el valor de la expresión condicional es igual al de la expresión después de la etiqueta `case`, se ejecutan las instrucciones correspondientes a dicha etiqueta de manera secuencial (o sea, en el orden en que las pusimos).

Veamos un ejemplo:
```
#include <iostream>

void imprimeNombreDigito(int x)
{
    switch (x) // x es evaluada para producir el valor 2
    {
    case 1:
        std::cout << "Uno";
        return;
    case 2: // Como `x=2` se ejecutan las instrucciones que
            // que corrresponden a esta etiqueta.
        std::cout << "Dos"; // La ejecución empieza aquí
        return; // Regresamos al llamador (en este caso, `main`)
    case 3:
        std::cout << "Tres";
        return;
    default:
        std::cout << "No sé :(";
        return;
    }
}

int main()
{
    imprimeNombreDigito(2); // Se imprime en terminal "Dos"
    
    return 0;
}
```
`x` es evaluada para producir el valor `2`. Como hay una etiqueta `case` con el valor `2`, la ejecución salta a la instrucción posterior inmediata a `case 2:`. El programa imprime `Dos` y luego se ejecuta la instrucción `return` que nos manda de vuelta al llamador de la función, que en este caso es `main`.

No hay un límite en cuanto al número de etiquetas `case` que podemos usar, el único requisito es que cada etiqueta debe ser única. O sea:
```
switch (x)
{
case 54:
case 54:  // ¡error! ya usamos el valor 54
}
```
**no** se vale.

### Etiqueta `default`

Esta etiqueta es declarada al usar la palabra clave `default` y hace las veces de `else` en las declaraciones `switch`. Lo anterior ya que, si la expresión condicional no coincide con ninguna etiqueta `case` y existe una etiqueta `default`, la ejecución empieza en la instrucción inmediata posterior a la etiqueta `default`.

Veamos un ejemplo:
```
#include <iostream>

void imprimeNombreDigito(int x)
{
    switch (x) // `x` es evaluado para producir el valor 5
    {
    case 1:
        std::cout << "Uno";
        return;
    case 2:
        std::cout << "Dos";
        return;
    case 3:
        std::cout << "Tres";
        return;
    default: // `x=5` no coincide con ninguno de los valores de
             // las etiquetas `case`
        std::cout << "No sé :("; // Entonces, la ejecución empieza aquí
        return; // Y luego volvemos al llamador (en este caso, `main`)
    }
}

int main()
{
    imprimeNombreDigito(5);
    
    return 0;
}
```
El código anterior imprime `No sé :(`.

La etiqueta `default` es opcional y sólo puede haber una por cada declaración `switch` (podemos tener tantos `case` como querramos pero sólo un `default`). Por convención, la etiqueta `default` va al final de la declaración `switch`.

En caso de que hayamos decidido no poner una etiqueta `default` y tengamos una expresión que no coincida con ninguna de las etiquetas `case`, entonces no se ejecuta ninguna de las instrucciones dentro de `switch` y la ejecución continúa después del paréntesis de cierre (`}`) del bloque `switch`.
```
#include <iostream>

void imprimeNombreDigito(int x)
{
    switch (x) // `x` es evaluado para producir el valor 5
    {
    case 1:
        std::cout << "Uno";
        return;
    case 2:
        std::cout << "Dos";
        return;
    case 3:
        std::cout << "Tres";
        return;
    // `x` no es igual a 1, 2 ó 3 y no tenemos un caso `default`
    } 

    // Entonces la ejecución continúa aquí
    std::cout << "Hola ( ͡° ͜ʖ ͡°)\n";
}

int main()
{
    imprimeNombreDigito(5);

    return 0;
}
```

### `return` vs. `break`

En los ejemplos anteriores, hemos estado usando declaraciones `return` para detener la ejecución de instrucciones depués de nuestras etiquetas. Sin embargo, [como ya vimos en la sección sobre funciones](../1.3_Funciones_basicas/0_Introducción.md), al usar `return` salimos de la función y volvemos al llamador de ésta.

Una **declaración `break`**, le dice al compilador que hemos terminado de ejecutar las instrucciones dentro de la declaración `switch` y que la ejecución debe continuar con la instrucción inmediata posterior al corchete de cierre (`}`) del bloque `switch`. Esto nos permite salir de dicho bloque sin salir de la función completa.

Veamos un ejemplo para entender la diferencia entre usar `return` y `break`
```
#include <iostream>

void imprimeNombreDigito(int x)
{
    switch (x) // `x` es evaluado para producir el valor 3
    {
    case 1:
        std::cout << "Uno";
        return;
    case 2:
        std::cout << "Dos";
        return;
    case 3:
        std::cout << "Tres"; // la ejecución inicia aquí porque
                             // x = 3
        return; // Salimos de la función y volvemos a `main`
    } 

    // Esta línea no se ejecuta
    std::cout << "Hola ( ͡° ͜ʖ ͡°)\n";
}

int main()
{
    imprimeNombreDigito(3);

    return 0;
}
```
El código anterior imprime: `Tres`

Por otro lado:
```
#include <iostream>

void imprimeNombreDigito(int x)
{
    switch (x) // `x` es evaluado para producir el valor 3
    {
    case 1:
        std::cout << "Uno";
        break;
    case 2:
        std::cout << "Dos";
        break;
    case 3:
        std::cout << "Tres"; // la ejecución inicia aquí porque
                             // x = 3
        break; // Salimos del bloque `switch` y continuamos con
               // la ejecución de las instrucciones siguientes 
               // dentro de la función
    } 

    // Esta línea ahora sí se ejecuta
    std::cout << "\tHola ( ͡° ͜ʖ ͡°)\n"; // `\t` es para que haya 
                                      // un espacio (obtenido de
                                      // presionar una vez la tecla
                                      // Tab) entre "Tres" y
                                      // "Hola ( ͡° ͜ʖ ͡°)"
}

int main()
{
    imprimeNombreDigito(3);

    return 0;
}
```
Imprime: `Tres    Hola ( ͡° ͜ʖ ͡°)`

Lo mejor es utilizar `break` en vez de `return` a menos que deliberadamente querramos salir de la función y volver a su llamador.

**Nota:** Todo lo que puede hacer una declaración `switch` puede ser replicado por una declaración `if`-`else`. `if`-`else` es mucho más flexible, así que (aunque `switch` puede llegar a ser más eficiente en ciertos casos) para evitar confusiones me parece que lo más recomendable es usar `if`-`else` en principio y posteriormente modificar el código a una declaración `switch` si es necesario o conveniente por alguna razón.
