#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int part1(string line){
    string firstElfArea = line.substr(0, line.find(","));
    string secondElfArea = line.substr(line.find(",")+1);
    
    int firstElfArea1 = stoi(firstElfArea.substr(0, firstElfArea.find("-")));
    int firstElfArea2 = stoi(firstElfArea.substr(firstElfArea.find("-")+1));
    int secondElfArea1 = stoi(secondElfArea.substr(0, secondElfArea.find("-")));
    int secondElfArea2 = stoi(secondElfArea.substr(secondElfArea.find("-")+1));
    if(secondElfArea1 >= firstElfArea1 && firstElfArea2 >= secondElfArea2){
        return 1;
    } else if (firstElfArea1 >= secondElfArea1 && secondElfArea2 >= firstElfArea2) {
        return 1;
    }

    return 0;
}

int part2(string line){
    string firstElfArea = line.substr(0, line.find(","));
    string secondElfArea = line.substr(line.find(",")+1);
    
    int firstElfArea1 = stoi(firstElfArea.substr(0, firstElfArea.find("-")));
    int firstElfArea2 = stoi(firstElfArea.substr(firstElfArea.find("-")+1));
    int secondElfArea1 = stoi(secondElfArea.substr(0, secondElfArea.find("-")));
    int secondElfArea2 = stoi(secondElfArea.substr(secondElfArea.find("-")+1));

    if(firstElfArea2 < secondElfArea1)
        return 0;
    else if (firstElfArea1 > secondElfArea2)
        return 0;

    return 1;
}


int main() {
    ifstream myfile;
    string line;
    myfile.open("input.txt");

    int count1 = 0;
    int count2 = 0;

    while ( getline (myfile,line) ) {
        if(part1(line) == 1){
            count1++;
            count2++;
        } else if (part2(line) == 1){
            count2++;
        }
    }

    cout << "Total count: " << count1 << endl;
    cout << "Total overlaps: " << count2 << endl;


}
