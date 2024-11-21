Un **cizallamiento** es una transformación lineal que desplaza cada punto en una dirección fija, en una cantidad proporcional a su distancia orientada desde la línea que es paralela a esa dirección y pasa por el origen.

En el plano $xy$ un **cizallamiento horizontal** (o **cizallamiento paralelo al eje-x**) es una función que toma un punto genérico de la forma $(x,y)$ y lo manda al punto $(x+my, y)$ donde $m$ es un parámetro fijo llamado **factor de cizallamiento**.

Cada punto es desplazado horizontalmente en una cantidad proporcional a su coordenada $y$. Si $m>0$, cualquier punto por encima del eje-x se desplaza hacia la derecha, y, si $m<0$, se dirige hacia la izquierda (si $m=0$ entonces no estamos haciendo nada). Puntos debajo del eje-x se mueven en la dirección opuesta y los puntos en el eje se mantienen fijos.

Un cizallamiento horizontal $(x, y) \mapsto (x+my, y)$ tiene por matriz asociada a:

![image](https://github.com/user-attachments/assets/93c76c4e-1595-4a45-8c99-d4442166b7aa)

Un **cizallamiento vertical** (o **cizallamiento paralelo al eje-y**) es similar. Este cizallamiento desplaza puntos a la derecha del eje vertical hacia arriba o hacia abajo, según el signo de $m$. Deja invariantes las líneas verticales, pero inclina todas las demás líneas sobre el punto donde se encuentran con el eje vertical.

Un cizallamiento horizontal $(x, y) \mapsto (x, mx+y)$ tiene por matriz asociada a:

![image](https://github.com/user-attachments/assets/9ac33d02-6b81-44fb-80bf-cc869589bdfc)

El siguiente programa le permite al usuario dar $m$ y $m'$ factores de cizallamiento horizontal y vertical (respectivamente) y ayuda a calcular a dónde son enviados un cierto conjunto de puntos.
```c++
#include <iostream>
#include <vector>

// Aplica el cizallamiento dado por el usuario a un conjunto de puntos
// (que es un "vector de vectores" puesto que cada punto es por sí mismo
// un vector).
void cizallamiento(std::vector<std::vector<double>>& puntos, double factorX, double factorY)
{
    for (auto& punto: puntos){
        // `punto[0]` es la coordenada `x`, `punto[1]` es la coordenada
        // `y`
        double nuevoX{punto[0] + factorX * punto[1]};
        double nuevoY{factorY * punto[0] + punto[1]};
        
        // Cambiamos las coordenadas:
        punto[0] = nuevoX;
        punto[1] = nuevoY;
    }
}

int main()
{
    // Lista de puntos (cada punto es un vector de 2 elementos: {x, y}):
    std::vector<std::vector<double>> puntos {{1, 1}, {2, 1}, {2, 2}, {1, 2}};

    // Le pedimos al usuario los factores de cizallamiento:
    double factorX{};
    std::cout << "Da el factor de cizallamiento horizontal: ";
    std::cin >> factorX;

    double factorY{};
    std::cout << "Da el factor de cizallamiento vertical: ";
    std::cin >> factorY;

    // Aplicamos la transformación a nuestro conjunto de puntos:
    cizallamiento(puntos, factorX, factorY);

    // Imprimimos nuestros puntos transformados:
    for (std::size_t i{0}; i<puntos.size(); ++i){
        std::cout << "Punto " << i+1 << ": (" << puntos[i][0] << ", " << puntos[i][1]
                  << ")\n";
    }

    return 0;
}
```
En terminal nos imprime cosas del estilo:
```
Da el factor de cizallamiento horizontal: 0.5
Da el factor de cizallamiento vertical: 0
Punto 1: (1.5, 1)
Punto 2: (2.5, 1)
Punto 3: (3, 2)
Punto 4: (2, 2)
```
