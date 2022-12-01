#include "iostream"
#include <fstream>
#include <vector>

int main(){

    std::string line;
    std::vector<int> elfs;
    int calo = 0;

    std::ifstream infile("input.txt");
    infile.is_open();

    while (std::getline(infile, line)) {

        if (line.empty()){
            elfs.push_back(calo);
            calo = 0;
        }
        else{
            int add = std::stoi(line);
            calo += add;
        }
    }

    int three = 0;
    int maxElementIndex1 = std::max_element(elfs.begin(),elfs.end()) - elfs.begin();

    for (int i = 0; i<3; i++){
        int p = *std::max_element(elfs.begin(), elfs.end());
        int maxElementIndex = std::max_element(elfs.begin(),elfs.end()) - elfs.begin();
        elfs.erase (elfs.begin() + maxElementIndex);
        three += p;
    }

    std::cout << maxElementIndex1 << std::endl;
    std::cout << three << std::endl;

}

