Una **configuración de compilado** es una colección de configuracines de proyecto que determinan como el IDE (para nosotros, VSCode) va a construir nuestros proyectos.

Una configuaración de compilado típicamente incluye cosas como:
* Como se llamarán los archivos ejecutables (ej.: .exe).
* En qué directorios (carpetas) el IDE buscará código y archivos.
* Que tanto el compilador optimizará el programa.
* Etc.

De manera general, aquí se aplica la regla de 'si no le sabes, no le muevas'. En el sentido de que, trataremos de dejar los valores puestos por default a menos que tengamos una razón específica para cambiarlos.

Cuando se crea un proyecto nuevo, la mayoría de los IDEs ofrecen dos configuraciones de compilado: **Una configuración de lanzamiento** (release configuration) y una **configuración de depuración** (debug configuration).

La configuración de lanzamiento está designada para cuando tengamos pensado liberar nuestros programas al público. Esta versión está típicamente optimizada para que nuestros archivos pesen poco y los ejecutables sean más veloces. Pero no inluye información de depuración.

La configuración de depuración es la que usualmente se usa cuando estamos escribiendo nuestros programas, esta nos ayuda a identificar y remover errores. Esta es la configuración recomendable en principio, una vez que estemos seguros de que nuestros programas funcionan, podemos cambiarla a la de lanzamiento para hacer que nuestros archivos sean menos pesados.

## Configurar el compilador de VSCode:

Cuando en un proyecto se corre un programa (de C++) por primera vez, en la carpeta *.vscode* del proyecto se crea un archivo llamado *tasks.json*.

Buscaremos la línea `${file}` en la sección `"args"`. Encima de `${file}` agregaremos el comando `"-ggdb",` (este nos servirá para la configuración de depuración). Cuando querramos usar la configuración de lanzamiento, borramos `"-ggdb",` y encima de *${file}* pegamos (en orden):
* `"-O2",` y luego
* `"-DNDEBUG",`

