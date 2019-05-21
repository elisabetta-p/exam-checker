#include "esame.hpp"
#include "domanda.hpp"
#include "exp.hpp"
#include "database.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char* argv[]) {

    std::cout << argv[0];
    std::cin.get();

    int totPunteggio=0;
    char caricamentoEsame;

    //db new database("./"+nome, |)


    //CREAZIONE / CARICAMENTO ESAME

    cout << "Devi creare un nuovo esame o devi caricarne uno vecchio? Se devi caricarne uno vecchio premi V ed inserisci il percorso del file. Se devi caricarne uno nuovo premi N ";
    cin >> caricamentoEsame;
    if (caricamentoEsame == 'N' || caricamentoEsame == 'n') {
        Esame esame;

        //SALVATAGGIO ESAME
        Database db("./"+esame.getData()+".txt", '|');
        db.save(esame);
        //CORREZIONE ESAME
        cout << "Ora c'e' la parte di correzione delle domande." << endl;
        cout << "Inserisci in numero la risposta selezionata (5 se lasciata in bianco)"<< endl;
        totPunteggio = esame.totPunteggio();
        cout << "Il totale dell'esame e': " << totPunteggio << endl;
    }

    else if (caricamentoEsame == 'V' || caricamentoEsame == 'v') {
        //CARICA ESAME DA FILE + correzione
    }
    else throw Exp('f'); // CARICAMENTO FALLITO



}
