Sean $V$ y $W$ dos [espacios vectoriales](https://es.wikipedia.org/wiki/Espacio_vectorial) sobre $\mathbb{R}$ y $T:V \to W$ una función.

Decimos que $T$ es una **transformación lineal** si para cualesquiera $\bar{u}$ y $\bar{v}$ en $V$ y $\alpha \in \mathbb{R}$ se cumplen:
1. $T(\bar{u}+\bar{v})=T(\bar{u})+T(\bar{v})$ y
2. $T(\alpha \cdot \bar{u})=\alpha \cdot T(\bar{u})$

Una [transformación lineal](https://www.youtube.com/watch?v=kYB8IZa5AuE) puede ser representada con una matriz. Para esta sección nos interesarán las transformaciones lineales entre los $\mathbb{R}^n$*s* (en concreto, aquellas entre espacios de dimensión 2).

Si $T:\mathbb{R}^n \to \mathbb{R}^m$ es una transformación lineal y $\bar{v}$ es un vector columna en $\mathbb{R}^n$, entonces: $T(x)=Ax$ para alguna matriz $A$ de tamaño $n \times m$. A la matriz $A$ le llamamos **matriz de transformación de $T$**.

Hacer uso de las matrices nos permite presentar a las transformaciones lineales en un formato consistente y adecuado para poder operar con ellas mediante el uso de la computadora (en particular facilita mucho la composición de transformaciones, porque éstas se pueden hacer mediante el producto de sus matrices).

Las transformaciones lineales no son las únicas que se pueden representar mediante el uso de matrices, otras transformaciones no necesariamente lineales (como la traslación, que es una transformación [afín](https://en.wikipedia.org/wiki/Affine_transformation)) también se pueden representar de esta forma. Si tenemos una transformación afín en $\mathbb{R}^n$, ésta puede ser representada como una transformación lineal en $\mathbb{R}^{n+1}$.

## Encontrar la matriz de una transformación lineal

Si $T:\mathbb{R}^n \to \mathbb{R}^m$ es una transformación lineal, su matriz de transformación $A$ se puede obtener transformando cada uno de los vectores de la [base canónica](https://es.wikipedia.org/wiki/Base_can%C3%B3nica) (en $\mathbb{R}^2$ esta es { $\bar{e}_1, \bar{e}_2$ } $=$ { $(1,0), (0,1)$ }) e insertando el resultado en las columnas correspondientes de la matriz.

O sea, $A=[T(\bar{e}_1)\quad T(\bar{e}_2) \quad...\quad T(\bar{e}_n)]$.

**Por ejemplo:** $T:\mathbb{R}^2 \to \mathbb{R}^2$ dada por $T(\bar{x})=2\bar{x}$ es una transformación lineal.

Su matriz de transformación $A$ es: 

![image](https://github.com/user-attachments/assets/c9d2111b-7be8-46ba-a4b5-b508280cbf9b)


Esto podemos hacerlo en C++:
```c++
#include <iostream>
#include <vector>

// Función que aplica T a un vector:
std::vector<double> transformacionT(const std::vector<double>& vector){
    std::vector<double> resultado(2); // Esperamos que se nos devuelva un vector en R2
    resultado[0] = 2*vector[0];
    resultado[1] = 2*vector[1];

    return resultado;
}

// Función que imprime la matriz:
void imprimeMatriz(const std::vector<std::vector<double>>& matrix) {
    for (const auto& fila : matrix) {
        for (const double& val : fila) {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }
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

    return 0;
}
```
El programa anterior imprime en consola:
```
Matriz de transformación A:
2 0
0 2
```
## Ejemplos en 2D:

Las transformaciones geométricas más comunes son aquellas que mantienen fijo al origen (propiedad que tienen las transformaciones lineales). Entre ellas destacan: la rotación, homotecia, el cizallamiento, la reflexión y proyección ortogonal. Si una transformación afín no es una traslación pura, mantiene algún punto fijo, y ese punto puede elegirse como origen para hacer que la transformación sea lineal. En dos dimensiones, las transformaciones lineales se pueden representar utilizando una matriz de transformación de $2 \times 2$.

### Rotación:

Sea $\theta$ un ángulo de rotación en sentido positivo (en contra de las manecillas del reloj) con respecto al origen. 

$T:\mathbb{R}^2 \to \mathbb{R}^2$ dada por $T\begin{pmatrix} x \\ y \end{pmatrix} = \begin{pmatrix} x\cos\theta-y\sin\theta \\ x\sin\theta+y\cos\theta \end{pmatrix}$ es la transformación lineal que rota al plano $\theta$ radianes en sentido positivo.

Su matriz de transformación es: $A = \begin{bmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{bmatrix}$.

Así, $T\begin{pmatrix} x \\ y \end{pmatrix} = \begin{bmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{bmatrix} \begin{pmatrix} x \\ y \end{pmatrix}$.

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
Y al vector $\begin{pmatrix} 1 \\ 1 \end{pmatrix}$ lo manda a:
```
( 1.41421  0  )
```
