#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
using Plateau = vector<vector<int>>;


void affichageConsole(Plateau plateau);
bool ajoutJeton(Plateau& plateau, unsigned int x, int joueur);

int main() {
    cout << "Regles de la puissance 4 : " << endl;

    const int longueur = 7;
    const int hauteur = 6;

    Plateau plateau(hauteur, std::vector<int>(longueur, 0));
    plateau[5][0] = 1;

    int colonne = 0; 

    do {
        std::cout << "Entrez un nombre entre 0-6: ";
        std::cin >> colonne;
        colonne = 0;
    }while(!ajoutJeton(plateau,colonne,2));

    affichageConsole(plateau);

    return EXIT_SUCCESS;
}

bool ajoutJeton(Plateau& plateau, unsigned int colonne, int joueur) {
    int count = 0;
    for(int i = plateau.size() - 1; i >= 0; i--) {
        if(plateau[i].at(colonne) == 0) {
            plateau[i].at(colonne) = joueur;
            return true;
        }

        if(plateau[i].at(colonne) != 0) {
            count++;
        }
    }
    return false;
}

void affichageConsole(Plateau plateau) {

    for(int i=0; i < plateau[0].size(); i++) {
       std::cout << " | " << i;
    }
    std::cout << std::endl;
    std::string s (plateau[0].size()*4,'-');
    std::cout << " " << s << std::endl;


    for(vector<int> colonne : plateau) {
        for(int i : colonne) {
           std::cout << " | " << i;
        }
        std::cout << std::endl;
    }
}