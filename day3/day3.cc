#include <iostream>
#include <fstream>
#include <string>
#include<list>

using namespace std;

int calculateTotal(string line){
    char common;
    for (int i = 0; i < line.length() / 2; i++){
        for(int b = line.length()/2; b < line.length(); b++){
            if(line[i] == line[b]){
                common = line[i];
                break;
            }
        }
    }
    if (common > 'Z')
        return (int(common) - 96);
    else
        return (int(common) - 38);
}

int calculateThreeElfGroup(string line){
    int first_idx = line.find(' ');
    int second_idx = line.find('#');
    list<char>duplicateChars;

    for(int i = 0; i < first_idx; i++){
        for(int j = first_idx+1; j < second_idx; j++){
            if(line[i] == line[j])
                duplicateChars.push_back(line[i]);
        }
    }
    char common; 
    list<char>::iterator it;
    for(it = duplicateChars.begin(); it != duplicateChars.end(); ++it){
        for(int i = second_idx+1; i < line.length(); i++){
            if(*it == line[i]){
                common = line[i];
            }
        }
    }

    if (common > 'Z')
        return (int(common) - 96);
    else
        return (int(common) - 38);
}

int main() {
    ifstream myfile;
    string line;
    myfile.open("input.txt");

    int totalOne = 0;
    int totalThree = 0;
    int counter = 0;
    string newline = "";
    while ( getline (myfile,line) ) {
        totalOne += calculateTotal(line);
        counter++;
        if(counter == 1){
            newline = line;
        } else if (counter == 2){
             newline = newline + " " + line;
        } else if(counter == 3){
            newline = newline + "#" + line;
            totalThree += calculateThreeElfGroup(newline);
            newline = "";
            counter = 0;
        }

    }

    cout << "Sum of priorities: " << totalOne << endl;
    cout << "Sum of Three priorities: " << totalThree << endl;


}

// lowercase - 96
// uppercase - 38