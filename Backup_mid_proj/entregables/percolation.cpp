#include "percolation.h"

std::vector<std::vector<int>> fill_matrix(int const L, double const p, std::mt19937 &gen){
    std::uniform_real_distribution<> dis(0.0, 1.0);       // uniform distribution in [0 , 1)
    std::vector<std::vector<int>> matrix(L, std::vector<int>(L, 0));
    for(int ii = 0; ii < L; ++ii) {
        for(int jj = 0; jj < L; ++jj) {
            if(dis(gen)<=p){
                matrix[ii][jj]  = 1;           // Fill elements in matrix with 1 if the random number has probability <= p
            }            
        }
    }
    return matrix;
}

std::vector<std::vector<int>> Hoshen_Kopelman(std::vector<std::vector<int>> matrix, int const L){
    int id_label = 2;
    if (matrix[0][0]!=0){
        matrix[0][0] = id_label;
    }
    for(int jj = 1; jj < L; jj++){
        if (matrix[0][jj]!=0){
            if (matrix[0][jj-1]!=0){
                matrix[0][jj] = matrix[0][jj-1];
            } else{
                id_label++;
                matrix[0][jj] = id_label;
            }
        }
    } 
    for(int ii = 1; ii < L; ii++){
        for(int jj = 0; jj < L; jj++){
            if (matrix[ii][jj]!=0){
                if (jj==0){
                    if (matrix[ii-1][0]!=0){
                        matrix[ii][0] = matrix[ii-1][0];
                    } else{
                        id_label++;
                        matrix[ii][0] = id_label;
                    }
                } else{
                    if ((matrix[ii-1][jj]==0)&&(matrix[ii][jj-1]==0)){
                        id_label++;
                        matrix[ii][jj] = id_label;
                    } else if ((matrix[ii-1][jj]==0)&&(matrix[ii][jj-1]!=0)){
                        matrix[ii][jj] = matrix[ii][jj-1];
                    } else if ((matrix[ii-1][jj]!=0)&&(matrix[ii][jj-1]==0)){
                        matrix[ii][jj] = matrix[ii-1][jj];
                    } else if ((matrix[ii-1][jj]!=0)&&(matrix[ii][jj-1]!=0)){
                        merge_clusters(matrix, L, matrix[ii][jj-1], matrix[ii-1][jj]); // gives priority to 'last ii'
                        matrix[ii][jj] = matrix[ii-1][jj];
                    } 
                } 
            } 
        } 
    }
    return matrix; 
}

std::vector<std::vector<int>> merge_clusters(std::vector<std::vector<int>> & matrix, int const L, int const id_toe, int const id_tor){
    for(int ii = 0; ii < L; ++ii) {
        for(int jj = 0; jj < L; ++jj) {
            if (matrix[ii][jj]== id_toe){
                matrix[ii][jj]= id_tor;
            }
        }
    }
    return matrix;
}

std::vector<int> check_if_percolant(std::vector<std::vector<int>> const & matrix, int const L){
    std::vector<int> results(1,0);  
    int is_unique;
    for(int ii0 = 0; ii0 < L; ++ii0) {
        for(int iif = 0; iif < L; ++iif) {
            is_unique = 1;
            if ((matrix[ii0][0]==matrix[iif][L-1])&&(matrix[ii0][0]!=0)){
                results[0] = 1;
                for (auto x: results){
                    if (x==matrix[ii0][0]){
                        is_unique =  0;
                    }
                }
                if (is_unique==1){
                    results.push_back(matrix[ii0][0]);
                }
            } 
        }
    }
    for(int jj0 = 0; jj0 < L; ++jj0) {
        for(int jjf = 0; jjf < L; ++jjf) {
            is_unique = 1;
            if ((matrix[0][jj0]==matrix[L-1][jjf])&&(matrix[0][jj0]!=0)){
                results[0] = 1;
                for (auto x: results){
                    if (x==matrix[0][jj0]){
                        is_unique =  0;
                    }
                }
                if (is_unique==1){
                    results.push_back(matrix[0][jj0]);
                } 
            }
        }
                                                                            
    }
    return results;
}

double count(std::vector<std::vector<int>> const & matrix, int const L, int const index_to_count){
    double n_elements = 0.0;
    for(int ii = 0; ii < L; ++ii) {
        for(int jj = 0; jj < L; ++jj) {
            if (matrix[ii][jj]==index_to_count){
                ++n_elements;
            } 
        }
    }
    return n_elements/(L*L);
}     

std::vector<double> cluster_sizes(std::vector<std::vector<int>> const & matrix, int const L){
    auto result = check_if_percolant(matrix, L);                                                   
    result.erase(result.begin()); 
    std::vector<double> element_sizes;
    for (auto x: result){
        element_sizes.push_back(count(matrix, L, x)); 
    }
    return element_sizes;
}

void stats(std::vector<std::vector<double>> const & sizes, int const percolations){
    double sum = 0.0, desv = 0.0;

    if(percolations == 0){
        std::cout << 0 << "\t" << 0 << "\t" << 0 << "\n";
    }else{

    for(auto j : sizes){
        if(j.size() == 1){
            for(auto k : j)
                sum += k;
        }
        if(j.size() > 1){
            auto bigger_cluster = std::max_element(j.begin(), j.end());
            double bigger = *bigger_cluster;
            sum += bigger;
        }
    }

    for(auto j : sizes){
        if(j.size() == 1){
            for(auto k : j)
                desv += std::pow((k - sum/percolations), 2);
        }
        if(j.size() > 1){
            auto bigger_cluster = std::max_element(j.begin(), j.end());
            double bigger = *bigger_cluster;
            desv += std::pow((bigger - sum/percolations), 2);
        }
    }
    std::cout << sum/percolations << "\t" << sqrt(desv/(percolations-1)) << "\t" << percolations/10.0 << "\n";
    }
}