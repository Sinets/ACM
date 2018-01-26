#include<stdio.h>
#include<string.h>
#define INF 0x3f3f3f3f

int e[510][510],army[510];//每个点的救援队

int n,m,s,d;

void Rode()
{
    int step[510] = {0},rode[510] = {0};//存储最短路的个数与路径
    int dis[510],A[510] = {0};//dis~i点到源点的最短距离，A~i点到源点的最多救援队
    for(int i = 0; i<n; i++)
    {
        dis[i] = e[i][s];
        if(dis[i]<INF)//与i点相连的点
        {
            step[i] = 1;
            A[i] = army[i]+army[s];
            rode[i] = s;
        }
    }
    dis[s] = 0;
    int book[510] = {0},k = 1;
    book[s] = 1;
    
    while(1)
    {
        int Min = INF,x = 0;
        for(int i = 0; i<n; i++)
            if(book[i] == 0 && dis[i] < Min)
            {
                Min = dis[i];
                x = i;
            }
        if(x == d) break;
        book[x] = 1;
        for(int i = 0; i<n; i++)
        {
            if(dis[i] > dis[x]+e[x][i])
            {
                A[i] = A[x]+army[i];
                dis[i] = dis[x]+e[x][i];
                rode[i] = x;
                if(step[i] < step[x]) step[i] = step[x];
            }
            else if(dis[i] == dis[x]+e[x][i])
            {
                if(A[i] < A[x]+army[i])
                {
                    A[i] = A[x]+army[i];
                    rode[i] = x;
                }
                step[i] += step[x];
            }
        }
    }
    printf("%d %d\n",step[d],A[d]);
    int R[510],i = d,j = 0;
    while(i!=s)
    {
        R[j++] = i;
        i = rode[i];
    }
    printf("%d",s);
    for(j--; j>=0; j--)
        printf(" %d",R[j]);
    printf("\n");
}
int main()
{

    while(~scanf("%d%d%d%d",&n,&m,&s,&d))
    {
        memset(e,INF,sizeof(e));
        for(int i = 0; i<n; i++)
        {
            scanf("%d",&army[i]);
        }
        int a,b,c;
        for(int i = 0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(e[a][b] < c) continue;
            e[a][b] = e[b][a] = c;
        }
        Rode();
    }
}