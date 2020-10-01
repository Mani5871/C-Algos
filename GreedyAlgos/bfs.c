
#include<stdio.h>
int a[20][20],i,n,visited[20],front=-1,rear=-1,q[20];
void readgraph();
void initialvisited();
void enque(int x);
int deque();
void BFS(int v)
{
        enque(v);
        visited[v]=1;
        while(front!=-1)
        {
                v=deque();
                printf("%d ",v);
                for(i=1;i<=n;i++)
                if(a[v][i]==1 && visited[i]!=1)
                {
                    enque(i);
                    visited[i]=1;
                }
        }
}
main()
{
        int v;
        readgraph();
        initialvisited();
        printf("Enter starting vertex:");
        scanf("%d",&v);
        printf("The breadth first traversal of the given graph is\n");
        BFS(v);
}
void readgraph()
{
        int i,j;
        printf("Enter number of vertices:");
        scanf("%d",&n);
        printf("Enter the adjacency matrix of the graph\n");
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
          scanf("%d",&a[i][j]);
}
void initialvisited()
{
        int i;
        for(i=1;i<=n;i++)
           visited[i]=0;
}
void enque(int x)
{
        if(front==-1)
           front=rear=0;
        else
           ++rear;
        q[rear]=x;
}
int deque()
{
        int x=q[front];
        if(front==rear)
           front=rear=-1;
        else
           ++front;
        return x;
}
