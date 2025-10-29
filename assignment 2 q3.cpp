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


void main() 
{

	Clist l1;
	Cnode* pnn;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		pnn = new Cnode;
		cin >> pnn->info;
		pnn->pnext = NULL;
		l1.attach(pnn);
	}

	Cnode* ptrav = l1.phead;
	Cnode* pos;
	Cnode* prev;
	int count = 0;
	int step; cin >> step;

	while (count!= step) 
	{
		if (count +1 == step) 
		{
			prev = ptrav;
			pos = ptrav->pnext;
		}
		ptrav = ptrav->pnext;
	}

	prev->pnext = NULL;
	l1.ptail->pnext = l1.phead;
	l1.phead = pos;
	l1.ptail = prev;

	
}