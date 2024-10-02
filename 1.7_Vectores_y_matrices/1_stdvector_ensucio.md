**ESTÁS TOMANDO DE:** https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/

## Introducción

1. Cómo inicializarlos:
```
#include <vector> // Esto lo tienes que incluir

std::vector<tipo> nombre{elemento1, elemento2, ..., elementoN};
std::vector<tipo> nombre{}; // Para vectores vacíos.
```

tipo=int, double, ... (investiga qué tipos son válidos).
nombre= qué nombres se valen.

Parece ser que podemos saltarnos `<tipo>`:
```
#include <vector>
#include <iostream>

int main()
{
	// List construction (uses list constructor)
	std::vector primes{ 2, 3, 5, 7 };          // vector containing 4 int elements with values 2, 3, 5, and 7
	std::vector vowels{ 'a', 'e', 'i', 'o', 'u' }; // vector containing 5 char elements with values 'a', 'e', 'i', 'o', and 'u'.  Uses CTAD (C++17) to deduce element type char (preferred).

	std::cout << vowels[0] << '\n';
	return 0;
}
```
Sí compila. El programa (siempre y cuando estemos usando de C++17 en adelante, puede deducir sólo el tipo de elementos del vector.)

La longitud de los vectores está dada por el número de elementos en ellos, el orden en que pusimos los elementos sí importa (es como en las sucesiones de matemáticas, NO SON CONJUNTOS, se pueden repetir elementos y el orden sí importa).

## Índices

Los elementos de los vectores no tienen un nombre, pero sí un número asociado de acuerdo a su posición, por ejemplo en el vector:
```
std::vector<int> primos{ 2, 3, 5, 7 };
```
El elemento `2` tiene el número 0 asociado y para acceder a él usamos `primos[0]` y el elemento `7` tiene el número 7 asociado y para acceder a él usamos `primos[3]`. 

Los elementos de los vectores tienen índices asociados (formalmente se llaman subíndices, en inglés *subscript*) y estos empiezan en el 0 y terminan en N-1.

Conviene pensar en las posiciones de los elementos de los arrays en términos de sus índices en vez de decir "primer elemento", "segundo elemento", etc.

Por ejemplo:
```
#include <iostream>
#include <vector>

int main()
{
    std::vector primos { 2, 3, 5, 7, 11 }; // Tenemos los primeros
										   // 5 primos. Omitimo el
										   // <int> y aún así el 
										   // programa entendió que
										   // nuestro vector es de 
										   // enteros. 

    std::cout << "El primer primo es: " << primos[0] << '\n';
    std::cout << "El segundo primo es:: " << primos[1] << '\n';
    std::cout << "La suma de los primeros 5 primos es: " 
	          << primos[0] + primos[1] + primos[2] + primos[3] 
			     + primos[4] << '\n';

    return 0;
}
```
Imprime en consola:
```
El primer primo es: 2
El segundo primo es:: 3
La suma de los primeros 5 primos es: 28
```

Si tenemos un array con $N$ elementos, sus índices van de $0$ a $N-1$. Cuando querramos acceder a los índices de un array, es importante mantenernos en el rango permitido de los índices, en caso contrario tendremos comportamiento indefinido.

Por ejemplo, si intentamos:
```
#include <iostream>
#include <vector>

int main()
{
    std::vector primos { 2, 3, 5, 7, 11 }; 
	// El vector `primos` tiene 5 elementos, por tanto los índices
	// de sus elementos van de 0 a 4.

    std::cout << "El primer primo es: " << primos[5] << '\n';
	// `primos` no tiene un elemento al que le corresponda el 
	// índice 5.

    return 0;
}
```

En VSCode la consola imprimirá:
```
El primer primo es: -1414812757
```

Por sí solos, no todos los compiladores nos avisarán si el índice que pretendemos usar está en el rango válido (por ejemplo, VSCode no lo hace).


## Contruir un `std::vector` de cierta longitud