![Captura de pantalla 2024-08-17 190826](https://github.com/user-attachments/assets/cdf85869-ad99-4f14-9f6f-40abb720db56)

El estándar de C++ define reglas sobre como los programas deben de comportarse en circunstancias específicas. En la mayoría de los casos, los compiladores siguen estas reglas. Sin embargo, muchos compiladores (entre ellos VSCode) implementan cambios al lenguaje, usualmente para mejorar la compatibilidad con otras versiones del lenguaje. Este tipo de comportamientos se llaman **extensiones de compilador**.

Si escribimos nuestros programas haciendo uso de una extensión de compilador (esta puede ser no-estándar), puede ocurrir que estos no compilen si cambiamos de compilador o si lo hacen, puede que no lo hagan de la forma correcta.

La mayoría de estas extensiones están activas por default, pero no es muy difícil quitarlas.

En el caso de VSCode lo que tenemos que hacer es buscar la línea `${file}` en la sección `"args"`. Encima de `${file}` agregaremos el comando `"-pedantic-errors",`.

![Captura de pantalla 2024-08-17 231136](https://github.com/user-attachments/assets/96e397ea-57ea-46d5-a221-942f104c40ae)

Al agregar la línea anterior le estamos pidiendo a VSCode que agrege una línea nueva al final de archivos de código que no la tienen (esto es requerido por el estándar de C++).

### Aumentar niveles de advertencia

Cuando hacemos algo que no es debido (si rompimos alguna regla de C++), de manera normal el compilador nos dará un aviso. La mayoría de los compiladores sólo nos generarán una advertencia concerniendo a los problemas más evidentes. Pero le podemos pedir al compilador que sea más asertivo al proveernos con advertencias de cosas que encuentre raras.

Como apenas estamos aprendiendo a programar en C++, lo mejor es elevar los niveles de advertencia al máximo, para identificar posibles errores.

En el caso de VSCode lo que haremos es (como en las veces anteriores) abrir el archivo *tasks.json*, buscar la línea `${file}` en la sección `"args"`. Encima de `${file}` agregaremos las siguientes líneas de comando (un comando por línea):
* `"-Wall",`
* `"-Weffc++",`
* `"-Wextra",`
* `"-Wconversion",`
* `"-Wsign-conversion",`

![Captura de pantalla 2024-08-17 233031](https://github.com/user-attachments/assets/4cd759c5-0a0a-4160-b5b4-f8663aeccf77)

También es posible pedirle al compilador que trate las advertencias como errores. Los errores detienen la compilación del programa, las advertencias aparecen cuando el programa puede compilar a pesar de que algo en él viola alguna regla de C++.

Este paso es totalmente opcional (y **no** lo recomiendo para programadores experimentados), pero considerando que estamos aprendiendo y los programas que haremos (al menos en principio) son sencillos y con la finalidad de acostumbrarnos a las buenas prácticas, yo sugiero activar la opción de "Tratar advertencias como errores".

En VSCode, en el archivo *tasks.json*, buscaremos la línea `${file}` en la sección `"args"`. Encima de `${file}` agregaremos el comando `"-Werror",`.

![Captura de pantalla 2024-08-17 233804](https://github.com/user-attachments/assets/f0052ffa-efd6-4de8-ad80-e7cfe6aa12d1)

### Elegir un estándar de lenguaje

Hay muchas versiones disponibles de C++ (C++98, C++03, C++11, C++14, C++17, C++20, C++23, etc…). De manera general, el compilador escoge una por default y se adhiere a ella (casi nunca es la versión más reciente y de hecho esto es lo recomendable porque esta suele a tener algunos errores).

VSCode es compatible con C++20 (ofrece soporte experimental para C++23).

Para preguntarle al compilador qué estándar de C++ está usando, podemos usar este código tomado de https://www.learncpp.com/cpp-tutorial/what-language-standard-is-my-compiler-using/:
```
// This program prints the C++ language standard your compiler is currently using
// Freely redistributable, courtesy of learncpp.com (https://www.learncpp.com/cpp-tutorial/what-language-standard-is-my-compiler-using/)

#include <iostream>

const int numStandards = 7;
// The C++26 stdCode is a placeholder since the exact code won't be determined until the standard is finalized
const long stdCode[numStandards] = { 199711L, 201103L, 201402L, 201703L, 202002L, 202302L, 202612L};
const char* stdName[numStandards] = { "Pre-C++11", "C++11", "C++14", "C++17", "C++20", "C++23", "C++26" };

long getCPPStandard()
{
    // Visual Studio is non-conforming in support for __cplusplus (unless you set a specific compiler flag, which you probably haven't)
    // In Visual Studio 2015 or newer we can use _MSVC_LANG instead
    // See https://devblogs.microsoft.com/cppblog/msvc-now-correctly-reports-__cplusplus/
#if defined (_MSVC_LANG)
    return _MSVC_LANG;
#elif defined (_MSC_VER)
    // If we're using an older version of Visual Studio, bail out
    return -1;
#else
    // __cplusplus is the intended way to query the language standard code (as defined by the language standards)
    return __cplusplus;
#endif
}

int main()
{
    long standard = getCPPStandard();

    if (standard == -1)
    {
        std::cout << "Error: Unable to determine your language standard.  Sorry.\n";
        return 0;
    }

    for (int i = 0; i < numStandards; ++i)
    {
        // If the reported version is one of the finalized standard codes
        // then we know exactly what version the compiler is running
        if (standard == stdCode[i])
        {
            std::cout << "Your compiler is using " << stdName[i]
                << " (language standard code " << standard << "L)\n";
            break;
        }

        // If the reported version is between two finalized standard codes,
        // this must be a preview / experimental support for the next upcoming version.
        if (standard < stdCode[i])
        {
            std::cout << "Your compiler is using a preview/pre-release of " << stdName[i]
                << " (language standard code " << standard << "L)\n";
            break;
        }
    }

    return 0;
}
```
Lo único que tenemos que hacer es hacer un archivo nuevo en nuestra carpeta madre (en mi caso es 'prueba0') con terminación *.cpp* (para avisarle al compilador que es un archivo de C++), copiar, pegar y correr el código anterior. 

**Nota:** Cada vez que se inicie un proyecto nuevo (es decir, si quieres trabajar en otra 'carpeta madre') se tienen que volver a aplicar las configuraciones modificadas anteriormente. Otra opción es crear una plantilla con la configuración que más te guste y usarla para crear proyectos nuevos.

