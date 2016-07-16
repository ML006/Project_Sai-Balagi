

 
#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;
int vertex=5000;
int size=5000;
int heap1[6000];
int heap2[6000];
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
 

 // Adjacency List
   
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
        
  //Print the graph
          
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
			//cout<<counter<<" "<<random1;
			//cout<<endl;
		}

	}

	for(int i=1;i<=4999;i++)
  {
	  int w2=rand()%100+1;
	  addedge(i,i+1,w2);
  }

 }

 
void maxheapify(int* heap1, int i, int size)
{
	
	int largest;
	int left=2*i;
	int right=(2*i)+1;
	if(left<=size&&heap2[heap1[left]]>heap2[heap1[i]])
		largest=left;
	else
		largest=i;
	if(right<=size&&heap2[heap1[right]]>heap2[heap1[largest]])
		largest=right;

	if(largest!=i)
	{
		int temp=heap1[i];
		heap1[i]=heap1[largest];
		heap1[largest]=temp;
		maxheapify(heap1,largest,size);
	}
}

void buildmaxheap(int* heap1,int size)
{
	for(int i=size/2;i>=1;i--)
		maxheapify(heap1,i,size);
}
 

int extractmax(int* heap1)
{
	//int tempsize=size;
	if(size<1)
	{
		//cout<<size;
	   cout<<"error";
	}
	else
	{
		int max=heap1[1];
	    heap1[1]=heap1[size];
	    size=size-1;
	    maxheapify(heap1,1,size);
	    return max;
	}
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
	for(int i=1;i<=vertex;i++)
	{
		heap1[i]=i;
		heap2[heap1[i]]=-1000;
	}
	heap2[heap1[src1]]=1000;
	buildmaxheap(heap1,size);
	
	
	for(int i=1;i<=vertex;i++)
	{
		//cout<<2;
		int u = extractmax(heap1);
	
		
		node* p=array1[u].head;
	
		while(p)
		{
			
			if(heap2[p->dest]<min(heap2[u],p->weight))
			{
				heap2[p->dest]=min(heap2[u],p->weight);
			}
			p=p->next;
		}
	}
	
	//for(int i=1;i<=vertex;i++)
		cout<<"The max bandwidth between"<<src1<<"and"<<final<<"is:"<<heap2[final]<<endl;
	
}




int main()
{
	cout<<" This is the Modified Dijkstra Algorithm using heap for a Dense graph"<<endl;
    graph1(vertex);
	seed();
    //addedge(1,2,2);
    //addedge(1,3,4);
    //addedge(2,3,1);
	//addedge(2,5,3);
	//addedge(3,4,6);
	//addedge(4,5,5);
	//addedge(1,2,1);
    //addedge(1,7,11);
    //addedge(1,8,8);
	//addedge(1,9,7);
	//addedge(2,3,2);
	//addedge(2,9,6);
	//addedge(3,4,10);
	//addedge(3,5,14);
	//addedge(3,6,4);
	//addedge(4,5,9);
	//addedge(5,6,7);
	//addedge(6,7,8);
	//addedge(6,9,2);
	//addedge(7,8,4);
	
   // addedge(3,4,4);
	
	//dikstra(1,4);
    
 
    // print the adjacency list representation of the above graph
  //  printgraph();
	
  generategraphwith1000degree();
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

