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

	int tot = 0;
	Cnode* ptrav;
	Cnode* pcatch;
	int pos;
	ptrav = l1.phead;
	while (ptrav != NULL) {
		tot += ptrav->info;
		ptrav = ptrav->pnext;
	}
	ptrav = l2.phead; int i = 0;
	while (ptrav != NULL) {
		if (ptrav->info == tot) {
			pcatch = ptrav;
			 pos = i;
			break;
		}
		ptrav = ptrav->pnext;
		i++;
	}

	int j = pos / 2 + 1;
	ptrav = l2.phead;

	for (int i = 0; i < j; i++) {
		ptrav = ptrav->pnext;
	}
	int max = -1;
	while (ptrav != NULL) {
		if (ptrav->info > max){
			max = ptrav->info;
		}
		ptrav = ptrav->pnext;
	}
}
