#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int checkArgs (int argc, char*argv[]) 
{
	// Checks number of arguments
	if (argc != 5) 
		cout<<"Usage: "<< argv[0] <<" 0 numpoints numtrials dimension\n";
	else 
		for (int i = 1; i < argc; i++) {
			int dim = *argv[4];
			if (i == 4 && dim > 4) {
				cout<<*argv[i]<<"\n";;
				cout<<"The dimension must between 1 and 4!\n";
			}
		}
	return 0;
}

int main(int argc, char *argv[]) 
{
	checkArgs(argc, argv);
}
