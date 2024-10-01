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

Afortunadamente, en C++ tenemos tipos de datos que pueden almacenar múltiples elementos (como vectores y matrices), estos se llaman **contenedores**. Los **contenedores** almacenan múltiples elementos de un mismo tipo. Los podemos imaginar como una "caja" donde podemos poner varios objetos (datos) y, dependiendo del tipo de contenedor, podemos acceder, añadir, eliminar o reorganizar estos elementos de diferentes maneras.

En C++, los contenedores más utilizados para la implementación de vectores y matrices son `std::vector` y `std::array`. Ambos permiten gestionar colecciones de elementos de manera eficiente, aunque se diferencian principalmente en cómo manejan el tamaño y la asignación de memoria:


