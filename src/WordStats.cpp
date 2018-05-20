//
//  WordStats1.cpp
//  TopFrequent
//
//  Created by Steven on 20/5/18.
//  Copyright © 2018 tengx. All rights reserved.
//

#include <stdio.h>
#include "WordStats.hpp"

bool WordStats::Skip() {
    scanf("%*[^a-z||A-Z]");
    return true;
}

bool WordStats::Load(string& f) {
    char _word[MAX_LENGTH];
    Word w;
    unordered_map<string, int>::iterator it;
    
    FILE* fp = freopen(f.c_str(), "r", stdin);
    if (!fp) {
        fprintf(stderr, "Failed to open file!\n");
        return false;
    }
    while(Skip() && scanf("%[a-zA-Z]", _word) != EOF) {
        mTotalWords++;
        it = mRaw.find(_word);
        if (it != mRaw.end()) {
            it->second += 1;
        } else {
            mRaw.insert(std::make_pair(_word, 1));
        }
    }
    fclose(stdin);
    
    for (it = mRaw.begin(); it != mRaw.end(); it++) {
        w.str = it->first;
        w.cnt = it->second;
        
        if (mStats.size() < NUM_TOP_FREQ) {
            mStats.push(w);
        } else if ( w < mStats.top() ){
            mStats.pop();
            mStats.push(w);
        }
    }

    return true;
}

bool WordStats::ShowStats() {
    int i = 1;
    vector<Word> stk;
    vector<Word>::reverse_iterator rit;

    FILE* fp = freopen(STATS_OUT, "w", stdout);
    if (!fp) {
        fprintf(stderr, "Failed to write file!\n");
        return false;
    }
    while (mStats.size() > 0) {
        stk.push_back(mStats.top());
        mStats.pop();
    }
    
    for(rit=stk.rbegin(); rit!=stk.rend() && i<=NUM_TOP_FREQ; rit++, i++)
    {
        printf("%5d %-16s\n", (*rit).cnt, ((*rit).str).c_str());
    }
    
    fclose(stdout);
    return true;
}
