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
	Clist list;
	Cnode* pnn;
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		pnn = new Cnode[1];
		cin >> pnn->info;
		pnn->pnext = NULL;
		list.attach(pnn);
	}

	int target;
	cin >> target;
	int count = 0;
	Cnode* ptrav = list.phead;
	while (ptrav != NULL) {
		count++;
		if (ptrav->info == target) {
			break;
		}
		ptrav = ptrav->pnext;
	}

	int quarter = count / 4;
	int total = 0;
	ptrav = list.phead;
	for (int i = 0; i < count; i++) {
		if ((i >= quarter && i < 2 * quarter) || (i >= 3 * quarter)) {
			total += ptrav->info;
		}
		ptrav = ptrav->pnext;
	}

	cout << total << endl;
}