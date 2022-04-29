#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int board[20],count;

int main()
{
    int n,i,j;
    void queen(int row ,int n);
    printf("\n\nEnter number of Queens : ");
    scanf("%d",&n);
    queen(1,n); // 1 4
    return 0;
}

void print(int n)
{
    int x,y;
    printf("\n\nSolution %d:\n\n",++count);
    for(x=1;x<=n;++x)
        printf("\t%d",x);
    for(x=1;x<=n;++x)
    {
        printf("\n\n%d",x);
        for(y=1;y<=n;++y) 
        {
            if(board[x]==y)
                printf("\tQ"); 
            else
                printf("\t-");
        }
    }
}

int place(int k,int i) // k is row   1 1
{
    int j;
    for(j=1;j<=k-1;++j)
    {
        if(board[j] == i || abs(board[j]-i) == abs(j-k)) // 1st condition is to check if 2 queens are in same col; 2nd condition is to check if 2 queens are in same diag
            return 0;
    }
    return 1;
}

void queen(int k ,int n) // here, k is row  1 4
{
    int i;
    for(i=1;i<=n;++i) // 1
    {
        if(place(k,i)) // 1  1
        {
            board[k]=i;
            if(k==n) 
                print(n);
            else 
                queen(k+1,n);
        }
    }
}