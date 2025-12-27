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
int main() {
	Clist* x[20];
	int n;


	for (int i = 0; i < 20; i++) {
		cin >> n;
		x[i] = new Clist();
		for (int j = 0; j < n; j++) {
			Cnode* pnn = new Cnode();
			cin >> pnn->info;
			pnn->pnext = NULL;
			x[i]->attach(pnn);
		}
	}
	
	
	Clist NewL;

	for (int i = 0; i < 20; i++)
	{
		Cnode* ptrav = x[i]->phead;
		Cnode* prev = NULL;

		while (ptrav != NULL) {
			if (ptrav->info < 0) {
			Cnode* next = ptrav->pnext;

				if (prev == NULL) 
				{
					x[i]->phead = next;
				}
				else 
				{
					prev->pnext = next;
				}

				ptrav->pnext = NULL;

				if (NewL.phead == NULL) 
				{
					NewL.phead = ptrav;
					NewL.ptail = ptrav;
				}
				else 
				{
					NewL.ptail->pnext = ptrav;
					NewL.ptail = ptrav;
				}

				ptrav = next;
			} 
			else 
			{
				prev = ptrav;
				ptrav = ptrav->pnext;
			}
		}
	}
	

	return 0;
}