#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	// Checks number of arguments
	if (argc != 5) 
		cout<<"usage: "<< argv[0] <<" 0 numpoints numtrials dimension\n";
	else 
		for ( int i = 1; i < argc; i++ ) {
			cout << "value of a: " << argv[i] << endl;
		}
	return 0;
}