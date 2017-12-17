//
// Created by Hubert on 2017/12/16.
//

#include <vector>
#include "Cache.h"

Cache::Cache(int myIndex, int myAssoc) {
    index = myIndex;
    assoc = myAssoc;

    validBit = new int[assoc];
    tag = new int[assoc];
    for (int i = 0; i < assoc ; ++i) {
        validBit[i] = 0;
        tag[i] = 0;
    }
}

void Cache::setTag(int myTag) {

}
