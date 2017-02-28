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
	int* args = checkArgs(argc, argv);
	int flag = args[0];
	int numpoints = args[1];
	int numtrials = args[2];
	int dimension = args[3];
	float sum = 0;

	// run randmst with a certain number of trials
	for (int i = 0; i < numtrials; i++) {
		Complete_Undirected G = Complete_Undirected(numpoints, dimension);
		G.generate_graph(true);
		sum += G.prims();
	}
	float avg = sum/numtrials;
	cout<<avg<<' '<<numpoints<<' '<<numtrials<<' '<<dimension<<'\n';

}
