set terminal png
set output "plot1.png"
set xrange [0:8000]
set yrange [0:8000]
plot "brusselator.dat" using 2:3 with dots 3

set output "stoch1.png"
set xrange [0:15]
set yrange [0:8000]
plot "brusselator.dat" using 1:2 with dots 3

set output "stoch2.png"
set xrange [0:15]
set yrange [0:8000]
plot "brusselator.dat" using 1:3 with dots 3


