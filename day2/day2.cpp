#include "iostream"
#include <fstream>

const char ROCK_ME = 'X';
const char PAPER_ME = 'Y';
const char SCISSORS_ME = 'Z';

const char ROCK_COMPONENT = 'A';
const char PAPER_COMPONENT = 'B';
const char SCISSORS_COMPONENT = 'C';

const int ROCK_SCORE = 1;
const int PAPER_SCORE = 2;
const int SCISSORS_SCORE = 3;


bool won(char A, char B){
    if (A == ROCK_COMPONENT && B == PAPER_ME) { return true; }
    else if (A == PAPER_COMPONENT && B == SCISSORS_ME) { return true; }
    else if (A == SCISSORS_COMPONENT && B == ROCK_ME) { return true; }
    else { return false; }
}

bool draw(char A, char B){
    if (A == ROCK_COMPONENT && B == ROCK_ME) { return true; }
    else if (A == PAPER_COMPONENT &&  B == PAPER_ME) { return true; }
    else if (A == SCISSORS_COMPONENT && B == SCISSORS_ME) { return true; }
    else { return false; }
}

int part_one(char B, bool win, bool draw){
    int tmp = 0;
    if ( win ) { tmp = 6; }
    if ( draw ) { tmp = 3; }

    if ( B == ROCK_ME) { return ROCK_SCORE + tmp; }
    else if ( B == SCISSORS_ME) { return SCISSORS_SCORE + tmp; }
    else if ( B == PAPER_ME) { return PAPER_SCORE + tmp; }
    else { return 42; }

}

int part_two(char A, char B) {
    /*
     * Y --> DRAW
     * X --> LOSE
     * Z --> WIN
     */

    if (A == ROCK_COMPONENT) {
        if (B == 'Y') { return ROCK_SCORE + 3; }
        else if (B == 'X') { return SCISSORS_SCORE + 0; }
        else if (B == 'Z') { return PAPER_SCORE + 6; }
        else {
            std::cout << "err" << std::endl;
            return 42; }
    }
    else if (A == SCISSORS_COMPONENT) {
        if (B == 'Y') { return SCISSORS_SCORE + 3; }
        else if (B == 'X') { return PAPER_SCORE + 0; }
        else if (B == 'Z') { return ROCK_SCORE + 6; }
        else { return 42; }
    }
    else if (A == PAPER_COMPONENT) {
        if (B == 'Y') { return PAPER_SCORE + 3; }
        else if (B == 'X') { return ROCK_SCORE + 0; }
        else if (B == 'Z') { return SCISSORS_SCORE + 6; }
        else { return 42; }
    }
    else { return 42; }
}


int main(){

    std::string line;
    std::ifstream infile("input.txt");
    infile.is_open();

    int score_part_1 = 0;
    int score_part_2 = 0;

    while (std::getline(infile, line)) {

        const char *component = line.c_str();

        char A = component[0]; // COMPONENT
        char B = component[2]; // ME

        bool WIN = won(A, B);
        bool DRAW = draw(A, B);

        /*
        if ( WIN ) { score_part_1 += 6; }
        if ( DRAW ) { score_part_1 += 3; }
        if ( B == ROCK_ME) { score_part_1 += ROCK_SCORE; }
        else if ( B == SCISSORS_ME) { score_part_1 += SCISSORS_SCORE; }
        else if ( B == PAPER_ME) { score_part_1 += PAPER_SCORE; }
        */

        score_part_1 += part_one(B, WIN, DRAW);
        score_part_2 += part_two(A, B);

    }

    std::cout << "part one:   " << score_part_1 << std::endl;
    std::cout << "part two:   " << score_part_2 << std::endl;


}

