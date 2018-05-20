//
//  StatsFile.hpp
//  TopFrequent
//
//  Created by Steven on 20/5/18.
//  Copyright © 2018 tengx. All rights reserved.
//

#ifndef StatsFile_hpp
#define StatsFile_hpp

#include <stdio.h>
#include <string>
#include "AbsWordStats.hpp"

/* StatsFile class. Stats file could be splited for huge document,
 and multiple AbsWordStats shall be managed.
 */
class StatsFile {
public:
    std::string mFileName;
    AbsWordStats*  mpStats;
    
public:
    StatsFile(std::string& fname);
    StatsFile(char* fname);
    ~StatsFile();

    bool Load();
    bool ShowStats();
};

#endif /* StatsFile_hpp */