Consideremos el problema del curso de Cálculo I visto en la introducción de esta sección. Si estamos en el primer parcial, (idealmente) todavía tenemos 56 alumnos cuyas calificaciones queremos guardar. 

Si el programa será usado por la profesora o profesor introduzca las 56 calificaciones y estas serán guardadas en un `std::vector`, entonces primero necesitamos un `std::vector` con elementos de tipo `double` de longitud 56.

Podríamos crear un `std::vector`, especificar que sus elementos son de tipo `double` y rellenarlo con 56 valores iniciales que después serán reemplazados por las calificaciones de cada estudiante:
```
std::vector<double> calificaciones{1, 2, 3, ... 55, 56}
// vector que contiene 56 valores de tipo `double`. En `...`
// van los números del 4 al 54 separados por comas. Como el
// ejemplo es solamente ilustrativo, no los pondremos.
```

Esta forma de construir vectores es bastante mala por varias razones: Hay que teclear mucho, a menos que explícitamente estemos contando es muy difícil verificar que tenemos exactamente el número de iniciadores que necesitamos (y aún así, podemos equivocarnos y agregar uno de más/menos) y si después queremos cambiar el tamaño del vector (que es parte de nuestro problema inicial, pues los cursos de Cálculo suelen reducir su tamaño) tendremos que volver a definirlo desde cero.

Afortunadamente, `std::vector` tiene una herramienta que nos permite construir vectores de cierto tamaño y tipo.

## El constructor `std::vector<T>(std::size_t count)`

Imaginemos que queremos construir un edificio. Para que ese edificio esté listo y pueda usarse, necesitamos un proceso de construcción. Algo que lo prepare y lo deje en buenas condiciones para empezar a vivir o trabajar ahí. 

Un **constructor** en programación es como ese proceso de construcción, pero aplicado a objetos (entidades que agrupan datos y acciones; por ahora no es necesario profundizar en este concepto). Cuando creamos algo en un programa (por ejemplo, una lista, un número o cualquier otra cosa), el constructor se asegura de que todo esté preparado, inicializado o listo para usarse correctamente.

El constructor `std::vector<T>(std::size_t count)` es el constructor de la clase `std::vector` (por el momento tampoco profundizaremos en el concepto de clase) de tamaño `std::size_t` y elementos de tipo `T`. Si no se especifican valores de inicialización, todos los elementos se inicializan utilizando el constructor por defecto del tipo `T`. Por ejemplo, para los tipos `int` y `double`, los elementos se inicializan a cero (`0`  en el caso de `int` y `0.0` para `double`).

Para crear el vector donde podríamos guardar las 56 calificaciones del primer parcial, haríamos algo así:
```
std::vector<double> calificacionesParcial1(56);
// Creamos un std::vector con 56 elementos, todos de tipo `double`
// e inicializados a 0.0
```

Si queremos que los elementos de nuestro vector tengan un valor inicial distinto del por defecto (que en este caso es 0.0) usamos algo así:
```
std::vector<double> calificacionesParcial1(56, 5.0);
// Creamos un std::vector con 56 elementos, todos de tipo `double`
// e inicializados a 5.0
```

**OJO:**
```
std::vector<double> calificacionesParcial1(56);
```
Crea un std::vector con 56 elementos, todos de tipo `double` e inicializados a 0.0 (valor por defecto para `double`).

```
std::vector<double> calificacionesParcial1{56};
```
Crea un std::vector con 1 elemento cuyo valor es 56.

Es muy importante ser cuidadosos y recordar que:
* `()` se utiliza para especificar la cantidad de elementos del vector. Los elementos se inicializan con el valor por defecto de su tipo o con un valor específico si se proporciona.
* `{}` se utiliza para inicializar los elementos explícitamente con los valores que se pasen dentro de las llaves. Si se pasa un solo valor, se crea un vector con ese único elemento.

