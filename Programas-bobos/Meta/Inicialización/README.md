Ya vimos que cuando definimos una variable debemos especificar su tipo, ponerle nombre y darle un valor. 

Existe la opción de darle un valor inicial a un objeto cuando lo definimos, este proceso se llama 'inicialización' y la  sintaxis usada para inicializar un objeto se llama 'inicializador'

`int longitud { 5 };` define la variable 'longitud' y le da el valor inicial de 5. `{ 5 }` es el inicializador.


En C++ hay 6 formas básicas de inicializar variables:
* `int a;`: Podemos no inicializar la variable (este es el default). Esto deja a la variable con un valor indefinido y si la dejamos así, puede causarnos problemas al correr el código.
* `int b = 5;`: Guardamos el valor 5 en la variable de tipo entero 'b' (inicialización de copia).
* `int c(6);`: El valor inicial está en paréntesis (inicialización directa). Este tipo de inicialización no es muy popular porque puede confundirse con funciones:
    * `int x();`: declara a la función `x`
    * `int x(0);`: define a la variable `x` con inicializador `0`.

Los 3 que siguen son de C++11 para adelante, las 3 son 'de tipo lista' y aparentemente son los preferentes:
* `int d { 7 };`: El valor inicial está entre {} (inicialización de lista directa).
* `int e = { 8 };`: Esta se llama inicialización de copiado de lista.
* `int f {};`: El inicializador son corchetes vacíos (inicializador de valor).
La principal ventaje de usar este tipo de inicialización es que si intentas asignarle a la variable un valor que no es correcto (por ejemplo, si intentas `int w2 { 4.5 };`), el compilador nos da un error de diagnóstico. Cosa que no pasaría si intentamos `int w2 = 4.5;`, ahí la variable sólo se guardaría con el valor 4 y no nos daríamos cuenta del error porque el compilador podría o no darnos una advertencia.

Los espacios dentro de { } y ( ) son una cuestión puramente estética.

**Ojo**: En general, lo mejor es incializar nuestras variables al momento de crearlas.


Se pueden inicializar varias variables en una misma línea.

Esto está permitido:
```
int a = 5, b = 6;          // copy initialization
int c( 7 ), d( 8 );        // direct initialization
int e { 9 }, f { 10 };     // direct brace initialization
int g = { 9 }, h = { 10 }; // copy brace initialization
int i {}, j {};            // value initialization
```

Esto no:
int a, b = 5; // wrong (a is not initialized!)
