//
//  AbsWordStats.hpp
//  TopFrequent
//
//  Created by Steven on 20/5/18.
//  Copyright © 2018 tengx. All rights reserved.
//

#ifndef AbsWordStats_hpp
#define AbsWordStats_hpp

#include <string>
#include <stdio.h>

#define MAX_LENGTH   1024         //Max length of a word
#define NUM_TOP_FREQ 20           //Number of top frequent words
#define STATS_OUT    "stats.txt"  //Stats output file

class AbsWordStats {
protected:
    int mTotalWords;              //total number of words in file.
public:
    virtual bool Load(std::string& f) = 0;
    virtual bool ShowStats() = 0;
    
    AbsWordStats() { mTotalWords = 0; }
    virtual ~AbsWordStats() {};
};

#endif /* AbsWordStats_hpp */
