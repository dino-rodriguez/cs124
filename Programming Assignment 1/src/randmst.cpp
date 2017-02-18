#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

// checks for right number and types of args
int checkArgs(int argc, char*argv[]) 
{
	// Checks number of arguments
	if (argc != 5) {
		cout<<"usage: "<< argv[0] <<" 0 numpoints numtrials dimension\n";
		exit(0);
	}
	else 
		for (int i = 1; i < argc; i++) {
			int arg = atoi(argv[i]);
			int num;
			// TODO: check if num is positive
			// checks that each argument is an int
			if (!(arg << num) && arg > 0) {
				cout<<argv[i]<<" is not a number\n";
				exit(0);
			}
		}
	return 0;
}

int main(int argc, char *argv[]) 
{
	checkArgs(argc, argv);
}
