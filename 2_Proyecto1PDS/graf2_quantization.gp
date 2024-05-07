#Configuracion en GNUPlot
#system("gnuplot -p 'graf2_quantization.gp' ");
###
set autoscale
set multiplot layout 3,1 rowsfirst
#set output "seno.eps"
set grid
set style data lines

#-----Grafica 1------
#set title "Señal de entrada x(n)"
#unset label
#set xlabel "n"
#set ylabel "x(n)"
plot "3_data_with_noise.dat" #Grafica el archivo de datos
#unset xlabel
#unset ylabel
unset title

#-----Grafica 2--------
#set title "Señal x(n) 6 bits truncamiento"
#unset label
set xlabel "n"
set ylabel "x(n)"
plot "5_L6_trunc_data.dat"
unset xlabel
unset ylabel
unset title
#pause(3)
#unset multiplot

#-----Grafica 3--------
#set title "Señal x(n) 6 bits redondeo"
#unset label
set xlabel "n"
set ylabel "x(n)"
plot "5_L6_redondeo_data.dat"
unset xlabel
unset ylabel
unset title