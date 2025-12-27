#include <iostream>
#include <string>
using namespace std;


class cnode {
public:
	int side1theif[3];
	int side1money[3];
	int side2theif[3];
	int side2money[3];
	int boat;
	cnode* pnext;
	string history;
};

class cstack
{
public:
	cnode* phead;

	cstack()
	{
		phead = NULL;
	}

	~cstack()
	{
		// Don't delete nodes - visited list owns them
		phead = NULL;
	}

	void push(cnode* pnn)
	{
		pnn->pnext = phead;
		phead = pnn;
	}

	cnode* pop()
	{
		if (phead == NULL)
			return NULL;

		cnode* ptrav = phead;
		phead = phead->pnext;
		ptrav->pnext = NULL;

		return ptrav;
	}

	int isempty()
	{
		if (phead == NULL)
			return 1;
		else
			return 0;
	}
};

class clist {
public:
	cnode* phead;
	cnode* ptail;

	clist() {
		phead = NULL;
		ptail = NULL;
	}

	~clist() {
		cnode* ptrav = phead;
		while (ptrav != NULL) {
			phead = ptrav->pnext;
			ptrav->pnext = NULL;
			delete ptrav;
			ptrav = phead;
		}

	}
	void attach(cnode* pnn) {
		if (phead == NULL) {
			phead = pnn;
			ptail = pnn;
		}
		else {
			ptail->pnext = pnn;
			ptail = pnn;
		}
		pnn->pnext = NULL; 
	}

};

cnode* createinit()
{
	cnode* pnn = new cnode;
	for (int i = 0; i < 3; i++) {
		pnn->side1theif[i] = 1;
		pnn->side1money[i] = 1;
		pnn->side2theif[i] = 0;
		pnn->side2money[i] = 0;
	}
	pnn->boat = 1;
	pnn->pnext = NULL;
	pnn->history = "";  
	return pnn;
}

int islegal(cnode* pnn, int defaultmoney[])
{
	int totalmoney = 0;
	if (pnn->side1theif[0] == 1 && pnn->side1theif[1]==0 && pnn->side1theif[2]==0)
	{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side1money[i] * defaultmoney[i];
		}
		if(totalmoney> 1000)
		{
			return 0;
		}
	}
	totalmoney = 0;
	if (pnn->side2theif[0] == 1 && pnn->side2theif[1] == 0 && pnn->side2theif[2] == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side2money[i] * defaultmoney[i];
		}
		if (totalmoney > 1000)
		{
			return 0;
		}
	}
	totalmoney = 0;
	if (pnn->side1theif[1] == 1 && pnn->side1theif[0]==0 && pnn->side1theif[2]==0)
	{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side1money[i] * defaultmoney[i];
		}
		if (totalmoney > 700)
		{
			return 0;
		}
	}
	totalmoney = 0;
	if (pnn->side2theif[1] == 1 && pnn->side2theif[0] == 0 && pnn->side2theif[2] == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side2money[i] * defaultmoney[i];
		}
		if (totalmoney > 700)
		{
			return 0;
		}
	}
	totalmoney = 0;
	if (pnn->side1theif[2] == 1 && pnn->side1theif[0] == 0 && pnn->side1theif[1] == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side1money[i] * defaultmoney[i];
		}
		if (totalmoney > 300)
		{
			return 0;
		}
	}
	totalmoney = 0;
	if (pnn->side2theif[2] == 1 && pnn->side2theif[0] == 0 && pnn->side2theif[1] == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side2money[i] * defaultmoney[i];
		}
		if (totalmoney > 300)
		{
			return 0;
		}
	}

	totalmoney = 0;
	if(pnn->side1theif[0]==1 && pnn->side1theif[1]==1 && pnn->side1theif[2]==0)
		{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side1money[i] * defaultmoney[i];
		}
		if (totalmoney > 1700)
		{
			return 0;
		}
	}
	totalmoney = 0;
	if (pnn->side2theif[0] == 1 && pnn->side2theif[1] == 1 && pnn->side2theif[2] == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side2money[i] * defaultmoney[i];
		}
		if (totalmoney > 1700)
		{
			return 0;
		}
	}
	totalmoney = 0;
	if(pnn->side1theif[0]==1 && pnn->side1theif[2]==1 && pnn->side1theif[1]==0)
	{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side1money[i] * defaultmoney[i];
		}
		if (totalmoney > 1300)
		{
			return 0;
		}
	}
	totalmoney = 0;
	if (pnn->side2theif[0] == 1 && pnn->side2theif[2] == 1 && pnn->side2theif[1] == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side2money[i] * defaultmoney[i];
		}
		if (totalmoney > 1300)
		{
			return 0;
		}
	}
	totalmoney = 0;
	if(pnn->side1theif[1]==1 && pnn->side1theif[2]==1 && pnn->side1theif[0]==0)
	{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side1money[i] * defaultmoney[i];
		}
		if (totalmoney > 1000)
		{
			return 0;
		}
	}
	totalmoney = 0;
	if (pnn->side2theif[1] == 1 && pnn->side2theif[2] == 1 && pnn->side2theif[0] == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			totalmoney += pnn->side2money[i] * defaultmoney[i];
		}
		if (totalmoney > 1000)
		{
			return 0;
		}
	}


	return 1;
}




