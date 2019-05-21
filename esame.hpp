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

class Esame {
private:
    vector<Domanda> vettoreDomanda;
public:
    int getPunteggio(int) const;
    void inserisciValoriDomande(int);
    int totPunteggio() const;
    Esame();
    void save() const;
};

#endif /* esame_hpp */
