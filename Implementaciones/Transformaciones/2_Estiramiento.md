Un estiramiento en el plano $xy$ es una transformación lineal que alarga (o achica) todas las distancias en una dirección particular por un factor constante $k$ pero no afecta las distancias en la dirección perpendicular. Solamente consideraremos los estiramientos sobre el eje-x y el eje-y.

De este modo, si $T:\mathbb{R}^2 \to \mathbb{R}^2$ es un estiramiento, entonces $T$ es de la forma:

![image](https://github.com/user-attachments/assets/7b3eb9d1-e7a5-4941-9b74-030fbb98a872)

Y en este caso decimos que es un estiramiento por un factor $k$ en el eje-x.

o 

![image](https://github.com/user-attachments/assets/bd3f31f5-e313-4434-bfeb-8a81ca14be3d)

En este caso decimos que es un estiramiento por un factor $k$ en el eje-y.

Nótese que si $k>1$, entonces $T$ es propiamente un "estiramiento", si $k<1$, $T$ es una "compresión" (aunque igual le llamamos estiramiento) y si $k=1$ entonces $T$ es la transformación identidad (o sea, no estamos haciendo nada).

La matriz asociada con un estiramiento por un factor $k$ en el eje-x viene dada por:

![image](https://github.com/user-attachments/assets/ffa9498c-d793-4fd2-b8a6-e38d5f1ed7ab)

Similarmente, la matriz asociada con un estiramiento por un factor $k$ en el eje-y viene dada por:

![image](https://github.com/user-attachments/assets/8c9336d9-c17c-4edd-858f-530436d83369)

Sean dos estiramientos $T$ y $T'$ con factores $k$ y $k'$ respectivamente, su composición (obtenida mediante el producto de sus matrices asociadas) tiene por matriz asociada a:

![image](https://github.com/user-attachments/assets/0f6f5968-a4e6-46ba-82d6-c01a79d30609)

Si $k'=\frac{1}{k}$, entonces decimos que $L = T \circ T' $ es una **contracción.** Las contracciones son un tipo especial de transformaciones, puesto que no alteran el valor del área de la figura sobre la que se aplican.

El siguiente programa recibe las matrices asociadas de dos estiramientos (uno sobre el eje-x y otro sobre el eje-y), hace el producto entre ellas y nos dice si el resultado es una contracción o no.
```c++
#include <iostream>
#include <vector>
#include <string>

/*
Dado que en este programa, queremos comparar que dos factores de estiramiento (k y k')
sean inversos el uno del otro, o sea k'=1/k, es razonable esperar que el usuario de por
input fracciones (por ejemplo k=3 y k'=1/3). Para que nuestro programa pueda leer cosas 
del estilo '3/4' tenemos que hacer algunas cosas extras...
*/

// Función para convertir una entrada en formato "numerador/denominador" a `double`
double lectoraDeFracciones(const std::string& input) {
    // Recibe el input del usuario (`input`) y encuentra la posición del caracter `/`
    std::size_t slashPos {input.find('/')}; // Como `slashPos` es un índice, lo definimos
                                            // como el tipo que venimos usando para índices.

    // Si no se encuentra '/', asumimos que es un número normal
    if (slashPos == std::string::npos) { // En C++ `std::string::npos``es un valor especial 
                                         // de tipo `std::size_t` que se usa como indicador
                                         // de "no encontrado" cuando se utiliza en una
                                         // búsqueda en una cadena (`std::string`).
        return std::stod(input); // Convertimos directamente el input del usuario en un tipo
                                 // `double` (número con punto decimal). `std::stood` es una 
                                 // función de la biblioteca estándar de C++ que se utiliza 
                                 // para convertir un `std::string` (cadena de texto) en un
                                 // valor de tipo `double`. Su nombre proviene de "string to
                                 // double".
    }

    // Si sí se encuentra '/'...
    
    // Dividimos la cadena en dos partes: numerador y denominador
    std::string numeradorStr {input.substr(0, slashPos)};
    /*
    En el numerador va todo desde el inicio del input hasta lo que está antes de '/'.
    */

    std::string denominadorStr {input.substr(slashPos + 1)}; 
    /*
    En el denominador va todo lo que viene a partir del caracter que está después de '/'.
    */

    // Convertimos las partes a `double`:
    double numerador {std::stod(numeradorStr)};
    double denominador {std::stod(denominadorStr)};


    // Retornamos el resultado como la división de las partes
    return numerador / denominador;
}    


// Función para rellenar la matriz permitiéndole al usuario introducir los valores de cada
// posición:
void rellenarMatriz(std::vector<std::vector<double>>& matriz){
    std::size_t N{matriz.size()}; 
    
    std::cout << "\nIntroduce los valores para la matriz:\n";
    for (std::size_t i{0}; i < N; ++i){
        for (std::size_t j{0}; j<N; ++j){
            std::cout << "Elemento [" << i+1 << "][" << j+1 << "]: ";
            std::string input{}; // Aquí guardaremos el input del usuario como un string 
                                 // que le pasaremos a la función `lectoraDeFracciones`.
            std::cin >> input;
            matriz[i][j] = lectoraDeFracciones(input);
        }
    } 
}

// Función para mostrar la matriz:
void mostrarMatriz(const std::vector<std::vector<double>>& matriz) {
    for (const auto& fila : matriz) {
        for (const auto& elem : fila) {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }

}

// Función para calcular el producto de dos matrices:
std::vector<std::vector<double>> multiplicarMatrices(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& B) {

    std::size_t filasA{A.size()};
    std::size_t columnasA{A[0].size()};
    std::size_t columnasB{B[0].size()};

    // Crea la matriz resultante (igual es de 2x2):
    std::vector<std::vector<double>> matrizC(2, std::vector<double>(2));

    // Realiza el producto:
    for (std::size_t i{0}; i<filasA; ++i){
        for (std::size_t j{0}; j<columnasB; ++j){
            for (std::size_t k{0}; k<columnasA; ++k){
                matrizC[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return matrizC;
}

int main() { 
    
    // Creamos las matrices:
    std::vector<std::vector<double>> matrizA(2, std::vector<double>(2));
    std::vector<std::vector<double>> matrizB(2, std::vector<double>(2));

    // Rellenamos las matrices:
    std::cout << "\nPrimera matriz:";
    rellenarMatriz(matrizA);
    std::cout << "\nSegunda matriz:";
    rellenarMatriz(matrizB);

    // Mostramos las matrices:
    std::cout << "\nPrimera matriz:\n";
    mostrarMatriz(matrizA);
    std::cout << "\nSegunda matriz:\n";
    mostrarMatriz(matrizB);

    // Calculamos el producto:
    auto C{multiplicarMatrices(matrizA, matrizB)};

    // Mostramos el resultado:
    std::cout << "\nEl producto de las matrices es:\n";
    mostrarMatriz(C);

    // Verificamos si tenemos una contracción (para ello tiene que ocurrir que los valores 
    // en la diagonal sean uno el inverso del otro).

    double k {C[0][0]}; // `k` es el primer elemento de la primer columna de `C` (recordemos 
                        // que en C++ los vectores y matrices empiezan sus índices en 0).
    double kPrima {C[1][1]}; // `kPrima` es el segundo elemento de la segunda columna de `C`.

    if (k == 1/kPrima){
        std::cout << "\nTu transformación es una contracción ʕ·ᴥ·ʔ\n";
    }
    else{
        std::cout << "\nTu transformación no es una contracción ●︿●\n";
    }

    return 0;
}
```
En terminal nos imprime cosas del estilo:
```
Primera matriz:
Introduce los valores para la matriz:
Elemento [1][1]: 3
Elemento [1][2]: 0
Elemento [2][1]: 0
Elemento [2][2]: 1

Segunda matriz:
Introduce los valores para la matriz:
Elemento [1][1]: 1
Elemento [1][2]: 0
Elemento [2][1]: 0
Elemento [2][2]: 1/3

Primera matriz:
3 0
0 1

Segunda matriz:
1 0
0 0.333333

El producto de las matrices es:
3 0
0 0.333333

Tu transformación es una contracción ʕ·ᴥ·ʔ
```

