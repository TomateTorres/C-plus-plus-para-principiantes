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



## Otros ejemplos:
* El programa _funcion_producto.cpp_ contiene un ejemplo de de una función que le pide dos números al usuario y le da como resultado el producto entre ellos.
