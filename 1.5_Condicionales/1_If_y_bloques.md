C++ admite dos tipos básicos de condicionales: las declaraciones `if` y las declaraciones `switch` (estas las veremos más adelante).

Ya habíamos mencionado que por sí solas las declaraciones `if` solamente ejecutan la declaración inmediata posterior una vez que su condicional se cumple.

Eventualmente vamos a encontrarnos en situaciones donde vamos a requerir que una vez que una condición sea verdadera (o falsa), se ejecute una serie de instrucciones.

Un primer intento (con base en lo que sabemos hasta ahora), podría verse así:

```
#include <iostream>

int minEstaturaCM { 140 }; // la estatura mínima para subir a
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
        // Prestémosle atención a la útlima línea.

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
    // Prestémosle atención a la útlima línea.

    return 0;
}
```
Así es más claro ver por qué la línea '`Lo siento, pequeño amigo Lannister.`' se imprime sin importar la estatura en cm. 

Para poder ejecutar varias declaraciones basadas en alguna condición, necesitaremos usar una **declaración compuesta** o **bloque** (éstas, aunque nunca las hemos llamado por este nombre, ya las hemos visto antes; ya que el cuerpo de una función es un bloque).

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
        // Prestémosle atención a la útlima línea.
    }

    return 0;
}
```
El programa ahora sí funciona como esperábamos porque las declaraciones dentro del bloque se ejecutan bajo una sola condición (en este caso, que la estatura dada por el usuario no verifique la condición `x >= minEstaturaCM`).  

Aunque en la [introducción de este capítulo](/1.5_Condicionales/0_Introducción.md) vimos que la estructura básica de una condicional `if`-`else` no requiere de bloques (`{}`), hay varias razones por las cuales sí conviene usarlos aún cuando dentro de nuestra condicional sólo haya una declaración a ejecutar:

1. Siempre existe la posibilidad de que necesitemos modificar el programa y querramos agregar una nueva instrucción dentro de una condicional. Si ya hemos puesto llaves `{}` desde un inicio, es menos probable que cometamos el error expuesto más arriba y acabemos con una declaración que se ejecuta sin importar lo que pasa en la condicional.

2. Supongamos que tenemos un programa al que estamos depurando:
```

```
