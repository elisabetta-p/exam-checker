//
//  verofalso.hpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 24/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#ifndef verofalso_hpp
#define verofalso_hpp

#include <vector>
#include <string>
using std::vector;
using std::string;

class VeroFalso {
private:
    int VFuno, VFdue, numDomandaVF; //la risposta tre indica la risposta lasciata in bianco
public:
    
    VeroFalso(int, int=0, int =0);
    
    //metodi per settare i punteggi
    void setUno(int);
    void setDue(int);
    
    //metodi per ottenere il punteggio della risposta selezionata
    int getUno() const;
    int getDue() const;
    int getTre() const; //getTre() ritorna 0 => domanda saltata
    
    string serializza(char) const;
    static VeroFalso deserializza(const vector<string>&);
};

#endif /* verofalso_hpp */
