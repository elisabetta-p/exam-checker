//
//  gui.cpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 21/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#include "gui.hpp"

int Gui::numeroDomande() const {
    int numD;
    std::cout << "Da quante domande e' composto l'esame? " << std::endl;
    std::cin >> numD;
    return numD;
}

void Gui::inserimentoValoriDomande(int numDomande) {
    std::cout << "Ora ti verra' chiesto di inserire i punteggi delle quattro risposte alle domande." << std::endl;
    for (int i = 1; i <= numDomande; ++i) {
        //inserimento del valore delle domande
        esame.inserisciValoriDomande(i);
    }
}

void Gui::dataEsame() {
    string exData;
    std::cout <<"Inserisci la data dell'esame (non usare / o \\ nel formato della data): ";
    std::cin >> exData;
    esame.setData(exData);
}

void Gui::creaNuovoEsame() {
    dataEsame();
    inserimentoValoriDomande(numeroDomande());
}

void Gui::caricaVecchioEsame() {
    try {
        string nomeEsame;
        std::cout << "Inserisci il nome dell'esame che vuoi caricare: " << std::endl;
        std::cin >> nomeEsame;
        Database db("./"+nomeEsame+".txt", '|');
        db.load(esame);
    }
    catch (Exp e) {
        caricaVecchioEsame();
    }
}

void Gui::salvataggioEsame() {
    Database db("./"+esame.getData()+".txt", '|');
    db.save(esame);
    std::cout << "Salvataggio del nuovo esame avvenuto con successo" << std::endl;
}

void Gui::correggiDomande() {
    try {
        std::cout << "Ora c'e' la parte di correzione delle domande." << std::endl;
        std::cout << "Inserisci in numero la risposta selezionata (5 se lasciata in bianco)"<< std::endl;
        int totPunteggio = esame.totPunteggio();
        std::cout << "Il totale dell'esame e': " << totPunteggio << " e ha preso "<< esame.getVoto(totPunteggio) << " su 30. " << std::endl;
    }
    catch (Exp e) {
        correggiDomande();
    }
}
