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

int main(){
    Clist l1;
    Clist l2;
    Cnode*pnn1; Cnode * pnn2; Cnode * pos1l1; Cnode * pos2l1; Cnode * pos1l2; Cnode * pos2l2; 


    int n;
    cin >> n;
	int flag = 0;	
	Cnode * catcherprevl2 = NULL; Cnode * catcherprevl1 = NULL;

    for (int i = 0; i < n; i++) {
        pnn1 = new Cnode;
        cin >> pnn1->info;
        pnn1->pnext = NULL;
        l1.attach(pnn1);

        pnn2 = new Cnode;
        cin >> pnn2->info;
        pnn2->pnext = NULL;
        l2.attach(pnn2);

        if (pnn1->info == pnn2 -> info&& flag==0) {
            pos1l1=pnn1;
            pos1l2=pnn2;
			flag=1;
        }

		if( pnn1->pnext->info == pnn2 -> pnext->info && flag==1){
			catcherprevl2 = pnn2;
			catcherprevl1 = pnn1;
		}

		if (pnn1->info == pnn2 -> info&& flag==1) {
			pos2l1=pnn1;
			pos2l2=pnn2;
		}
    }




	Cnode* temp =pos1l1->pnext;
	catcherprevl2->pnext = pos1l1->pnext;
	pos1l1->pnext = pos1l2->pnext;
	pos1l2->pnext = temp;
	catcherprevl1->pnext = pos2l2;
	
	return 0;

}