/*
El siguiente programa usa un ciclo `for` basado en rango para verificar si un nombre dado 
por el usuario se encuentra en una lista.
*/

#include <iostream>
#include <string> // Para el input del usuario, necesitamos una cadena modificable.
#include <string_view> // No necesitamos modificar el array de los nombres, podemos usar un
                       // tipo de string "barato".
#include <vector>

int main()
{
    // En agosto de 2022 la Dirección del Registro Civil de la CDMX dio a conocer una lista 
    // de 62 nombres prohibidos en México, he aquí algunos de ellos:
    std::vector<std::string_view> nombresProhibidos{"Anivdelarev", "Batman", "Culebro", 
                                                    "Espinaca", "Gordonia", "Hitler", 
                                                    "Masiosare", "Robocop", "Terminator",
                                                    "Usnavy"};

    std::cout << "Dame tu nombre: ";
    std::string nombreUsuario{};
    std::cin >> nombreUsuario;

    bool prohibido{false}; // Esta variable verifica si el nombre del usuario está en la lista
                           // de nombres prohibidos.

    for (const auto& nombre : nombresProhibidos) // Iteramos por los nombres prohibidos.
    {
        if (nombre == nombreUsuario) // Si el nombre del usuario está en la lista...
        {
            prohibido = true; // entonces su nombre sí está prohibido
            break;            // y terminamos el ciclo (ya no es necesario verificar los demás
                              // nombres)
        }
    }

    if (prohibido) // Si `prohibido == true`, o sea, si el nombre del usuario sí está 
                   // prohibido en México.
    {
        std::cout << nombreUsuario << ", tu nombre está prohibido en México.\n";
    }

    else
    {
        std::cout << nombreUsuario << ", tu nombre (probablemente) no está prohibido en " 
                  << "México.\n";
    }                            

    return 0;
}
