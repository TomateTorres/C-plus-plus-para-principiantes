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

		else {
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

## Generación de números aleatorios en un intervalo $[a,b]$:

```c++
/*
El siguiente programa le pide al usuario los límites de un intervalo de la forma [a,b] 
y una cantidad `n` de números a generar.
*/

#include <iostream>
#include <random>
#include <iomanip> // Para formatear la salida

int main()
{
	std::random_device rd{};
	
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; 
	// Generamos 8 enteros aleatorios usando `std::random_device` y los usamos para
	// generar nuestra semilla.
	
	std::mt19937 mt{ ss }; // Inicializamos nuestro Mersenne Twister con la semilla
	                       // generada usando `std::seed_seq`

	// Solicitamos al usuario los límites del intervalo:
	double a{};
	double b{};
	std::cout << "\n*** Generador de números aleatorios ***\n";
	std::cout << "Introduce el límite inferior del intervalo: ";
	std::cin >> a;
	std::cout << "Introduce el límite superior del intervalo: ";
	std::cin >> b;

	// Validamos que el intervalo esté bien dado (que a < b):
	while (a >= b){
		std::cout << "El límite inferior debe ser menor que el superior.\n";
		std::cout << "Introduce el límite inferior del intervalo: ";
		std::cin >> a;
		std::cout << "Introduce el límite superior del intervalo: ";
		std::cin >> b;
	}

	// Solicitamos al usuario que de la cantidad de números a generar:
	int n{};
	std::cout << "¿Cuántos números aleatorios deseas generar? ";
	std::cin >> n;

	/*
	Crea un generador de números aleatorios (reusable) de `a` a `b` con probabilidad
	uniforme. 
	Cambiamos `std::uniform_int_distribution` por `std::uniform_real_distribution`
	para poder generar números que no sólo sean enteros.
	*/ 
	std::uniform_real_distribution generarNumAleatorio(a,b); 

	// Generamos y mostramos los números aleatorios:
	std::cout << "\nNúmeros generados:\n";
	for (int contador{ 1 }; contador <= n; ++contador)
	{
		double numAleatorio{generarNumAleatorio(mt)}; // Se genera un aleatorio.

		// Imprimimos el número con salida formateada:
		std::cout << std::fixed << std::setprecision(4) << std::setw(10) << numAleatorio;
		/*
		1. `std::fixed`: Garantiza que los números se impriman en formato fijo (sin notación 
		   científica).
		2. `std::setprecision(4)`: Limita la salida a 4 decimales.
		3. `std::setw(10)`: Establece un ancho fijo de 10 caracteres para cada número, lo que 
		   alinea la salida en columnas.
		*/
		
		// Salto de línea cada 5 resultados.
		if (contador % 5 == 0){
			std::cout << '\n';}
	}

	return 0;
}
```

En consola se imprimen cosas del estilo:
```
*** Generador de números aleatorios ***
Introduce el límite inferior del intervalo: 0
Introduce el límite superior del intervalo: 1
¿Cuántos números aleatorios deseas generar? 10

Números generados:
    0.3621    0.0966    0.4606    0.6744    0.3282
    0.6583    0.1510    0.3539    0.2304    0.4550
```