void copy(cnode* pnext, cnode* pcurr)
{
	for (int i = 0; i < 3; i++)
	{
		pnext->side1theif[i] = pcurr->side1theif[i];
		pnext->side1money[i] = pcurr->side1money[i];
		pnext->side2theif[i] = pcurr->side2theif[i];
		pnext->side2money[i] = pcurr->side2money[i];
	}
	pnext->boat = pcurr->boat;
	pnext->pnext = NULL;
	pnext->history = pcurr->history;
}
int compare(cnode* pA, cnode* pB)
{
	if (pA->boat != pB->boat) return 0;

	for (int i = 0; i < 3; i++)
	{
		if (pA->side1theif[i] != pB->side1theif[i]) return 0;
		if (pA->side2theif[i] != pB->side2theif[i]) return 0;
		if (pA->side1money[i] != pB->side1money[i]) return 0;
		if (pA->side2money[i] != pB->side2money[i]) return 0;
	}

	return 1;
}


int isvisited(cnode* pnn, clist& visited)
{
	cnode* ptrav = visited.phead;

	while (ptrav != NULL)
	{
		if (compare(pnn, ptrav) == 1)
		{
			return 1;
		}
		ptrav = ptrav->pnext;
	}

	return 0;
}

int solutionfound(cnode* pnn)
{
	for (int i = 0; i < 3; i++)
	{
		if (pnn->side2theif[i] != 1)
		{
			return 0;
		}
		if (pnn->side2money[i] != 1)
		{
			return 0;
		}
	}
	return 1;
}

