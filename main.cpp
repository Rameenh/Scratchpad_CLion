
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{
    default_random_engine generator (time(NULL));
    poisson_distribution<int> distribution (10);

    int pageNumbers [1000] = {};

    for (int i=0; i<1000; ++i){
        pageNumbers[i] = distribution(generator); //
    }

    return 0;
}