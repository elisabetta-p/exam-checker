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
#include "verofalso.hpp"
#include <vector>
using std::vector;
#include <iostream>
#include <string>
using std::string;
#include <cctype>

class Esame {
private:
    string data; //formato 12 Dicembre 2014;
    vector<Domanda> vettoreDomanda;
    vector<VeroFalso> vettoreVeroFalso;
public:
    void inserisciValoriDomande(int);
    void inserisciValoriVeroFalso(int);
    int totPunteggioDomande() const;
    int totPunteggioVeroFalso() const;
    int TotPunteggioGlobale() const;
    double getVoto(int) const;
    void save() const;
    void setData(string);
    string getData() const;
    const vector<Domanda> getDomande() const;
    const vector<VeroFalso> getVF() const;
    void insertDomanda(const Domanda&);
    void insertVF(const VeroFalso&);
};

#endif /* esame_hpp */
