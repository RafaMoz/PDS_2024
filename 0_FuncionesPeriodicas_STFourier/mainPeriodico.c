#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.14159
#define N 1000
#define k 100 //Armónicos k

int main(int argc, char* argv[]){

    FILE* fourier = fopen("dat_fourier.dat", "w");
    float samples[N];
    double senial;
    float t;
    int prueba;
 /*
//************************* Señal A *********** son líneas horizontales de amplitud 1 y -1 de longitud pi
    for(t=0; t<2*pi;t=t+0.001){ //Tiempo. En matlab es un vector de tiempo de 0 a 2t con saltos de 1ms t=0:0.001:2*pi   
        for(int n=1; n<k; n++){ //Para los armónicos. Definidos por k 
            senial = senial + ((2/(pi*n))*(1-(pow(-1,n)))*sin(n*t)); 
        }
        fprintf(fourier, "%f\n", senial);
        senial = 0;
    }
//En matlab tengo mi hoja de datos de 6283 valores -> Esto viene de 2*pi que es mi periodo * 1000 saltos de tiempo
//****************************************************************
 */
// /*
//************************* Señal B *********** 
    for(t=0; t<2*pi;t=t+0.001){ //Tiempo. En matlab es un vector de tiempo de 0 a 2t con saltos de 1ms t=0:0.001:2*pi   
        senial = pi/4;
        for(int n=1; n<k; n++){ //Para los armónicos. Definidos por k 
            senial = senial + ((1/(pi*n*n))*(1-pow(-1,n))*cos(n*t)+(sin(n*t)/n));
        }
        fprintf(fourier, "%f\n", senial);
    }
//****************************************************************
// */
 /*
//************************* Señal C *********** Señal triangular
    senial = pi/2;
    for(t=0; t<2*pi;t=t+0.001){ //Tiempo. En matlab es un vector de tiempo de 0 a 2t con saltos de 1ms t=0:0.001:2*pi   
        for(int n=1; n<k; n++){ //Para los armónicos. Definidos por k 
            senial = senial + (2/(pi*n*n)*(pow(-1,n)-1)*cos(n*t)); 
        }
        fprintf(fourier, "%f\n", senial);
        senial = 0;
    }
//****************************************************************
 */
    fclose(fourier);

    system("gnuplot -p <grafica.gp");

    return 0;
}