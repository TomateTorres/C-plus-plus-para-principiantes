La biblioteca `random` admite dos tipos de Mersenne Twister:
* `mt19937` es un Mersenne Twister que genera enteros sin signo de 32-bits.
* `mt19937_64` es un Mersenne Twister que genera enteros sin signo de 64-bits.

Para efectos prácticos, el que Mersenne Twister genere enteros sin signo quiere decir que los números generados son enteros no negativos: todo el espacio de bits disponibles se utiliza para representar valores positivos, sin reservar un bit para el signo (positivo o negativo). Si estamos usando `mt19937` los enteros generados son de tipo `unsigned int` y si estamos usando `mt19937_64` son de tipo `unsigned long long`.

Usar Mersenne Twister es sencillo:
```c++
#include <iostream>
#include <random> // Para `std::mt19937`

int main()
{
	std::mt19937 mt{}; // Inicializa un Mersenne Twister de 32-bits

	// Se imprimen 40 números pseudo-aleatorios
	for (int contador{ 1 }; contador <= 40; ++contador)
	{
		std::cout << mt() << '\t'; // Se genera un número aleatorio.

		// Si ya se imprimieron 5 números, hacemos salto de línea.
		if (contador % 5 == 0){
			std::cout << '\n';}
	}

	return 0;
}
```

En consola se imprime algo como:
```
3499211612      581869302       3890346734      3586334585      545404204
4161255391      3922919429      949333985       2715962298      1323567403
418932835       2350294565      1196140740      809094426       2348838239
4264392720      4112460519      4279768804      4144164697      4156218106
676943009       3117454609      4168664243      4213834039      4111000746
471852626       2084672536      3427838553      3437178460      1275731771
609397212       20544909        1811450929      483031418       3933054126
2747762695      3402504553      3772830893      4120988587      2163214728
```

Utilizamos el encabezado `<random>` puesto que ahí "vive" Mersenne Twister, luego mediante `std::mt19937 mt{};` inicializamos un Mersenne Twister de 32-bits y llamamos `mt()` cada vez que queramos generar un entero sin signo aleatorio de 32-bits (en total, esto último se hizo 40 veces).

`mt()` **no** es una variable (a diferencia de `mt` en la declaración `std::mt19937 mt{};`), es una sintaxis concisa de la función `mt.operator()` que sirve para generar el siguiente número en la secuencia dado un PRNG.

## Lanzar un dado usando Mersenne Twister

Si usamos `std::mt19937`, estamos inicializando un Mersenne Twister de 32-bits. Esto quiere decir que la secuencia de números puede tomar valores entre $0$ y $2^{32}-1=4,294,967,295$.

Como los PRNGs sólo pueden generar números que usen el rango completo (es decir, no hay manera de que por sí solos nos generen valores en un intervalo más pequeño), si queremos usarlos en aplicaciones donde se requiera la generación de aleatorios en un rango menor, lo que necesitamos hacer es encontrar la manera de convertir los números en el output de nuestro PRNG a valores dentro del rango más pequeño.

Por el momento, supongamos que este *rango más pequeño* son los enteros del 1 al 6 porque queremos simular el lanzamiento de un dado.

Una forma básica de hacer la conversión del rango $0$ a $2^{32}-1=4,294,967,295$ al rango $1$ a $6$ sería usando el **módulo** (`%`):
```c++
int numero_en_rango {(numero_grande % 6) + 1};
```

Esto divide el número grande entre 6 y toma el residuo, asegurando que el resultado esté entre 0 y 5, y luego le sumamos 1 para ajustarlo al rango 1-6.

Pero hacer esto podría ser algo complicado (sin mencionar que es ineficiente), y podría introducir sesgos si no tenemos cuidado.

Aquí es donde las **distribuciones de números aleatorios** de la biblioteca `random` entran al rescate. Estas distribuciones se encargan de transformar automáticamente los números grandes generados por el PRNG en valores dentro del rango que nosotros elijamos.

Una **distribución de números aleatorios** es una regla o modelo que describe cómo deben generarse los números aleatorios para que sigan un patrón específico. En términos simples, una **distribución** decide qué números tienen más probabilidad de aparecer y cómo están distribuidos esos números en un intervalo.

En el caso de un dado justo, todos los números tienen la misma probabilidad de aparecer: $\frac{1}{6}$. Esto sería una **distribución uniforme**: los números están distribuidos de manera equitativa. Por otro lado, si estamos jugando un juego donde ciertos números tienen más probabilidad de aparecer (por ejemplo: si nuestro dado está trucado y hay una cara que sale con mucha más frecuencia), entonces los números ya no tienen la misma probabilidad de aparecer, y tendríamos una distribución diferente.

