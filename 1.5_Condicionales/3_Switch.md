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
            break;
        case 6:
            std::cout << "bȳre";
            break;
        case 7:
            std::cout << "sīkuda";
            break;
        case 8:
            std::cout << "jēnqa";
            break;
        case 9:
            std::cout << "vōre";
            break;
        case 10:
            std::cout << "ampa";
            break;
        default:
            std::cout << "No sé, es demasiado conocimiento para mí.";
            break;
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
1. `Lunes` es `0` 
2. `Martes` es `1`
...
7. `Domingo` es `6`

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

Si el valor de la expresión
