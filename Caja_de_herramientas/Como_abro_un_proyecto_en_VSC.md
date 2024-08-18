Una de las ventajas de usar un IDE (como lo es VSCode) es que podemos organizar nuestros códigos en carpetas y proyectos.

**Nota:** Para todo lo que sigue, se asume que ya se ha instalado VSCode y se siguieron las instrucciones para descargar la extensión de C++ en él.

Aquí veremos como generar nuestro primer proyecto en VSCode:

1. Creamos una carpeta donde guardaremos nuestro código (La carpeta de este ejemplo yo la creé desde GitHub y se llama *prueba0*, pero esto fue mi gusto personal. La carpeta puede estar donde sea).
2. Cuando iniciamos un proyecto en VSCode (una vez que ya tenemos la carpeta donde lo vamos a guardar) seguimos la ruta *File>Open Folder...* 

![Captura de pantalla 2024-08-17 161303](https://github.com/user-attachments/assets/9ff8284f-ce9b-4a45-aa24-107e546d6029)

3. Se nos abrirá un explorador donde podremos buscar nuestra carpeta, una vez que la encontremos, la seleccionamos y damos click en *Seleccionar carpeta*.

![Captura de pantalla 2024-08-17 180915](https://github.com/user-attachments/assets/1f8f1fb4-1cde-496b-aeb3-ee5f3394ea97)

4. Una vez que la carpeta se haya abierto en VSCode, se nos desplegará un cuadro de diálogo, hay que picar la opción *Yes, I trust the authors*.

![Captura de pantalla 2024-08-17 180932](https://github.com/user-attachments/assets/bdeb3599-b3d2-462d-a5a3-7c7e09fc99ce)

5. Al poner el cursor encima de donde aparece el nombre de nuestra carpeta (del lado superior izquierdo) se nos desplegarán varias opciones. Para crear un archivo nuevo dentro de la carpeta, hay que elegir la opción de hasta la izquierda (*New File...*).

![Captura de pantalla 2024-08-17 181516](https://github.com/user-attachments/assets/2b137c54-9f35-4665-8e0d-f8f5860a1d65)

6. Para efectos del ejemplo, digamos que queremos crear un programa de C++ que imprima el mensaje: '*¡Hola Mundo!*' (Que original, ¿no?). Después de elegir la opción *New File...* le pondremos como nombre al archivo nuevo 'holamundo.cpp'.

![Captura de pantalla 2024-08-17 181934](https://github.com/user-attachments/assets/34af25ee-538f-4d56-8341-a2c33ef1c41d)

Siempre que tengamos un archivo de la forma **.cpp* sabremos que tenemos un archivo de código de C++ (de manera similar, si tuviéramos un archivo de la forma **.py* sabemos que es un archivo de código de Python).

7. Escribimos el código necesario en nuestro programa y luego desplegamos las opciones del botón que tiene un 'símbolo de pausa con un bichito encima' (está del lado superior derecho) y elegimos *Debug C/C++ File*.

![Captura de pantalla 2024-08-17 182551](https://github.com/user-attachments/assets/f9858cb5-339e-4696-a9ec-033dabdf15ad)

Si acabamos de abrir VSCode, se desplegará un mensaje muy largo en la terminal de abajo y será necesario volver a elegir la misma opción. Lo mejor es elegir *Debug C/C++ File* la primera vez que correremos el programa para verificar que funciona antes de *Run C/C++ File*.

Si nos da a elegir alguna otra opción antes de ejecutar la instrucción *Debug C/C++ File*, deberemos elegir la opción que contenga '*().g++.()*'.



