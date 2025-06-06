El **operador condicional** `?:` (también llamado 'operador ternario' por ser el único operador en C++ que tiene 3 operandos) es un operador que proporciona un método compacto para realizar un tipo particular de declaración `if`-`else`.

Recordemos que una declaración `if`-`else` tiene la siguiente forma:
```c++
if (condición)
{    
    declaración1
}

else
{
    declaración2
}
```
Si la `condición` se verifica, entonces la `declaración1` es ejecutada, en caso contrario `declaración2` es ejecutada. El `else` y `declaración2` son opcionales.

El operador `?:` toma la siguiente forma:
```c++
condición ? expresión1 : expresión2;
```
Si la `condición` se verifica, entonces la `expresión1` es evaluada, en otro caso la `expresión2` es evaluada. El `:` (que hace el papel del `else`) y `expresión2` (que hace el papel de la `declaración2`) **no** son opcionales.

El operador condicional tiene algunas diferencias importantes con las declaraciones `if`-`else`:

### 1. El operador condicional es más conciso

Esto:
```c++
int max{}; // definimos a la variable entera `max`

if (a > b) 
{
    max = a; 
} 
else 
{
    max = b;
}
/*'a' y 'b' son enteros, si 'a' es mayor que 'b', entonces
guardamos el valor de 'a' en la variable `max` y guardamos el
valor de 'b' en `max` en otro caso */ 
```
y esto:
```c++
int max {}; // definimos a la variable entera `max`
max = ( (a > b) ? a : b );
```
son equivalentes.

O sea, el operador condicional es más conciso que una declaración `if`-`else` porque nos permite hacer lo mismo en menos líneas de código.

### 2. El operador condicional es evaluado como una expresión

En C++ (entre muchas otras cosas) tenemos **expresiones** y **declaraciones**.

Una **expresión** es cualquier combinación de variables, operadores y valores que se evalúa para producir un valor. Las expresiones pueden ser tan simples como un número o una variable, o tan complejas como una combinación de operadores y funciones.
Los siguientes:
```c++
5              // Un valor literal, una expresión simple.
a              // Una variable, que es una expresión.
a + b          // Suma de dos variables, una expresión aritmética.
x = y + 2      // Una expresión de asignación que guarda el resultado de `y + 2` en `x`.

```
son todos ejemplos de expresiones.

Una **declaración**  es una instrucción completa que realiza alguna acción. Las declaraciones pueden definir variables, ejecutar expresiones, entre otras cosas. Una declaración generalmente termina con un punto y coma (;).
Los siguientes:
```c++
int a{5};                   // Declaración de una variable con inicialización.
x = y + 2;                  // Declaración de asignación.
if (a > 3)                  // Declaración `if` (no termina con punto y coma)
{                
    std::cout << "Hola";    // Declaración de salida a la consola.
}
```
son todos ejemplos de declaraciones.

Una declaración puede contener una o más expresiones. Por ejemplo, `int a{5};` es una declaración que contiene la expresión `5`.

Una diferencia clave entre las expresiones y declaraciones es que las declaraciones **no** pueden ser usadas en lugares donde una expresión es requerida.

Por ejemplo, si queremos inicializar una variable (aquí necesitamos de una **expresión**):
```c++
#include <iostream>

int main()
{
    bool enSalonGrande { false };
    // La variable `enSalonGrande` nos indica si será necesario o
    // no asignar al grupo a un salón grande. La inicializamos 
    // como `false` (podemos pensar que tenemos información previa
    // que nos dice que el grupo no está en un salón grande)
    
    int tamañoGrupo { enSalonGrande ? 30 : 20 }; // La variable a inicializar
    // Como `enSalonGrande` tiene asignado el valor `false`, la 
    // variable `tamañoGrupo` es inicializada con el valor `20`
    // (pues, al no verificarse la condición, el operador `?:`
    // nos da el segundo valor como salida).
    
    // Como el grupo no estaba en un salón grande, entonces debió
    // haber sido un grupo de 20 estudiantes.

    std::cout << "El grupo tiene " << tamañoGrupo << " estudiantes." << '\n';

    return 0;
}
```

Como **no** podemos usar declaraciones para inicializar variables, no hay una manera directa de reemplazar el operador condicional por un `if`-`else` dentro de los corchetes `{}` donde inicializamos a la variable.
Una forma (parecida, pero no igual) de hacer lo anterior, pero usando `if`-`else` es:
```c++
#include <iostream>

int daTamañoClase(bool enSalonGrande)
{
    if (enSalonGrande)
    {
        return 30;
    }
    else
    {
        return 20;
    }
}
/* La función `daTamañoClase()` recibe como parámetro la variable
booleana `enSalonGrande`. Si `enSalonGrande` es `true` (es decir, si
el grupo está en un salón grande), entonces el valor devuelto por la
función es 30. Si `enSalonGrande` es `false` (es decir, si el grupo 
no está en un salón grande), entonces el valor devuelto por la función 
es 20.
*/


int main()
{
    int tamañoClase { daTamañoClase(false) };
    /* Inicializamos a la variable entera `tamañoClase` con el valor
    dado por el output de la función `daTamañoClase()` al ser esta 
    evaluada con el parámetro `false` (o sea: `daTamañoClase(false)`).
    Como la evaluación de una función es una expresión, se vale inicializar
    variables de esta forma.
    */

    std::cout << "El grupo tiene " << tamañoClase << " estudiantes." << '\n';

    return 0;
}
```

