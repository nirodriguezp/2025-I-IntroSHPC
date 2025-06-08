#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include "percolation.h"

int main(int argc, char **argv){
    int const L = atoi(argv[1]);
    double const p = atof(argv[2]);
    int percolations = 0;
    std::random_device rd;
    std::mt19937 gen(rd());                                // Random seed from rd
    std::vector<std::vector<double>> sizes;                   // Vector que guardará los tamaños de los clusters percolantes sobre el total de iteraciones

    for(int i = 1; i < 11; i++){
        auto id_matrix = Hoshen_Kopelman(fill_matrix(L, p, gen), L);  // Toma la matriz que se llenó en fill_matrix y coloca los id 

        //print_matrix(id_matrix, L); // Descomentar esta línea y comentar las siguientes si se quiere visualizar la matriz
        //std::cout << i << "\t";
        //print_sizes(id_matrix, L);    // Imprime el tamaño de cada cluster percolante (si hay)
        sizes.push_back(cluster_sizes(id_matrix, L));  //Guarda los tamaños de todos los clusters
        
        if(check_if_percolant(id_matrix, L)[0] == 1)
            percolations++;
    }

    stats(sizes, percolations);
    return 0;   
}