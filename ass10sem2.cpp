//ASSN:10

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int len;
    int **adja_mat;
    int **cost;
    int *visited;
    int *distance;
    int *from;

    public:Graph(int x)
           {
               int i,j;
               len=x;
               adja_mat=new int* [x];
               for(i=0;i<x;i++)
               {
                   adja_mat[i]=new int[x];
               }

               for(i=0;i<len;i++)
                    for(j=0;j<len;j++)
                        adja_mat[i][j]=0;


               cost=new int*[x];
               for(i=0;i<x;i++)
               {
                   cost[i]=new int[x];
               }
               for(i=0;i<len;i++)
                    for(j=0;j<len;j++)
                        cost[i][j]=10000;

               visited=new int[x];
               for(i=0;i<len;i++)
                    *(visited+i)=0;

               distance=new int[x];
               for(i=0;i<len;i++)
                    *(distance+i)=10000;

               from=new int[x];
               for(i=0;i<len;i++)
                    *(from+i)=i;
        }

           void create()
           {
               int x,y,w;
               cout<<"\n\nEnter the City A and City B between which telephone line exist and distance between them .(Enter -1,-1 to stop)!";

               while(1)
               {
                    cout<<"\n\nCity A:";
                    cin>>x;
                    cout<<"\nCity B:";
                    cin>>y;

                    if(x==-1 && y==-1)
                        break;
                    else if(x>len || y>len)
                    {
                        cout<<"\nOut of Bound!";
                        continue;
                    }
                    cout<<"\nDistance:";
                    cin>>w;
                    adja_mat[x-1][y-1]=1;
                    adja_mat[y-1][x-1]=1;
                    cost[x-1][y-1]=w;
                    cost[y-1][x-1]=w;
               }
            }

            void display()
            {
                int i,j;
                cout<<"\n\nAdjacency Matrix\n\n";

                for(i=0;i<len;i++)
                {
                    for(j=0;j<len;j++)
                        cout<<adja_mat[i][j]<<" ";
                    cout<<"\n";
                }

                cout<<"\n\nCOST Matrix\n\n";

                for(i=0;i<len;i++)
                {
                    for(j=0;j<len;j++)
                        cout<<cost[i][j]<<"   ";
                    cout<<"\n";
                }
            }

            void Prim()
            {
                int i,j,source,flag=0;
                long costmin=0;

                for(i=0;i<len;i++)
                    from[i]=i;

                for(i=0;i<len;i++)
                {
                    *(distance+i)=10000;
                    *(visited+i)=0;
                }

                int spann[len][len];

                for(i=0;i<len;i++)
                    for(j=0;j<len;j++)
                        spann[i][j]=0;

                *(distance+0)=0;
                cout<<"\n\nPath of the Minimum Spanning Tree is:\n";
                while(flag==0)
                {
                    for(i=0;i<len;i++)
                    {
                        if(visited[i]==0)
                        {
                            source=i;
                            break;
                        }
                    }

                    for(i=0;i<len;i++)
                    {
                        if(visited[i]==0 && source!=i)
                        {
                            if(*(distance+i)<*(distance+source))
                                source=i;
                        }
                    }

                    *(visited+source)=1;

                    if(source!=0)
                    {
                        spann[ from[source] ][source]=1;
                        spann[source][from[source]]=1;
                        cout<<":"<<from[source]+1<<"->"<<source+1<<":\n";
                    }

                    for(i=0;i<len;i++)
                    {
                        if(cost[source][i]!=10000 && *(visited+i)==0)
                        {
                            if(cost[source][i]<distance[i])
                            {
                                distance[i]=cost[source][i];
                                from[i]=source;
                            }
                        }
                    }
                    flag=1;

                    for(i=0;i<len;i++)
                    {
                        if(visited[i]==0)
                        {
                            flag=0;
                            break;
                        }
                    }
                }
                for(i=0;i<len;i++)
                    costmin+=*(distance+i);

                cout<<"\n\nMinimum Spanning Tree Adjacency Matrix is:\n";

                for(i=0;i<len;i++)
                {
                    for(j=0;j<len;j++)
                        cout<<spann[i][j]<<" ";
                    cout<<"\n";
                }
                cout<<"\n\nMinimum Spanning Tree Distance is:\n";
                for(i=0;i<len;i++)
                    cout<<distance[i]<<" ";
                cout<<"\n";
                cout<<"\nFinally Minimum Cost"<<costmin<<"\n";
            }
};

int main()
{
    int len;
    cout<<"\n// PROBLEM CAN BE SOLVED BY CONSIDERING THE CITIES AS GRAPH NODE AND TELEPHONE WIRE AS EDGES.THEN CALCULATING THE MINIMUM SPANNING TREE,WE CAN FIND THE MIN COST";
    cout<<"\nNOTE:Considering Graph as undirected.\n";
    cout<<"\nEnter the number of cities";
    cin>>len;
    Graph G(len);
    G.create();
    cout<<"\n\nGraph Representation of Cities:\n\n";

    cout<<"\n\nCOST MATRIX AND ADJACENCY MATRIX\n\n";
    G.display();
    cout<<"\n\nPRIM's ALGORITHM\n\n";
    G.Prim();
    return 0;
}
