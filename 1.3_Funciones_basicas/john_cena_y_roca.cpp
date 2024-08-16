/*
El siguiente programa es una modificación a uno de los ejemplos
del archivo '2_Intro_a_parámetros_de_funciones_y_argumentos.md'.
Este ejemplo tiene el fin de mostrar una función que recibe más
de un argumento donde inicializamos dos variables que utilizan
'paso por valor'.
*/

#include <iostream>

void peso(double x, double y) 
// Creamos a la función `peso()` que tiene dos parámetros 
// 'x' y 'y' de tipo double (El peso de John Cena o de la Roca
// puede en algún momento dejar de ser un número entero).

{
	std::cout << "El peso de John Cena en Newtons es: " 
              << x * 9.8 << '\n';
    std::cout << "El peso de la Roca en Newtons es: "
              << y * 9.8 << '\n';          
}

int main()
{
    peso(114, 118); 
	return 0;

}