```
std::vector<int> v(5); // Crea un vector de 5 elementos, todos 
                       // inicializados a 0. Esta inicialización
                       // no funciona (da un error al compilar) 
                       // si el vector es miembro de una clase
                       // (por el momento, esto no tiene que
                       // preocuparnos).

std::vector<int> v{5}; // Crea un vector con 1 elemento que 
                       // tiene el valor 5.

std::vector<int> v(5, 10); // Crea un vector de 5 elementos, 
                           // todos inicializados a 10.

std::vector<int> v{5, 10}; // Crea un vector con 2 elementos: el
                           // primero con valor 5 y el segundo 
                           // con valor 10.
```

# `std::vector` y el problema de la longitud e índices sin signo

**AHORA ESTÁS TOMANDO DE:** https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/

## Obtener la cantidad de elementos en un `std::vector`

Podemos obtener la longitud (cantidad de elementos) en un `std::vector` usando `size()`:
```
#include <iostream>
#include <vector>

int main()
{
    std::vector primos { 2, 3, 5, 7, 11 };
    std::cout << "Tienes " << primos.size() << " números primos"
              << " en el vector." <<'\n'; 
    // OJO: `primos.size()` no es un entero (en el sentido de 
    //      que no es de tipo `int`). El uso de .size() retorna
    //      un dato de tipo `size_type`, que es un tipo de 
    //      entero sin signo (unsigned).        
    
    return 0;
}
```

En este contexto `size_type` es un alias para `std::size_t`, lo que significa que aunque estrictamente no son lo mismo, en el contexto de ciertas clases o bibliotecas, usar `size_type` es lo mismo que usar `std::size_t`. Por ejemplo, aquí en `std::vector`.

Lo que nos interesa sobre el hecho de que `primos.size()` sea de tipo `size_type` es que si intentamos utilizar `primos.size()` en un contexto donde el programa espera un entero con signo (algo de tipo `int` propiamente).  

Por ejemplo, si intentamos comparar `primos.size()` con un valor negativo o usarlo como argumento de una función que espera un `int` como parámetro, podríamos tener resultados no deseados o advertencias del compilador debido a la conversión implícita entre tipos con y sin signo.

Aquí se nos generaría un problema:
```
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vecA { 1, 2, 3, 4, 5 };
    std::vector<int> vecB { 1, 2, 3 };

    // Queremos calcular la diferencia en tamaños de nuestros
    // vectores.
    int diferencia {vecB.size() - vecA.size()}; 
    // vecA tiene 5 elementos, vecB tiene 3

    if (diferencia < 0){ // Si obtuvimos un número negativo.
        diferencia = -diferencia;
    }
    
    std::cout << "Diferencia de tamaños: " << diferencia << '\n';

    return 0;
}
```

Uno podría esperar que la diferencia sea $2$, porque $3 - 5 = 2$ y $-(-2) = 2$.

Pero en realidad pasa una de dos cosas:
* El código no compila si nuestra configuración del compilador es restrictiva (la advertencia mostrada en VSCode empieza: `narrowing conversion of...`)
* En caso de que el código sí compile, obtendremos un número grande como 4294967294 (dependiendo del sistema), ya que el sistema interpreta a los números sin signo de manera distinta a los enteros de tipo `int`, de modo que la resta de números sin signo no genera valores negativos y, en cambio, se comporta de manera inesperada. 

Para arreglar este problema, deberemos convertir explícitamente a `vecA.size()` y `vecB.size()` en un tipo con signo (en este caso, `int`):

```
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vecA { 1, 2, 3, 4, 5 };
    std::vector<int> vecB { 1, 2, 3 };

    // Queremos calcular la diferencia en tamaños de nuestros
    // vectores.
    int diferencia {static_cast<int>(vecB.size())  
                    - static_cast<int>(vecA.size())}; 
    // vecA tiene 5 elementos, vecB tiene 3.

    if (diferencia < 0){ // Si obtuvimos un número negativo.
        diferencia = -diferencia;
    }
    
    std::cout << "Diferencia de tamaños: " << diferencia << '\n';

    return 0;
}
```
`static_cast <tipo_después_de_conversión>( valor )` es un operador que recibe un `valor` (o una expresión) de algún tipo (en nuestro ejemplo, `size_type`) y devuelve el mismo valor, pero ahora del `tipo_después_de_conversión` (en nuestro ejemplo, `int`). No todas las conversiones entre distintos tipos son posibles utilizando este operador.

