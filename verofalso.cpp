//
//  verofalso.cpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 24/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#include "verofalso.hpp"
#include "exp.hpp"
#include "gui.hpp"

VeroFalso::VeroFalso(int numD, int u, int d) : numDomandaVF(numD), VFuno(u), VFdue(u) {}

void VeroFalso::setUno(int u) { if (u > 1 || u < -1) throw Exp('r'); else VFuno = u; }

void VeroFalso::setDue(int d) { if (d > 1 || d < -1) throw Exp('r'); VFdue = d;}

int VeroFalso::getUno() const { return VFuno; }

int VeroFalso::getDue() const { return VFdue; }

int VeroFalso::getTre() const { return 0; }

string VeroFalso::serializza(char delimiter) const {
    return "V|" + std::to_string(numDomandaVF) + "|" + std::to_string(VFuno) + "|" + std::to_string(VFdue) + "\r\n";
}

VeroFalso VeroFalso::deserializza(const vector<string>& valoriVF) {
    return VeroFalso(std::stoi(valoriVF[0]), std::stoi(valoriVF[1]), std::stoi(valoriVF[2]));
}
