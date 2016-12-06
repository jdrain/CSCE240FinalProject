/*
 *
 *
 *
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "Gene.h"
#include <typeinfo>
#include <ctime>

using namespace std;

void build(Gene &builder, Gene allseq[], int counter, int &addedCounter);

int main(int argc, char** argv){
	ifstream in_file; //input file
	ofstream out_file; //output file
	ofstream out_file2; //output file for the metadata

	if(argc != 4) {
		cout << "Usage: " << argv[0] << " <Input File> <Output File> <Minimum Overlap" << endl;
		exit(1);
	}

	in_file.open(argv[1]);
	if(in_file.fail()) {
		cout << "Error opening input file." << endl;
		exit(1);
	}

	out_file.open(argv[2]);
	if(out_file.fail()) {
		cout << "Error creating output file." << endl;
		exit(1);
	}

	out_file2.open("ProcessingRuns.txt", ofstream::app);
	if(out_file2.fail()) {
		cout << "Error accessing metadata file." << endl;
	}
	
	int minOverlap(atoi(argv[3]));
	int counter(0);
	string forcount;
	while(!in_file.eof()){
		getline(in_file,forcount);
		getline(in_file,forcount);
		counter++;
	}

	in_file.clear();
	in_file.seekg(0);

	Gene allseq[counter];
	string seq;
	int i(0);

	while(!in_file.eof()) {
		getline(in_file, seq);
		getline(in_file, seq);
		Gene temp(seq);

		allseq[i] = temp;
		i++;
	}

	bool done = false;
    
	clock_t ti, tf;
	ti=clock(); //start time
	cout << "here?" << endl;
	Gene builder(allseq[0]);
	int addedCounter = 1;
	while(!done) {
		//building full gene
		int lastAddC = addedCounter;

		builder.build(allseq,counter,addedCounter,minOverlap);
		builder.print();

		cout << "SIZE OF ARRAY: " << counter - 1 << endl;
		cout << "NUMBER ADDED: " << addedCounter << endl;
		if(addedCounter == lastAddC){
			done = true;
		}
	}

	out_file << builder << endl;

	in_file.close();
	out_file.close();

	tf=clock(); //end time
	//calculate the program run time
	float cycles = (float(tf)-float(ti));
	float time = (cycles)/CLOCKS_PER_SEC;
	//write to console and file
	cout << "Clock cycles elapsed: " << cycles << endl;
	cout << "Time elapsed (seconds):" << time << endl;
	out_file2 << ",File: " << argv[1] << "," << cycles << "," << time << "," << endl; 
	out_file2.close();
}

