En C++ **las condicionales** se usan para tomar decisiones basadas en el valor de una expresión booleana (ver: [el archivo de texto anterior](-1_Booleanos.md)).

La estructura básica de una condicional es el uso de la **declaración `if`** que nos permite ejecutar una (o más) línea de código sólo si una condición es verdadera.

La forma más simple de la declaración `if` tiene la siguiente forma:
```
if (condición) declaración_verdadera;
```
Para que sea más fácil para nosotros los humanos leer lo anterior (sobre todo cuando la `declaración_verdadera` es muy larga), es mejor escribirla así:
```
if (condición)
    declaración_verdadera;
```

Una **condición** (también llamada **expresión condicional**) es una expresión que es evaluada a un valor booleano. Si la *condición* de una declaración `if` es evaluada al valor booleano `true`, entonces la `declaración_verdadera` se ejecuta. Si la condición es evaluada al valor booleano `false`, entonces la `declaración_verdadera` es omitida por el programa.

**Nota:** El indentado de `declaración_verdadera` tendremos que ponerlo nosotros de forma manual (lo recomendable es usar la tecla *Tab*). Aunque éste no es necesario, sí es recomendable ponerlo porque nos ayuda a distinguir fácilmente cuál es la instrucción que se ejecutará si se cumple la condición.

Veamos un ejemplo de un programa simple que usa la declaración `if`:
```
#include <iostream>

int main()
{
    std::cout << "Dame un entero: ";
    int x {};
    std::cin >> x;

    if (x == 0) 
        std::cout << "El valor es cero\n";

    return 0;
}
```
Una vez que el usuario ha dado un entero, la condición entre paréntesis `x==0` es evaluada:
* Si se cumple (o sea, si el número que el usuario dio es 0) el operador `==` devuelve el valor `true` y se ejecuta la declaración subsecuente (`std::cout << "El valor es cero\n";`).
* Si no se cumple (o sea, si el número que el usuario dio es distinto de 0) el operador `==` devuelve el valor `false` y la declaración inmediata después de la condicional (`std::cout << "El valor es cero\n";`) es omitida.

**Nota:** Por sí solas, las declaraciones `if` solamente ejecutan una sola declaración (la inmediata posterior) una vez que su condicional se cumple. Más adelante veremos como dar condicionales de manera en que se ejecuten múltiples declaraciones una vez que se satisfaga una declaración. Es por esta razón que en los ejemplos de esta sección, sólo hay una posible instrucción ejecutable inmediatamente después de `if` o (próximamente) `else`.

## `if`-`else`

Dado el ejemplo anterior, puede que el usuario se desconcierte un poco si inmediatamente después de que introduce un entero distinto del cero, el programa termine sin más aviso.

Para remediar esta situación podríamos hacer algo así:
```
#include <iostream>

int main()
{
    std::cout << "Dame un entero: ";
    int x {};
    std::cin >> x;

    if (x == 0) 
        std::cout << "El valor es cero\n";

    if (x != 0)
        std::cout << "El valor es distinto de cero\n";

    return 0;
}
```

O (si queremos complicar nuestro programa de manera innecesaria) así:
```
#include <iostream>

int main()
{
    std::cout << "Dame un entero: ";
    int x {};
    std::cin >> x;

    bool cero {(x == 0)}; 
    // `cero` es una variable booleana que gardará `true` si el
    // entero que nos dio el usuario es 0 y `false` en otro caso.

    if (cero) // si `cero` vale `true`
        std::cout << "El valor es cero\n";

    if (!cero) //si `cero` vale `false`
        std::cout << "El valor es distinto de cero\n";

    return 0;
}
```
En realidad (aunque ambos programas nos dan lo que queremos y por tanto son correctos), hay una manera más sencilla de hacer las cosas usando una forma alternativa de la declaración `if` llamada **`if-else`**. La **declaración `if-else`** tiene la siguiente forma:
```
if (condición)
    declaración_verdadera
else 
    declaración_falsa
```
**Nota:** Nuevamente, el indentado de `declaración_verdadera` (así como el de `declaración_falsa`) tendremos que ponerlo nosotros de forma manual.

Si la `condición` es evaluada al valor booleano `true`, la `declaración_verdadera` se ejecuta, en otro caso el programa salta a la `declaración_falsa` y ejecuta ésta en su lugar.

Arreglemos nuestro ejemplo usando `if-else`:
```
#include <iostream>

int main()
{
    std::cout << "Dame un entero: ";
    int x {};
    std::cin >> x;

    if (x == 0) 
        std::cout << "El valor es cero\n";

    else
        std::cout << "El valor es distinto de cero\n";

    return 0;
}
```

## Encadenamiento de condiciones `if`

A veces queremos evaluar el valor de verdad de varios enunciados en una secuencia. Esto lo podemos hacer encadenando una declaración `if` (o una `if-else`) a una `if` anterior. Por ejemplo:
```
#include <iostream>

int main()
{
    std::cout << "Dame un entero: ";
    int x {};
    std::cin >> x;

    if (x > 0) 
        std::cout << "El valor es positivo\n";

    else if (x < 0)
        std::cout << "El valor es negativo\n";
    
    else
        std::cout << "El valor es cero\n";

    return 0;
}
```

