// 
//  domanda.hpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 16/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#ifndef domanda_hpp
#define domanda_hpp

#include <string>
#include <vector>
#include <iostream>
#include "exp.hpp"

class Domanda {
private:
    int numDomanda, rispUno, rispDue, rispTre, rispQuattro;
public:
    bool uno, due, tre, quattro, cinque; //a quale di questa domanda ha risposto?
    Domanda(int, int = 0, int = 0, int = 0, int = 0);
    //setto quali sono i punteggi di ogni risposta alla domanda
    void setRispostaUno(int);
    void setRispostaDue(int);
    void setRispostaTre(int);
    void setRispostaQuattro(int);
    //
    int getRispostaUno() const;
    int getRispostaDue() const;
    int getRispostaTre() const;
    int getRispostaQuattro() const;
    int getRispostaCinque() const;
    int getNumDomanda() const;
    std::string serializza(char) const;
    static Domanda deserializza(const std::vector<std::string>&);
};
#endif /* domanda_hpp */
