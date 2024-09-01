En nuestros cursos de álgebra solemos tener nuestros primeros encuentros con las *proposiciones*, que son enunciados que pueden ser calificados como verdadero o falso (pero no ambos a la vez). O sea, las proposiciones son enunciados con valores de verdad bien definidos.

* *El 7 es un número par.* Es una proposición (porque podemos asignarle un valor de verdad) falsa.
* *Ojalá hoy no llueva.* No es una proposición porque no podemos asignarle un valor de verdad.
* *Los burritos son alimento.* Es una proposición (porque podemos asignarle un valor de verdad) verdadera.

![images](https://github.com/user-attachments/assets/fa0131ec-9e52-4546-ba83-fc87f2969393)


Las proposiciones también aparecen en el mundo de la programación, de hecho son tan comunes que muchos lenguajes de programación incluyen un tipo (*type*) especial para lidiar con ellas, este tipo de dato se llama **booleano**.

Las **variables booleanas** son variables que (al igual que las proposiciones) sólo pueden tener dos valores posibles: verdadero (`true`) o falso (`false`).

Para declarar una variable booleana, usamos la palabra reservada `bool`:
```
bool p;
```
Para inicializar o asignar un valor de verdad a nuestra variable booleana, usamos las palabras reservadas `true` y `false`:
```
bool p1{true};  //p1 se inicializa con el valor de verdad `true`
bool p2{false}; //p2 se inicializa con el valor de verdad `false`
p1 = false;     //cambiamos el valor de verdad de p1 a `false`
bool p3{};      //la inicialización por default de una variable 
                //booleana es `false`. Como no pusimos nada, p3 
                //tendrá asignado como valor de verdad `false`
```

Cuando tenemos una proposición *P* y queremos cambiar su valor de verdad usamos el símbolo *¬* y obtenemos *¬P*. Si *P* era verdadera, *¬P* será falsa y viceversa. Para los booleanos tenemos algo análogo: el operador lógico *!* nos sirve para cambiar el valor de verdad de un booleano:
```
bool p1{!true};  //p1 es inicializado como `false`
bool p2{!false}; //p2 es inicializado como `true`
```

Los valores booleanos (`true` y `false`) no se guardan en las variables booleanas como palabras, en su lugar, son guardadas como valores enteros: `true` se guarda como `1` y `false` se guarda como `0`. De la misma forma, cuando valores booleanos son evaluados, no lo son como `true` y `false` sino como `1` y `0` respectivamente. Es por ello que al imprimirlos en pantalla, aparecen los valores enteros asociados al valor de verdad.
```
#include <iostream>

int main()
{
    std::cout << true << '\n'; // `true` evalua a 1
    std::cout << !true << '\n'; // `!true` es `false` que evalua a 0

    bool b {}; // b es inicializada por default, así es `false`
    std::cout << b << '\n'; // b es `false` que evalua a 0
    std::cout << !b << '\n'; // !b es `true` que evalua a 1
    return 0;
}
```

Aunque al inicializar variables booleanas, usemos `true` y `false`, cuando querramos inicializar una variable booleana mediante input del usuario (usando `std::cin`), debemos hacerlo usando `0` y `1`.
```
#include <iostream>

int main()
{
	bool b{};
	std::cout << "Dame un valor booleano: ";

	// El usuario deberá escribir `0` para 'false' y `1` para 'true'
	std::cin >> b;

	std::cout << "Tu input fue: " << b << '\n';

	return 0;
}
```
El programa anterior corre aún cuando el usuario da un input distinto a `0` ó `1`, lo que sucede es que:
* Cuando damos un input no válido (digamos un string o combinación de números o letras), `std::cin` falla silenciosamente y la inicialización que se queda para nuestra variable booleana es la que está por default, o sea `false`.
* Cuando introducimos un entero (aunque éste no sea 1), éste pasa a la memoria como `true` y es por ello que podemos tener outputs del estilo:
```
Dame un valor booleano: -98
Tu input fue: 1
```
Lo anterior ocurre porque de manera general, en C++ **un entero se convierte en booleano automáticamente** cuando se utiliza en contextos donde se espera un valor booleano, como en condiciones (`if`, `while`), operadores lógicos y retornos de funciones booleanas. La regla es que **0 se convierte en `false`** y **cualquier otro valor se convierte en `true`**.

## Valores de retorno booleanos

Los valores booleanos a menudo son utilizados como valores de retorno para funciones que verifican alguna condición. Por ejemplo:
```
#include <iostream>

bool sonIguales(int x, int y)
{
    return x == y; 
    // el operador `==` devuelve `true` si `x` y `y` son 
    //iguales, `false` en otro caso
}

int main()
{
    std::cout << "Dame un entero: ";
    int x{};
    std::cin >> x;

    std::cout << "Dame otro entero: ";
    int y{};
    std::cin >> y;

    std::cout << std::boolalpha; 
    // `std::boolalpha` manipula a `std::cout` para que imprima
    // 'true' o 'false' en vez de '1' ó '0'
    // para apagar `std::boolalpha` (en caso de que más adelante
    // en el código querramos volver a imprimir 0s y 1s) usamos
    // `std::noboolalpha`

    std::cout << x << " y " << y << " ¿son iguales? ";
    
    std::cout << sonIguales(x, y) << '\n'; 
    // devolverá `true` o `false`

    return 0;
}
```

Aunque toma un poco de tiempo acostumbrarse a los valores booleanos, son bastante útiles ya que son una parte crucial en el mundo de la programación (recordemos que las computadoras 'piensan' en 0s y 1s). La razón por la que los introdujimos ahora, es que nuestro primer contacto directo con ellos será con la **declaración `if`**, cuyo uso es la estructura básica de una condicional.
