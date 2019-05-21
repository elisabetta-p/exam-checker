#include "esame.hpp"
#include "domanda.hpp"
#include "exp.hpp"
#include "database.hpp"
#include "gui.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char* argv[]) {
    
    std::cout << argv[0];
    std::cin.get();
    
    
    char caricamentoEsame;
    
    Gui gui;


    cout << "Devi creare un nuovo esame o devi caricarne uno vecchio? Se devi caricarne uno vecchio premi V ed inserisci il percorso del file. Se devi caricarne uno nuovo premi N ";
    cin >> caricamentoEsame;
    if (caricamentoEsame == 'N' || caricamentoEsame == 'n') {
        gui.creaNuovoEsame();
        gui.salvataggioEsame();
    }

    else if (caricamentoEsame == 'V' || caricamentoEsame == 'v') {
        gui.caricaVecchioEsame();
    }
    
    gui.correggiDomande();
    
    //else throw Exp('f'); // CARICAMENTO FALLITO



}
