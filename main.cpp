#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
using Plateau = vector<vector<int>>;


void affichageConsole(Plateau plateau);

int main() {
    cout << "Regles de la puissance 4 : " << endl;

    const int longueur = 7;
    const int hauteur = 6;

    Plateau plateau(hauteur, std::vector<int>(longueur, 0));
    affichageConsole(plateau);


    return EXIT_SUCCESS;
}



void affichageConsole(Plateau plateau) {
    vector<int> colonne = plateau[0];
    for(vector<int> colonne: plateau) {
        for(int i : colonne) {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}