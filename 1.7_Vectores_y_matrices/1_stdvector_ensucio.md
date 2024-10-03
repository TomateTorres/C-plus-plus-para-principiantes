ESTO VA DESPUÉS DE [ESTO](1.1_stdvector__longitud_e_índices.md)


Recordatorio: [Paso por referencia](../1.3_Funciones_basicas/2.5_Paso_por_referencia.md)

**TOMADO DE:** https://www.learncpp.com/cpp-tutorial/passing-stdvector/

Cuando usamos un `std::vector` como parámetro de una función, tenemos que especificar el `<tipo>` de dicho vector.

Como ya hemos visto, los `std::vector`es son objetos que tienen una cierta estructura y pueden llegar a tener muchos elementos. Aún cuando se trate de vectores pequeños, si pretendemos

En la sección sobre [funciones](../1.3_Funciones_basicas/), ya habíamos hablado sobre el [paso por valor](../1.3_Funciones_basicas/2.0_Intro_a_parámetros_de_funciones_y_argumentos.md) y el [paso por referencia](../1.3_Funciones_basicas/2.5_Paso_por_referencia.md) de argumentos.

A estos conceptos agregaremos uno nuevo antes de meternos de lleno a cómo pasar vectores como argumentos de funciones: el **paso por referencia constante `const &`**.

Recordemos que:
1. Cuando **pasamos un argumento por valor**, se crea una copia del argumento. Esto significa que los cambios que hagamos dentro de la función no afectarán al objeto original fuera de la función.
```
#include <vector>
#include <iostream>
#include <string>

void TeHeFalladoAnakin(std::vector<std::string> v)
{ // La función `TeHeFalladoAnakin` pasa el argumento que le 
  // demos por valor. Se crea una copia local de `v`

    v[2] = "Vader"; // Se modifica el elemento con índice 2 del
                    // vector `v`.

} // La copia local del vector `v` es destruida.

int main()
{
	std::vector<std::string> dosJedisYmedio{ "Ahsoka", "Obi-Wan", 
                                             "Anakin" }; 

    TeHeFalladoAnakin(dosJedisYmedio);
    // Pasamos una copia de `dosJedisYMedio`, los cambios que 
    // hace la función, sólo se aplican a esa copia local.

    std::cout << dosJedisYmedio[2]; 
    // Se imprime el elemento con índice 2 de `dosJedisYMedio`
    // que definimos dentro de `main`. O sea, Anakin no se
    // convirtió en Vader.
                                                                          
	return 0;
}
```

2. Cuando **pasamos un argumento por referencia**, estamos permitiendo que la función pueda modificar el contenido original del vector.
```
#include <vector>
#include <iostream>
#include <string>

void TeHeFalladoAnakin(std::vector<std::string>& v)
{ // La función `TeHeFalladoAnakin` pasa el argumento que le 
  // demos por referencia. Estamos trabajando directamente con
  // el vector `v`.

    v[2] = "Vader"; // Se modifica el elemento con índice 2 del
                    // vector `v`.

}

int main()
{
	std::vector<std::string> dosJedisYmedio{ "Ahsoka", "Obi-Wan", 
                                             "Anakin" }; 

    TeHeFalladoAnakin(dosJedisYmedio);
    // Pasamos `dosJedisYMedio`, los cambios que hace la 
    // función, se aplican directamente a `dosJedisYMedio`.

    std::cout << dosJedisYmedio[2]; 
    // Se imprime el elemento con índice 2 de `dosJedisYMedio`
    // después de ser modificado por `TeHeFalladoAnakin`. O sea,
    // Anakin se convirtió en lo que juró destruir.
                                                                          
	return 0;
}
```

3. Cuando **pasamos un vector por referencia constante**,



| Forma de pasar el vector                          | ¿Crea copia? | ¿Se puede modificar?       | Eficiencia  |
| ------------------------------------------------- | ------------ | -------------------------- | ----------- |
| Por valor (`std::vector v`)                       |        Sí    | Sí (pero la copia local)   | Baja        |
| Por referencia (`std::vector& v`)                 |        No    | Sí (el original)           | Alta        |
| Por referencia constante (`const std::vector& v`) |         No   |  No                        | Alta        |
