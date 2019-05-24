//
//  database.cpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 21/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#include "database.hpp"

Database::Database(string p, char c) : path(p), delimiter(c) {}

void Database::load(Esame& esame) {
    std::ifstream file;
    file.open(path, std::ios::in);
    if (file.is_open()) {
        string currentLine;
        std::getline(file, currentLine, '\n');
        
        while (std::getline(file, currentLine, '\n')) {
            std::stringstream buffer(currentLine);
            
            vector<string> values;
            string currentValue;
            
            while (std::getline(buffer, currentValue, delimiter)) 
                values.push_back(currentValue);
            
            string tipoDomanda = values[0];
            values.erase(values.begin());
            
            
            if (tipoDomanda=="D")
                esame.insertDomanda(Domanda::deserializza(values));
            if (tipoDomanda=="V")
                esame.insertVF(VeroFalso::deserializza(values));
        }
    }
    else {
        throw Exp('f');
    }
}

void Database::save(const Esame& esame) {
    std::ofstream file;
    file.open(path, std::ofstream::trunc);

    if (file.is_open()) {
        file << "# " +esame.getData() << "\r\n";

        const vector<Domanda> domande = esame.getDomande();
        const vector<VeroFalso> vf = esame.getVF();

        for (auto it = domande.begin(); it != domande.end(); ++it) {
            file << it->serializza(delimiter);
        }
        for (auto it = vf.begin(); it != vf.end(); ++it) {
            file << it->serializza(delimiter);
        }

    }
}
