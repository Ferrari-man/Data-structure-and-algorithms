#include <iostream>
using namespace std;

class Cnode {
public:
	int info;
	Cnode* pnext;
};

int  main() {
	Cnode* phead = NULL;
	Cnode* pnn;
	for(int i = 0; i < 5; i++) {
		if (phead == NULL) {
			phead = new Cnode[1];
			cin >> phead->info;
			phead->pnext = NULL;
		} 
		else {
			pnn = new Cnode[1];
			cin >> pnn->info;
			pnn->pnext = NULL;
			Cnode* ptrav = phead;
			for(int k=0; k < i - 1; k++) {
				ptrav = ptrav->pnext;
			}
			ptrav->pnext = pnn;
		}
	}
	return 0;
}
