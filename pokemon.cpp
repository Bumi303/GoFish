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

/*********************************************************************
** Function: user choice
** Description:This funtion asks the user which option they wish to choose to search for pokemon
** Parameters: Pokemon *p, ofstream &fout, Pokedex &pokemon
** Pre-Conditions: the only precondition is if the file exists
** Post-Conditions: the user correctly entered their choice
*********************************************************************/
void user_choice(Pokemon *p, ofstream &fout, Pokedex &pokemon){
    char c = ' ';
    
    do{
        cout << endl;
        cout << "Welcome to the PokeDex!" << endl << endl;
        cout << "1. Search by dex number" << endl;
        cout << "2. Search by name" << endl;
        cout << "3. Search by type" << endl;
        cout << "Q. Quit" << endl;
        cout << "Enter Choice: " ;
        cin >> c;
        cout << endl;
        
    }while (c != 'q' && c != 'Q' && c != '1' && c != '2' && c != '3' && c != '4');
    if (c != 'q' && c != 'Q'){
        direct_user(c, p, fout, pokemon);
    }
}

/*********************************************************************
** Function:direct_user
** Description: the function directs the user to which option they choose in user choice
** Parameters:char choice, Pokemon* p, ofstream &fout, Pokedex &pokemon
** Pre-Conditions: they corrected entered their choice from user choice
** Post-Conditions: there are no post conditions
*********************************************************************/
void direct_user(char choice, Pokemon* p, ofstream &fout, Pokedex &pokemon){
    
    if (choice == '1'){ // search by dex num
        option_one(p, fout, pokemon);
    }
    
    else if(choice == '2') { // search by name
        option_two(p, fout, pokemon);
    }
    
    else if(choice == '3') { // search by type:
        option_three(p, fout, pokemon);
    }
    user_choice(p, fout, pokemon);
}

/*********************************************************************
** Function:option_one
** Description: sends information to search by dex and asks user how they want to output their info
** Parameters:Pokemon* p, ofstream &fout, Pokedex &pokemon
** Pre-Conditions: the user inputs option one
** Post-Conditions:there are no post conditions
*********************************************************************/
void option_one(Pokemon* p, ofstream &fout, Pokedex &pokemon){// search by dex num
    int output_choice;
    cout << "Would you like it outputed on screen or in a file {1 - on screen : 2 - in a file}? ";
    cin >> output_choice;
    cout << endl;
    if (output_choice == 1){
        search_by_dex_num(p, pokemon.num_pokemon, fout, true, pokemon);
    }
    else if(output_choice == 2){
        search_by_dex_num(p, pokemon.num_pokemon, fout, false, pokemon);
    }
}

/*********************************************************************
** Function:option_two
 ** Description: sends information to search by name and asks user how they want to output their info
 ** Parameters:Pokemon* p, ofstream &fout, Pokedex &pokemon
 ** Pre-Conditions: the user inputs option two
 ** Post-Conditions:there are no post conditions
*********************************************************************/
void option_two(Pokemon* p, ofstream &fout, Pokedex &pokemon){ // search by name
    int output_choice;
    cout << "Would you like it outputed on screen or in a file {1 - on screen : 2 - in a file}? ";
    cin >> output_choice;
    cout << endl;
    if (output_choice == 1){
        search_by_name(p, pokemon.num_pokemon, fout, true, pokemon);
    }
    else if(output_choice == 2){
        search_by_name(p, pokemon.num_pokemon, fout, false, pokemon);
    }
}

/*********************************************************************
** Function:option_three
 ** Description: sends information to search by type and asks user how they want to output their info
 ** Parameters:Pokemon* p, ofstream &fout, Pokedex &pokemon
 ** Pre-Conditions: the user inputs option three
 ** Post-Conditions:there are no post conditions
*********************************************************************/
void option_three(Pokemon* p, ofstream &fout, Pokedex &pokemon){ // search by type
    int output_choice;
    cout << "Would you like it outputed on screen or in a file {1 - on screen : 2 - in a file}? ";
    cin >> output_choice;
    cout << endl;
    if (output_choice == 1){
        search_by_type(p, pokemon.num_pokemon, fout, true, pokemon);
    }
    else if(output_choice == 2){
        search_by_type(p, pokemon.num_pokemon, fout, false, pokemon);
    }
}

