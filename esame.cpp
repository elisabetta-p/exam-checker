//
//  esame.cpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 16/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#include "esame.hpp"
#include <string>
#include <fstream>

void Esame::setData(string s) {
    data = s;
}

string Esame::getData() const {
    return data;
}


void Esame::inserisciValoriDomande(int numDomanda) {
    try {
        int punteggio;
        Domanda domanda(numDomanda);
        std::cout << "Inserisci il punteggio della PRIMA risposta della domanda numero " << numDomanda << ": " << std::endl;
        std::cin >> punteggio;
        domanda.setRispostaUno(punteggio);
        std::cout << "Inserisci il punteggio della SECONDA risposta della domanda numero " << numDomanda << ": " << std::endl;
        std::cin >> punteggio;
        domanda.setRispostaDue(punteggio);
        std::cout << "Inserisci il punteggio della TERZA risposta della domanda numero " << numDomanda << ": " << std::endl;
        std::cin >> punteggio;
        domanda.setRispostaTre(punteggio);
        std::cout << "Inserisci il punteggio della QUARTA risposta della domanda numero " << numDomanda << ": " << std::endl;
        std::cin >> punteggio;
        domanda.setRispostaQuattro(punteggio);
        vettoreDomanda.push_back(domanda);
        std::cout << " " << std::endl;
    }
    catch (Exp e) {
        inserisciValoriDomande(numDomanda);
    }
}

void Esame::inserisciValoriVeroFalso(int numDomanda) {
    try {
        int punteggio;
        VeroFalso verofalso(numDomanda);
        std::cout << "Inserisci il punteggio della PRIMA risposta della domanda VERO O FALSO numero " << numDomanda << ": " << std::endl;
        std::cin >> punteggio;
        verofalso.setUno(punteggio);
        std::cout << "Inserisci il punteggio della SECONDA risposta della domanda VERO O FALSO numero " << numDomanda << ": " << std::endl;
        std::cin >> punteggio;
        verofalso.setDue(punteggio);
        vettoreVeroFalso.push_back(verofalso);
        std::cout << " " << std::endl;
    }
    catch (Exp e) {
        inserisciValoriVeroFalso(numDomanda);
    }
}

int Esame::totPunteggioDomande() const {
    int totDomande = 0, i=1, scelta=0;
    //Calcola i punteggi delle domande normali
    for (auto it = vettoreDomanda.begin(); it != vettoreDomanda.end(); ++it, ++i) {
        std::cout << "Risposta selezionata per domanda numero " << i << ": " << std::endl;
        std::cin >> scelta;
        if(scelta == 1) {
            totDomande += it->getRispostaUno();
            std::cout << "Totale parziale: " << totDomande << std::endl;
        }
        else if(scelta == 2) {
            totDomande += it->getRispostaDue();
            std::cout << "Totale parziale: " << totDomande << std::endl;
        }
        else if(scelta == 3) {
            totDomande += it->getRispostaTre();
            std::cout << "Totale parziale: " << totDomande << std::endl;
        }
        else if(scelta == 4) {
            totDomande += it->getRispostaQuattro();
            std::cout << "Totale parziale: " << totDomande << std::endl;
        }
        else if (scelta == 5) {
            std::cout << "Totale parziale: " << totDomande << std::endl;
        }
        else {
            throw Exp('s'); //eccezione scelta sbagliata
        }
        std::cout << " " << std::endl;
    }
    return totDomande;
}

int Esame::totPunteggioVeroFalso() const {
    int totVeroFalso = 0, i =1, scelta = 0;
    //calcola i punteggi dei vero falso
    for (auto it = vettoreVeroFalso.begin(); it != vettoreVeroFalso.end(); ++it, ++i) {
        std::cout << "Risposta selezionata per Vero Falso numero " << i << ": " << std::endl;
        std::cin >> scelta;
        if(scelta == 1) {
            totVeroFalso += it->getUno();
            std::cout << "Totale parziale dei Vero Falso: " << totVeroFalso << std::endl;
        }
        else if(scelta == 2) {
            totVeroFalso += it->getDue();
            std::cout << "Totale parziale dei Vero Falso: " << totVeroFalso << std::endl;
        }
        else if(scelta == 3) {
            totVeroFalso += it->getTre();
            std::cout << "Totale parziale dei Vero Falso: " << totVeroFalso << std::endl;
        }
        std::cout <<" " <<std::endl;
    }
    return totVeroFalso;
}

int Esame::TotPunteggioGlobale() const {
    int totD = totPunteggioDomande();
    int totVF = totPunteggioVeroFalso();
    return totD + totVF;
}

const vector<Domanda> Esame::getDomande() const {
    return vettoreDomanda;
}

const vector<VeroFalso> Esame::getVF() const {
    return vettoreVeroFalso;
}

int Esame::getVoto(int totPunteggio) const {
    int totPuntiPossibili = vettoreDomanda.size() * 2 + vettoreVeroFalso.size();
    int voto = totPunteggio*30 / totPuntiPossibili;
    if (voto < 0) return 0;
    else return voto;
}

void Esame::insertDomanda(const Domanda & d) {
    vettoreDomanda.push_back(d);
}

void Esame::insertVF(const VeroFalso & v) {
    vettoreVeroFalso.push_back(v);
}

