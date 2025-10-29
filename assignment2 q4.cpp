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


void main(){

Clist l1;
Cnode* pnn;
int n;
cin >> n;
int min = 10000;
int max = -10000;
Cnode* posmin;
Cnode* posmax;

for (int i = 0; i < n; i++) 
{
    pnn = new Cnode;
    cin >> pnn->info;
    if (pnn->info < min)
    {
        min = pnn->info;
        posmin = pnn;
    }
    if (pnn->info > max)
    {
        max = pnn->info;
        posmax = pnn;
    }
    pnn->pnext = NULL;
    l1.attach(pnn);
}

Clist l2;
pnn = new Cnode;
pnn->info =posmin->info;
pnn->pnext = NULL;
l2.attach(pnn);
pnn = new Cnode;
pnn->info = posmax->info;
pnn->pnext = NULL;
l2.attach(pnn);
Cnode*ptrav=posmin->pnext;
while(ptrav!=posmax)
{
    pnn = new Cnode;
    pnn->info = ptrav->info;
    pnn->pnext = NULL;
    l2.attach(pnn);
    ptrav=ptrav->pnext;
}
}