// --------------------------Allocate Space and----------------------------------
// --------------------------Populate structs-----------------------------------

/*********************************************************************
** Function:create_moves
** Description: allocates memory to create the array of moves
** Parameters:int moves
** Pre-Conditions:there are no pre conditions
** Post-Conditions:there are no post conditions
*********************************************************************/
string* create_moves(int moves){
    string* arr_moves = new string[moves];
    return arr_moves;
}

/*********************************************************************
** Function:create_pokemons
** Description: allocates memory to create the array of pokemons
** Parameters:int size
** Pre-Conditions:there are no pre conditions
** Post-Conditions: there are no post conditions
*********************************************************************/
Pokemon* create_pokemons(int size){
    Pokemon* p = new Pokemon[size];
    return p;
}

/*********************************************************************
** Function:populate_pokedex_data
** Description: populates the pokemon struct with pokemon from the file
** Parameters: Pokedex &pokemon, ifstream &fin
** Pre-Conditions:there are no pre conditions
** Post-Conditions:there are no post conditions
*********************************************************************/
void populate_pokedex_data(Pokedex &pokemon, ifstream &fin){
    fin >> pokemon.num_pokemon;
    pokemon.dex = create_pokemons(pokemon.num_pokemon);// populates all pokemon info from file
    for(int i = 0; i < pokemon.num_pokemon; i++){
        populate_pokemon(pokemon.dex[i], fin);
    }
}

/*********************************************************************
** Function:populate_pokemon
** Description: populates the pokemon struct with pokemon from the file
** Parameters: Pokemon &p, ifstream &fin
** Pre-Conditions:there are no pre conditions
** Post-Conditions: there are no post conditions
*********************************************************************/
void populate_pokemon(Pokemon &p, ifstream &fin){
    fin >> p.dex_num >> p.name >> p.type >> p.num_moves;
    p.moves = create_moves(p.num_moves);
    for (int k = 0; k < p.num_moves; k++){ // populates all pokemon info from file
        fin >> p.moves[k];
    }
}

/*********************************************************************
** Function:populate_moves
** Description: this funciton populates all the moves of the
** Parameters: int moves, string* p, ifstream &fin
** Pre-Conditions:there are no pre conditions
** Post-Conditions:there are no post conditions
*********************************************************************/
void populate_moves(int moves, string* p, ifstream &fin){
    for (int k = 0; k < moves; k++){ // populates the moves struct
        fin >> p[k];
    }
}

// -------------------------------------------------------------
// -------------------------------------------------------------

/*********************************************************************
** Function: print_search
** Description: this funciton outputs the info into the console
** Parameters: Pokemon* p, int pos, Pokedex &pokemon
** Pre-Conditions: the user has to select output via terminal
** Post-Conditions: only exit after fully outputed
*********************************************************************/
void print_search(Pokemon* p, int pos, Pokedex &pokemon){ // print search in terminal
    cout << endl;
    cout << pokemon.dex[pos].dex_num << " " << pokemon.dex[pos].name << " " << pokemon.dex[pos].type << " " << pokemon.dex[pos].num_moves << " " << endl;
    
    for (int i = 0; i < pokemon.dex[pos].num_moves; i++){ // iterates through moves
        cout << pokemon.dex[pos].moves[i] << " ";
    }
    cout << endl;
}

/*********************************************************************
** Function:output_search_in_file
** Description: this funciton outputs the info in a file
** Parameters: Pokemon* p, int pos, Pokedex& pokemon
** Pre-Conditions: the user has to selete output in file
** Post-Conditions: there are no post conditions
*********************************************************************/
void output_search_in_file(Pokemon* p, int pos, Pokedex& pokemon){ // output seach in a txt file
    ofstream output_file;
    open_output_file(output_file);
    cout << endl;
    output_file << pokemon.dex[pos].dex_num << " " << pokemon.dex[pos].name << " " << pokemon.dex[pos].type << " " << pokemon.dex[pos].num_moves << "\n";
    
    for (int i = 0; i < pokemon.dex[pos].num_moves; i++){ // iterates through moves
        output_file << pokemon.dex[pos].moves[i] << " ";
    }
    output_file << "\n";
    
    output_file.close();
}

