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
	Clist l1;
	Clist l2;
	Cnode* pnn;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		pnn = new Cnode;
		cin >> pnn->info;
		pnn->pnext = NULL;
		l1.attach(pnn);
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		pnn = new Cnode;
		cin >> pnn->info;
		pnn->pnext = NULL;
		l2.attach(pnn);
	}

	int t1, t2;
	cin >> t1 >> t2;
	Cnode* pcatch1;
	Cnode* pcatch2;

	//logic starts here

	Cnode* ptrav;
	ptrav = l1.phead;
	while (ptrav != NULL) {
		if (ptrav->info == t1) {
			pcatch1 = ptrav;
			break;
		}
		ptrav = ptrav->pnext;
	}
	while (ptrav != NULL) {
		if (ptrav->pnext->info == t2) {
			l2.ptail->pnext = pcatch1->pnext;
			l2.ptail = ptrav;
			pcatch1->pnext = ptrav->pnext;
			ptrav->pnext = NULL;
			break;
		}
		ptrav = ptrav->pnext;
	}


}
