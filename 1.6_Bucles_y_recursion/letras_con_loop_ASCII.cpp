/*
El siguiente programa imprime las letras del abecedario en inglés
de la 'a' a la 'z' (específicamente en minúsculas) junto con sus
códigos ASCII.
*/

#include <iostream>

int main(){

    char miLetra{'a'}; // Empezamos con la letra 'a'.
    while (miLetra <= 'z') // Terminamos en la 'z'
    {
        std::cout << miLetra << ' ' << static_cast<int>(miLetra)
                  << '\n';
        // Se imprime la letra en la que vamos, un espacio en 
        // blanco y el código ASCII que le corresponde a la letra
        // (para eso sirve el `static_cast<int>(miLetra)`)`

        ++miLetra; // Nos movemos a la siguiente letra.
    }
    

    return 0;
}
