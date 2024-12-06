La **proyección ortogonal** de un vector $\bar{x} \in \mathbb{R}^2$ sobre otro vector no nulo $\bar{v} \in \mathbb{R}^2$ es el vector $\bar{p} \in \mathbb{R}^2$ tal que:
1. Es un múltiplo escalar de $\bar{v}$ (es decir, $\bar{p}=k\bar{v}$ con $k \in \mathbb{R}$).
2. Es el vector más cercano a $\bar{x}$ en la línea recta que pasa por el origen y está en la dirección de $\bar{v}$.

El vector $\bar{p}$ se calcula mediante la siguiente fórmula:

![image](https://github.com/user-attachments/assets/48072663-fae5-4ab1-8bcb-f0709b6478b1)

Donde $\cdot$ representa el producto punto entre vectores.

Se puede demostrar que la proyección ortogonal definida de esta forma es una transformación lineal.

Así, $T:\mathbb{R}^2 \to \mathbb{R}^2$ dada por

![image](https://github.com/user-attachments/assets/a9169ccb-2c80-4e5b-8693-7b0830e8b1dd)

Es una transformación lineal y su matriz asociada es:

![image](https://github.com/user-attachments/assets/811ced8a-4a7a-44f5-8cd3-37fd73b7d445)

Donde $\bar{v}=(v_1, v_2)$

Dado un vector $\bar{v}=(v_1,v_2)$, el siguiente programa le pide al usuario las coordenadas de un vector $\bar{x}=(x_1,x_2)$ para proyectarlo en la recta definida por $\bar{v}$.

```c++
#include <iostream>
#include <vector>

// Función que calcula el vector p (el resultado de la proyección)
std::vector<double> vectorProyectado(const std::vector<std::vector<double>>& matriz, const std::vector<double>& vec) {
    std::vector<double> vectorP(2, 0.0); // Inicializamos un vector de tamaño 2 con ceros
    vectorP[0] = matriz[0][0] * vec[0] + matriz[0][1] * vec[1];
    vectorP[1] = matriz[1][0] * vec[0] + matriz[1][1] * vec[1];
    return vectorP;
}

// Función para calcular la matriz de proyección ortogonal
std::vector<std::vector<double>> calculaMatrizDeProyeccion(double v1, double v2) {
    double normaAlCuadrado = v1 * v1 + v2 * v2; // Norma al cuadrado del vector (v1, v2)
    return {
        { (v1 * v1) / normaAlCuadrado, (v1 * v2) / normaAlCuadrado },
        { (v2 * v1) / normaAlCuadrado, (v2 * v2) / normaAlCuadrado }
    };
}

int main() {
    // Vector que define la línea de proyección
    double v1 = 3, v2 = 4; // Dirección de la línea (por ejemplo, y = 4/3 x)

    // Vector que queremos proyectar:
    double x1{};
    double x2{};
    std::cout << "Introduce las coordenadas del vector (x1, x2)\n";
    std::cout << "La coordenada x1: ";
    std::cin >> x1;
    std::cout << "La coordenada x2: ";
    std::cin >> x2;

    // Representamos al vector x como un vector columna para poder hacer el producto con la matriz:
    std::vector<double> vectorX {x1, x2};

    // Calculamos la matriz de proyección
    std::vector<std::vector<double>> matrizDeProyeccion {calculaMatrizDeProyeccion(v1, v2)};

    // Calculamos la proyección usando la multiplicación matriz-vector
    std::vector<double> vectorP {vectorProyectado(matrizDeProyeccion, vectorX)};

    // Mostramos el resultado
    std::cout << "La proyección de (" << x1 << ", " << x2 << ") sobre la línea definida por ("
              << v1 << ", " << v2 << ") es: (" << vectorP[0] << ", " << vectorP[1] << ")" << '\n';

    return 0;
}
```
En terminal se imprime algo del estilo:
```
Introduce las coordenadas del vector (x1, x2)
La coordenada x1: 2
La coordenada x2: 3
La proyección de (2, 3) sobre la línea definida por (3, 4) es: (2.16, 2.88)
```