void expandnextgen(cnode* pcurr, cstack& s, clist& visited)
{

	int defaultmoney[3] = { 1000,700,300 };

	string MOVE_NAMES[15] = {
   "M0:T0", "M1:T1", "M2:T2",
   "M3:T0+T1", "M4:T0+T2", "M5:T1+T2",
   "M6:T0+M0", "M7:T0+M1", "M8:T0+M2",
   "M9:T1+M0", "M10:T1+M1", "M11:T1+M2",
   "M12:T2+M0", "M13:T2+M1", "M14:T2+M2"
	};

	for (int i = 0; i < 15; i++)
	{
		cnode* pnn = new cnode;
		copy(pnn, pcurr);
		int original_boat = pcurr->boat;

		// move 1 thief 
		if (i == 0)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[0] == 1)
				{
					pnn->side1theif[0] = 0;
					pnn->side2theif[0] = 1;
					pnn->boat = 2;
				}

			}
			else
			{
				if (pnn->side2theif[0] == 1)
				{
					pnn->side2theif[0] = 0;
					pnn->side1theif[0] = 1;
					pnn->boat = 1;
				}
			}

		}
		if (i == 1)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[1] == 1)
				{
					pnn->side1theif[1] = 0;
					pnn->side2theif[1] = 1;
					pnn->boat = 2;
				}

			}
			else
			{
				if (pnn->side2theif[1] == 1)
				{
					pnn->side2theif[1] = 0;
					pnn->side1theif[1] = 1;
					pnn->boat = 1;
				}
			}
		}
		if (i == 2)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[2] == 1)
				{
					pnn->side1theif[2] = 0;
					pnn->side2theif[2] = 1;
					pnn->boat = 2;
				}

			}
			else
			{
				if (pnn->side2theif[2] == 1)
				{
					pnn->side2theif[2] = 0;
					pnn->side1theif[2] = 1;
					pnn->boat = 1;
				}
			}
		}
		// move 2 thieves
		if (i == 3)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[0] == 1 && pnn->side1theif[1] == 1)
				{
					pnn->side1theif[0] = 0;
					pnn->side2theif[0] = 1;
					pnn->side1theif[1] = 0;
					pnn->side2theif[1] = 1;
					pnn->boat = 2;
				}
			}
			else
			{
				if (pnn->side2theif[0] == 1 && pnn->side2theif[1] == 1)
				{
					pnn->side2theif[0] = 0;
					pnn->side1theif[0] = 1;
					pnn->side2theif[1] = 0;
					pnn->side1theif[1] = 1;
					pnn->boat = 1;
				}
			}
		}
		if (i == 4)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[0] == 1 && pnn->side1theif[2] == 1)
				{
					pnn->side1theif[0] = 0;
					pnn->side2theif[0] = 1;
					pnn->side1theif[2] = 0;
					pnn->side2theif[2] = 1;
					pnn->boat = 2;
				}
			}
			else
			{
				if (pnn->side2theif[0] == 1 && pnn->side2theif[2] == 1)
				{
					pnn->side2theif[0] = 0;
					pnn->side1theif[0] = 1;
					pnn->side2theif[2] = 0;
					pnn->side1theif[2] = 1;
					pnn->boat = 1;
				}
			}
		}
		if (i == 5)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[1] == 1 && pnn->side1theif[2] == 1)
				{
					pnn->side1theif[1] = 0;
					pnn->side2theif[1] = 1;
					pnn->side1theif[2] = 0;
					pnn->side2theif[2] = 1;
					pnn->boat = 2;
				}
			}
			else
			{
				if (pnn->side2theif[1] == 1 && pnn->side2theif[2] == 1)
				{
					pnn->side2theif[1] = 0;
					pnn->side1theif[1] = 1;
					pnn->side2theif[2] = 0;
					pnn->side1theif[2] = 1;
					pnn->boat = 1;
				}
			}
		}

		// move 1 thief and 1 money :(

		if (i == 6)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[0] == 1 && pnn->side1money[0] == 1)
				{
					pnn->side1theif[0] = 0; pnn->side2theif[0] = 1;
					pnn->side1money[0] = 0; pnn->side2money[0] = 1;
					pnn->boat = 2;
				}
			}
			else
			{
				if (pnn->side2theif[0] == 1 && pnn->side2money[0] == 1)
				{
					pnn->side2theif[0] = 0; pnn->side1theif[0] = 1;
					pnn->side2money[0] = 0; pnn->side1money[0] = 1;
					pnn->boat = 1;
				}
			}
		}
		if (i == 7)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[0] == 1 && pnn->side1money[1] == 1)
				{
					pnn->side1theif[0] = 0; pnn->side2theif[0] = 1;
					pnn->side1money[1] = 0; pnn->side2money[1] = 1;
					pnn->boat = 2;
				}
			}
			else
			{
				if (pnn->side2theif[0] == 1 && pnn->side2money[1] == 1)
				{
					pnn->side2theif[0] = 0; pnn->side1theif[0] = 1;
					pnn->side2money[1] = 0; pnn->side1money[1] = 1;
					pnn->boat = 1;
				}
			}
		}
		if (i == 8)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[0] == 1 && pnn->side1money[2] == 1)
				{
					pnn->side1theif[0] = 0; pnn->side2theif[0] = 1;
					pnn->side1money[2] = 0; pnn->side2money[2] = 1;
					pnn->boat = 2;
				}
			}
			else
			{
				if (pnn->side2theif[0] == 1 && pnn->side2money[2] == 1)
				{
					pnn->side2theif[0] = 0; pnn->side1theif[0] = 1;
					pnn->side2money[2] = 0; pnn->side1money[2] = 1;
					pnn->boat = 1;
				}
			}
		}
		if (i == 9)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[1] == 1 && pnn->side1money[0] == 1)
				{
					pnn->side1theif[1] = 0; pnn->side2theif[1] = 1;
					pnn->side1money[0] = 0; pnn->side2money[0] = 1;
					pnn->boat = 2;
				}
			}
			else
			{
				if (pnn->side2theif[1] == 1 && pnn->side2money[0] == 1)
				{
					pnn->side2theif[1] = 0; pnn->side1theif[1] = 1;
					pnn->side2money[0] = 0; pnn->side1money[0] = 1;
					pnn->boat = 1;
				}
			}
		}
		if (i == 10)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[1] == 1 && pnn->side1money[1] == 1)
				{
					pnn->side1theif[1] = 0; pnn->side2theif[1] = 1;
					pnn->side1money[1] = 0; pnn->side2money[1] = 1;
					pnn->boat = 2;
				}
			}
			else
			{
				if (pnn->side2theif[1] == 1 && pnn->side2money[1] == 1)
				{
					pnn->side2theif[1] = 0; pnn->side1theif[1] = 1;
					pnn->side2money[1] = 0; pnn->side1money[1] = 1;
					pnn->boat = 1;
				}
			}
		}
		if (i == 11)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[1] == 1 && pnn->side1money[2] == 1)
				{
					pnn->side1theif[1] = 0; pnn->side2theif[1] = 1;
					pnn->side1money[2] = 0; pnn->side2money[2] = 1;
					pnn->boat = 2;
				}
			}
			else
			{
				if (pnn->side2theif[1] == 1 && pnn->side2money[2] == 1)
				{
					pnn->side2theif[1] = 0; pnn->side1theif[1] = 1;
					pnn->side2money[2] = 0; pnn->side1money[2] = 1;
					pnn->boat = 1;
				}
			}
		}
		if (i == 12)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[2] == 1 && pnn->side1money[0] == 1)
				{
					pnn->side1theif[2] = 0; pnn->side2theif[2] = 1;
					pnn->side1money[0] = 0; pnn->side2money[0] = 1;
					pnn->boat = 2;
				}
			}
			else
			{
				if (pnn->side2theif[2] == 1 && pnn->side2money[0] == 1)
				{
					pnn->side2theif[2] = 0; pnn->side1theif[2] = 1;
					pnn->side2money[0] = 0; pnn->side1money[0] = 1;
					pnn->boat = 1;
				}
			}
		}
		if (i == 13)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[2] == 1 && pnn->side1money[1] == 1)
				{
					pnn->side1theif[2] = 0; pnn->side2theif[2] = 1;
					pnn->side1money[1] = 0; pnn->side2money[1] = 1;
					pnn->boat = 2;
				}
			}
			else
			{
				if (pnn->side2theif[2] == 1 && pnn->side2money[1] == 1)
				{
					pnn->side2theif[2] = 0; pnn->side1theif[2] = 1;
					pnn->side2money[1] = 0; pnn->side1money[1] = 1;
					pnn->boat = 1;
				}
			}
		}
		if (i == 14)
		{
			if (pnn->boat == 1)
			{
				if (pnn->side1theif[2] == 1 && pnn->side1money[2] == 1)
				{
					pnn->side1theif[2] = 0; pnn->side2theif[2] = 1;
					pnn->side1money[2] = 0; pnn->side2money[2] = 1;
					pnn->boat = 2;
				}
			}
			else 
			{
				if (pnn->side2theif[2] == 1 && pnn->side2money[2] == 1)
				{
					pnn->side2theif[2] = 0; pnn->side1theif[2] = 1;
					pnn->side2money[2] = 0; pnn->side1money[2] = 1;
					pnn->boat = 1;
				}
			}
			
		}


		if (pnn->boat != original_boat)
		{
			pnn->history += MOVE_NAMES[i] + "->";

			if (islegal(pnn, defaultmoney))
			{ 

				if (isvisited(pnn, visited) == 0)
				{

					visited.attach(pnn);
					s.push(pnn);
				}
				else
				{
					delete pnn;
				}
			}
			else
			{
				delete pnn; 
			}
		}
		else
		{
			delete pnn; 
		}
	}

}


int main() {
	int countsol = 0;
	cstack s;
	clist visited;
	cnode* pcurr, * pinit;
	pinit = createinit();

	visited.attach(pinit);
	s.push(pinit);

	int defaultmoney[3] = { 1000,700,300 };
	if (islegal(pinit, defaultmoney) == 1) {
		cout << "Initial state is legal." << endl;
	}

	for (;;)
	{

		pcurr = s.pop();

	

		if (solutionfound(pcurr))
		{
			cout << "Solution found! " << countsol << endl;
			cout << "Solution path: " << pcurr->history << endl;
			countsol++;
		}

		expandnextgen(pcurr, s, visited);

	}

	return 0;
}