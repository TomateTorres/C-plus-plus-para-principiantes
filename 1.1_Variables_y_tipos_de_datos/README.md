# Variables y tipos de datos.
Un programa produce resultados mediante la maniplación de _datos_, estos son cualquier tipo de información que puede ser procesada por la computadora.

Los datos con los que un programa puede trabajar pueden ser obtenidos mediante una base de datos, la red o mediante input del usuario.

La unidad básica de los datos es conocida como _valor_, esta puede ser una letra (ej.: 'z'), un número (ej.: '256') o texto (ej.: 'HolaMundo').

C++ es un lenguaje de programación orientado a objetos, un _objeto_ es una región de almacenamiento (léase: memoria) que puede guardar un valor y tiene ciertas propiedades asociadas. Dicho de manera muy burda: cuando trabajamos con C++, le estamos diciendo a la computadora _'dame el valor resguardado por este objeto'_, en vez de decirle _'dame el valor que se encuentra en el espacio de memoria número tal'_.
De este modo, no tenemos que preocuparnos donde están nuestros objetos en la memoria, sino solamente en usarlos y recuperar valores.

Un objeto con un nombre asociado se llama _variable_. Nombrar a nuestros objetos nos permite poder referirnos a ellos más adelante en nuestros programas.

**Ojo:** En general la palabra _'objeto'_ puede referirse a cualquier objeto en la memoria, en C++ los _'objetos'_ excluyen a las funciones.

## Tipos de variables.
Algunos tipos de variables que existen en C++ son:
* _int_: Esta variable es usada para guardar números enteros.
* _float_: Esta variable es usada para guardar números con punto decimal. Puede guadar cifras de hasta 7 espacios decimales.
* _double_: Esta variable es usada para guardar números con punto decimal. Puede guadar cifras de hasta 15 espacios decimales.
* _bool_: Es usada para guardar valores de tipo 'verdadero' o 'falso'.
* _char_: Es usado para guardar un caracter, letra, número o valor de tipo ASCII. Lo que se almacena en la memoria es el código numérico del caracter en cierta codificación. 
* _string_: Es usado para guardar texto, por ejemplo: "Hola Mundo". Este tipo de variables siempre empiezan y terminan con comillas dobles ("_____").

## Reglas importantes.
* Sobre nombrar variables:
    * El nombre de una variable debe empezar con una letra o con un guión bajo (_). En el nombre pueden usarse letras, números y más guiones bajos.
    * Los símbolos como '$' y '%' no se pueden usar para nombrar variables. Tampoco está permitido poner espacios dentro de los nombres de las variables. 
    * Para C++ (en general, esto es así en cualquier lenguaje de programación) las variables 'volumen_de_lata' y 'Volumen_de_lata' son distintas, esto porque distingue entre mayúsculas y minúsculas.
    * No se pueden usar _palabras reservadas_ para nombrar variables. Una palabra reservada es aquella que ya tiene un significado para el lenguaje de programación, por ejemplo en C++ no es posible llamar a una variable '`double`' porque esta palabra ya corresponde a un tipo de variable que puede almacenar valores decimales. 

* Crear variables:
    * De manera general, la sintaxis es: `tipo de variable nombre = valor;`. Donde `tipo de variable` es alguna de los tipos de variables de C++ (_int_ por ejemplo), `nombre` es el nombre de la variable ('volumen_de_lata' por ejemplo), `=` sirve para asignarle algún valor a la variable y `valor` es aquello que guardaremos en la variable.
        * `int latas_por_paquete = 6;` es una variable de tipo entero llamada 'latas_por_paquete' que guarda el valor 6.
        * `double decimal = 6.66;` es una variable de tipo decimal llamada 'decimal' que guarda el valor 6.66.

* Observaciones:
    * Siempre que creemos una variable es necesario que especifiquemos su tipo.
    * Una variable puede cambiar de valor tantas veces como queramos pero no puede cambiar de tipo.
    * Es común pensar que el símbolo `=` tiene el mismo significado en programación que el usual en matemáticas, esto es incorrecto. Cuando decimos que `latas_por_paquete = 6;`, estamos diciéndole al programa que guarde el valor 6 en la variable 'latas_por_paquete'; más adelante podemos incluir la línea `latas_por_paquete = 8;`, diciéndole al programa que ahora guarde el valor 8. De este modo, el símbolo `=` denota una asignación de valores en vez de una igualdad matemática.
        * Aunque se vea extraño, es perfectamente legal darle a C++ la instrucción: `latas_por_paquete = latas_por_paquete + 2;`. Esto le dice al programa que busque el valor guardado en la variable 'latas_por_paquete', le sume 2 y lo guarde en el mismo lugar.

## Tipos de datos.
Menciona brevemente qué es un entero y así.

Llevas 33 minutos.
