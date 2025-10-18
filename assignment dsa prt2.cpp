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
		if (phead == NULL) {
			phead = pnn;
			ptail = pnn;
		}
		else {
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
};



void main() {

	Cnode* pnn;
	Clist L1;
	Clist L2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		pnn = new Cnode;
		cin >> pnn->info;
		pnn->pnext = NULL;
		L1.attach(pnn);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		pnn = new Cnode;
		cin >> pnn->info;
		pnn->pnext = NULL;
		L2.attach(pnn);
	}

	int nstep;
	cin >> nstep;
	Cnode* ptrav1=L1.phead;
	Cnode* ptrav2=L2.phead;
	int count = 0; int count2 = 0;

	while (ptrav1 != NULL || ptrav2 != NULL) {
		if (ptrav1 != NULL) {
			count++;
			if (count == nstep) {
				cout << ptrav1->info << ",";
				count = 0;
			}
			ptrav1 = ptrav1->pnext;
		}
		if (ptrav2 != NULL) {
			count2++;
			if (count2 == nstep) {
				cout << ptrav2->info << ">>";
				count2 = 0;
			}
			ptrav2 = ptrav2->pnext;
		}

	}



}