

#include <iostream>
#include <cstdlib>
#include<time.h>
#include<conio.h>
#include<ctime>
using namespace std;
 int vertex=5000;
 int deg=6;
 int graph[6000][6000];
 int vertexcounter[6000];
 int countvert[6000];

 void seed()
{
	srand(time(0));
}

 





 
 // Adjacency List Node
struct node
{
    int dest;
	int weight;
    struct node* next;
};
 

//  Adjacency List   
struct adjlist
{
    struct node *head;
};

adjlist* array1;
void graph1(int vertex)
{
	array1= new adjlist[vertex];
	for(int i=1;i<=vertex;i++)
	 array1[i].head=NULL;
}

 
 node* newadjnode(int dest)
    {
       node* newnode = new node;
       newnode->dest = dest;
       newnode->next = NULL;
       return newnode;
    }
        
 //Adding Edge to Graph
 void addedge(int src, int dest,int weight)
     {
        node* newnode = newadjnode(dest);
        newnode->next = array1[src].head;
	    newnode->weight=weight;
        array1[src].head = newnode;
        newnode = newadjnode(src);
		newnode->weight=weight;
        newnode->next = array1[dest].head;
        array1[dest].head = newnode;
     }
        
// Print the graph
          
void printgraph()
 {
    int v;
    for (v = 1; v <= vertex; ++v)
       {
           node* pCrawl = array1[v].head;
           cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (pCrawl)
                {
                    cout<<"-> "<<pCrawl->dest;
					cout<<"()"<<pCrawl->weight;
                    pCrawl = pCrawl->next;
                }
                cout<<endl;
       }
 }

 void generategraphwith1000degree()
 {
	 
 for(int i=1;i<=vertex;i++)
		for(int j=1;j<=vertex;j++)
			graph[i][j]=0;
  for(int i=1;i<=vertex;i++)
	{
		for(int j=1;j<=vertex;j++)
		{

		if(i!=j)
		{
			int r=rand()%5000+1;
			if(r<500)
			{
			    //graph[i][j]=1;
				//graph[j][i]=1;
				seed();
				int w1= rand()%100+1;
				addedge(i,j,w1);
				
			}
		}
		}
	}
	
  for(int i=1;i<=4999;i++)
  {
	  int w2=rand()%100+1;
	  addedge(i,i+1,w2);
  }
  
	}
void generategraphwith6degree()
 {
	 for(int i=1;i<=vertex;i++)
		vertexcounter[i]=0;
	
	int random1,random2;
	int counter=0;
	
	while(counter<(vertex*deg)/2)
	{
		random1=rand()%vertex+1;
		random2=rand()%vertex+1;
		if((vertexcounter[random1]<6)&&(vertexcounter[random2]<6)&&(random1!=random2)&&(graph[random1][random2]!=1))
		{
			graph[random1][random2]=1;
			graph[random2][random1]=1;
			counter++;
			int w= rand()%100+1;
			addedge(random1,random2,w);
		
		}

	}
	for(int i=1;i<=4999;i++)
  {
	  int w2=rand()%100+1;
	  addedge(i,i+1,w2);
  }

 }

 
int maxDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int max = -1000, max_index;
 
    for (int v = 1; v <= vertex; v++)
	{
        if (sptSet[v] == false && dist[v] >= max)
		{
            max = dist[v];
			max_index = v;
		}
	}
    return max_index;
}

int min(int x,int y)
{
	if(x>y)
		return y;
	else
		return x;
}

void dikstra(int src1,int final)
{
	int dist[6000];
	bool set[6000];
	for(int i=1;i<=vertex;i++)
	{
		dist[i]=-1000;
		set[i]=false;
	}
	dist[src1]=1000;
	for(int i=1;i<=vertex;i++)
	{
		
		int u = maxDistance(dist,set);
		set[u]=true;
		node* p=array1[u].head;
		while(p)
		{
			
			if(set[p->dest]==false&&dist[p->dest]<min(dist[u],p->weight))
			{
				dist[p->dest]=min(dist[u],p->weight);
			  
			}
			p=p->next;
		}
	}
	
		cout<<"max bandth with between"<<src1<<"and"<<final<<"is :"<<dist[final]<<endl;
}






int main()
{
	seed();
	cout<<" This is the Modified Dijkstra Algorithm without heap for a Sparse graph"<<endl;
    graph1(vertex);
    generategraphwith6degree();
	int s1,d1;
	s1=rand()%5000+1;
	d1=rand()%5000+1;
	clock_t beg=clock();
	dikstra(s1,d1);
    clock_t end=clock();
	double timeelapsed=0;
	timeelapsed=(double(end-beg))/CLOCKS_PER_SEC;
	cout<<"time elapsed :"<<timeelapsed<<endl;

    return 0;
}

