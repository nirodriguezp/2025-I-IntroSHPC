set term pdf
set out "optimization.pdf"
set title "Time for fast and slow fibonacci"
set xlabel "n"
set ylabel "Normalized time"
set logscale y
set key left
set grid
plot "data0.txt" u 1:2 w lp title "Slow O0", "data0.txt" u 1:3 w lp title "Fast O0", "data1.txt" u 1:2 w lp title "Slow O1", "data1.txt" u 1:3 w lp title "Fast O1", "data2.txt" u 1:2 w lp title "Slow O2", "data2.txt" u 1:3 w lp title "Fast O2", "data3.txt" u 1:2 w lp title "Slow O3", "data3.txt" u 1:3 w lp title "Fast O3", "datafast.txt" u 1:2 w lp title "Slow fast optim", "datafast.txt" u 1:3 w lp title "Fast fast optim"