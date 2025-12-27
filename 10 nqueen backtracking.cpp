#include <iostream>
using namespace std;


class cnode
{
    public:
    cnode* pnext;
    char board[10][10];
    int current_row;

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

};

void copy(cnode* pnn,cnode*current)
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            pnn->board[i][j]=current->board[i][j];
        }
    }
    pnn->current_row=current->current_row;
}
void addqueen(cnode*pnn,int currentrow,int i)
{
    pnn->board[currentrow][i]='Q';
}
int islegal(cnode* pnn)
{
    int r = pnn->current_row - 1;
    int c = -1;

    for(int j=0; j<10; j++) {
        if(pnn->board[r][j] == 'Q') {
            c = j;
            break;
        }
    }

    for(int k=0; k<r; k++) {
        if(pnn->board[k][c] == 'Q') return 0;
    }

    for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--) {
        if(pnn->board[i][j] == 'Q') return 0;
    }

    for(int i=r-1, j=c+1; i>=0 && j<10; i--, j++) {
        if(pnn->board[i][j] == 'Q') return 0;
    }

    return 1;
}


void main()
{
    cstack S;
    cnode* pstart = new cnode;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            pstart->board[i][j]=' ';
        }
    }

    S.push(pstart);
    for(;;)
    {
        cnode*pcurrent=S.pop();
        for(int i=0;i<10;i++)
        {
            cnode*pnn=new cnode;
            copy(pnn,pcurrent);
            addqueen(pnn,pnn->current_row,i);
            pnn->current_row++;
            if(islegal(pnn)==1)
            {
                S.push(pnn);
            }
            else
            {
                delete pnn;
            }
        }
        delete pcurrent;
    }
}