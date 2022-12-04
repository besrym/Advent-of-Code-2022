#include <iostream>
#include <fstream>

using namespace std;

int check_fully_overlap(int x1, int x2, int y1, int y2){
    if ( x1 <= y1 && y2 <= x2){ return 1;}
    else if ( y1 <= x1 && x2 <= y2) { return 1;}
    else { return 0;}
}

int check_overlap(int x1, int x2, int y1, int y2){
    if (max(x1, y1) <= min(x2, y2)) { return 1;}
    else { return 0; }
}

int main(){

    string line;
    ifstream infile("input.txt");
    infile.is_open();

    int fully_contain = 0;
    int partly_contain = 0;


    while (std::getline(infile, line)) {

        string delimiter = ",";
        string ID_1 = line.substr(0, line.find(delimiter));
        string ID_2 = line.substr(line.find(delimiter));

        delimiter = "-";
        string start_1 = ID_1.substr(0, ID_1.find(delimiter));
        string end_1 = ID_1.substr( ID_1.find(delimiter) + 1);
        string start_2 = ID_2.substr(1, ID_2.find(delimiter)-1);
        string end_2 = ID_2.substr( ID_2.find(delimiter) + 1);

        int x1 = stoi(start_1);
        int x2 = stoi(end_1);
        int y1 = stoi(start_2);
        int y2 = stoi(end_2);

        fully_contain += check_fully_overlap(x1, x2, y1, y2);
        partly_contain += check_overlap(x1, x2, y1, y2);

    }

    cout << fully_contain << endl;
    cout << partly_contain << endl;

}