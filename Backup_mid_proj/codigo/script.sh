# Compilar el programa con optimización y sanitizers
g++ -O3 -fsanitize=address,leak,undefined modularized_rawcode.cpp -o modularized.x

# Loop sobre valores de p 
for p in $(awk 'BEGIN{for(i = 0.05; i <= 0.55; i += 0.05) printf "%.3f\n", i}')
do
    echo "Ejecutando simulaciones para p=$p"

    # Paraleliza las 10 ejecuciones con el mismo valor de p
    parallel -j 10 "./modularized.x 32 {1} >> p{1}_L32.txt" ::: $p ::: {1..10}
done

for p in $(awk 'BEGIN{for(i = 0.56; i <= 0.66; i += 0.01) printf "%.3f\n", i}')
do
    echo "Ejecutando simulaciones para p=$p"

    # Paraleliza las 10 ejecuciones con el mismo valor de p
    parallel -j 10 "./modularized.x 32 {1} >> p{1}_L32.txt" ::: $p ::: {1..10}
done

for p in $(awk 'BEGIN{for(i = 0.70; i < 1; i += 0.035) printf "%.3f\n", i}')
do
    echo "Ejecutando simulaciones para p=$p"

    # Paraleliza las 10 ejecuciones con el mismo valor de p
    parallel -j 10 "./modularized.x 32 {1} >> p{1}_L32.txt" ::: $p ::: {1..10}
done

# Limpieza
rm modularized.x
