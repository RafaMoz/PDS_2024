#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define fo 10
#define pi 3.14159
#define N 1000
#define amp 100

int main(int argc, char* argv[]){

    FILE* datos_periodicos = fopen("dat.dat", "w");
    FILE* fourier = fopen("dat_f.dat", "w");
    float samples[N];
    float muestreo_fourier[N];
    float senial;

    /*for(int i=0; i<N;i++){
        samples[i] = sin(2*pi*fo*i/N);
        fprintf(datos_periodicos, "%f\n" ,samples[i]);
    } */
    for(int i=0;i<N;i++){
        if(i<N/2){
            senial = 1;
        }else{
            senial = -1;
        }
        fprintf(datos_periodicos,"%f\n", senial);
    }
    

    for(int i=0; i<N; i=i+2){
        //muestreo_fourier[i] = amp* (pi/4)*((1/(i*i*pi))*cos(2*pi*fo*i/N) + (1/i)*sin(2*pi*fo*i/N));
        muestreo_fourier[i] = (2/(N*pi))*((1-(-1)^N))*sin(N*i);
        fprintf(fourier, "%f\n", muestreo_fourier[i]);
    }

    fclose(datos_periodicos);
    fclose(fourier);

    system("gnuplot -p <grafica.gp");

    return 0;
}