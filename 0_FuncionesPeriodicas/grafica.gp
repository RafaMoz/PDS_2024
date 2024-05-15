# GRAFICA CUATRO GRAFICAS EN UNA VENTANA
# l@rry
#system("gnuplot -p 'graf.gp' ");
#set term corel
set output  "Dos_graficas.eps"

set autoscale
set multiplot layout 2,1 rowsfirst
set grid
set style data lines

#------------- Graf 1 ----------------
set title "Funcion seno"
#unset label
set xlabel   "muestras"
set ylabel   "x(n)"
plot  "dat.dat"
unset xlabel
unset ylabel
unset title

#------------- Graf 2 ----------------
set title "Funcion periodica"
#unset label
#set xlabel   "muestras"
set ylabel   "x(n)"
plot  "dat_f.dat"
unset xlabel
unset ylabel
unset title





#pause(3)
#unset multiplot

#