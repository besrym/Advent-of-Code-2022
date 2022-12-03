#include <iostream>
#include <fstream>


using namespace std;

int main(){

    string line;
    ifstream infile("input.txt");
    infile.is_open();


    while (std::getline(infile, line)) {

        cout << line << endl;

    }


}