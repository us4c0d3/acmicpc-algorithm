#include "hat.h"
#include <vector>
using namespace std;

void init(int N)
{
	// Do Something...
}

int call(vector<int> F, vector<int> B, int num)
{
    int total = 0;
	for(int x: F) total ^= x;
    for(int x: B) total ^= x;
    
	return total;
}