La biblioteca `random` tiene muchas distribuciones de números aleatorios, la más útil (a reserva de que se esté haciendo algún análisis estadístico o algo más sofisticado) es la **distribución uniforme** que dado un intervalo $(a,b)$ (puede ser abierto o cerrado) retorna números dentro de él con igual probabilidad.

El siguiente programa simula el lanzamiento de un dado justo de 6 caras usando distribución uniforme:
```c++
#include <iostream>
#include <random> // Para `std::mt19937` y `std::uniform_int_distribution`

int main()
{
	std::mt19937 mt{}; // Inicializa el Mersenne Twister de 32-bits.

	// Crea un generador de números aleatorios (reusable) del 1 al 6 con
	// probabilidad uniforme.
	std::uniform_int_distribution dado6Caras{ 1, 6 };

	// Imprime 40 números aleatorios del 1 al 6.
	for (int contador{ 1 }; contador <= 40; ++contador)
	{
		std::cout << dado6Caras(mt) << '\t'; // Se lanza el dado.

		// Si ya imprimimos 10 números, hacemos un salto de línea.
		if (contador % 10 == 0)
			std::cout << '\n';
	}

	return 0;
}
```
En consola se imprime algo como:
```
5       1       6       6       1       6       6       2       4       2
1       4       2       2       4       6       6       6       6       6
1       5       6       6       6       1       3       5       5       2
1       1       3       1       6       4       5       6       6       4
```

Sin importar cuántas veces se corra el programa anterior (o el que vino antes de ése), la secuencia de números generada **siempre es la misma**. Esto pasa porque, como no proporcionamos una semilla, el sistema utiliza una por default (que muy probablemente es 0); como la semilla utilizada siempre es la misma, la secuencia de números generados siempre es la misma también.

Para garantizar que la secuencia de números generados sí cambie cada vez que corremos el programa, necesitamos elegir una semilla que no sea un número fijo. Hay dos métodos comúnmente usados para esto:
* Usar la hora del sistema
* Usar el dispositivo aleatorio (*random device*) del sistema

## Sembrar usando el reloj del sistema

A menos que corramos un programa dos (o más) veces *exactamente* al mismo tiempo, la hora del día a la que es corrido va a ser distinta. 

Mucho código existente utiliza la función `std::time()` para fijar semillas para PRNGs usando la hora del sistema. La librería `<chrono>` de C++ cuenta con varios relojes que podemos usar para generar una semilla. Para minimizar la probabilidad de que dos valores de tiempo sean idénticos si corremos el programa dos (o más) veces en sucesión rápida, lo ideal es utilizar una medida de tiempo que cambie lo más rápido posible. Para ello, podemos preguntarle al reloj qué tanto tiempo ha pasado desde el primer momento que puede medir. Este tiempo se mide en **"ticks"**, que es una unidad muy pequeña de tiempo (suelen ser nanosegundos, pero pueden ser milisegundos):
```c++
#include <iostream>
#include <random> // Para `std::mt19937` y `std::uniform_int_distribution`
#include <chrono> // Para `std::chrono`

int main()
{
	// Inicializa el Mersenne Twister de 32-bits sembrado con `steady_clock`
	std::mt19937 mt{static_cast<std::mt19937::result_type>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		)}; 

	// Crea un generador de números aleatorios (reusable) del 1 al 6 con
	// probabilidad uniforme.
	std::uniform_int_distribution dado6Caras{ 1, 6 };

	// Imprime 40 números aleatorios del 1 al 6.
	for (int contador{ 1 }; contador <= 40; ++contador)
	{
		std::cout << dado6Caras(mt) << '\t'; // Se lanza el dado.

		// Si ya imprimimos 10 números, hacemos un salto de línea.
		if (contador % 10 == 0)
			std::cout << '\n';
	}

	return 0;
}
```
Este programa sólo tiene dos cambios respecto a su versión anterior:
1. Incluimos la biblioteca `chrono` para acceder el reloj.
2. Usamos el tiempo en la hora del sistema como semilla para nuestro Mersenne Twister.

Con los cambios anteriores, ahora el programa sí genera una secuencia diferente cada vez que lo corremos.

