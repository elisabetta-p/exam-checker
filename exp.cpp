//
//  exp.cpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 16/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#include "exp.hpp"

#include <iostream>

Exp::Exp (char ecc) : c(ecc) {
    if (ecc == 'f') {
        std::cerr << "Caricamento o creazione del nuovo esame fallito!" << std::endl;
    }
    else if (ecc == 'r') {
        std::cerr << "Valore di risposta inserito sbagliato" << std::endl;
    }
    else if (ecc == 'd') {
        std::cerr << "Hai selezionato una risposta che non esiste" << std::endl;
    }
}
