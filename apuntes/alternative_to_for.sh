#!/bin/bash

opt_levels=(0 1 2 3 fast)
inputs=$(seq 0 2 40)

# Compilar
parallel "g++ -O{} fib.cpp -o fib_{}.x" ::: "${opt_levels[@]}"

# Ejecutar
parallel "./fib_{1}.x {2} >> data_{1}.txt" ::: "${opt_levels[@]}" ::: $inputs
