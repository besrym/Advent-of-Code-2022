#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

const string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int findDuplicate(string A, string B){
    map <char, int> countA;
    map <char, int> countB;
    for (int i = 0; i < A.length(); i++) {
        countA[A[i]]++;
        countB[B[i]]++;
    }
    char c;
    for (auto itA : countA){
        for (auto itB : countB) {
            if (itA.first == itB.first){
                c = itA.first;
            }
        }
    }
    return abc.find(c) + 1;
}

int part2(string A){
    map <char, int> count;

    for (int i = 0; i < A.length(); i++) {
        count[A[i]]++;

    }
    char c;
    for (auto it : count) {
        if (it.second == 3){
            c = it.first;
        }
    }
    return abc.find(c) + 1;
}

string remove_duplicates(string s){

    for ( std::string::size_type i = 0; i < s.size(); i++ )
    {
        std::string::size_type j = i + 1;
        while ( j < s.size() )
        {
            if ( s[i] == s[j] )
            {
                s.erase( j, 1 );
            }
            else
            {
                ++j;
            }
        }
    }

    return s;
}

int main(){

    string line;
    ifstream infile("input.txt");
    infile.is_open();

    int priorities_p1 = 0;
    int priorities_p2 = 0;

    string strGroup;
    vector<string> V;

    while (std::getline(infile, line)) {
        V.push_back(line);
        string substr1 = line.substr(0,line.length()/2);
        string substr2 = line.substr(line.length()/2);
        priorities_p1 += findDuplicate(substr1, substr2);
    }

    for (int i = 0; i < V.size(); i+=3){
        string A = V[i];
        string B = V[i+1];
        string C = V[i+2];

        strGroup = remove_duplicates(A) + remove_duplicates(B) + remove_duplicates(C);
        //cout << strGroup << endl;
        priorities_p2 += part2(strGroup);
    }

    cout << "part 1: " << priorities_p1 << endl;
    cout << "part 2: " << priorities_p2 << endl;
}