//
//  gui.hpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 21/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#ifndef gui_hpp
#define gui_hpp

#include <iostream>
#include "esame.hpp"
#include "database.hpp"

class Gui {
private:
    Esame esame;
    int numeroDomande() const;
    
    void dataEsame();
public:
    void inserimentoValoriDomande(int);
    void creaNuovoEsame();
    void caricaVecchioEsame();
    void salvataggioEsame();
    void correggiDomande();
};

#endif /* gui_hpp */
