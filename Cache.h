//
// Created by Hubert on 2017/12/16.
//

#ifndef IPLC_CACHE_H
#define IPLC_CACHE_H

#endif //IPLC_CACHE_H

class Cache {
public:
    Cache(int myIndex, int myAssoc);
    void setTag( int myTag );
    void setValidBit( int myValidBit );
    void iplc_sim_LRU_replace_on_miss(int index, int tag);
    void iplc_sim_LRU_update_on_hit(int index, int assoc_entry);

private:
    int index;
    int assoc;
    int* tag ;
    int* validBit;

};
