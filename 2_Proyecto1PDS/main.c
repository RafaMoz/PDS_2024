#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.141592
#define N 1000 //Longitud de muestras por segundo
#define amp 18//Amplitud 2 * Ei
#define fo 18//Frecuencia 2*Ei 

void info_proyecto(){
    printf("Tamanio de un int %d y de un float %d\n", sizeof(int), sizeof(float));
}

int main(int argc, char* argv[]){
    FILE *data = fopen("data.dat", "w");
    float samples[N];

    //std::cout << "DSP con c++" << std::endl;
    for(int i=0; i<N; ++i){
        samples[i] = sin(2*pi*fo*i/N);
        //std::cout << "dato " << i << ": " << samples[i] << std::endl;
        fprintf(data, "%f\n", samples[i]);
    }

    fclose(data);
    //GNU PLOT
    //system("gnuplot -p -e 'graf.gp' ");
    //system("gnuplot -p -e \"plot './data.dat' with lines\"");
    system("gnuplot -p <graf.gp");
   
    
    return 0;
}