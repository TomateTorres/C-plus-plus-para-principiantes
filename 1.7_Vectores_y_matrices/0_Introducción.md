Supongamos que tenemos un programa que guarda las calificaciones de cada parcial de los alumnos de algún curso de Cálculo I para calcular el promedio del grupo. En la Facultad de Ciencias de la UNAM, los primeros cursos de Cálculo suelen tener muchos alumnos (por ejemplo: En el semestre 2025-1, el profesor Héctor Méndez Lango tuvo 56 alumnos inscritos).

Supongamos que tenemos 56 alumnos, con lo que sabemos hasta ahora, podemos empezar por definir 56 variables (una por alumno):
```
double califAlumno1 {}; // Usamos tipo `double` porque lo usual
double califAlumno2 {}; // es que las calificaciones no sean
double califAlumno3 {}; // números enteros.
//...
double califAlumno56 {};
```

Luego, tendríamos que calcular el promedio del grupo haciendo algo parecido a esto:
```
double promedio {(califAlumno1 + califAlumno2 + califAlumno3
                 + ... + califAlumno56)/56;}; 
                 // En `...` van el resto de las calificaciones
                 // de los alumnos restantes. Como el ejemplo
                 // sólo es ilustrativo, no las pondremos.
```

Hacer el programa de esta manera no es una buena idea por varias razones:
* Tenemos muchas variables que debemos de introducir de manera manual, lo que hace que sea fácil cometer algún error a la hora de escribir y no darnos cuenta hasta que el programa haga cosas extrañas (o directamente no compile).
* En los cursos de Cálculo es muy común que el tamaño de los grupos se reduzca conforme avanza el semestre. Así que cada vez que querramos calcular el promedio del grupo tendremos que eliminar manualmente a los alumnos que hayan abandonado el curso (o añadirlos nuevamente si es que regresan en un parcial posterior) y cambiar el número total de alumnos para calcular el promedio.

Cada vez que necesitemos modificar el código, estamos en riesgo de cometer algún error y estropearlo todo.

![elmo-satan](https://github.com/user-attachments/assets/425fddd8-4fc5-4384-8297-88a03007cd50)

... Y esto fue sólo con 56 variables, si nos ponemos a pensar en programas más sofisticados, tendremos que pensar en situaciones en las que estaremos trabajando con cientos o miles de objetos. Cuando necesitamos trabajar con más de unos pocos objetos del mismo tipo (como en el caso de las calificaciones de los alumnos por parcial, donde todos los objetos eran tipo `double`), definir múltiples variables individuales simplemente no escala.

Afortunadamente, en C++ tenemos tipos de datos que pueden almacenar múltiples elementos, estos se llaman **contenedores**. Los **contenedores** almacenan múltiples elementos de un mismo tipo. Los podemos imaginar como una "caja" donde podemos poner varios objetos (datos) y, dependiendo del tipo de contenedor, podemos acceder, añadir, eliminar o reorganizar estos elementos de diferentes maneras.

En C++, los contenedores más utilizados son `std::vector` y `std::array`. Las otras clases de contenedores normalmente sólo se usan en situaciones muy específiicas, así que no los mencionaremos aquí.

## Introducción a arrays

Un **array** es un tipo de dato que guarda una secuencia de variables de forma contigua (esto quiere decir que cada elemento se coloca en una ubicación de memoria adyacente, sin espacios). Los arrays permiten acceder de forma rápida y directa a cualquiera de sus elementos. Conceptualmente son sencillos de entender y fáciles de usar, esto los hace **la** opción cuando necesitamos trabajar con un conjunto de datos que se relacionan entre sí (como en el ejemplo de las calificaciones).

En C++ hay 3 tipos de arrays principales: (C-style) arrays, `std::vector` y `std::array`.

Los **(C-style) arrays** son heredados de C. El estándar de C++ los llama "arrays", pero en C++ moderno a menudo se les llama **C arrays** o **C-style arrays** para diferenciarlos de los `std::array`.

Para los estándares modernos, los C-style arrays se comportan de manera extraña y pueden ser preligrosos. Más adelante veremos por qué.

El más flexible y sencillo de usar de los 3 tipos de arrays es `std::vector`. Además de que tiene un montón de capacidades útiles que los otros tipos de array no tienen.

Los `std::array` fueron introducidos en C++11 (la versión de C++ publicada en 2011) con la intención de reemplazar a los C-style arrays. Los `std::array` son más limitados que los `std::vector`, pero suelen ser más eficientes, sobre todo en arrays pequeños.
