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

int Gui::numeroDomandeVF() const {
    int numVF;
    std::cout << "Da quante domande Vero Falso e' composto l'esame? " << std::endl;
    std::cin >> numVF;
    return numVF;
}

void Gui::inserimentoValoriDomande(int numDomande) {
    std::cout << "Ora ti verra' chiesto di inserire i punteggi delle quattro risposte alle domande." << std::endl;
    for (int i = 1; i <= numDomande; ++i) {
        //inserimento del valore delle domande
        esame.inserisciValoriDomande(i);
    }
}

void Gui::inserimentoValoriVeroFalso(int numDomandeVF) {
    std::cout << "Ora ti verra' chiesto di inserire i punteggi delle due risposte ai vero falso." << std::endl;
    std::cout << "Per il funzionamento corretto del programma, e' necessario che IN OGNI MOMENTO le lettere V e F, corrispondenti a vero o falso, vengano SEMPRE inserite in MAIUSCOLO!" << std::endl;
    for (int i = 1; i <= numDomandeVF; ++i) {
        //inserimento del valore dei vero/falso
        esame.inserisciValoriVeroFalso(i);
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
    inserimentoValoriVeroFalso(numeroDomandeVF());
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

void Gui::votoEsame() const{
    try {
        std::cout << "Ora c'e' la parte di correzione delle domande." << std::endl;
        std::cout << "Inserisci in numero la risposta selezionata (5 se e' una domanda lasciata in bianco, 3 se e' un vero falso lasciato in bianco)"<< std::endl;
        int totPunteggio = esame.TotPunteggioGlobale();
        std::cout << "Il totale dell'esame e': " << totPunteggio << " e ha preso "<< esame.getVoto(totPunteggio) << " su 30. " << std::endl;
    }
    catch (Exp e) {
        votoEsame();
    }
}
