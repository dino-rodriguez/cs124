#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) 
{
	// Checks number of arguments
	if (argc != 5) 
		cout<<"Usage: "<< argv[0] <<" 0 numpoints numtrials dimension\n";
	else 
		for ( int i = 1; i < argc; i++ ) {
			int n;
			argv[i] >> n;
			if (!argv[i].fail()) {
				cout<<"Fail";
			}
		}
	return 0;
}