De manera general, hacer conversiones mediante `static_cast` entre tipos de datos "parecidos" (por ejemplo, de `int` a `float` o de `float` a `int`, con la posible pérdida de lo que esté después del punto decimal) es posible en C++.

Aunque hay más opciones además de `.size()` para obtener el número de elementos en un `std::vector`, en C++, no hay una forma directa de obtener dicho valor como tipo `int`. Así que sin importar la herramienta que utilicemos, nos veremos obligados a usar `static_cast` o alguna herramienta similar si queremos el tamaño de nuestros vectores como tipo `int`.

## Los índices pueden ser un dolor de cabeza

Si intentamos:
```
int main()
{
    std::vector primos{ 2, 3, 5, 7, 11 };

    int indice { 3 }; // `indice` es de tipo `int`, o sea es un
                      // número entero con signo.
    std::cout << primos[indice] << '\n'; 
    // En VScode se genera una advertencia: 
    // "... [-Werror=sign-conversion]"

    return 0;
}
```

`indice` es de tipo `int` (un entero con signo).

El operador `[]` definido dentro de `std::vector` que utilizamos para acceder a los índices recibe tipo `size_type` (el mismo tipo que obtenemos al hacer `vector.size()`). Así, cuando llamamos `primos[indice]`, el código deberá convertir `indice` a `size_type` (un entero sin signo).

Esta conversión en principio no es peligrosa porque los índices de un vector son números positivos (los problemas al convertir `int` a tipos sin signo realmente aparecen con números negativos). Pero al correr el programa, el compilador muy probablemente nos advertirá sobre una conversión no segura (VSCode nos da la siguiente advertencia: `... [-Werror=sign-conversion]`).

Si nuestra conversión para el compilador es estricta, nuestro programa no correrá.

Hay varias formas de evitar este problema cuando definamos índices (por ejemplo, podemos usar `static_cast`):
```
#include <iostream>
#include <vector>

int main()
{
    std::vector primos{ 2, 3, 5, 7, 11 };

    int indice { 3 }; // `indice` es de tipo `int`, o sea es un
                      // número entero con signo.

    
    std::cout << "El elemento con índice 3 es: " 
              << primos[static_cast<std::size_t>(indice)] 
              << '\n'; 
    // Pasamos de `int` a `size_type` dentro de `[]`. Recordemos
    // que `size_type` es un alias para `std::size_t`. 

    return 0;
}
```
Pero esto en realidad no es lo más conveniente porque si pensamos en muchos índices, eventualmente tendremos un código que se verá saturado (en particular tendríamos que repetir la línea `primos[static_cast<std::size_t>(indice)]` tantas veces como índices tengamos). 

Lo más sencillo es definir a nuestros índices usando tipo `std::size_t` y no usar estas variables para nada más que indexar (o si queremos usarla para algo más, sólo hacer las conversiones necesarias que el compilador nos exija):
```
#include <iostream>
#include <vector>

int main()
{
    std::vector primos{ 2, 3, 5, 7, 11 };

    std::size_t indice1 { 3 }; 
    // `indice1` es de tipo `size_type`

    std::size_t indice2 { 4 }; 
    // `indice2` es de tipo `size_type`

    std::size_t indice3 { }; 
    // `indice3` es de tipo `size_type`

    std::cout << "Dame un índice de 0 a 4: ";
    std::cin >> indice3;

    
    std::cout << "El elemento con índice 3 es: " 
              << primos[indice1] 
              << '\n'; 
    std::cout << "El elemento con índice 4 es: " 
              << primos[indice2] 
              << '\n';

    std::cout << "El elemento con índice " << indice3 <<" es: " 
              << primos[indice3] 
              << '\n';
    // Podemos imprimir `indice3` sin ningún problema.    

    return 0;
}
```
