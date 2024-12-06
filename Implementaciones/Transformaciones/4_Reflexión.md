Sea $L$ una recta que pasa por el origen. La reflexión del plano $xy$ con respecto a $L$ es una transformación lineal, llamémosle $T$.

Los puntos $(x,y)$ sobre $L$ cumplen con ser de la forma $(x,y)=(x,mx)$ donde $m$ es la pendiente de la recta.

$L$ es parametrizada por:

![image](https://github.com/user-attachments/assets/89a86474-b793-4367-a695-8d8e31515bdf)

con $t \in \mathbb{R}$. 

La recta ortogonal a $L$, llamémosle $L'$, es parametrizada por:

![image](https://github.com/user-attachments/assets/c428e7aa-3ef3-4781-b023-73bce80cdc5f)

con $r \in \mathbb{R}$.

Si reflejamos el plano respecto a $L$, $L$ debe quedarse fija y los puntos en $L'$ son de la misma forma, sólo que multiplicados por $-1$.

De este modo, los puntos de $T(L')$ son de la forma:

![image](https://github.com/user-attachments/assets/a10ceb6c-82ca-434e-9424-0f84a3d447aa)

De este modo, la matriz de transformación $A$ que estamos buscando debe cumplir simultáneamente que:

![image](https://github.com/user-attachments/assets/4c33bc09-9b22-4f7a-8104-dc35c2e39a4c)

y

![image](https://github.com/user-attachments/assets/d1332ca8-9cda-4699-b670-6d35d87b1883)

O sea:

![image](https://github.com/user-attachments/assets/7325b5ad-5ef0-44ce-848b-149656f0d465)


Multiplicando a la derecha de ambos lados de la ecuación por la matriz inversa y factorizando $\frac{1}{1+m^2}$...

![image](https://github.com/user-attachments/assets/aa06688c-1fa7-49c5-98a3-f1024e057cd4)

Dada la pendiente de una recta que pasa por el origen, el siguiente programa nos da la matriz asociada a la transformación lineal que refleja al plano con respecto a dicha recta:
```c++
#include <iostream>
#include <vector>
#include <cmath> // Para la función `pow()`


void rellenarMatriz(std::vector<std::vector<double>>& matriz, double& pendiente, double& constante){
    
    matriz[0][0] = constante *(1-pow(pendiente, 2));
    matriz[0][1] = constante *(2*pendiente);
    matriz[1][0] = constante *(2*pendiente);
    matriz[1][1] = constante * (pow(pendiente, 2)-1);
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

int main()
{
    // Le pedimos al usuario la pendiente de su recta que pasa por el origen:
    double pendiente{};
    std::cout << "Da la pendiente de la recta: ";
    std::cin >> pendiente;

    std::vector<std::vector<double>> matriz(2, std::vector<double>(2)); 
    // Crea una matriz de 2x2 (rellena de puros ceros)

    // `constante` = 1/(1+m^2)
    double constante{1/(1+pow(pendiente, 2))}; // La función `pow(número, potencia)` nos ayuda
                                               // a elevar un `número` a una `potencia`.

    // Rellenamos a la matriz:
    rellenarMatriz(matriz, pendiente, constante);

    // Mostramos la matriz:
    std::cout << "La matriz asociada a la transformación es:\n";
    mostrarMatriz(matriz);    

    return 0;
}
```
En terminal imprime algo del estilo:
```
Da la pendiente de la recta: 0.5
La matriz asociada a la transformación es:
0.6 0.8
0.8 -0.6
```
