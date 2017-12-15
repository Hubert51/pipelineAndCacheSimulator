// if we want to do more real simluation, we need to refer the spim. R3000

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

#define MAX_CACHE_SIZE 10240
#define CACHE_MISS_DELAY 10 // 10 cycle cache miss penalty
#define MAX_STAGES 5

void iplc_sim_init(int index, int blocksize, int assoc);


int cache_index=0;
int cache_blocksize=0;
int cache_blockoffsetbits = 0;
int cache_assoc=0;
long cache_miss=0;
long cache_access=0;
long cache_hit=0;




unsigned int data_address=0;
unsigned int instruction_address=0;
unsigned int pipeline_cycles=0;   // how many cycles did you pipeline consume
unsigned int instruction_count=0; // home many real instructions ran thru the pipeline
unsigned int branch_predict_taken=0;
unsigned int branch_count=0;
unsigned int correct_branch_predictions=0;



void iplc_sim_init(int index, int blocksize, int assoc)
{
    int i = 0;
    long cache_size = 0;
    cache_index = index;
    cache_blocksize = blocksize;
    cache_assoc = assoc;

    cache_blockoffsetbits =
            (int) rint((log( (double) (blocksize * 4) )/ log(2)));
    /* Note: rint function rounds the result up prior to casting */

    cache_size = assoc * ( 1 << index ) *
                 ((32 * blocksize) + 33 - index - cache_blockoffsetbits);

    printf("Cache Configuration \n");
    printf("   Index: %d bits or %d lines \n", cache_index, (1<<cache_index) );
    printf("   BlockSize: %d \n", cache_blocksize );
    printf("   Associativity: %d \n", cache_assoc );
    printf("   BlockOffSetBits: %d \n", cache_blockoffsetbits );
    printf("   CacheSize: %lu \n", cache_size );

    if (cache_size > MAX_CACHE_SIZE ) {
        printf("Cache too big. Great than MAX SIZE of %d .... \n", MAX_CACHE_SIZE);
        exit(-1);
    }
//
//    // to initialize the cache. it is an array to store the struct of cache_line
//    cache = (cache_line_t *) malloc((sizeof(cache_line_t) * 1<<index));
//
//    // Dynamically create our cache based on the information the user entered
//    for (i = 0; i < (1<<index); i++) {
//        cache[i].tag = (int*)malloc(sizeof(int)*assoc);
//        cache[i].validBit = (int*)malloc(sizeof(int)*assoc);
//
//        // initial the cache
//        for (int j = 0; j < assoc ; ++j) {
//            cache[i].tag[j] = 0;
//            cache[i].validBit[j] = 0;
//        }
//    }
//
//    // init the pipeline -- set all data to zero and instructions to NOP
//    for (i = 0; i < MAX_STAGES; i++) {
//        // itype is set to O which is NOP type instruction
//        bzero(&(pipeline[i]), sizeof(pipeline_t));
//    }
}


int main() {
    string inputFileName;
    std::string trace_file_name;
    int index = 2;
    int blocksize = 2;
    int assoc = 2;

    cout << "Please enter the input file: " ;
    cin >> inputFileName;
    std::ifstream input(inputFileName);
    if (!input.good()){
        cout << "Can't open " << inputFileName << " to read" << endl;
        exit(1);
    }

    input >> trace_file_name;
    std::ifstream trace_file(trace_file_name);
    // to check whether the trace_file is open successfully
    if (!trace_file.good()){
        cout << "Can't open " << trace_file_name << "to read" << endl;
        exit(1);
    }

    // from input to get Cache Size (index), Blocksize and Level of Assoc
    input >> index >> blocksize >> assoc ;

    // from input to get whether Branch Prediction or not: 0 (NOT taken), 1 (TAKEN): ");
    input >> branch_predict_taken ;

    iplc_sim_init(index, blocksize, assoc);













    return 0;

}