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

Esame::Esame() {
    int numTotDomande;
    setData();
    std::cout << "Da quante domande e' composto l'esame? ";
    std::cin >> numTotDomande;
    std::cout <<"L'esame e' composto da " << numTotDomande << " domande. Se non e' corretto, riavviare il programma e reinserire il numero corretto di domande." << std::endl;
    std::cout << "Ora ti verra' chiesto di inserire i punteggi delle quattro risposte alle domande." << std::endl;
    for (int i = 0; i < numTotDomande; ++i) {
        //inserimento del valore delle domande
        inserisciValoriDomande(i+1);
    }
}

void Esame::setData() {
    string exData;
    std::cout <<"Inserisci la data dell'esame (formato: 12-12-2002): ";
    std::cin >> exData;
    data = exData;
}

string Esame::getData() const {
    return data;
}

int Esame::getPunteggio(int domandaRisposta) const {
    int punteggio=0;
    for (auto it = vettoreDomanda.begin() ; it != vettoreDomanda.end(); ++it) {
        if (domandaRisposta==1) {
            punteggio= it->getRispostaUno();
        }
        else if (domandaRisposta==2) {
            punteggio= it->getRispostaDue();
        }
        else if (domandaRisposta==3) {
            punteggio= it->getRispostaTre();
        }
        else if (domandaRisposta==4) {
            punteggio= it->getRispostaQuattro();
        }
        else if (domandaRisposta==5) {
            punteggio= 0;
        }
        else {
            throw Exp('d');
        } //eccezione domanda inserita sbagliata
    }
    return punteggio;
}

void Esame::inserisciValoriDomande(int numDomanda) {
    int punteggio;
    Domanda domanda;
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

int Esame::totPunteggio() const {
    int tot = 0, i=1, scelta=0;
    for (auto it = vettoreDomanda.begin(); it != vettoreDomanda.end(); ++it, ++i) {
        std::cout << "Risposta selezionata per domanda numero " << i << ": " << std::endl;
        std::cin >> scelta;
        if(scelta == 1) {
            tot += it->getRispostaUno();
        }
        else if(scelta == 2) {
            tot += it->getRispostaDue();
        }
        else if(scelta == 3) {
            tot += it->getRispostaTre();
        }
        else if(scelta == 4) {
            tot += it->getRispostaQuattro();
        }
        else if (scelta == 5) {
            tot = tot;
        }
        else {
            throw Exp('s'); //eccezione scelta sbagliata
        }
        std::cout << " " << std::endl;
    }
    return tot;
}

vector<Domanda> Esame::getDomande() const {
    return vettoreDomanda;
}
/*
void Esame::save() const {
    std::string filename;
    std::cout << "Inserisci il nome con cui vuoi salvare il file: ";
    std::cin >> filename;
    filename = filename + ".txt";
    std::ofstream file;
    file.open(filename.c_str());
    //ho il file aperto -> ora dovrei scriverci dentro la roba...
    file.close();
}
 */
