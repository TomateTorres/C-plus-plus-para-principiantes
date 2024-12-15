En la entrada anterior, ya vimos cómo podemos simular el [lanzamiento de un dado](../Numeros_aleatorios/1_Mersenne_Twister.md) usando Mersenne Twister.

A continuación van otro par de aplicaciones útiles haciendo uso de este PRNG:

## Lanzar una moneda:

![fear-and-hunger-coin-flip](https://github.com/user-attachments/assets/8133713d-8c1b-48dc-868d-cee77119c58e)

```c++
/*
El siguiente programa le pide al usuario una cantidad N de lanzamientos.
Imprime los resultados de cada lanzamiento, alineándose en filas de 10
resultados y al final calcula y muestra la proporción de águilas y soles en 
porcentaje, junto con el número total de cada resultado.
*/

#include <iostream>
#include <random>
#include <iomanip> // Para formato de decimales

int main()
{
	std::random_device rd{};
	
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; 
	// Generamos 8 enteros aleatorios usando `std::random_device` y los usamos para
	// generar nuestra semilla.
	
	std::mt19937 mt{ ss }; // Inicializamos nuestro Mersenne Twister con la semilla
	                       // generada usando `std::seed_seq`

	// Crea un generador de números aleatorios (reusable) del 0 al 1 con
	// probabilidad uniforme (0 = águila y 1 = sol)
	std::uniform_int_distribution lanzarMoneda{ 0, 1 }; 

	// Solicitamos al usuario la cantidad de lanzamientos (`n`):
	std::cout << "\n*** Simulador de lanzamientos de moneda ***\n";
	std::cout << "Introduce la cantidad de lanzamientos: ";
	int n{};
	std::cin >> n;

	int contadorAguila{};
	int contadorSol{};

	// Imprimimos los resultados de los lanzamientos:
	std::cout << "\nResultados de los lanzamientos:\n";

	// Tiramos la moneda `n` veces.
	for (int contador{ 1 }; contador <= n; ++contador)
	{
		int resultadoDelLanzamiento{lanzarMoneda(mt)}; // Se lanza la moneda una vez.
		
		if (resultadoDelLanzamiento == 0){
			std::cout << "Águila\t";
			++contadorAguila;
		}

		if (resultadoDelLanzamiento == 1){
			std::cout << "Sol\t";
			++contadorSol;
		}

		// Salto de línea cada 10 resultados.
		if (contador % 10 == 0){
			std::cout << '\n';}
	}

	// Calculamos las proporciones:
	double proporcionAguila{static_cast<double>(contadorAguila)/n};
	double proporcionSol{static_cast<double>(contadorSol)/n};

	// Mostramos el resumen:
	std::cout << "\n\n*** Resumen ***\n";
	std::cout << "Total de águilas: " << contadorAguila << " (" << std::fixed 
	          << std::setprecision(2) << proporcionAguila * 100 << "%)\n";
	std::cout << "Total de soles: " << contadorSol << " (" << std::fixed 
	          << std::setprecision(2) << proporcionSol * 100 << "%)\n";
	/*
	`std::fixed << std::setprecision(2)` sirve para contolar cómo se imprimen los números
	de punto decimal:
	1. `std::fixed`: Indica que los números decimales deben imprimirse en formato fijo (es
	   decir, sin notación científica). Esto asegura que los valores como 0.1234 se impriman
	   como 0.12 en lugar de 1.23e-1.
	2. `std::setprecision(2)`: Configura la precisión de los decimales en la salida, en este
	   caso, dos lugares después del punto decimal. Por ejemplo: 0.1234 se imprimirá como 0.12
	*/

	return 0;
}
```

Con 40 lanzamientos, se imprime en consola algo como:
```
*** Simulador de lanzamientos de moneda ***
Introduce la cantidad de lanzamientos: 40

Resultados de los lanzamientos:
Águila  Águila  Águila  Águila  Águila  Sol     Sol     Sol     Sol     Águila
Sol     Sol     Sol     Sol     Sol     Sol     Águila  Sol     Sol     Águila
Sol     Águila  Sol     Águila  Águila  Sol     Sol     Sol     Sol     Sol
Sol     Águila  Sol     Sol     Sol     Águila  Águila  Águila  Sol     Águila


*** Resumen ***
Total de águilas: 16 (40.00%)
Total de soles: 24 (60.00%)
```

Conforme $n \to ∞$, tendremos proporciones más cercanas a la esperada (50/50).
