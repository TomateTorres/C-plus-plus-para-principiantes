En C++ existen dos formas principales de pasar argumentos a una función: el **paso por valor** y el **paso por referencia**.

En [el archivo de texto anterior](2_Intro_a_parámetros_de_funciones_y_argumentos.md) ya vimos que es el paso por valor. En resumen: cuando pasamos argumentos por valor, la función trabaja con **copias** de los valores originales, por lo que cualquier modificación que se haga dentro de la función **no afecta a las variables originales**.

El paso por referencia funciona de manera distinta ya que permite que una función trabaje directamente con las variables originales en vez de usar copias. Esto se logra pasando a la función la **referencia** de las variables, usando el operador `&` en la declaración de parámetros.

En C++, una referencia es básicamete un 'alias' para una variable existente. 

Veamos un pequeño ejemplo de cómo funciona una referencia:
```
int a{10};
int& refA{a}; // refA es una referencia a 'a'
```
Lo que está pasando es:
1. `int a{10};` inicializa a la variable `a` con el valor `10`. 
2. `int& refA{a};` inicializa a la variable `refA` como una referencia a la variable `a`. `refA` **no** es una variable independiente
