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
    char VF;
    int numDomandaVF; 
public:
    
    VeroFalso(char, int =0);
    
    //metodi per settare i punteggi
    void setVF(char);
    
    //metodi per ottenere il punteggio della risposta selezionata
    char getVF() const;
    //come gestisco la risposta saltata?
    
    //int getTre() const; //getTre() ritorna 0 => domanda saltata
    
    string serializza(char) const;
    static VeroFalso deserializza(const vector<string>&);
};

#endif /* verofalso_hpp */