La desventaja de este enfoque es que si corremos el programa múltiples veces en sucesión rápida, las semillas generadas para cada ejecución no son muy diferentes (probablemente sólo difieran en la parte que corresponde a los segundos), lo que puede impactar la calidad de los resultados aleatorios desde un punto de vista estadístico. Para programas normales, esto no importa, pero para programas que requieran resultados independientes de alta calidad, este método de sembrado puede ser ineficiente.

Una elección popular en vez de `std::chrono::steady_clock` es `std::chrono::high_resolution_clock`. `std::chrono::high_resolution_clock` es un reloj que usa una medida más granular de tiempo, pero puede usar la hora del sistema (que puede ser modificada por el usuario). `std::chrono::steady_clock` tiene ticks menos granulares, pero es el único reloj que tiene la garantía de no poder ser ajustado por el usuario.

## Sembrar usando random device

Un **random device** de un sistema es una herramienta o mecanismo que genera números verdaderamente aleatorios basándose en la entropía del entorno físico del hardware. Esto quiere decir que proporciona datos aleatorios obtenidos de fenómenos impredecibles en el hardware de un sistema. Estos datos suelen usarse para tareas que requieren alta seguridad o aleatoriedad verdadera, como criptografía o generación de claves seguras.

Algunas de las fuentes típicas de entropía en un sistema incluyen:
1. Ruido térmico en circuitos electrónicos (generado por fluctuaciones de voltaje).
2. Actividad del sistema operativo (movimientos del ratón, pulsaciones de teclado, etc.)
3. Ruido ambiental del hardware (algunos sistemas especializados usan sensores físicos para capturar ruido del entorno, como el ruido fotónico en sistemas ópticos).
4. Osciladores electrónicos (componente en un circuito que produce una señal periódica, como una onda).

La biblioteca `random` contiene un tipo llamado `std::random_device` que es un PRNG cuya implementación específica depende del compilador o de la biblioteca estándar del lenguaje que se esté usando. En otras palabras, el comportamiento exacto no está definido universalmente por el estándar del lenguaje, sino que lo decide el proveedor del compilador o la biblioteca.

Normalmente, es recomendable evitar cosas cuya implementación no dependa del estándar del lenguaje porque no suele haber garantías de calidad o portabilidad, sin embargo estamos ante una excepción a la regla.

Típicamente `std::random_device` le pide al sistema operativo (*OS* por sus siglas en inglés) un número pseudo-aleatorio (cómo lo hace, depende del OS):
```c++
#include <iostream>
#include <random> // Para `std::mt19937` y `std::random_device`

int main()
{
	// Inicializa el Mersenne Twister de 32-bits sembrado con `std::random_device`
	std::mt19937 mt{std::random_device{}()}; 

	// Crea un generador de números aleatorios (reusable) del 1 al 6 con
	// probabilidad uniforme.
	std::uniform_int_distribution dado6Caras{ 1, 6 };

	// Imprime 40 números aleatorios del 1 al 6.
	for (int contador{ 1 }; contador <= 40; ++contador)
	{
		std::cout << dado6Caras(mt) << '\t'; // Se lanza el dado.

		// Si ya imprimimos 10 números, hacemos un salto de línea.
		if (contador % 10 == 0)
			std::cout << '\n';
	}

	return 0;
}
```
En el programa anterior, estamos sembrando nuestro Mersenne Twister con un número aleatorio generado usando `std::random_device`. Cada vez que corremos el programa anterior, se produce una secuencia distinta.

Un problema potencial de usar `std::random_device` es que no es imperativo que sea no-determinista, lo que quiere decir que *podría* (en algunos sistemas) generar siempre la misma semilla (y en consecuencia provocar que el PRNG al que siembra produzca siempre la misma secuencia). Sin embargo, las versiones más recientes de prácticamente cualquier compilador, dan soporte a implementaciones adecuadas de `std::random_device`.

### Por qué no se debe sembrar un PRNG más de una vez:

Muchos PRNGs pueden ser resembrados (*reseeded*) después de la siembra inicial. Esto esencialmente re-inicializa el estado del generador de números aleatorios, provocando que genere resultados empezando por el nuevo estado dado por la nueva semilla.

