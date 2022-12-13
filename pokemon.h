
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Pokemon {
    int dex_num;
    string name;
    string type;
    int  num_moves;
    string* moves;
};

struct Pokedex {
    string trainer;
    int num_pokemon;
    Pokemon* dex;
};


void user_choice(Pokemon* p, ofstream &fout, Pokedex &pokemon);
void direct_user(char choice, Pokemon* p, ofstream &fout, Pokedex &pokemon);
Pokemon* create_pokemons(int size);
void populate_pokedex_data(Pokedex &pokemon, ifstream &fin);
void populate_pokemon(Pokemon &p, ifstream &fin);
string* create_moves(int moves);
void print_search(Pokemon* p, int position, Pokedex &pokemon);
void populate_moves(int moves, string* p, ifstream &fin);
void search_by_dex_num(Pokemon* p, int size, ofstream &fout, bool output_console, Pokedex &pokemon);
void search_by_name(Pokemon* p, int size, ofstream &fout, bool output_console, Pokedex &pokemon);
void search_by_type(Pokemon* p, int size, ofstream &fout, bool output_console, Pokedex &pokemon);
void option_one(Pokemon* p, ofstream &fout, Pokedex &pokemon);
void option_two(Pokemon* p, ofstream &fout, Pokedex &pokemon);
void option_three(Pokemon* p, ofstream &fout, Pokedex &pokemon);
void option_four(Pokemon* p, ofstream &fout, Pokedex &pokemon);
void output_search_in_file(Pokemon* p, int pos, Pokedex& pokemon);
void open_output_file(ofstream &output_file);
void delete_info(Pokedex &pokemon);
