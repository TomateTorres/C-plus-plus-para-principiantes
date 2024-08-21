Consideremos el siguiente código:
```
#include <iostream>
int obtenValorDeUsuario()
{
 	std::cout << "Dame un entero: ";
	int input{};
	std::cin >> input;

	return input; // Devuelve el valor ingresado por el usuario.
}

int main()
{
    int num { obtenValorDeUsuario() };
    std::cout << "El sucesor de " << num << " es: " 
	          << num + 1 << '\n';

    return 0;
}
```
Este programa le pide al usuario un entero y nos devuelve su sucesor. ¿Qué pasaría si quisiéramos poner la línea de output (_'El sucesor de...'_) en su propia línea?

Un primer intento podría verse así:
```
#include <iostream>
int obtenValorDeUsuario()
{
 	std::cout << "Dame un entero: ";
	int input{};
	std::cin >> input;

	return input; // Devuelve el valor ingresado por el usuario.
}

// La siguiente función no compilará:
void imprimeSucesor()
{
    std::cout << "El sucesor de " << num << " es: " 
	          << num + 1 << '\n';

}

int main()
{
    int num { obtenValorDeUsuario() };

	imprimeSucesor(); // Aquí va a fallar la ejecución

    return 0;
}
```
La razón por la que este intento falló es que la función `imprimeSucesor()` no sabe quién es `num`. Podríamos intentar definir a la variable `num` dentro de la función `imprimeSucesor()`. Si hacemos esto, el programa sí va a compilar, pero no nos dará lo que queremos (de hecho, el output siempre será 'El sucesor de 0 es: 1'). Necesitamos alguna manera de pasarle la información de la variable `num` a la función `imprimeSucesor()` para que ésta pueda usar el valor y darnos el output que queremos.

## Parámetros de funciones y argumentos
Un _parámetro de una función_ es una variable utilizada en el encabezado de una función, este tipo de variable se inicializa con un valor provisto por el llamador de la función. 

Los parámetros de funciones van dentro de los paréntesis después del nombre de la función, si queremos usar dos o más parámetros tendremos que separarlos con comas.

Veamos como quedaría nuestro programa del entero sucesor, pero ahora escrito de una manera correcta:
```
#include <iostream>
int obtenValorDeUsuario()
{
 	std::cout << "Dame un entero: ";
	int input{};
	std::cin >> input;

	return input; // Devuelve el valor ingresado por el usuario.
}

void imprimeSucesor(int valor) // La función va a recibir un
							   // entero y hará cosas.
{
	std::cout << "El sucesor de " << valor << " es: " 
	          << valor + 1 << '\n';

}

int main()
{
	int num {obtenValorDeUsuario()};
	imprimeSucesor(num); 

    return 0;
}
```
Lo que está pasando es:
* Definimos una función que nos servirá para guardar el input del usuario (la función `obtenValorDeUsuario()`).
* En el ejecutable (de la línea `int main()` hasta el final del código) definimos a la variable `num` que inicializamos con lo obtenido del input del usuario.
* Llamos a la función `imprimeSucesor()` y la aplicamos a `num`. El argumento `num` es copiado en el parámetro `valor` (dentro de la función `imprimeSucesor()`) para que `imprimeSucesor()` use el valor del parámetro `valor` para imprimirnos en pantalla 'El sucesor de (nuestro número) es: (el número + 1)'.

Cuando una función es llamada, todos los parámetros de la función son creados como variables y el valor de cada argumento es copiado en el parámetro correspondiente. Este proceso se llama _paso por valor_. Los parámetros de una función que utilizan paso por valor son llamados _valores de parámetro_. Veamos un ejemplo:
```
#include <iostream>

void peso(double x) 
// Creamos a la función `peso()` que tiene único parámetro 
// x de tipo double (El peso de John Cena puede en algún 
// momento dejar de ser un número entero).

{
	std::cout << "El peso de John Cena en Newtons es: " 
              << x * 9.8 << '\n';
}

int main()
{
    peso(114); // El valor del argumento (114) es pasado por
               // `main()` al parámetro `x`.
	return 0;

}
```
El argumento (en el ejemplo anterior: 114) es esencialmente sólo un inicializador para el parámetro (en el ejemplo anterior: x).

