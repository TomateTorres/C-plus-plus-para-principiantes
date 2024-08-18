Una **configuración de compilado** es una colección de configuracines de proyecto que determinan como el IDE (para nosotros, VSCode) va a construir nuestros proyectos.

Una configuaración de compilado típicamente incluye cosas como:
* Como se llamarán los archivos ejecutables (ej.: .exe).
* En qué directorios (carpetas) el IDE buscará código y archivos.
* Que tanto el compilador optimizará el programa.
* Etc.

De manera general, aquí se aplica la regla de 'si no le sabes, no le muevas'. En el sentido de que, trataremos de dejar los valores puestos por default a menos que tengamos una razón específica para cambiarlos.

Cuando se crea un proyecto nuevo, la mayoría de los IDEs ofrecen dos configuraciones de compilado: **Una configuración de lanzamiento** (release configuration) y una **configuración de depuración** (debug configuration).

La configuración de lanzamiento está designada para cuando tengamos pensado liberar nuestros programas al público. Esta versión está típicamente optimizada para que nuestros archivos pesen poco y los ejecutables sean más veloces. Pero no inluye información de depuración.

La configuración de depuración es la que usualmente se usa cuando estamos escribiendo nuestros programas, esta nos ayuda a identificar y remover errores. Esta es la configuración recomendable en principio, una vez que estemos seguros de que nuestros programas funcionan, podemos cambiarla a la de lanzamiento para hacer que nuestros archivos sean menos pesados.

## Configurar el compilador de VSCode:

Cuando en un proyecto se corre un programa (de C++) por primera vez, en la carpeta *.vscode* del proyecto se crea un archivo llamado *tasks.json*.

