#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
using Plateau = vector<vector<int>>;


void affichageConsole(Plateau plateau);
bool verifyInput(Plateau& plateau, unsigned int x, int joueur);

int main() {
    cout << "Regles de la puissance 4 : " << endl;

    const int longueur = 7;
    const int hauteur = 6;

    Plateau plateau(hauteur, std::vector<int>(longueur, 0));
    plateau[5][0] = 1;
    verifyInput(plateau, 0,1);
    affichageConsole(plateau);


    return EXIT_SUCCESS;
}

bool verifyInput(Plateau& plateau, unsigned int x, int joueur) {
    for(int i = plateau[0].size() - 1; i > 0; i--) {
        // if(plateau[x][i] != 0) {
        //     plateau[x][i] = joueur;
        //     return true;
        // }
        std::cout << i;
    }
    return false;
}

void affichageConsole(Plateau plateau) {
    for(vector<int> colonne : plateau) {
        for(int i : colonne) {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}