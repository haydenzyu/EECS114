#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>
#include "d1.h"

using namespace std;

D1::D1(int a, int b){
	m=a;
	n=b;
	s=m;
	i=0;
}

int D1::mini(int a, int b, int c){
	return min(min(a, b), c);
}

int D1::d(string x, string y, int m1, int n1, int m, int n, int path[][maxi]){
	if(m1==0){//reached end of x
		return n1*3;
	}

	if(n1==0){//reached end of y
		return m1*2;
	}

	if(path[m1-1][n1-1] != -1){//memoization
		return path[m1-1][n1-1];
	}

	if(x[m-1] == y[n-1]){//if the letter of x and y are the same
		return path[m1-1][n1-1] = d(x, y, m1-1, n1-1, m-1, n-1, path);
	}

		
	return path[m1-1][n1-1] = mini(d(x, y, m1, n1-1, m, n-1,  path)+3,//insert
					d(x, y, m1-1, n1, m-1, n,  path)+2,//remove
					d(x, y, m1-1, n1-1, m-1, n-1, path)+4);//replace
}

void D1::track(int m, int n, std::string x, std::string y, int path[][maxi], std::vector<int> &steps){
	if(m==0&&n==0){
		//steps.insert(steps.begin(), path[m][n]);
		//print_track(steps);
		return;
	}

	if(m==0){//reached end of x
		steps.insert(steps.begin(), 3);	
		track(m, n-1, x, y, path, steps);
		return;	
	}

	if(n==0){//reached end of y
		steps.insert(steps.begin(), 2);
		track(m-1, n, x, y, path, steps);
		return;
	}

	if(path[m][n]==path[m-1][n-1]&&x[m-1]==y[n-1]){//shifted right
		steps.insert(steps.begin(), 0);
		track(m-1, n-1, x, y, path, steps);
	}
	else if(path[m][n]-2==path[m-1][n] && path[m-1][n]!=-1){//deleted
		steps.insert(steps.begin(), 2);	
		track(m-1, n, x, y, path, steps);
	}
	else if(path[m][n]-3==path[m][n-1]){//inserted 
		steps.insert(steps.begin(), 3);
		track(m, n-1, x, y, path, steps);	
	}
	else if(path[m][n]-4==path[m-1][n-1]){//replaced
		steps.insert(steps.begin(), 4);	
		track(m-1, n-1, x, y, path, steps);
	}	
}

void D1::edit(string x, string y, std::vector<int> steps){
	NODE z = new node;
	NODE temp = new node;
	DLIST list = new dlist;
	temp->letter = x[i];
	temp->prev = NULL;
	temp->next = NULL;
	int total=0;	

	z=temp;
	list->head=z;
	list->tail=z;
	for(int j=1; j<m+1; j++){//copy x to z
		temp=new node;
		temp->letter = x[j];
		temp->prev = z;
		temp->next = NULL;
		z->next = temp;
		z = temp;
		list->tail = z;
	}
	cout<<"inital string\t";
	print_z(list);
	cout<<"\t\t0\t\t0\n";

	temp=list->head;
	for(int j=0; j<steps.size(); j++){
		if(steps[j]==0){//move right
			cout<<"right\t\t";
			temp=temp->next;
			i++;
			print_z(list);
			cout<<"\t\t0\t\t"<<total<<endl;
		}
		else if(steps[j]==2){//delete
			cout<<"delete\t\t";
			remove(temp, list);
			temp=temp->next;
			total+=2;
			s-=1;
			print_z(list);
			cout<<"\t\t2\t\t"<<total<<endl;
		}
		else if(steps[j]==3){//insert
			cout<<"insert\t\t";
			insert(y[i], temp, list);
			total+=3;
			s+=1;
			i++;
			print_z(list);
			cout<<"\t\t3\t\t"<<total<<endl;
		}
		else if(steps[j]==4){//replace
			cout<<"replaced by "<<y[i]<<"\t";
			replace(y[i], temp);
			temp=temp->next;
			total+=4;
			i++;
			print_z(list);
			cout<<"\t\t4\t\t"<<total<<endl;
		}
	}
}

void D1::remove(NODE patch, DLIST list){
	NODE del = new node;
	NODE temp = new node;
	del = patch;
	if(del == list->head){//if the node is last
		list->head = del->next;
		list->head->prev = NULL;
        }
        else if(del == list->tail){//if the node is first
		list->tail = del->prev;
		list->tail->next = NULL;
        }
        else if(del == NULL){
		return;
        }
	else{//everything else in between
		patch = del->prev;
		temp = del->next;
		patch->next = temp;
		temp->prev = patch;
        }
        del=NULL;
        delete del;	
}

void D1::insert(char alpha, NODE n, DLIST list){
	NODE inserted = new node;
	NODE temp = new node;
	if(n->prev == NULL){//inserting in the front	
		inserted->letter = alpha;
		inserted->prev = NULL;
		inserted->next = n;
		n->prev = inserted;
		list->head = inserted;
	}
	else{
		temp = n->prev;
		inserted->letter = alpha;
		inserted->prev = temp;
		inserted->next = n;
		temp->next = inserted;
		n->prev = inserted;
	}
}

void D1::replace(char alpha, NODE n){
	n->letter = alpha;
}

void D1::print_track(std::vector<int> steps){
	int s = steps.size();
	cout<<"Track size: "<<s<<endl;
	cout<<"Track: ";
	for(int i=0; i<steps.size(); i++){
		cout<<steps[i]<<"  ";
	}
	cout<<"\n";
}

void D1::print_z(DLIST list){
	NODE temp;
	temp = list->head;
	
	while(temp!=NULL){
		cout<<temp->letter;
		temp = temp->next;
	}
}
	
void D1::print_path(int path[][maxi]){
	for(int i=0; i<n+1; i++){
		for(int j=0; j<m+1; j++){
			cout<<path[j][i]<<"\t";
		}
		cout<<"\n";
	}
}
