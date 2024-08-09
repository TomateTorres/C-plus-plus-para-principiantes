/*
A veces tenemos variables que usamos en otros programas y hemos
pegado en un particular código donde no la vamos a usar. No
podemos borrar la variable porque la estamos usando en otro
lado y (por alguna razón) no nos es conveniente agregar una
línea de código donde esta variable sea usada. 

En estos casos, lo mejor es usar el atributo `[[maybe_unused]]`
*/

//Consideremos el siguiente ejemplo:


#include <iostream>
int main()
{
    [[maybe_unused]] double pi { 3.14159 };
    [[maybe_unused]] double gravity { 9.8 };
    [[maybe_unused]] double phi { 1.61803 };

    std::cout << pi << '\n';
    std::cout << phi << '\n';

    // The compiler will not warn about gravity not being used

    return 0;
}

/*
El compilador (posiblemente) optimizarás las variables que en
verdad no se usen para sacarlas del programa, de manera que no
habrá impacto en su funcionamiento.

`[[maybe_unused]]` sólo debe ser usado de manera selectiva en 
variables que tienen una razón legítima para aparecer en un
programa donde no se van a usar.
*/
