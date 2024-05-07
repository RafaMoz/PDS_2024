#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define pi 3.141592
#define N 1000 //Longitud de muestras por segundo
#define amp 18//Amplitud 2 * Ei
#define fo 18//Frecuencia 2*Ei 
#define sub 27 //Razón de submuestreo 3*9

int main(int argc, char* argv[]){

    FILE *data = fopen("1_data.dat", "w");
    FILE *noise_file = fopen("2_noise_file.dat", "w");
    FILE *data_with_noise = fopen("3_data_with_noise.dat", "w");
    FILE *sub_data = fopen("4_subsampling_data.dat", "w");
    FILE *L6_bits_trunc_data = fopen("5_L6_trunc_data.dat", "w");
    FILE *L6_bits_redondeo_data = fopen("5_L6_redondeo_data.dat", "w");

    float samples[N], noise[N], samples_noise[N];
    char samples_L6_truncamiento[N], samples_L6_redondeo[N];
    double error_cuadratico = 0.0;
    double power_signal, power_signal_with_noise, power_noise;
    float SNR;

    srand(time(0)); //Primera llamda para generar números aleatorios 

    for(int i=0; i<N; ++i){
        samples[i] = sin(2*pi*fo*i/N)*amp;
        fprintf(data, "%f\n", samples[i]);
        //noise[i] = rand() % 2;
        noise[i] = ((float)rand() /(float)(RAND_MAX)) * 16 ;
        fprintf(noise_file, "%f\n", noise[i]);
        samples_noise[i] = samples[i] + noise[i];//rand() % 2;
        fprintf(data_with_noise, "%f\n", samples_noise[i]);

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
    for(int i=0; i<N; i=i+sub){ 
        //printf("%d\n", i);
        fprintf(sub_data, "%f\n", samples_noise[i]);
    }

    //Cuantización a partir de la señal original x(n). Simular una señal cuantizada x_q(n) por 
    //truncamiento y redondeo a razón L = 6 y 13 bits
    //Primer caso, a razón de 6 bits: 5 bits parte entera y 1 bit de signo.
    for(int i=0; i<N; i++){
        samples_L6_truncamiento[i] = samples_noise[i]; //samples_L6[i] = (int)samples_noise[i]; -> casteo
        fprintf(L6_bits_trunc_data, "%d\n", samples_L6_truncamiento[i]);

        if(samples_noise[i] < 0){
            samples_L6_redondeo[i] = samples_noise[i] - 0.5;
        }else{
            samples_L6_redondeo[i] = samples_noise[i] + 0.5;
        }
        fprintf(L6_bits_redondeo_data, "%d\n", samples_L6_redondeo[i]);
    }

    //Calcular el error medio cuadrático de la cuantización 
    //Por truncamiento 
    for(int i=0; i<N;i++){
        error_cuadratico += pow(samples_noise[i] - samples_L6_truncamiento[i], 2);
    }
    error_cuadratico = error_cuadratico / N;
    printf("Error medio cuadratico para la senial cuantizada a 6 bits por truncamiento %f \n", error_cuadratico);

    error_cuadratico = 0.0;
    //Por redondeo
    for(int i=0; i<N;i++){
        error_cuadratico += pow(samples_noise[i] - samples_L6_redondeo[i], 2);
    }
    error_cuadratico = error_cuadratico / N;
    printf("Error medio cuadratico para la senial cuantizada a 6 bits por redondeo %f \n", error_cuadratico);

    
    fclose(data);
    fclose(data_with_noise);
    fclose(sub_data);
    fclose(L6_bits_trunc_data);
    fclose(L6_bits_redondeo_data);
    //GNU PLOT
    //system("gnuplot -p -e 'graf.gp' ");
    //system("gnuplot -p -e \"plot './data.dat' with lines\"");

    system("gnuplot -p <graf.gp");
    system("gnuplot -p <graf2_quantization.gp");
    
    return 0;
}

//Para git es necesario primero git commit -am "Comentario" //Bandera m mensaje a all
//Y después git push <repositorio remoto> <rama> git push origin main
