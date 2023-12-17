/*Created by: Erin Swinson
* Created on: 12/7/2023
* Last edited: 12/10/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>
#include "GroceryItem.h"

using namespace std;

//function to read in the file and close once done
void inputData(map<string, int>& groceryMap) {
    ifstream infile;
    infile.open("CS210_Project_Three_Input_File.txt");
    if(!infile.is_open()){
        cout << "Input file reading failed." << endl;
        return;
    }
    string item;

    while (infile >> item) {
        groceryMap[item]++;
    }

    infile.close();
}
//funtion to print the menu text
void displayMenu(){
    cout << "1. Search for an item." << endl; 
    cout << "2. Display all frequencies." << endl;
    cout << "3. Print histogram." << endl;
    cout << "4. Exit."<< endl;
    cout << "5. Create a back up file." << endl;
}

//function to search for an item
void itemSearch(map<string, int>& groceryMap){
    string itemSearch;
    cout << "Enter item you wish to search for." <<endl;
    cin >> itemSearch;
    if (groceryMap.find(itemSearch) != groceryMap.end()){
        cout << itemSearch << ": " << groceryMap[itemSearch] << endl;
    }
    else {
       cout << "Item not found. Please try again. Tip: Items all begin with a capital letter and are case and spelling sensitive." << endl;
    }
}
//fuction to display all frequencies
void displayFrequencies(map<string, int>& groceryMap){
    for (auto entry : groceryMap) {
        cout << entry.first << " " << entry.second << endl;
    }
}

//function to print histogram
void displayHistogram(map<string, int>& groceryMap) {
    for (auto entry : groceryMap) {
        cout << entry.first << " ";
        for (int i = 0; i < entry.second; i++){
            cout << "*";
        }
        cout << endl;
    }
}

//function to create aditional data file
void createData(map<string, int>& groceryMap){
    ofstream frequency;
    frequency.open("frequency.dat");
    if(!frequency.is_open()) {
        cout << "File creation failed.";
    }

    for (auto entry : groceryMap) {
        frequency << entry.first << " " << entry.second << endl;
    }
    frequency.close();
}


//Main program
int main() {
map<string, int>groceryMap;
inputData(groceryMap); //will initialize reading the project file into the programs map
int option = 0;

while(option != 4){
    displayMenu();
    cin >> option;
    //verifies input is an interger
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input." << endl;
    }
    if(option == 1){
        itemSearch(groceryMap); //will initialize searching for an item function
    }
    if(option == 2){
        displayFrequencies(groceryMap); //will initialize a numeric count of all items and thier frequencies
    }
    if(option == 3){
        displayHistogram(groceryMap); //will initialize a vizual histogram using "*"
    }
    if(option == 4){ //ends the while loop in main and exits the program
        cout << "Program exited." << endl;
    }
    if(option == 5){
        createData(groceryMap); //will initialize a loop to right grocery map to a .dat file
    }
    
    if (option != 1 && option != 2 && option != 3 && option != 4 && option !=5) {
        cout << "Invalid input." << endl; //error handles if a number is entered that is not valid to the menu
    }
} 
    return 0;
}




