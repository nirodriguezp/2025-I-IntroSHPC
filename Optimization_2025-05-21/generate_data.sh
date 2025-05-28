MSIZE = 512;
for ((OPT = 0; OPT <= 3; OPT++))
    do gcc -O$OPT cache_blocking.c
    for ((csize = 1; csize <= $MSIZE; csize *=2))
        do echo -n $MSIZE $csize
        ./a.out $MSIZE $csize
        done > data-$OPT.txt
done