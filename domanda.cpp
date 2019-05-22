//
//  domanda.cpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 16/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#include "domanda.hpp"

void Domanda::setRispostaUno(int i) {
    if (i > 2 || i < -2) throw Exp('r');
    rispUno = i;
}

void Domanda::setRispostaDue(int i) {
    if (i > 2 || i < -2) throw Exp('r');
    rispDue = i;
}

void Domanda::setRispostaTre(int i) {
    if (i > 2 || i < -2) throw Exp('r');
    rispTre = i;
}

void Domanda::setRispostaQuattro(int i) {
    if (i > 2 || i < -2) throw Exp('r');
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

std::string Domanda::serializza(char delimiter) const {
    return std::to_string(numDomanda) + "|" + std::to_string(rispUno) + "|" + std::to_string(rispDue) + "|" + std::to_string(rispTre) + "|"+  std::to_string(rispQuattro) + "\r\n";
}

Domanda Domanda::deserializza(const std::vector<std::string> & valori) {
   
    return Domanda(std::stoi(valori[0]), std::stoi(valori[1]), std::stoi(valori[2]), std::stoi(valori[3]), std::stoi(valori[4]));
}
