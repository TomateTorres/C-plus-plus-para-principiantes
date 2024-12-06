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

Las transformaciones geométricas más comunes son aquellas que mantienen fijo al origen (propiedad que tienen las transformaciones lineales). Entre ellas destacan: la rotación, el estiramiento, cizallamiento, la reflexión y proyección ortogonal. En dos dimensiones, las transformaciones lineales se pueden representar utilizando una matriz de transformación de $2 \times 2$.
