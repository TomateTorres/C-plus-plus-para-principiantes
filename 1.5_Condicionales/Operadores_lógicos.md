En C++ (y en la mayoría de los lenguajes de programación) los **operadores lógicos** son muy importantes en los condicionales ya que estos nos permiten probar si múltiples condiciones se cumplen.

En C++ tenemos 3 operadores lógicos:
| Operador                         | Símbolo | Ejemplo | Operación  |
| -------------------------------- | ------- | ------- | --- |
| Negación lógica (*logical NOT*)  |    `!`    | `!true` | Nos da `false` (pues es la negación de `true`)|
| Conjunción lógica (*logical AND*)|   `&&`    | `x && y`  | Da `true` si `x` y `y` se verifican, `false` en otro caso |
| Disyunción lógica (*logical OR*) |   `\|\|`    |  `x \|\| y` | Da `true` si `x` o `y` se verifican (o ambas), `false` en otro caso |

## No lógico

Al **operador de negación lógica** (también llamado *no lógico*) [ya lo habíamos visto](-1_Booleanos.md). En resumen: El operador de negación lógica cambia el valor de un booleano `true` a `false` y viceversa.

El operador de negación lógica es usado frecuentemente en condicionales:
```
bool muyGrande { x > 100 }; // `muyGrande` es `true` si `x > 100`

if (!muyGrande) // si `muyGrande` es `false`
{
    /* ponemos algo aquí de manera que se haga algo con `x`,
    por ejemplo: evaluarlo en alguna función.
    */
}    

else // si `muyGrande` es `true`
{
    // se hace algo distinto con `x`
}
```

Es importante mencionar que el *no lógico* tiene un nivel de precedencia muy alto (a menos que en el código especifiquemos lo contrario, es de las primeras cosas que se evalúan en una expresión). Veamos algunos ejemplos:
```
#include <iostream>

int main()
{
    int a{3};
    int b{5};
    bool resultado{};

    // Ejemplo: Comparando '!' con '<'
    resultado = !a < b;  // Evaluación: (!a) < b
    // Aquí se evalúa primero el "no lógico" (!) sobre 'a'.
    // Luego, el resultado de esa operación se compara con 'b' usando '<'.

    std::cout << "Resultado de !a < b: " << resultado << '\n'; // Imprime 1 (true)

    // Ejemplo con paréntesis para cambiar la precedencia
    resultado = !(a < b);  // Evaluación: !(a < b)
    // Aquí primero se evalúa la comparación 'a < b', luego se aplica el "no lógico" (!).

    std::cout << "Resultado de !(a < b): " << resultado << '\n'; // Imprime 0 (false)

    return 0;
}
```
```
#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 7 };

    if (!x > y) // Se evalúa (!x) > y
    {
    // `!x` es 0, y `0 > 7` es `false`, así se ejecuta la instrucción en `else`
        std::cout << x << " no es mayor que " << y << '\n';
    }
   
    else
    {
        std::cout << x << " es mayor que " << y << '\n';
    }

    return 0;
}
```

**Notas:**
* Los códigos anteriores no compilarán si usamos la configuración sugerida en la [Caja de herramientas](../Caja_de_herramientas/Configurar_el_compilador.md). Pero si la configuración es más permisiva, sucede lo que se menciona en los comentarios.
* De manera general, en C++ [un entero se convierte en booleano automáticamente](-1_Booleanos.md) cuando se utiliza en contextos donde se espera un valor booleano, como en operadores lógicos. De ahí que `!a` sea igual a `0` (como `a` es un entero distinto de `0`, al evaluarlo como booleano le es asignado el valor de `1` en la memoria).

Lo mejor es usar paréntesis para indicarle al compilador cómo queremos que evalúe nuestras expresiones. Usos simples del *no lógico* (del estilo `if (!bool)`) no necesitan del uso de parántesis porque aquí la precedencia del operador por encima de otros no importa.

## O lógico

El **operador de disyunción lógica** (también llamado *o lógico*) sirve para verificar si una (o ambas) condición de dos se cumple. `||` nos dará `false` sólo en el caso donde ambos operandos se evalúen como `false`, en cualquier otro caso `||` nos dará `true`.

Por ejemplo, en el siguiente programa:
```
#include <iostream>

int main()
{
    std::cout << "Dame un número: ";
    int valor {};
    std::cin >> valor;

    if (valor == 0 || valor == 1)
    {
        std::cout << "Elegiste 0 ó 1\n";
    }    
        
    else
    {
        std::cout << "No elegiste 0 ó 1\n";
    }
        
    return 0;
}
```
Usamos el *o lógico* para verificar si la condición de la izquierda (`valor == 0`) o la de la derecha (`valor == 1`) se cumplen. Si alguna es cierta, `||` se evalúa como `true`, lo que quiere decir que se ejecuta la declaración `if` y en pantalla se imprime `Elegiste 0 ó 1`. Si ninguna es cierta, `||` se evalúa como `false`, se ejecuta `else` y en pantalla se imprime `No elegiste 0 ó 1`

Es posible encadenar múltiples declaraciones *o lógicas*:
```
if (valor == 0 || valor == 1 || valor == 2 || valor == 3)
    {
        std::cout << "Elegiste 0, 1, 2, ó 3\n";
    }
```


## Y lógico

El **operador de conjunción lógica** (también llamado *y lógico*) es usado para verificar si ambos operandos son verdaderos. Si ambos operandos son verdaderos, `||` nos da `true` y nos da `false` en cualquier otro caso.

Por ejemplo, podríamos querer evaluar si una variable `x` está en cierto intervalo, digamos entre $\(0, 6\)$. Necesitamos verificar dos condiciones: Necesitamos verificar que `0 < x` y `x < 6`.
```
#include <iostream>

int main()
{
    std::cout << "¿Cuál fue tu calificación en este parcial? ";
    double x{};
    std::cin >> x;

    if (0 < x && x < 6) 
    // Vamos a ser optimistas y suponer que nadie sacó 0.
    {    
        std::cout << "Ni modo, te toca reponer.\n";
    }
    
    else
    {
        std::cout << "Estás a salvo... por ahora.\n";
    }
    
    return 0;
}
```

Al igual que con las declaraciones *o lógicas*, es posible encadenar múltiples *y lógicas*:
```
// Supongamos que tenemos un `valor` y queremos verificar si está
// en (10, 20) pero no es igual a 16.

if (valor > 10 && valor < 20 && valor != 16)
{
    // hacemos algo
}
else
{
    // hacemos algo diferente
}
```
Si todas las condiciones se verifican, la declaración `if` se ejecutará y si cualquiera de las condiciones es `false`, se ejecutará la declaración `else`.

## Evaluación de cortocircuito

Para que el operador **y lógico** (`&&`) devuelva `true`, ambos operandos deben valer `true`. Si el operando de la izquierda es evaluado como `false`, entonces el operador sabe que debe devolver el valor `false` sin importar el valor de verdad del operando de la derecha. En este caso, el operador 


## Combinar `&&`s y `||`s

Podemos encadenar y combinar declaraciones `y lógicas` y `o lógicas`:
```
#include <iostream>

int main()
{
    std::cout << "¿Cuál fue tu calificación en este parcial? ";
    double calif{};
    std::cin >> calif;

    if ((0 < calif && calif < 6) || calif == 0) 
    // Rechazamos el optimismo, resulta que alguien sí sacó 0 :(.
    {    
        std::cout << "Ni modo, te toca reponer.\n";
    }
    
    else
    {
        std::cout << "Estás a salvo... por ahora.\n";
    }
    
    return 0;
}

```
