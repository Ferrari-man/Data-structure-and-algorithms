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


int main()
{
    Clist l1;
    Clist l2;

    Cnode* pnn1;
    Cnode* pnn2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        pnn1 = new Cnode;
        cin >> pnn1->info;
        pnn1->pnext = NULL;
        l1.attach(pnn1);

        pnn2 = new Cnode;
        cin >> pnn2->info;
        pnn2->pnext = NULL;
        l2.attach(pnn2);
    }

    Cnode *ptrav=l2.phead; Cnode *prev=NULL;
    while(ptrav != NULL){
        if(ptrav->info == l1.phead->info && ptrav->pnext->info == l1.phead->pnext->info){
            prev->pnext = ptrav->pnext->pnext;
            delete ptrav->pnext;
            delete ptrav;
        }
        prev = ptrav;
        ptrav = ptrav->pnext;
    }

    Cnode* l1ptailprev=NULL;
    while(l1ptailprev->pnext != l1.ptail){
        l1ptailprev = l1ptailprev->pnext;
    }

    ptrav = l2.phead;
     while(ptrav != NULL){
        if(ptrav->info == l1ptailprev->info && ptrav->pnext->info == l1.ptail->info){
            prev->pnext = ptrav->pnext->pnext;
            delete ptrav->pnext;
            delete ptrav;
        }
        prev = ptrav;
        ptrav = ptrav->pnext;
    }
    



    return 0;



}