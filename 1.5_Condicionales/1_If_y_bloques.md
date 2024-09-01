C++ admite dos tipos básicos de condicionales: las declaraciones `if` y las declaraciones `switch` (estas las veremos más adelante).

Ya habíamos mencionado que por sí solas las declaraciones `if` solamente ejecutan la declaración inmediata posterior una vez que su condicional se cumple.

Eventualmente vamos a encontrarnos en situaciones donde vamos a requerir que una vez que una condición sea verdadera (o falsa), se ejecute una serie de instrucciones.

Un primer intento (con base en lo que sabemos hasta ahora), podría verse así:

```
#include <iostream>

int minEstaturaCM { 140 }; // La estatura mínima para subir a
                           // la atracción.

int main()
{
    std::cout << "Dame tu estatura (en cm): ";
    int x{};
    std::cin >> x;

    if (x >= minEstaturaCM)
        std::cout << "Eres lo suficientemente alto para subir.\n";
    else
        std::cout << "No tienes la estatura sufiente para subir.\n";
        std::cout << "Lo siento, pequeño amigo Lannister.\n"; 
        // Prestémosle atención a la última línea.

    return 0;
}
```
Para empezar, el código anterior (en el supuesto de que estamos [usando VSCode con la opción de 'tratar advertencias como errores'](../Caja_de_herramientas/Configurar_el_compilador.md)) probablemente no va compilar y nos dará la siguiente advertencia al pasar el cursor por encima del `else` (que estará marcado con señal de alerta):
```
this 'else' clause does not guard... [-Werror=misleading-indentation]gcc
```
Lo anterior es sólo para avisarnos que, aunque hemos 'agrupado' la segunda línea que queremos que se imprima si alguien es muy bajo para subir (`Lo siento, pequeño amigo Lannister.`), en realidad esta última línea se ejecuta de manera independiente a la declaración condicional `if`-`else`.

O sea, es como si hubiéramos escrito:
```
#include <iostream>

int minEstaturaCM { 140 };

int main()
{
    std::cout << "Dame tu estatura (en cm): ";
    int x{};
    std::cin >> x;

    if (x >= minEstaturaCM)
        std::cout << "Eres lo suficientemente alto para subir.\n";
    else
        std::cout << "No tienes la estatura sufiente para subir.\n";
    
    std::cout << "Lo siento, pequeño amigo Lannister.\n"; 
    // Prestémosle atención a la última línea.

    return 0;
}
```
Así es más claro ver por qué la línea '`Lo siento, pequeño amigo Lannister.`' se imprime sin importar la estatura en cm. 

