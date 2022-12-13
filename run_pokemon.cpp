/*********************************************************************
** Program Filename:assignment2.cpp
** Author: Hayden Henderson
** Date: 10/23/22
** Description: This program is designed to simulate the pokedex from pokemon. This program allows the user to search for
 pokemon in the pokemon through different methods
** Input: The user inputs the name of the file they would like to open and then selects which way they want to search for the pokemon
 lastly, the user is prompted if they want to quit or continue
** Output: The output will be either outputed in a file on in the ocnsole depending on the user choice. Also, the program outputs when errors arise
*********************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "pokemon.h"

using namespace std;

// ------------------ Main Function ------------------- //
/*********************************************************************
** Function: Main function
** Description: This function starts the program off and calls all the funcitons
** Parameters:
** Pre-Conditions: there are no pre conditions to this function
** Post-Conditions: there are no post conditions to this function
*********************************************************************/
int main(){
    Pokemon* p;
    Pokedex pokemon;
    char choice = ' ';
    string file_name;
    
    cout << "Enter the name of the file you want to open: "; // takes user input for file opening
    cin >> file_name;
    cout << endl;
    ifstream fin;
    fin.open(file_name.c_str());
    
    if (!fin.is_open()){ // checks if file exists
        cout << "Error opening file . . . " << endl;
        return 1;
    }
    
    
    populate_pokedex_data(pokemon, fin); // fills the pokedex
    fin.close();
    
    ofstream fout;
    fout.open(file_name.c_str(), ios::app);
   
    user_choice(p, fout, pokemon); // starts the base program
    fout.close();

    delete_info(pokemon); // deletes memory
    return 0;
}
