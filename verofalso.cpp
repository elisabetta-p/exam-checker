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

VeroFalso::VeroFalso(char vf, int numD) : numDomandaVF(numD), VF(vf) {}

void VeroFalso::setVF(char vf) {
    if (vf == 'V' || vf == 'F')
        VF = vf;
    else
        throw Exp('r');
}

char VeroFalso::getVF() const { return VF; }

//int VeroFalso::getTre() const { return 0; }

string VeroFalso::serializza(char delimiter) const {
    std::cout << "serializza num domanda " << numDomandaVF << std::endl;
    return "V|" + std::to_string(numDomandaVF) + "|" + VF + "\r\n";
}

VeroFalso VeroFalso::deserializza(const vector<string>& valoriVF) {
    string str1 = valoriVF[1];
    char c = str1[0];
    std::cout << "AJDOFJSFJSòDFJKSòKFDSLò  " << valoriVF[0] << std::endl;
    return VeroFalso(c, std::stoi(valoriVF[0]));
}
