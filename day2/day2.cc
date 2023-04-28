#include <iostream>
#include <fstream>
#include <string>

#define A 1
#define B 2
#define C 3
#define X 1
#define Y 2
#define Z 3
#define Win 6
#define Draw 3
#define Lose 0

using namespace std;

int CalculateScoreA(char opponent, char me){
    switch (opponent)
    {
    case 'A':
        if(me == 'X')
            return X+Draw;
        else if (me == 'Y')
            return Y+Win;
        else
            return Z+Lose;
        break;
    case 'B':
        if(me == 'X')
            return X+Lose;
        else if (me == 'Y')
            return Y+Draw;
        else
            return Z+Win;
        break;
    default:
        if(me == 'X')
            return X+Win;
        else if (me == 'Y')
            return Y+Lose;
        else
            return Z+Draw;
        break;
    }
}

int CalculateScoreB(char opponent, char me){
    switch (opponent)
    {
    case 'A':
        if(me == 'X')
            return Z+Lose;
        else if (me == 'Y')
            return X+Draw;
        else
            return Y+Win;
        break;
    case 'B':
        if(me == 'X')
            return X+Lose;
        else if (me == 'Y')
            return Y+Draw;
        else
            return Z+Win;
        break;
    default:
        if(me == 'X')
            return Y+Lose;
        else if (me == 'Y')
            return Z+Draw;
        else
            return X+Win;
        break;
    }
}

int main() {
    ifstream myfile;
    string line;
    myfile.open("input.txt");

    int totalScore1 = 0;
    int totalScore2 = 0;
    while ( getline (myfile,line) ) {
        totalScore1 += CalculateScoreA(line[0], line[2]);
        totalScore2 += CalculateScoreB(line[0], line[2]);
    }

    cout << "Total score1: " << totalScore1 << endl;
    cout << "Total score2: " << totalScore2 << endl;
}

// For B 13143 too low