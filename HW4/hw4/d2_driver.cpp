#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "d1.h"

using namespace std;

int main(int argc, char* argv[]){
	string x;
	string y;
	string x_m;
	string y_n;	
	int m;
	int n;

	char filename[100];
	cout<<"Please input a filename: ";
	cin>>filename;
	ifstream file(filename);
	getline(file, x_m);
	stringstream parse(x_m);
	parse>>m;
	//cout<<"m: "<<m<<endl;
	getline(file, x);
	//cout<<"x[]:\n"<<x<<"\n\n";

	getline(file, y_n);
	stringstream parse2(y_n);
	parse2>>n;
	//cout<<"n: "<<n<<endl;
	getline(file, y);
	//cout<<"y[]:\n"<<y<<"\n\n";

	
	int m1 = m+1;
	int path[m1][maxi];
	
	memset(path, -1, sizeof path);

	D1 ed(m, n);
	cout<<"Edit distance is "<<ed.d(x, y, m1, n+1, m, n, path)<<endl;
	//ed.print_path(path);

	vector<int> steps;
	ed.track(m, n, x, y, path, steps);

	ed.edit(x, y, steps);
	return 0;
}
