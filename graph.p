set title "data"
set xlabel "x1"
set ylabel "x2"
set xrange [2.0:10.0]
set yrange [2.0:10.0]
set grid
set palette rgb 33,13,10


plot 'Dataset.dat' using 1:2:3 ls 7 ps 2 palette 