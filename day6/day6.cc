#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int CheckLine(string line, int consecutiveNumbers){
    list<char> CharsList;
    list<char> UniqueValuesList;
    for(int i = 0; i < consecutiveNumbers; i++){
        CharsList.push_back(line[i]);
    }

    UniqueValuesList = list<char>(CharsList);
    UniqueValuesList.sort();
    UniqueValuesList.unique();

    if(UniqueValuesList.size() == consecutiveNumbers)
        return 4;

    for(int i = consecutiveNumbers; i < line.length(); i++){
        CharsList.pop_front();
        CharsList.push_back(line[i]);

        UniqueValuesList = list<char>(CharsList);
        UniqueValuesList.sort();
        UniqueValuesList.unique();

        if(UniqueValuesList.size() == consecutiveNumbers)
            return i+1;
    }

    return -1;
}


int main() {
    ifstream myfile;

    string line;
    myfile.open("input.txt");

    getline (myfile,line);

    int nthNumber;
    if((nthNumber = CheckLine(line, 4)) != -1)
        cout << "First signal processed at Part1 is at " << nthNumber << "th character" << endl;
    else
        cout << "Could not process singal" << endl;
    
    if((nthNumber = CheckLine(line, 14)) != -1)
        cout << "First signal processed at Part2 is at " << nthNumber << "th character" << endl;
    else
        cout << "Could not process singal" << endl;

    
}

