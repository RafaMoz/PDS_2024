#Configuracion en GNUPlot
#system("gnuplot -p 'graf.gp' ");
###
set autoscale
set output "seno.eps"
set grid
set style data lines

#-----Grafica 1------
set title "Señal de entrada"
#unset label
set xlabel "n"
set ylabel "x(n)"
plot "data.dat" #Grafica el archivo de datos
unset xlabel
unset ylabel
unset title