#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

using namespace std;

// checks for right number and types of args
int* checkArgs(int argc, char*argv[]) 
{
	static int num_args[4];
	// Checks number of arguments
	if (argc != 5) {
		cout<<"usage: "<< argv[0] <<" 0 numpoints numtrials dimension\n";
		exit(0);
	}
	else {
		for (int i = 1; i < argc; i++) {
			int arg = atoi(argv[i]);
			int num;

			// checks that each argument is an int
			//if (!(arg << num) && arg > 0) {
				//cout<<argv[i]<<" is not a number\n";
				//exit(0);
			//} 
			if (i == 4 && arg > 4) {
				cout<<"The dimension must be between 0 and 4 (inclusive)!"<<'\n';
				exit(0);
			}
			num_args[i-1] = arg;
		}
	}
	return num_args;
}

int main(int argc, char *argv[]) 
{

	// int N[11] = {128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};
	int* args = checkArgs(argc, argv);
	int flag = args[0];
	int numpoints = args[1];
	int numtrials = args[2];
	int dimension = args[3];
	float sum; 
	for (int i = 0; i < numtrials; i++) {
		Complete_Undirected G = Complete_Undirected(numpoints, dimension);
		G.generate_graph();
		sum += G.prims();
	}
	float avg = sum/numtrials;
	cout<<avg<<' '<<numpoints<<' '<<numtrials<<' '<<dimension<<'\n';

}
