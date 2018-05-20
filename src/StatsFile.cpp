//
//  StatsFile.cpp
//  TopFrequent
//
//  Created by Steven on 20/5/18.
//  Copyright © 2018 tengx. All rights reserved.
//

#include "StatsFile.hpp"
#include "WordStats.hpp"

StatsFile::StatsFile(std::string& fname) {
    mFileName.assign(fname);
    mpStats = new WordStats();
}

StatsFile::StatsFile(char* fname) {
    mFileName.assign(fname);
    mpStats = new WordStats();
}

StatsFile::~StatsFile() {
    if (mpStats) {
        delete mpStats;
    }
}

bool StatsFile::Load() {
    if (mpStats) {
        return mpStats->Load(mFileName);
    }
    return false;
}

bool StatsFile::ShowStats() {
    if (mpStats) {
        return mpStats->ShowStats();
    }
    return false;
}
