//
//  domanda.cpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 16/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#include "domanda.hpp"

void Domanda::setRispostaUno(int i) {
    rispUno = i;
}

void Domanda::setRispostaDue(int i) {
    rispDue = i;
}

void Domanda::setRispostaTre(int i) {
    rispTre = i;
}

void Domanda::setRispostaQuattro(int i) {
    rispQuattro = i;
}

int Domanda::getRispostaUno() const {
    return rispUno;
}

int Domanda::getRispostaDue() const {
    return rispDue;
}

int Domanda::getRispostaTre() const {
    return rispTre;
}

int Domanda::getRispostaQuattro() const {
    return rispQuattro;
}
Domanda::Domanda(int numD, int u, int d, int t, int q) : numDomanda(numD),
rispUno(u),
rispDue(d),
rispTre(t),
rispQuattro(q) {}
