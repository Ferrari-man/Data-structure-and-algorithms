#include<iostream>
using namespace std;

class CNode {
public:
    int info;
    CNode* pnext;
    char** board;
    int currentRow;


    CNode(int size) {
        pnext = NULL;
        board = new char* [size];
        for (int i = 0; i < size; i++) {
            board[i] = new char[size];
        }
    }
};

class CList
{
public:
    CNode* phead;
    CNode* ptail;
    CList()
    {
        phead = NULL;
        ptail = NULL;
    }
    ~CList()
    {
        CNode* current = phead;
        while (current != NULL)
        {
            CNode* nextNode = current->pnext;
            delete current;
            current = nextNode;
        }
        phead = NULL;
        ptail = NULL;
    }

    void attach(CNode* pnn)
    {
        if (phead == NULL)
        {
            phead = pnn;
            ptail = pnn;
        }
        else
        {
            ptail->pnext = pnn;
            ptail = pnn;
        }
        pnn->pnext = NULL;
    }

    void display()
    {
        CNode* Ptrav = phead;
        while (Ptrav != NULL)
        {
            cout << Ptrav->info << " ";
            Ptrav = Ptrav->pnext;
        }
        cout << endl;

    }
};

class CStack
{
public:
    CNode* phead;

    CStack()
    {
        phead = NULL;
    }

    ~CStack()
    {


    }

    void push(CNode* pnn)
    {
        pnn->pnext = phead;
        phead = pnn;
    }

    CNode* pop()
    {
        if (phead == NULL)
            return NULL;

        CNode* ptrav = phead;
        phead = phead->pnext;
        ptrav->pnext = NULL;
        return ptrav;
    }

};

void copy(CNode* pnn, CNode* pCurr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pnn->board[i][j] = pCurr->board[i][j];
        }
    }

    pnn->currentRow = pCurr->currentRow;

}

void addQueen(int col, CNode* pnn) {
    pnn->board[pnn->currentRow][col] = 'Q';
    pnn->currentRow++;
}


int islegal(CNode* pnn, int n)
{
    int r = pnn->currentRow - 1;
    int c = -1;

    for (int j = 0; j < n; j++) {
        if (pnn->board[r][j] == 'Q') {
            c = j;
            break;
        }
    }

    for (int k = 0; k < r; k++) {
        if (pnn->board[k][c] == 'Q') return 0;
    }

    int i = r - 1;
    for (int j = c - 1; i >= 0 && j >= 0; i--) {
        if (pnn->board[i][j] == 'Q')
        {
            return 0;
        }
        j--;
    }
    int j = c + 1;
    for (int i = r - 1; i >= 0 && j < n; i--) {
        if (pnn->board[i][j] == 'Q')
        {
            return 0;
        }
        j++;
    }

    return 1;
}

void display(CNode* pnn, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << pnn->board[r][c] << " | ";
        }
        cout << endl;
    }
    cout << endl << "------------------------------------------------------------------------" << endl;
}

int main() {

    int n; cin >> n;

    CStack stack;
    CNode* pnn = new CNode(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pnn->board[i][j] = ' ';
        }
    }
    pnn->currentRow = 0;

    stack.push(pnn);
    int currSolution = 1;
    for (;;) {

        CNode* pCurr = stack.pop();
        if (pCurr == NULL) {
            break;
        }

        for (int i = 0; i < n; i++) {

            CNode* pnn = new CNode(n);
            copy(pnn, pCurr, n);
            addQueen(i, pnn);
            if (islegal(pnn, n)) {
                if (pnn->currentRow == n) {
                    cout << "Solution " << currSolution << " :" << endl;
                    display(pnn, n);
                    currSolution++;
                }
                else {
                    stack.push(pnn);
                }

            }
        }

    }
    return 0;
}