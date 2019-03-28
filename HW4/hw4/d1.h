#ifndef D1_H
#define D1_H


typedef struct node{
	char letter;
	node* next;
	node* prev;
}* NODE;

typedef struct dlist{
	NODE head;
	NODE tail;
}* DLIST;

const int maxi = 1000;

class D1{
	public:
		int m, n, s, i;

		D1(int a, int b);	
		int d(std::string x, std::string y, int m1, int n1, int m, int n, int path[][maxi]);
		int mini(int a, int b, int c);
		void track(int m, int n, std::string x, std::string y, int path[][maxi], std::vector<int> &steps);	
		void print_path(int path[][maxi]);
		void print_track(std::vector<int> steps);
		void print_z(DLIST list);
		void edit(std::string x, std::string y, std::vector<int> steps);
		void remove(NODE patch, DLIST list);
		void insert(char alpha, NODE n, DLIST list);
		void replace(char alpha, NODE n);
};

#endif
