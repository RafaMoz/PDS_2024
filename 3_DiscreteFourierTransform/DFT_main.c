#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 1000
#define pi 3.14159
#define fo 30 
#define N1 200 //For square signal
#define N2 300
#define A 10 //Amplitud


int main(int argc, char* argv[]){

    FILE* x_input_data = fopen("1_senialx.dat", "w");
    FILE* XSpectrum_data = fopen("2_XSpectrum.dat", "w");
    float x_input[N];
    float x_spectrum[N];
    double Real, Imag;
    int n, k;

/*
//*****************First input -> cosine signal***********************
    for(int i=0; i<N;i++){
        x_input[i] = cos(2*pi*fo*i/N);
        fprintf(x_input_data, "%f \n", x_input[i]);
    }

*/

//*****************Second input -> Square wave signal***********************
    for(int i=0;i<N1;i++){
        x_input[i] = 0;
        fprintf(x_input_data, "%f \n", x_input[i]);
    }
    for(int i=N1;i<N2;i++){
        x_input[i] = 1*A;
        fprintf(x_input_data, "%f \n", x_input[i]);
    }

    for(int i=N2;i<N;i++){
        x_input[i] = 0;
        fprintf(x_input_data, "%f \n", x_input[i]);
    }
/*
//****************Third input Square signal*************************
    for(int i=0;i<N1;i++){
        x_input[i] = 1*A;
        fprintf(x_input_data, "%f \n", x_input[i]);
    }

    for(int i=N1;i<N;i++){
        x_input[i] = 0;
        fprintf(x_input_data, "%f \n", x_input[i]);
    }
*/
//------------------------Spectrum part------------------------------
    for(k=0; k<N;k++){
        Real = 0;
        Imag = 0;
        for(n=0; n<N;n++){
            Real = Real + x_input[n]*cos(2*pi*k*n/N);
            Imag = Imag + x_input[n]*sin(2*pi*k*n/N);
        }
        x_spectrum[k] = sqrt(Real*Real + Imag*Imag);
        fprintf(XSpectrum_data,"%f\n", x_spectrum[k]);
    }

    fclose(x_input_data);
    fclose(XSpectrum_data);

    system("gnuplot -p <graf_DFT.gp");

    return 0;
}