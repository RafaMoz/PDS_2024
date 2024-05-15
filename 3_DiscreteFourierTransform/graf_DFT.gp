#Configuracion en GNUPlot
#system("gnuplot -p 'graf_DFT.gp' ");
###
set autoscale
set multiplot layout 2,1 rowsfirst
set grid
set style data lines

#-----Grafica 1------
#set title "Señal de entrada"
#unset label
#set xlabel "n"
#set ylabel "x(n)"
plot "1_senialx.dat" #Grafica el archivo de datos
#unset xlabel
#unset ylabel
unset title

#-----Grafica 2--------
#set title "Señal DFT"
#unset label
set xlabel "n"
set ylabel "x(n)"
plot "2_XSpectrum.dat"
unset xlabel
unset ylabel
unset title