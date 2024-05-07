#Configuracion en GNUPlot
#system("gnuplot -p 'graf.gp' ");
###
set autoscale
set multiplot layout 3,1 rowsfirst
#set output "seno.eps"
set grid
set style data lines

#-----Grafica 1------
#set title "Señal de entrada"
#unset label
#set xlabel "n"
#set ylabel "x(n)"
plot "1_data.dat" #Grafica el archivo de datos
#unset xlabel
#unset ylabel
unset title

#-----Grafica 2--------
#set title "Señal de entrada con ruido"
#unset label
set xlabel "n"
set ylabel "x(n)"
plot "3_data_with_noise.dat"
unset xlabel
unset ylabel
unset title
#pause(3)
#unset multiplot

#-----Grafica 3--------
#set title "Señal de submuestreada"
#unset label
set xlabel "n"
set ylabel "x(n)"
plot "4_subsampling_data.dat"
unset xlabel
unset ylabel
unset title