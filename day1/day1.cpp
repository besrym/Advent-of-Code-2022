#include <iostream>
#include <fstream>
#include <vector>

int main(){

    std::string line;
    std::vector<int> elves;
    int calo = 0;

    std::ifstream infile("input.txt");
    infile.is_open();

    while (std::getline(infile, line)) {

        if (line.empty()){
            elves.push_back(calo);
            calo = 0;
        }
        else{
            int add = std::stoi(line);
            calo += add;
        }
    }

    int top_three = 0;
    int maxElementIndex1 = std::max_element(elves.begin(),elves.end()) - elves.begin();

    for (int i = 0; i<3; i++){
        int p = *std::max_element(elves.begin(), elves.end());
        int maxElementIndex = std::max_element(elves.begin(),elves.end()) - elves.begin();
        elves.erase(elves.begin() + maxElementIndex);
        top_three += p;
    }

    std::cout << maxElementIndex1 << std::endl;
    std::cout << top_three << std::endl;

}

