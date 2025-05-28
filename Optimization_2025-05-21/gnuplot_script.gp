set term pdf
set out "Optimization_levels.pdf"
set grid 
set logscale x      
set xlabel "Block size"  
set ylabel "Time" 
set title "Time for different optimization levels"
plot 'data-0.txt' u 2:4 w lp,'data-1.txt' u 2:4 w lp, 'data-2.txt' u 2:4 w lp, 'data-3.txt' u 2:4 w lp
unset output