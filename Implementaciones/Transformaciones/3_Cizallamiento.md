Un **cizallamiento** es una transformación lineal que desplaza cada punto en una dirección fija, en una cantidad proporcional a su distancia orientada desde la línea que es paralela a esa dirección y pasa por el origen.

En el plano $xy$ un **cizallamiento horizontal** (o **cizallamiento paralelo al eje-x**) es una función que toma un punto genérico de la forma $(x,y)$ y lo manda al punto $(x+my, y)$ donde $m$ es un parámetro fijo llamado **factor de cizallamiento**.

Cada punto es desplazado horizontalmente en una cantidad proporcional a su coordenada $y$. Si $m>0$, cualquier punto por encima del eje-x se desplaza hacia la derecha, y, si $m<0$, se dirige hacia la izquierda (si $m=0$ entonces no estamos haciendo nada). Puntos debajo del eje-x se mueven en la dirección opuesta y los puntos en el eje se mantienen fijos.

Un cizallamiento horizontal $(x, y) \mapsto (x+my, y)$ tiene por matriz asociada a:

![image](https://github.com/user-attachments/assets/93c76c4e-1595-4a45-8c99-d4442166b7aa)

Un **cizallamiento vertical** (o **cizallamiento paralelo al eje-y**) es similar. Este cizallamiento desplaza puntos a la derecha del eje vertical hacia arriba o hacia abajo, según el signo de $m$. Deja invariantes las líneas verticales, pero inclina todas las demás líneas sobre el punto donde se encuentran con el eje vertical.

Un cizallamiento horizontal $(x, y) \mapsto (x, mx+y)$ tiene por matriz asociada a:

![image](https://github.com/user-attachments/assets/9ac33d02-6b81-44fb-80bf-cc869589bdfc)

El siguiente programa le permite al usuario dar $m$ y $m'$ factores de cizallamiento horizontal y vertical (respectivamente) y ayuda a calcular a dónde son enviados un cierto conjunto de puntos.
