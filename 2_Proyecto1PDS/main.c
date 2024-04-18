#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define pi 3.141592
#define N 1000 //Longitud de muestras por segundo
#define amp 18//Amplitud 2 * Ei
#define fo 18//Frecuencia 2*Ei 
#define sub 27 //Razón de submuestreo 3*9

void info_proyecto(){
    printf("Tamanio de un int %d y de un float %d\n", sizeof(int), sizeof(float));
}

int main(int argc, char* argv[]){

    FILE *data = fopen("data.dat", "w");
    FILE *noise_file = fopen("noise.dat", "w");
    FILE *data_noise = fopen("data_noise.dat", "w");
    FILE *sub_data = fopen("subsampling_data.dat", "w");

    float samples[N], samples_noise[N], noise[N];
    float power_signal, power_signal_with_noise, power_noise;
    float SNR;

    srand(time(0)); //Primera llamda para generar números aleatorios 

    for(int i=0; i<N; ++i){
        samples[i] = sin(2*pi*fo*i/N)*amp;
        fprintf(data, "%f\n", samples[i]);
        //noise[i] = rand() % 2;
        noise[i] = ((float)rand() /(float)(RAND_MAX)) * 16 ;
        fprintf(noise_file, "%f\n", noise[i]);
        samples_noise[i] = samples[i] + noise[i];//rand() % 2;
        fprintf(data_noise, "%f\n", samples_noise[i]);

        power_signal += pow(samples[i], 2);
        //power_signal_with_noise += (samples_noise[i] * samples_noise[i]);
        power_noise += pow(noise[i], 2);
    }

    //Calculate SNR (Signal to Noise Ratio)
    //SNR = 10*(log(power_signal)/log(power_signal_with_noise));
    printf("PowerSignal: %f y PowerNoise: %f\n", power_signal, power_noise);
    printf("DIVIDE %f\n", power_signal/power_noise);
    SNR = 10*log10(power_signal/power_noise);
    printf("The SNR is %f\n", SNR);

    //Submuestrar a razón de 27 -> 3*9
    
    //for(int i=0; i<sub; i++){ //Primeras 27 muestras de la señal
  /*  for(int i=0; i<N; i=i+sub){ 
        printf("%d\n", i);
        fprintf(sub_data, "%f\n", samples[i]);
    }
*/
    //Cuantización a partir de la señal original x(n). Simular una señal cuantizada x_q(n) por 
    //truncamiento y redondeo a razón L = 6 y 13 bits
    
    fclose(data);
    fclose(data_noise);
    fclose(sub_data);
    //GNU PLOT
    //system("gnuplot -p -e 'graf.gp' ");
    //system("gnuplot -p -e \"plot './data.dat' with lines\"");
    system("gnuplot -p <graf.gp");
   
    
    return 0;
}