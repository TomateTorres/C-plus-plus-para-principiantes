#include <iostream>

double dameAlturaTorre()
{
    std::cout << "Dame la altura de la torre en metros: ";
    double alturaTorre{};
    std::cin >> alturaTorre;
    return alturaTorre;
}

double CalculaAlturaPelota(double alturaTorre, int segundos)
{
    double gravedad{9.8}; // asumimos que la gravedad es de 9.8
                          // m/s^2

    double distanciaCaida{gravedad*(segundos * segundos)/2};
    double alturaPelota{alturaTorre - distanciaCaida};

    if (alturaPelota < 0.0)
        return 0.0;
    // si `alturaPelota` es un número negativo, esto quiere decir
    // que la pelota ya ha caído al suelo
    
    return alturaPelota;
}

void imprimeAlturaPelota(double alturaPelota, int segundos)
{
    if (alturaPelota > 0.0)
        std::cout << "A los " << segundos << " segundos, la pelota "
                  << "tiene una altura de: " << alturaPelota 
                  << " metros.\n";

    else 
        std::cout << "A los " << segundos << " segundos, la pelota "
                  << " está en el suelo.\n";
}

void Calcula_e_imprime_altura_pelota(double alturaTorre,
                                     int segundos)
{
    double alturaPelota{CalculaAlturaPelota(alturaTorre, segundos)};
    imprimeAlturaPelota(alturaPelota, segundos);
}

int main()
{
    double alturaTorre{dameAlturaTorre()};

    Calcula_e_imprime_altura_pelota(alturaTorre, 0);
    Calcula_e_imprime_altura_pelota(alturaTorre, 1);
    Calcula_e_imprime_altura_pelota(alturaTorre, 2);
    Calcula_e_imprime_altura_pelota(alturaTorre, 3);
    Calcula_e_imprime_altura_pelota(alturaTorre, 4);
    Calcula_e_imprime_altura_pelota(alturaTorre, 5);
    
    return 0;
}
