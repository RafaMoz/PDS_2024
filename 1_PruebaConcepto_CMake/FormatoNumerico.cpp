#include<iostream>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159
#define fo 10 //Frecuency
#define N 1000 //Samples
#include "Stack.h"

void greet()
{
    std::cout << "Hello world" << std::endl;
}

int main(int argc, char *argv[])
{ //
    FILE *data = fopen("data.dat", "w");
    float samples[N];

    std::cout << "DSP con c++" << std::endl;
    greet();
    for(int i=0; i<N; ++i){
        samples[i] = sin(2*PI*fo*i/N);
        std::cout << "dato " << i << ": " << samples[i] << std::endl;
        fprintf(data, "%f\n", samples[i]);
    }

    fclose(data);
    //GNU PLOT
    //system("gnuplot -p -e 'graf.gp' ");
    int value;
    std::cout << "Write a number "; std::cin>>value;
    Stack pila(value);
    std::cout << "------------" << std::endl;
    std::cout << pila.GetNumber() << std::endl;
    
    return 0;
}

//Minuto 19 del video de CMAKE