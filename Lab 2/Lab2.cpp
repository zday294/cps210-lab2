#include <cstdio>
#include <vector>
#include "ArrayIter.h"
#include "mergesort.h"
#include "Compare.h"

template <typename T>
static void printArray( std::vector<T> vec, int len){
	for (int pos = 0; pos < len; ++pos) {
		printf(" %d", vec[pos]);
	}
	printf("\n");
}

int main(int argc, char** argv) 
{
	std::vector<int> vals = { 20,17,14,11,8,5,2,1,4,7,10,13,16,19,0,3,6,9,12,15,18 };
	std::vector<int> hold = std::vector<int>(vals.size());
	ArrayIter<int> valsBegin = ArrayIter<int>(vals);
	ArrayIter<int> tempStorage = ArrayIter<int>(hold);
	int N;

	N = 1;
	printf("Test case length = 1");		
	Mergesort<int>::sort(valsBegin, ArrayIter<int>(vals, N), tempStorage, Compare<int>());
	printArray(vals, N);
}

