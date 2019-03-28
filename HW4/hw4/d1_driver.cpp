#include <iostream>
#include <cstring>
#include <vector>
#include "d1.h"

using namespace std;

int main(int argc, char* argv[]){
	string x="electrical engineering";
	string y="computer science";
	int m = x.length();
	int n = y.length();

	int m1 = m+1;
	int path[m1][maxi];
	
	memset(path, -1, sizeof path);

	D1 ed(m, n);
	cout<<"Edit distance is "<<ed.d(x, y, m1, n+1, m, n, path)<<"\n\n";
	//ed.print_path(path);

	cout<<"Operation\t\tz\t\t\tCost\t\tTotal\n\n";
	vector<int> steps;
	ed.track(m, n, x, y, path, steps);//back track to find each edit step

	ed.edit(x, y, steps);//edits z to y;
	return 0;
}
