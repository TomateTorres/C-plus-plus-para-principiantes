/*
El siguiente programa usa un ciclo `for` para imprimir todos los
números pares del 0 al 20
*/

#include <iostream>

int main(){
    for (int i{0}; i<=20; i+=2){
        std::cout << i << " ";
    }

    return 0;
}
