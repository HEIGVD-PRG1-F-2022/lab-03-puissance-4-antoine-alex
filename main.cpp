#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
using Plateau = vector<vector<int>>;


void affichageConsole(Plateau plateau);
bool ajoutJeton(Plateau& plateau, unsigned int x, int joueur);
bool verifVictoire(int joueur, Plateau plateau, int x , int  y);

int main() {
    cout << "Regles de la puissance 4 : " << endl;

    const int longueur = 7;
    const int hauteur = 6;

    Plateau plateau(hauteur, std::vector<int>(longueur, 0));
    plateau[5][0] = 1;
    plateau[4][0] = 1;
    plateau[3][0] = 1;
    plateau[2][0] = 1;

   bool victoireJ1 = verifVictoire(1, plateau, 2, 0);

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

bool verifVictoire(int joueur, Plateau plateau, int x , int  y) {

    int J1 = 1;
    int J2 = 2;

    for (int k = 0; k < plateau[0].size(); k++) {
        if (y >= 3) //Verification alignement vertical
        {
            if (plateau[y][x] == J1 && plateau[y - 1][x] == J1 && plateau[y - 2][x] == J1 && plateau[y - 3][x] == J1
                || plateau[y][x] == J2 && plateau[y - 1][x] == J2 && plateau[y - 2][x] == J2 && plateau[y - 3][x] == J2)
                return 1;
        } else if (x <= 3) //Verification alignement horizontal
        {
            if (plateau[y][x] == J1 && plateau[y][x + 1] == J1 && plateau[y][x + 2] == J1 && plateau[y][x + 2] == J1
                || plateau[y][x] == J2 && plateau[y][x + 1] == J2 && plateau[y][x + 2] == J2 && plateau[y][x + 2] == J2)
                return 1;
        } else if (y >= 3) //Verification alignement diagonal montant
        {
            if (plateau[y][x] == J1 && plateau[y - 1][x + 1] == J1 && plateau[y - 2][x + 2] == J1 &&
                plateau[y - 3][x + 3] == J1
                || plateau[x][y] == J2 && plateau[x + 1][y - 1] == J2 && plateau[x + 2][y - 2] == J2 &&
                   plateau[x + 3][y - 3] == J2)
                return 1;
        } else if (y <= 2) //Verification alignement diagonal montant
        {
            if (plateau[y][x] == J1 && plateau[y + 1][x + 1] == J1 && plateau[y + 2][x + 2] == J1 &&
                plateau[y + 3][x + 3] == J1
                || plateau[y][x] == J2 && plateau[y + 1][x + 1] == J2 && plateau[y + 2][x + 2] == J2 &&
                   plateau[y + 3][x + 3] == J2)
                return 1;
        }

    }
}