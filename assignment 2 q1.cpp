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
		Cnode*ptrav=phead;
		while (ptrav != NULL) {
			phead=ptrav->pnext;
			ptrav->pnext = NULL;
			delete ptrav;
			ptrav = phead;
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


void Splitlistv1(Clist& l, Clist& l1, Clist& l2,int targetval) {
	Cnode* ptrav;
	ptrav = l.phead;
	Cnode* pnn;
	while (ptrav->info != targetval) {
		pnn = new Cnode;
		pnn->info = ptrav->info;
		pnn->pnext = NULL;
		l1.attach(pnn);
		ptrav = ptrav->pnext;
	}
	while (ptrav != NULL) {
		pnn = new Cnode;
		pnn->info = ptrav->info;
		pnn->pnext = NULL;
		l2.attach(pnn);
		ptrav = ptrav->pnext;
	}
}

void Splitlistv2(Clist& l, Clist& l1, Clist& l2, int targetval) {
	Cnode* ptrav;
	ptrav = l.phead;
	Cnode* pnn;
	while (ptrav->info != targetval) {
		pnn = ptrav;
		ptrav = ptrav->pnext;
		pnn->pnext = NULL;
		l1.attach(pnn);
	}
	while (ptrav != NULL) {
		pnn = ptrav;
		ptrav = ptrav->pnext;
		pnn->pnext = NULL;
		l2.attach(pnn);
	}
	Cnode* p;
	while (l.phead != NULL) {
		p = l.phead;
		l.phead = l.phead->pnext;
		delete p;
	}
	l.ptail = NULL;
}

