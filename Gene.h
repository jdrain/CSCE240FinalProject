#ifndef GENE
#define GENE

#include <iostream>
#include <cstdlib>
#include <string>
#include "String.h"

using namespace std;

class Gene : public String
{
	public:
		Gene();
		Gene(string str);
		Gene(String str);
		bool added;
		int getSize();
		void build(Gene allseq[], int counter, int &addedCounter, int minOverlap);
	private:
		int size;
};

#endif
