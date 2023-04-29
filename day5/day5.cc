#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // For std::find_if and std::isspace
#include <list>
#include <sstream>
#include<unistd.h>               // for linux 



using namespace std;

int getNumberOfStacks(string line){

    line.erase(find_if(line.rbegin(), line.rend(), [](unsigned char ch) {
        return !isspace(ch);            // Remove trailing whitespace
    }).base(), line.end());

    return stoi(line.substr(line.find_last_of(" ") + 1));

    return 0;
}

void CrateMover9000(string line, list <char> StackOfSupply[]){
    istringstream iss(line);
    string command;
    int numberOfPops, popStack, pushStack;

    iss >> command >> numberOfPops >> command >> popStack >> command >> pushStack; // extract the necessary info
    for(int i = 0; i < numberOfPops; i++){
        StackOfSupply[pushStack-1].push_back(StackOfSupply[popStack-1].back());
        StackOfSupply[popStack-1].pop_back();
    }
}

void CrateMover9001(string line, list <char> StackOfSupply[]){
    istringstream iss(line);
    string command;
    int numberOfPops, popStack, pushStack;

    iss >> command >> numberOfPops >> command >> popStack >> command >> pushStack; // extract the necessary info

    for(int i = numberOfPops; i > 0; i--){
        auto rit = StackOfSupply[popStack-1].rbegin();
        advance(rit, i-1);
        StackOfSupply[pushStack-1].push_back(*rit);
        StackOfSupply[popStack-1].erase(next(rit).base());
    }

}

int main() {
    ifstream myfile;
    ofstream outfile("helper.txt");

    string line;
    myfile.open("input.txt");

    int numberOfStacks = 0;
    string prevLine;

    while ( getline (myfile,line) ) {       // Loop to get stacks
        if(line == ""){
            numberOfStacks = getNumberOfStacks(prevLine);
            break;
        }
        outfile << line << endl;
        prevLine = line;
    }

    list <char> StackOfSupplyCrate9000[numberOfStacks];

    ifstream myfile2;
    myfile2.open("helper.txt");

    int stackCounter;
    while ( getline (myfile2,line) ) {                      // Fill each stack with its cargo.
        for(int i = 0; i < numberOfStacks; i++){
            int offset = (i*4) + 1;                         // Find the offset of the cargo and the stack it should go to.
            char cargo = line[offset];
            if(cargo != ' ')
                StackOfSupplyCrate9000[i].push_front(cargo);    
        }
    }

    for(int i = 0; i < numberOfStacks; i++)
        StackOfSupplyCrate9000[i].pop_front();       // remove  stack number.

    list<char> StackOfSupplyCrate9001[numberOfStacks];
    
    for(int i = 0; i < numberOfStacks; i++)
        StackOfSupplyCrate9001[i] = list<char>(StackOfSupplyCrate9000[i]);

    for(int i = 0; i < numberOfStacks; i++){
            for (auto v : StackOfSupplyCrate9001[i]){
                cout << v << "\t"; 
            }
            cout << endl;
        }

    while ( getline (myfile,line) ) {       // Loop to get instructions
        CrateMover9000(line, StackOfSupplyCrate9000);
        CrateMover9001(line, StackOfSupplyCrate9001);
    }
    
    cout << "CrateMover 9000 Order: ";
    for(int i = 0; i < numberOfStacks; i++){
        cout  << StackOfSupplyCrate9000[i].back();
    }
    cout << endl;

    cout << "CrateMover 9001 Order: ";
    for(int i = 0; i < numberOfStacks; i++)
        cout << StackOfSupplyCrate9001[i].back();
    cout << endl;
}

