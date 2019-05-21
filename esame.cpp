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
    catch (Exp e) {
        inserisciValoriDomande(numDomanda);
    }
}

int Esame::totPunteggio() const {
    int tot = 0, i=1, scelta=0;
    for (auto it = vettoreDomanda.begin(); it != vettoreDomanda.end(); ++it, ++i) {
        std::cout << "Risposta selezionata per domanda numero " << i << ": " << std::endl;
        std::cin >> scelta;
        if(scelta == 1) {
            tot += it->getRispostaUno();
            std::cout << "Totale parziale: " << tot << std::endl;
        }
        else if(scelta == 2) {
            tot += it->getRispostaDue();
            std::cout << "Totale parziale: " << tot << std::endl;
        }
        else if(scelta == 3) {
            tot += it->getRispostaTre();
            std::cout << "Totale parziale: " << tot << std::endl;
        }
        else if(scelta == 4) {
            tot += it->getRispostaQuattro();
            std::cout << "Totale parziale: " << tot << std::endl;
        }
        else if (scelta == 5) {
            std::cout << "Totale parziale: " << tot << std::endl;
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

int Esame::getVoto(int totPunteggio) const {
    int tot = vettoreDomanda.size() * 2;
    int voto = totPunteggio*30 / tot;
    if (voto < 0) return 0;
    else return voto;
}

void Esame::insertDomanda(const Domanda & d) {
    vettoreDomanda.push_back(d);
}
