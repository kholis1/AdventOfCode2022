#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct elf {
    int eldId;
    int calories;
} Elf;

int main(){
    ifstream myfile;
    string line;
    myfile.open("input.txt");
    int ElfCounter = 1;

    Elf MaxElf = {0, 0};
    Elf SecondElf = {0, 0};
    Elf ThirdElf = {0, 0}; 
    Elf CurrentElf = {ElfCounter, 0};

    while ( getline (myfile,line) ) {
        if(line == ""){
            ElfCounter++;
            if(CurrentElf.calories > MaxElf.calories){
                ThirdElf = SecondElf;
                SecondElf = MaxElf;
                MaxElf = CurrentElf;

            } else if (CurrentElf.calories > SecondElf.calories) {
                ThirdElf = SecondElf;
                SecondElf = CurrentElf;
            } else if (CurrentElf.calories > ThirdElf.calories) {
                ThirdElf = CurrentElf;
            }
            CurrentElf.calories = 0;
            CurrentElf.eldId = ElfCounter;
        }
        else{
            CurrentElf.calories += stoi(line);
        }
    }

    if(CurrentElf.calories > MaxElf.calories){
        ThirdElf = SecondElf;
        SecondElf = MaxElf;
        MaxElf = CurrentElf;
    } else if (CurrentElf.calories > SecondElf.calories) {
        ThirdElf = SecondElf;
        SecondElf = CurrentElf;
    } else if (CurrentElf.calories > ThirdElf.calories) {
        ThirdElf = CurrentElf;
    }


    cout << "Total calories carried by an elf are " << MaxElf.calories << endl;
    
    cout << "Total calories carried by 3 elfs are " << MaxElf.calories+SecondElf.calories+ThirdElf.calories << endl;

}