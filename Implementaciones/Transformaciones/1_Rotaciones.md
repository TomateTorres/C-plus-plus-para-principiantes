Sea $\theta$ un ángulo de rotación en sentido positivo (en contra de las manecillas del reloj) con respecto al origen. 

$T:\mathbb{R}^2 \to \mathbb{R}^2$ dada por 

![image](https://github.com/user-attachments/assets/e0470570-1be6-4438-8415-e2960679e18f)

es la transformación lineal que rota al plano $\theta$ radianes en sentido positivo.

Su matriz de transformación es: 

![image](https://github.com/user-attachments/assets/d3226a29-bdb8-49e4-957a-19baf9de2e6e)


Así:

![image](https://github.com/user-attachments/assets/1d5bb7d6-b098-433f-9220-e81cd26956ce)


Si consideramos $\theta = \frac{\pi}{4}$:
```c++
#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES // Esta línea nos permite usar constantes matemáticas como 
                          // M_PI (una aproximación de pi). Debe ir antes de <cmath>
#include <cmath> // Para seno y coseno.




// Consideremos theta == pi/4
double theta{M_PI/4};

// Función que aplica T a un vector:
std::vector<double> transformacionT(const std::vector<double>& vector){
    std::vector<double> resultado(2); // Esperamos que se nos devuelva un vector en R2
    resultado[0] = vector[0]*cos(theta)-vector[1]*sin(theta);
    resultado[1] = vector[0]*sin(theta)+vector[1]*cos(theta);

    return resultado;
}

// Función que imprime la matriz:
void imprimeMatriz(const std::vector<std::vector<double>>& matrix) {
    for (const auto& fila : matrix) {
        for (const double& val : fila) {
            std::cout << val << "  ";
        }
        std::cout << '\n';
    }
}

// Función para mostrar un vector:
void mostrarVector(const std::vector<double>& vec) {
    std::cout << "( ";
    for (double elem : vec) {
        std::cout << elem << "  ";
    }
    std::cout << ")\n";
}

// Función para calcular el producto de ua matriz y un vector:
std::vector<double> multiplicarMatrizYvector(
    const std::vector<std::vector<double>>& A,
    const std::vector<double>& vector) {

    std::size_t filasA{A.size()};
    std::size_t columnasA{A[0].size()};

    // Crea el vector resultante (del mismo tamaño que el vector original):
    std::vector<double> vectorTransformado(vector.size());

    // Realiza el producto:
    for (std::size_t i{0}; i<filasA; ++i){
        for (std::size_t j{0}; j<columnasA; ++j){
            vectorTransformado[i] += A[i][j] * vector[j];            
        }
    }
    return vectorTransformado;
}

int main() {
    // Vectores base estándar
    std::vector<double> e1 {1, 0}; // Primer vector base
    std::vector<double> e2 {0, 1}; // Segundo vector base

    // Aplicamos la transformación T a los vectores base
    std::vector<double> T_e1 {transformacionT(e1)};
    std::vector<double> T_e2 {transformacionT(e2)};

    // Construimos la matriz de transformación (recordemos que una matriz es un "vector de 
    // vectores").
    std::vector<std::vector<double>> A {T_e1, T_e2};

    // Imprimimos la matriz de transformación
    std::cout << "Matriz de transformación A:" << '\n';
    imprimeMatriz(A);

    // Le pedimos al usuario un vector al que quiera aplicarle la transformación:
    std::vector<double> vector(2); // Nuestro vector es de dos dimensiones.
    std::cout << "Da la primer entrada de tu vector: ";
    std::cin >> vector[0];
    std::cout << "Da la segunda entrada de tu vector: ";
    std::cin >> vector[1];

    // Imprimimos el vector resultante:
    auto vectorTransformado {multiplicarMatrizYvector(A, vector)};
    mostrarVector(vectorTransformado);

    return 0;
}
```
La matriz de transformación es:
```
0.707107  0.707107  
-0.707107  0.707107  
```
Y al vector $(1,1)$ lo manda a:
```
( 1.41421  0  )
```
