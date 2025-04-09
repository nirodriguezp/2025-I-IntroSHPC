#include <iostream>
#include <vector>

void print_v0(const std::vector<double>& mydata);
void print_v1(const std::vector<double>& mydata);
int main()
{
    std::vector<double> data = {0.1, 0.5 ,-0.6};
    print_v0(data);
    print_v1(data);

    return 0;
}

void print_v0(const std::vector<double>& mydata){

    for(int i=0; i<mydata.size(); i++){

        std::cout << mydata[i] << "  ";
    }
    std::cout << "\n";
}

void print_v1(const std::vector<double>& mydata){

    for(auto x: mydata){

        std::cout << x << "  ";
    }
    std::cout << "\n";
}

//cons le quita permiso a las funciones print de modificar el vector data.