![Captura de pantalla 2024-09-01 150022](https://github.com/user-attachments/assets/1ac000d2-6dbe-4520-9498-063b9e1fd5af)


Para poder ejecutar varias declaraciones basadas en alguna condición, necesitaremos usar una **declaración compuesta** o **bloque** (éstas, ya las hemos visto antes; ya que el cuerpo de una función es un bloque).

Un **bloque** en C++ es un conjunto de declaraciones agrupadas por llaves `{}` que se tratan como una sola unidad.

Si hubiéramos escrito:
```
#include <iostream>

int minEstaturaCM { 140 };

int main()
{
    std::cout << "Dame tu estatura (en cm): ";
    int x{};
    std::cin >> x;

    if (x >= minEstaturaCM)
        std::cout << "Eres lo suficientemente alto para subir.\n";
    else
    {
        std::cout << "No tienes la estatura sufiente para subir.\n";
        std::cout << "Lo siento, pequeño amigo Lannister.\n"; 
    }

    return 0;
}
```
El programa ahora sí funciona como esperábamos porque las declaraciones dentro del bloque se ejecutan bajo una sola condición (en este caso, que la estatura dada por el usuario no verifique la condición `x >= minEstaturaCM`).  

Aunque en la [introducción de este capítulo](/1.5_Condicionales/0_Introducción.md) vimos que la estructura básica de una condicional `if`-`else` no requiere de bloques (`{}`), hay varias razones por las cuales sí conviene usarlos aún cuando dentro de nuestra condicional sólo haya una declaración a ejecutar:

1. Siempre existe la posibilidad de que necesitemos modificar el programa y querramos agregar una nueva instrucción dentro de una condicional. Si ya hemos puesto llaves `{}` desde un inicio, es menos probable que cometamos el error expuesto más arriba y acabemos con una declaración que se ejecuta sin importar lo que pasa en la condicional.

2. Supongamos que tenemos un programa al que estamos depurando:
```
if (edad >= mayoriaEdad)
    agregaPistoACarrito(); // esta línea sólo se ejecuta si se 
                           // cumple la condición.

pagaEnCaja(); // esta línea se ejecuta siempre
```
Y tenemos la sospecha de que hay un error en la función `agregaPistoACarrito()`, entonces la comentamos para ver si el resto del programa corre bien sin ella (esto confirmaría que en efecto hay un problema en esa función).
```
if (edad >= mayoriaEdad)
    /*agregaPistoACarrito(); // esta línea ya no se ejecuta, es 
                             // un comentario
    */

pagaEnCaja(); // ahora se ejecuta sólo si se cumple el condicional
```
Aunque el indentado nos pueda engañar, la llamada a la función `pagaEnCaja()` es la declaración inmediata posterior después de `if`, así que esta es ahora la que se ejecutará sólo si la condicional se cumple.

3. Al menos en VSCode (probablemente esto también sea así en otros IDE) si usamos bloques al escribir condicionales, ya no tenemos que preocuparnos por poner el indentado de forma manual. Aunque indentar nuestro código no es necesario para que el compilador lo entienda, hacerlo es muy útil para que nosotros los humanos podamos leerlo con mayor facilidad.

Así que la recomendación es considerar a:
```
if (condición)
{    
    declaración_verdadera
}

else
{
    lo_que_pasa_si_(condición)_no_se_cumple
}
```
como nuestra forma 'canónica' para las declaraciones `if`-`else`.

## Bloques implícitos

Para el compilador, esto
```
if (condición)    
    declaración_verdadera

else
    lo_que_pasa_si_(condición)_no_se_cumple
```
y esto
```
if (condición)
{    
    declaración_verdadera
}

else
{
    lo_que_pasa_si_(condición)_no_se_cumple
}
```
son equivalentes. Cuando nosotros no ponemos los bloques, el compilador lo hace implícitamente por nosotros.

La mayoría de las veces esto no importa. Pero olvidar este tipo de detalles nos puede llevar a intentar definir variables dentro los bloques implícitos:
```
#include <iostream>

int main()
{
    if (true)
        int x{ 5 };
    else
        int x{ 6 };

    std::cout << x << '\n';

    return 0;
}
```

El programa anterior no compila, el error generado nos dice que el identificador `x` no está definido. Esto es porque para el compilador lo que hicimos fue:
```
#include <iostream>

int main()
{
    if (true)
    {
        int x{ 5 }; // x es creada e inicializada aquí
    } // x es destruida aquí
    else
    {
        int x{ 6 }; // x es creada e inicializada aquí
    } // x es destruida 

    std::cout << x << '\n'; // x está fuera de alcance aquí

    return 0;
}
```
En este contexto, la variable `x` tiene alcance sólo dentro de cada bloque donde es definida y es destruida al final de éste (en [1.3](../1.3_Funciones_basicas/3_Intro_a_alcance_local.md) ya hablamos un poco sobre qué es el alcance de una variable). Para cuando llegamos a la línea `std::cout << x << '\n';` la variable `x` ya no existe y el programa no tiene nada para imprimir en pantalla.


## Declaraciones `if` anidadas

En C++ está permitido hacer declaraciones `if` dentro de declaraciones `if`:
```
/*
Supongamos que queremos clasificar a una persona según su edad:
1. Si es menor de edad.
2. Si es adulto: tiene entre 18 y 64 años
3. Si es de la tercera edad.

Además, en caso de que la persona sea adulta, queremos saber si
es adulto joven (tiene entre 18 y 40) o está en la mediana edad
(tiene entre 41 y 64)
*/

#include <iostream>

int pideEdad() // Las edades son números enteros
{
    int edad{};
    std::cout << "Introduce tu edad: ";
    std::cin >> edad;
    return edad;
}

int main()
{
    int edad{pideEdad()}; // La edad del usuario

    if (edad < 18) // Primera declaración `if`-`else`
    {
        std::cout << "Eres menor de edad.\n";
    }

    else // La persona es mayor de edad
    {
        // Segunda declaración `if`-`else`
        if (edad < 65) 
        {
            // Tercera declaración `if`-`else`
            if (edad <= 40)
            {
                std::cout << "Eres un adulto joven.\n";
            }

            else 
            {
                std::cout << "Estás en la mediana edad.\n";
            }
        }

        else // La edad es mayor o igual a 65.
        {
            std::cout << "Estás en la tercera edad.\n";
        }
    }

    return 0;
}
```

**Nota:** Dentro de los condicionales, el operador que debemos usar si queremos verificar que una variable tiene asignado cierto valor es el operador `==`. En C++ (y en muchos lenguajes de programación) el operador `=` sirve para asignarle un valor nuevo a una variable, no para verificar una igualdad.
