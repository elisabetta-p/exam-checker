//
//  database.hpp
//  exam-checker
//
//  Created by Elisabetta Piombin on 21/05/2019.
//  Copyright © 2019 Elisabetta Piombin. All rights reserved.
//

#ifndef database_hpp
#define database_hpp

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "esame.hpp"

using std::string;
using std::vector;

class Database {
private:
    string path;
    char delimiter;
public:
    Database(string ="nd", char =',');
    void load(Esame&);
    void save(const Esame&);
};

#endif /* database_hpp */
