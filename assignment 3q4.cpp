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
		Cnode* ptrav = phead;
		while (ptrav != NULL) {
			phead = ptrav->pnext;
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


	Clist* x[30];
	int n;


	for (int i = 0; i < 30; i++) {
		cin >> n;
		x[i] = new Clist();
		for (int j = 0; j < n; j++) {
			Cnode* pnn = new Cnode();
			cin >> pnn->info;
			pnn->pnext = NULL;
			x[i]->attach(pnn);
		}
	}

	Clist targetlist; Cnode* pnn;
	cin >> n;
	for (int i = 0; i < n; i++) {
		pnn = new Cnode();
		cin >> pnn->info;
		pnn->pnext = NULL;
		targetlist.attach(pnn);
	}
	int halflist = n / 2;

	int flag = 0;

	for (int i = 0; i < 30; i++) {
		Cnode* search = x[i]->phead;

		while (search != NULL) {
			// find half 1
			Cnode* target = targetlist.phead;
			Cnode* current = search;
			int count = 0;

			while (target != NULL && current != NULL && count < halflist) {
				if (target->info != current->info) {
					break;
				}
				target = target->pnext;
				current = current->pnext;
				count++;
			}
			if (count == halflist && flag == 0) {
				flag = 1;
			}

			//find half 2
			target = targetlist.phead;
			for (int k = 0; k < halflist; k++) {
				target = target->pnext;
			}
			current = search;
			count = 0;

			while (target != NULL && current != NULL && count < (n - halflist)) {
				if (target->info != current->info) {
					break;
				}
				target = target->pnext;
				current = current->pnext;
				count++;
			}
			if (count == (n - halflist) && flag == 0) {
				flag = 2;
			}

			search = search->pnext;
		}
	}
	if (flag == 2) {
		Cnode* mid = targetlist.phead;
		Cnode* prev = NULL;

		for (int i = 0; i < halflist; i++) {
			prev = mid;
			mid = mid->pnext;
		}

		targetlist.ptail->pnext = targetlist.phead;
		prev->pnext = NULL;
		targetlist.phead = mid;
	}

}