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
    void dataEsame();
public:
    int numeroDomande() const;
    int numeroDomandeVF() const;
    void inserimentoValoriDomande(int);
    void inserimentoValoriVeroFalso(int);
    void creaNuovoEsame();
    void caricaVecchioEsame();
    void salvataggioEsame();
    
    void votoEsame() const;
};

#endif /* gui_hpp */
