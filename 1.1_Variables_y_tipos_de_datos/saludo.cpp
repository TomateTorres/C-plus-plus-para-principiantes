/*
El siguiente programa saluda al usuario y le pide su nombre para
poder darle la bienvenida adecuadamente.
*/

#include <iostream> //Se incluye para usar cout y cin
#include <string> //Vamos a usar texto.
 
using namespace std; //Recordemos que esta línea la incluimos sí o sí.

int main()
{
    cout <<"Hola, ¡me llamo HAL 9000!" << endl;
    //El programa saluda al usuario.

    cout <<"¿Cuál es tu nombre?" << endl;
    //El programa le pide su nombre al usuario.

    string nombre_usuario; 
    //Definimos una variable de texto (string) que guardará el 
    //nombre del usuario.

    getline(cin, nombre_usuario);
    //Esta línea sirve para pedirle al programa que lea una línea 
    //completa de texto ingresada por el usuario desde la entrada estándar
    // (el teclado) y la guarde en la variable 'nombre_usuario'

    cout << "Hola "
        << nombre_usuario << ", me da mucho gusto conocerte." << endl;
    //El programa le da la bienvenida al usuario llamándolo por su nombre.

    return 0;
    //El programa ha terminado.
}