Generalmente resembrar un PRNG no es una buena idea a menos que tengamos una razón específica para hacerlo ya que (entre otras razones):
1. Si se siembra un PRNG una vez, se obtendrá una secuencia de números "aparentemente aleatorios" que sigue evolucionando conforme se realizan llamadas sucesivas al generador. Si re-sembramos el PRNG, esta secuencia se reinicia, lo que interrumpe su flujo natural. Esto puede generar patrones repetitivos o resultados no deseados, especialmente si la nueva semilla es parecida a la anterior.
2. Con referencia al punto anterior, la semilla que se le proporciona al PRNG determina la secuencia que produce. Si re-siembras constantemente, dependes de que la fuente de entropía (aleatoriedad en las semillas) sea de alta calidad. Usar la hora del sistema garantiza semillas parecidas porque aún si esperamos "un buen rato" cada vez que corremos nuestro programa, hay partes de la semilla que se van a quedar fijas (la del año y el mes, por ejemplo), además de que en algunos sistemas `std::random_device` no es verdaderamente aleatorio, sino que genera valores basados en un contador, el tiempo del sistema, o un número limitado de estados internos. 
3. Re-sembrar un PRNG constantemente es computacionalmente costoso porque inicializar estructuras internas, lo cual puede ser mucho más lento que simplemente usar el estado ya existente del generador.

## Mersenne Twister y problemas de sub-siembra

El estado interno de Mersenne Twister contiene 624 valores enteros. Para `std::mt19937` (el que hemos estado usando) estos valores pueden tener un tamaño de 32 ó 64 bits. 

En los ejemplos anteriores donde sembramos con del reloj del sistema o `std::random_device`, nuestra semilla era un único valor. Esto quiere decir que esencialmente estamos inicializando 624 valores usando un solo valor, lo que significativamente *sub-siembra* a nuestro PRNG.

La **sub-siembra** ocurre cuando se siembra un PRNG con una semilla que no tiene suficiente aleatoriedad para garantizar que las secuencias generadas sean realmente impredecibles o diversas.

En el caso de nuestro Mersenne Twister sembrado con una semilla de un sólo valor, la biblioteca `random` hace lo mejor que puede para rellenar los 623 valores restantes con datos "aleatorios", pero tampoco puede hacer milagros. Sub-sembrar un PRNG puede generar resultados que son sub-óptimos en aplicaciones que necesitan resultados de alta calidad. Por ejemplo, sembrar `std::mt19937` con un único valor de 32-bits **nunca** va a generar el número 42 como primer output.

No hay una forma establecida para solucionar el problema de la sub-siembra (para Mersenne Twister u otro PRNG), pero aquí tenemos una opción:

### `std::seed_seq`

`std::seed_seq` es una herramienta del estándar de C++ que ayuda a mejorar la calidad de las semillas utilizadas en los PRNGs. Es especialmente útil para abordar el problema de la sub-siembra, ya que permite transformar una entrada inicial de baja entropía (por ejemplo, un conjunto pequeño de números) en un estado interno que maximiza la calidad de la semilla para el PRNG. 

En términos simples, `std::seed_seq` recibe una entrada que puede tener poca entropía (como unos pocos números o una lista corta) y utiliza un algoritmo de mezcla para distribuir la entropía de manera uniforme en todos los bits del estado  interno del PRNG. Esto significa que incluso si la entrada tiene poca aleatoriedad, la salida será más equilibrada.

La manera más sencilla de hacer uso de esta herramienta es usar `std::random_device` para proporcionarle varios valores a `std::seed_seq` (digamos 8) y así obtener una semilla que tenga más aleatoriedad:
```c++
#include <iostream>
#include <random>

int main()
{
	std::random_device rd{};
	
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; 
	// Generamos 8 enteros aleatorios usando `std::random_device` y los usamos para
	// generar nuestra semilla.
	
	std::mt19937 mt{ ss }; // Inicializamos nuestro Mersenne Twister con la semilla
	                       // generada usando `std::seed_seq`

	// Crea un generador de números aleatorios (reusable) del 1 al 6 con
	// probabilidad uniforme.
	std::uniform_int_distribution dado6Caras{ 1, 6 }; 

	// Tiramos el dado 40 veces
	for (int contador{ 1 }; contador <= 40; ++contador)
	{
		std::cout << dado6Caras(mt) << '\t'; // Tiramos el dado una vez

		// Si imprimimos 10 números, hacemos un salto de línea.
		if (contador % 10 == 0){
			std::cout << '\n';}
	}

	return 0;
}
```

En programas sencillos como este, la diferencia de usar semillas de mayor calidad puede no ser tan evidente. Sin embargo, en aplicaciones más complejas, los beneficios se hacen mucho más notorios. Dado que proporcionar semillas más variadas de esta forma es sencillo de implementar, resulta una buena práctica que vale la pena adoptar incluso en los casos más simples.