### Podemos usar valores de retorno como argumentos
En el programa anterior, la variable `num` solamente nos sirve para transportar el input del usuario al argumento de la llamada a la función `imprimeSucesor()`.

Aunque lo anterior es una manera válida de resolver nuestro problema, podemos simplificarlo:
```
#include <iostream>
int obtenValorDeUsuario()
{
 	std::cout << "Dame un entero: ";
	int input{};
	std::cin >> input;

	return input; // Devuelve el valor ingresado por el usuario.
}

// La siguiente función no compilará:
void imprimeSucesor(int valor) // La función va a recibir un
							   // entero y hará cosas.
{
	std::cout << "El sucesor de " << valor << " es: " 
	          << valor + 1 << '\n';

}

int main()
{
	imprimeSucesor(obtenValorDeUsuario()); 
	// Llamamos a la función `imprimeSucesor()` y dentro de ella,
	// llamamos a la función `obtenValorDeUsuario()`.

    return 0;
}
```
Estamos usando el valor de retorno de `obtenValorDeUsuario()` como argumento de la función `imprimeSucesor()`.

Ambas soluciones (la primera presentada y esta 'compactación') son igual de válidas y correctas. Por el momento lo esperable es que hagamos programas sencillos, así que cuestiones como la eficiencia del código (en este contexto: usar la menor cantidad de variables posibles), no son muy importantes.

### Como los parámetros y valores de retorno trabajan juntos

Como ya vimos, los parámetros y valores de retorno pueden trabajar en conjunto ya que podemos crear funciones que reciben algún valor como input, hacen algún cálculo o manipulación con él y le devuelven al resultado al llamador, que puede ser la función `main()` u otra función dentro de ella (en el ejemplo anterior, `imprimeSucesor()` recibe el output de `obtenValorDeUsuario()`).

## Parámetros no-referenciados y parámetros sin nombre.

A veces podemos encontrarnos con funciones que tienen parámetros que no aparecen en el cuerpo de la función, a estos se les llama _parámetros no-referenciados_. Por ejemplo:
```
#include <iostream>
#include <string>

void oyeHazAlgo(std::string algo) //'algo' es un parámetro 
                                  //no-referenciado.

{
    //'algo' no aparece en el cuerpo de la función
}

int main()
{
    oyeHazAlgo("Hola");

    return 0;
}
```
Es probable que el compilador se queje porque hemos definido el parámetro `algo`, pero no lo hemos usado.

Darle nombre al parámetro de una función al definirla es opcional. De este modo, en casos donde el parámetro de una función debe existir, pero no es usado en el cuerpo de la función, se puede omitir ponerle nombre. Un parámetro sin nombre se llama _parámetro sin nombre_ (increíble, ¿no?). 

En el ejemplo anterior, si quitamos `algo` (lo más conveniente es dejarlo, pero como comentario) nuestro código compilará bien:
```
#include <iostream>
#include <string>

void oyeHazAlgo(std::string /*algo*/) //'algo' es un parámetro 
                                  //no-referenciado.

{
    //'algo' no aparece en el cuerpo de la función
}

int main()
{
    oyeHazAlgo("Hola");

    return 0;
}
```
Lo anterior puede parecer un sinsentido, _¿por qué definiríamos una función con un parámetro que no vamos a usar?_ 💀. Puede haber varias razones, pero si pensamos en un proyecto grande podría suceder que: Tenemos una función con un cierto parámetro y la función es modificada de algún modo en que el valor del parámetro ya no es necesario. Podríamos borrarlo de la definición de la función, pero si hacemos eso tendríamos un problema porque en cada instancia donde llamamos a la función, tendríamos más parámetros de los que la función recibe. Entonces tendríamos que modificar cada instancia donde la función es llamada, pero si nuestro código es muy largo (o peor aún, cuenta de múltiples programas que trabajan juntos) esto podría ser muy difícil. Así que lo más conveniente es dejar el parámetro ahí, pero dejarlo como comentario para que no haga nada.

## Otros ejemplos:
* El programa _funcion_producto.cpp_ contiene un ejemplo de una función que le pide dos números al usuario y le da como resultado el producto entre ellos.
* El programa _john_cena_y_roca.cpp_ contiene un ejemplo de una función que recibe más de un argumento donde inicializamos dos variables que utilizan _paso por valor_.
