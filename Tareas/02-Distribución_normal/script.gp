set term pdf
set out "random_pdf.pdf"
set title "Probability density function"
set xlabel "Random numbers"
set ylabel "Probability density"
plot "data1.txt" u 1:2 w l lc "red" title "SEED = 1", "data2.txt" u 1:2 w l lc "orange" title "SEED = 2", "data5.txt" u 1:2 w l lc "blue" title "SEED = 5"