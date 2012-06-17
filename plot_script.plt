set terminal png
set output "ex2.png"
set xrange [0:5]
set yrange [0:3000]
plot "ex21.dat" using 1:2 with dots 3, \
     "ex22.dat" using 1:2 with dots 4

set output "lokia1.png"
set xrange [0:30]
set yrange [0:6000]
plot "lokia.dat" using 1:2 with dots 3

set output "lokia2.png"
set xrange [0:6000]
set yrange [0:6000]
plot "lokia.dat" using 2:3 with dots 3

set output "plot1.png"
set xrange [0:8000]
set yrange [0:8000]
plot "brusselator.dat" using 2:3 with dots 3

set output "plot2.png"
set xrange [0:15]
set yrange [0:8000]
plot "brusselator.dat" using 1:2 with dots 3, \
     "brusselator.dat" using 1:3 with dots 4


