#include <iostream> 

using namespace std;

int main() 

{
    int latas_por_paquete = 6;

    const double VOL_LATA = 0.355;

    double vol_total = latas_por_paquete * VOL_LATA;

    cout << "Un paquete de 6 latas contiene "
        << vol_total << " litros." << endl;
 
    const double VOL_BOTELLA = 2;

    vol_total = vol_total + VOL_BOTELLA;

    cout << "Un paquete de 6 latas y una botella de dos litros contienen "
        << vol_total << " litros." << endl;
   
    return 0;

}
