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


void reversev1(Clist& l) 
{
	Cnode* prev = NULL;
	Cnode* current = l.phead;
	Cnode* next = NULL;
	l.ptail = l.phead;
	while (current != NULL) {
		next = current->pnext; 
		current->pnext = prev; 
		prev = current;       
		current = next;
	}
	l.phead = prev;

}


void reversev2(Clist& lmain, Clist l1) 
{
	Cnode* pnn;
	Cnode* ptrav;
	while(ptrav != NULL){
		pnn = new Cnode;
		pnn->info = ptrav->info;
		pnn->pnext = NULL;
		lmain.attach(pnn);
		ptrav = ptrav->pnext;
	}
	Cnode* prev = NULL;
	Cnode* current = l1.phead;
	Cnode* next = NULL;
	l1.ptail = l1.phead;
	while (current != NULL) {
		next = current->pnext;
		current->pnext = prev;
		prev = current;
		current = next;
	}
	l1.phead = prev;



}
