/*
Para entender qué es una variable vamos a resolver el siguiente
problema: 
En el Seven se pueden comprar latas o botellas de Coca-Cola. 
Supongamos que puedes comprar un paquete de 6 latas de 335 ml. 
por el mismo precio que una botella de dos litros. Vamos a hacer
un progrma que nos ayude a decidir que conviene comprar.

Este ejemplo se puede consultar en el libro: 'C++ for everyone'
del autor Cay Horstmann. Págs. 30-37
*/

#include <iostream> 
/*
Por el momento, es importante agregar esta línea a todos los
programas que hagamos, ya que esta es la que nos permite que haya
input y/o output.
*/

using namespace std;
/*
Esta línea también se debe agregar a todos los programas que
hagamos; le dice al compilador que use el espacio de nombres
estándar ("standard namespace").
*/

int main() 
/*
Todo programa en C++ tiene una función 'main'.
Todo lo que esté dentro de '{}' son las declaraciones de la 
función. 
*/
{
    int latas_por_paquete = 6;
    /* 
    Definimos una variable llamada 'latas_por_paquete', esta 
    variable es del tipo 'int' (un número entero) y guarda el valor
    6. Hicimos esto porque sabemos que cada paquete contiene 6 latas
    de Coca-Cola.
    
    A partir de este momento, cuando el compilador vea el identificador
    'latas_por_paquete', sabrá que nos referimos a esta variable.

    Nótese que siempre que acabamos de dar una instrucción ponemos ';'
    */

    const double VOL_LATA = 0.355;
    /* 
    Definimos una variable llamada 'VOL_LATA', esta variable es del 
    tipo 'double' (un número decimal) y guarda el valor 0.355. Sabemos
    que una lata de Coca-Cola estándar tiene una capacidad de 0.355 
    litros; le agregamos el prefijo 'const' porque la capacidad de una
    lata es una cantidad fija y no se modificará.
    */

    double vol_total = latas_por_paquete * VOL_LATA;
    /*
    Definimos una variable llamada 'vol_total' dada por el producto
    de 'latas_por_paquete' con 'VOL_LATA', esta variable la declaramos
    del tipo 'double' (número decimal) porque una de las variables de 
    las que proviene es de este tipo.
    */

    cout << "Un paquete de 6 latas contiene "
        << vol_total << " litros." << endl;
    /*
    Para mostrar valores en la pantalla, usamos 'cout' y el operador
    '<<'.
    Podemos pedirle al programa que nos muestre más de un objeto,
    para ello debemos poner '<<' antes de cada uno.
    En las dos líneas de código anteriores:
        1.- [cout << "Un paquete de 6 latas contiene "] muestra el texto entre
        comillas
        2.- [<< vol_total] muesta en pantalla el valor que tenga 'vol_total'
        3.- [<< " litros."] muestra el texto entre comillas
        4.- [<< endl] le dice al programa que haga un salto de línea, si no lo
        pusiéramos y queremos imprimir más cosas en pantalla, estas se 
        imprimirían en la misma línea.
    */    
    
    const double VOL_BOTELLA = 2;
    /*
    Definimos una variable llamada 'VOL_BOTELLA', esta variable es del
    tipo 'double' (aunque también podríamos haberla dado como 'int') y 
    la pusimos como 'const' porque sabemos que la cantidad de líquido
    que tiene una botella de Coca-Cola es de 2 litros y esta cantidad
    es fija.
    */

    vol_total = vol_total + VOL_BOTELLA;
    /*
    El fin de esta línea es mostrar que podemos sumar variables y guardar
    el resultado en una variable que ya teníamos.
    La variable 'vol_total' ya estaba definida, era el volumen total de
    Coca-Cola en un paquete de 6 latas de 355 ml., si ahora nos preguntamos
    cuantos litros hay en un paquete de 6 latas más una botella de dos
    litros, basta con sumar lo que teníamos en 'vol_total' con el volumen
    en una botella de dos litros (que justo es 'VOL_BOTELLA').
    Para no tener que definir una nueva variable, podemos simplemente 
    guardar el resultado de esa suma en 'vol_total'.
    */

    cout << "Un paquete de 6 latas y una botella de dos litros contienen "
        << vol_total << " litros." << endl;
    /*
    Estas dos líneas siguen exactamente el mismo principio que las ya
    explicadas donde también aparecía 'cout'.
    */
    
    return 0;
    /*
    Esta línea tiene como único propósito decirle al programa que ha
    finalizado de manera exitosa.
    */

}