Ambos códigos hacen en esencia lo mismo, pero el segundo tiene más líneas de código (recordemos que los comentarios no son líneas de código) y complejidad que podemos evitar si usamos el primero.

## Uso de paréntesis en el operador condicional

Como C++ prioriza la evaluación de la mayoría de los operadores por encima de la evaluación del operador condicional, es fácil escribir código usando el operador condicional que termina siendo evaluado de forma distinta a la que queremos. Por ejemplo:
```c++
#include <iostream>

int main()
{
    int x { 2 };
    int y { 1 };
    int z { 10 - x > y ? x : y };
    std::cout << z;

    return 0;
}
```
Uno podría esperar que `z` sea inicializado con `10 - (x > y ? x : y)` (lo que haría que `z = 8`), pero en realidad se inicializa con `(10 - x) > y ? x : y` (lo que hace que `z = 2`).

Por esta razón, es necesario hacer uso de paréntesis cuando hagamos uso del operador condicional para ser claros en la forma en que deseamos que nuestras expresiones sean evaluadas:
```c++
#include <iostream>

int main()
{
    int x { 2 };
    int y { 1 };
    int z { 10 - (x > y ? x : y)};
    /* Ahora sí, el programa primero evaluará `x > y ? x : y`
    (que da como resultado 2) y le restará a 10 el resultado
    */

    std::cout << z;

    return 0;
}
```

Además, es buena práctica poner el operador condicional completo entre paréntesis `()` cuando lo usemos en una expresión compuesta:
```c++
int z {(x > y) ? x : y} // Pusimos a la condición `x > y` entre 
                        // paréntesis, pero no es necesario poner
                        // al operador condicional completo entre
                        // paréntesis porque no lo estamos usando
                        // en una expresión compuesta.

std::cout << (esTarde() ? "PM" : "AM"); // Aquí sí pusimos al operador
                                        // condicional completo entre
                                        // paréntesis porque al usarlo
                                        // junto con `std::cout` ya 
                                        // tenemos una expresión compuesta
```
En el segundo ejemplo, si no usamos paréntesis, la expresión se evaluaría como: `(std::cout << esTarde()) ? "PM" : "AM";`... que evidentemente no es lo que queríamos.

## El tipo de las expresiones debe coincidir (o ser convertible)

Cuando hagamos uso del operador condicional:
```c++
condición ? expresión1 : expresión2;
```
una de las siguientes se debe cumplir:
1. El tipo del segundo (`expresión1`) y tercer (`expresión2`) operando deben coincidir.
2. En caso de que **1.** no se cumpla, el compilador debe poder encontrar una forma de convertir el segundo o tercer operando (o ambos) a tipos coincidentes. 

Las reglas de conversión que usa el compilador son algo complejas y pueden dar resultados inesperados. Por esa razón, no profundizaremos en ellas, pero mostraré un par de ejemplos para dar a entender a qué nos referimos con las reglas **1.** y **2.**

Aquí se pudo hacer una conversión exitosa:
```c++
#include <iostream>

int main()
{
    std::cout << (true ? 1 : 2) << '\n';
    // `1` y `2` son variables de tipo entero,
    // aquí no es necesario hacer conversiones.    

    std::cout << (false ? 1 : 2.2) << '\n'; 
    // `1` de tipo entero y `2.2` es de tipo
    // double.
    // Aquí `1` es convertida a tipo `double`
    // y todo sale bien.

    return 0;
}
```

Aquí ya no se pudo:
```c++
#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << ((x != 5) ? x : "x es 5"); 
    // aquí ocurre un error de compilado, `x` es un entero y 
    // `"x es 5"` es una literal tipo C-string (texto).
    // El compilador no es capaz de encontrar un tipo en común
    // para hacer la conversión.

    return 0;
}
```

## ¿Cuándo uso el operador condicional?

Es conveniente usar el operador condicional cuando:
* Queramos inicializar un objeto con uno de dos valores.
* Le queramos asignar a un objeto uno de dos valores.
* Le queramos pasar uno de dos valores a una función.
* Queramos imprimir uno de dos valores.

Todo lo anterior, considerando preferentemente valores del mismo tipo (ya que el compilador no siempre podrá hacer las conversiones necesarias).

Lo mejor es **no** usar el operador condicional en expresiones complicadas (como hemos notado, la idea es usarlo cuando para expresiones de **una** línea), ya que estas tienden a ser propensas a errores y si son muy largas ponerlas en un operador condicional las hace difíciles de leer.
