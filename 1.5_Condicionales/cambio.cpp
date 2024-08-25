#include <iostream>

bool sePuedeSubir()
{
  std::cout << "¿Cuál es tu estatura? (en cm): ";

  double estatura{}; // hay gente traumada que puede darnos su
                     // estatura hasta con milímetros.
  std::cin >> estatura;

  return estatura >= 140.0; 

  /*
  `sePuedeSubir` en una función de tipo booleano, esto quiere
  decir que sólo hay dos valores posibles que nos puede devolver:
  `true` o `false`.
  El usuario nos dará su estatura y la compararemos con el mínimo
  para subirse que es 140.0 cm.
  Si el usuario es más alto, es decir si la condición `estatura >= 140.0`
  se verifica, la función nos devolverá el valor `true`.
  En caso contrario (si el usuario no es lo suficientemente alto),
  la condición `estatura >= 140.0` no se verifica y por tanto la 
  función nos devolverá el valor `false`.
  */
}

int main()
{

  if (sePuedeSubir())
    std::cout << "Te puedes subir, ¡yupi!\n";
  else
    std::cout << "Mi pequeño amigo Lannister, lo siento pero no" 
              << " puedes subir.\n";

  return 0;
}
