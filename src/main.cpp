#include "StatsFile.hpp"


int main(int argc, char *argv[])
{
    bool ret = false;
    /* for benchmark */
    clock_t start, finish;
    double total_time;
    start = clock();
    
    // Parameter check.
    if (argc < 2) {
        fprintf(stderr, "Invalid parameter list!\nUsage: ./bin/top_k_freq 2701.txt\n");
        return -1;
    }
    StatsFile* pStats = new StatsFile(argv[1]);
    if (pStats) {
        ret = pStats->Load();
        if (ret) {
            pStats->ShowStats();
        }
        if (!ret) {
            fprintf(stderr, "Failed to complete statistics!\n");
            return -2;
        }
    } else {
        fprintf(stderr, "Failed to initiate program!\n");
        return -3;
    }
    
    finish = clock();
    total_time=(double)(finish-start)/CLOCKS_PER_SEC;
    printf("The program cost %.4lf second(s)\n", total_time);
    
    return 0;
}