Una pregunta que puede surgir es *¿por qué usamos `else if` para la segunda condición en vez de solamente `if`?*. La cuestión es que si hacemos:
```
#include <iostream>

int main()
{
    std::cout << "Dame un entero: ";
    int x {};
    std::cin >> x;

    if (x > 0) 
        std::cout << "El valor es positivo\n";

    if (x < 0)
        std::cout << "El valor es negativo\n";
    
    else
        std::cout << "El valor es cero\n";

    return 0;
}
```
Si damos un entero positivo (digamos 87) en terminal veremos el siguiente output:
```
Dame un entero: 87
El valor es positivo
El valor es cero
```

Esto es porque en C++ un `else` siempre se asocia con el `if` más cercano si no se usan llaves `{}` para agrupar el código (más adelante veremos cómo hacer esto). 

Entonces, en el código anterior al dar un entero positivo:
1. Se imprime `El valor es positivo`
2. El `else` que imprime `El valor es cero` está asociado al `if` que verifica la condición `x < 0`. Como 87 (o cualquier otro entero positivo que demos) no cumple ser menor que 0, `x < 0` es evaluada y devuelve el valor `false` lo que hace que se ejecute la instrucción en `else` (imprimir `El valor es cero`).

Cuando usamos `if` varias veces, C++ los interpreta como 'bloques' independientes. Esto quiere decir que **cada condición se evalúa de manera separada e independiente** de las demás, sin importar si alguna anterior ya se cumplió. 

Cuando usamos `if` seguido de `else if`, el flujo del programa se detiene en cuanto se encuentra una condición verdadera. O sea, **sólo se ejecuta un 'bloque' de código**, incluso si alguna de las condiciones subsecuentes podrían ser verdaderas también. 
Por ejemplo:
```
#include <iostream>

int main() 
{
    int numero{};
    std::cout << "Dame un entero: ";
    std::cin >> numero;

    if (numero > 5) 
        std::cout << "Es mayor que 5.\n";

    else if (numero > 8)
        std::cout << "Es mayor que 8.\n";

    else if (numero > 10) 
        std::cout << "Es mayor que 10.\n";
    
    return 0;
}
```
Si el usuario introduce 500, técnicamente todas las condiciones se cumplen, pero como la primer condición (`numero > 5`) ya se cumplió, lo único que verá el usuario en terminal es:
```
Dame un entero: 500
Es mayor que 5.
```

## Declaraciones `if` y devoluciones anticipadas.

Como ya vimos en [la sección sobre funciones](../1.3_Funciones_basicas/0_Introducción.md), usualmente, una declaración `return` es la última instrucción de una función; a una declaración `return` que no es la última instrucción de una función la llamamos **devolución anticipada** (*early return*). Una declaración de este tipo hara que la función vuelva a su llamador una vez que lleguemos a la línea donde está `return` aún si después de esta hay más instrucciones.

Una *devolución anticipada* sin un condicional no es de mucha utilidad:
```
#include <iostream>

void print()
{
    std::cout << "A" << '\n';

    return; 
    // Como la función es de tipo `void` no es necesario decirle
    // de que tipo es la variable que esperamos que nos devuelva,
    // porque este tipo de funciones no devuelven variables de 
    // ningún tipo.
    
    // Aquí estamos haciendo una devolución anticipada, ya que toda
    // línea después de `return` no se ejecutará nunca porque la
    // función volverá a su llamador, que en este caso es `main`

    std::cout << "B" << '\n'; // esta línea nunca se va a imprimir.
}

int main()
{
    print(); // `main` llama a `print`
    return 0;
}
```
La línea `std::cout << "B" << '\n';` jamás se va a ejecutar, bien podríamos borrarla. Si lo hacemos, nuestra declaración `return` ya no será anticipada (pues será la última instrucción de la función).

Por sí solas, las devoluciones anticipadas no se ven muy útiles, pero si las combinamos con las declaraciones `if` podemos condicionalizar el valor de retorno de nuestras funciones:
```
#include <iostream>

// devuelve el valor absoluto de un entero `x`
int abs(int x)
{
    if (x < 0)
        return -x; // devolución anticipada sólo si x<0.

    return x; // si la condición anterior no se verificó (si x>=0),
              // esta instrucción sí se ejecuta.
}

int main()
{
    std::cout << abs(4) << '\n'; // imprime 4
    std::cout << abs(-3) << '\n'; // imprime 3

    return 0;
}
```
Cuando llamamos a la función `abs()` y le damos como parámetro al `4`, la condición `x < 0` es falsa, entonces la devolución anticipada no se ejecuta y la función salta a `return x;` y vuelve al llamador.

Cuando llamamos a la función `abs()` y le damos como parámetro al `-3`, la condición `x < 0` es verdadera, entonces la devolución anticipada sí se ejecuta. La función nos devuelve `-x` y vuelve al llamador.
