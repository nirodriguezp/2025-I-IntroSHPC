parallel 'g++ -O{} fibonacci.cpp -o fibonacci{}.x' ::: 0 1 2 3 fast

for ((n=2; n <= 30; n += 2)); 

    do parallel "./fibonacci{}.x $n >> data{}.txt" ::: 0 1 2 3 fast;

done

rm *.x