#include <iostream>
using namespace std;

class Cnode {
public:
	int info;
	Cnode* pnext;
};

class Clist {
public:
	Cnode* phead;
	Cnode* ptail;

	Clist() {
		phead = NULL;
		ptail = NULL;
	}
	
	~Clist() {
		Cnode* p;
		while (phead != NULL) {
			p = phead;
			phead = phead->pnext;
			delete p;
		}
	}

	void attach(Cnode* pnn) {
		if(phead == NULL) {
			phead = pnn;
			ptail = pnn;
		} else {
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
};



void main() {
	Clist L;
	Cnode* pnn;

	for ( int i = 1; i <= 5; i++) {
		pnn = new Cnode[1];
		cin >> pnn->info;
		pnn->pnext = NULL;
		L.attach(pnn);
	}
}