/*********************************************************************
** Function: open_output_file
** Description: this funciton opens the output file that the user wants to output to
** Parameters: ofstream &output_file
** Pre-Conditions: if the user decided to output to file
** Post-Conditions: there are no post conditions
*********************************************************************/
void open_output_file(ofstream &output_file){
    string file_name;
    
    cout << "Enter the name of the file you want to open: ";
    cin >> file_name;
    cout << endl;
    
    output_file.open(file_name.c_str(), ios::app);
}

/*********************************************************************
** Function: search_by_dex_num
 ** Description: searchs for pokemon by type in the dex file
 ** Parameters:Pokemon* p, int size, ofstream &fout, bool output_console, Pokedex &pokemon
 ** Pre-Conditions: the preconditions is that the user seleted they wanted to search by dex num
 ** Post-Conditions: only exits once the value is found or the message that it wasn't found
*********************************************************************/
// --------- OPTION 1 Search by Dex num ---------- //
void search_by_dex_num(Pokemon* p, int size, ofstream &fout, bool output_console, Pokedex &pokemon){
    int temp_dex_num;
    bool found = false;
    
    cout << "Which dex number would you like to search for? ";
    cin >> temp_dex_num;
    cout << endl;
    for (int i = 0; i < size; i++){
        if (pokemon.dex[i].dex_num == temp_dex_num){
            if (output_console == true){
                print_search(p, i, pokemon);// print output
            }
            else{
                output_search_in_file(p, i, pokemon);//output into file
            }
            found = true;
            break;
        }
    }
    if (found == false){
        cout << "A pokemon of dex num " << temp_dex_num << " does not exist" << endl;
    }
}

/*********************************************************************
** Function:search_by_name
 ** Description: searchs for pokemon by type in the dex file
 ** Parameters:Pokemon* p, int size, ofstream &fout, bool output_console, Pokedex &pokemon
 ** Pre-Conditions: the preconditions is that the user seleted they wanted to search by name
 ** Post-Conditions: only exits once the value is found or the message that it wasn't found
*********************************************************************/
// --------- OPTION 2 Search by Name ---------- //
void search_by_name(Pokemon* p, int size, ofstream &fout, bool output_console, Pokedex &pokemon){
    string temp_name;
    bool found = false;
    cout << "Which name would you like to search for? ";
    cin >> temp_name;
    cout << endl;
    for (int i = 0; i < size; i++){
        if (pokemon.dex[i].name == temp_name){
            if (output_console == true){
                print_search(p, i, pokemon); // print output
            }
            else{
                output_search_in_file(p, i, pokemon); //output into file
            }
            found = true;
            
            break;
        }
    }
    if (found == false){
        cout << "A pokemon of the name " << temp_name << " does not exist" << endl;
    }
}

/*********************************************************************
** Function:search_by_type
** Description: searchs for pokemon by type in the dex file
** Parameters:Pokemon* p, int size, ofstream &fout, bool output_console, Pokedex &pokemon
** Pre-Conditions: the preconditions is that the user seleted they wanted to search by type
** Post-Conditions: only exits once the value is found or the message that it wasn't found
*********************************************************************/
// --------- OPTION 3 Search by Type ---------- //
void search_by_type(Pokemon* p, int size, ofstream &fout, bool output_console, Pokedex &pokemon){
    string temp_type;
    bool found = false;
    cout << "Which type would you like to search for? ";
    cin >> temp_type;
    cout << endl;
    for (int i = 0; i < size; i++){
        if (pokemon.dex[i].type == temp_type){
            if (output_console == true){
                print_search(p, i, pokemon);// print output
            }
            else{
                output_search_in_file(p, i, pokemon);//output into file
            }
            found = true;
        }
    }
    if (found == false){
        cout << "A pokemon of the type " << temp_type << " does not exist" << endl;
    }
}

/*********************************************************************
** Function: delete_info
** Description: deletes the allocated memory
** Parameters:Pokedex &pokemon
** Pre-Conditions: the program is completed and it arrived here without errors
** Post-Conditions: there are no post conditions
*********************************************************************/
void delete_info(Pokedex &pokemon){ //free memory from the heap
    for (int i = 0; i < pokemon.num_pokemon; i++){
        delete [] pokemon.dex[i].moves;
        pokemon.dex[i].moves = NULL;
    }
    delete [] pokemon.dex;
    pokemon.dex = NULL;
}
 


