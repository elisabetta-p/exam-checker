//
//  esame.hpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 16/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#ifndef esame_hpp
#define esame_hpp

#include "exp.hpp"
#include "domanda.hpp"
#include <vector>
using std::vector;
#include <iostream>
#include <string>
using std::string;

class Esame {
private:
    string data; //formato 12 Dicembre 2014;
    vector<Domanda> vettoreDomanda;
public:
    void inserisciValoriDomande(int);
    int totPunteggio() const;
    int getVoto(int) const;
    void save() const;
    void setData(string);
    string getData() const;
    const vector<Domanda> getDomande() const;
    void insertDomanda(const Domanda&);
};

#endif /* esame_hpp */
