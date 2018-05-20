//
//  WordStats1.hpp
//  TopFrequent
//
//  Created by Steven on 20/5/18.
//  Copyright © 2018 tengx. All rights reserved.
//

#ifndef WordStats1_hpp
#define WordStats1_hpp

#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include "AbsWordStats.hpp"

using std::string;
using std::vector;
using std::priority_queue;
using std::unordered_map;

class WordStats : public AbsWordStats {
    
private:
    typedef struct Word {
        string str;
        int    cnt;
        bool operator < (const Word& right) const {
            return cnt > right.cnt;      // top() is min
        }
    } Word;

    unordered_map<string, int> mRaw;      //Raw data (words) extracted from doc.
    priority_queue<Word>       mStats;    //Stats of top 20 freq used words in doc.
    
    bool Skip();                          //Skip all non alphabet string.
    
public:
    virtual bool Load(string& f);         //Load doc and complete the stat
    virtual bool ShowStats();             //Show statistics
    virtual ~WordStats() {};
};

#endif /* WordStats1_hpp */
