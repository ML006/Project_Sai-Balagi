
#include<iostream>
#include<conio.h>
#include<queue>
#include<time.h>
using namespace std;
//defining variables
int vertex=5000;
int graph[6000][6000];
int weight[6000][6000];
int dad[6000];
int rank1[6000];
int heap1[6000];
int heap2[6000];
int noofedge;
	int size;
int mstpath[6000][6000];
int deg=6;
int vertexcounter[6000];
int countvert[6000];


struct edge{
	int from;
	int to;
	int weight;
	int edgeindex;
};
edge edge1[60000000];

void seed()
{
	srand(time(0));
}

void makeset()
{
	for(int i=1;i<=vertex;i++)
	{
		dad[vertex]=0;
		rank1[vertex]=0;
	}
}

int find(int v)
{
	int w=v;
	while(dad[w]!=0)
	{
		w=dad[w];
	}
	return w;
}

void union1(int p1,int p2)
{
	if(rank1[p1]>rank1[p2])
		dad[p2]=p1;
	else if(rank1[p1]<rank1[p2])
		dad[p1]=p2;
	else if(rank1[p1]==rank1[p2])
	{
		dad[p2]=p1;
		rank1[p1]++;
	}
}


void generategraphwith1000degree()
 {
	 noofedge=0;
	//cout<<"enter the graph matrix"<<endl;
	int k=1;int p=1;
	 
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
				int w1= rand()%100+1;
			    //graph[i][j]=1;
				//graph[j][i]=1;
				edge1[k].from=i;
			    edge1[k].to=j;
			    edge1[k].weight=w1;
			    edge1[k].edgeindex=k;
			    heap1[p]=edge1[k].edgeindex;
		//	cout<<heap1[p]<< " ";
			    heap2[heap1[p]]=edge1[k].weight;
			     k++;p++;

				seed();
		
				
				
			}
		}
		}
	}

  for(int i=1;i<=4999;i++)
  {
	  int w2= rand()%100+1;
			    //graph[i][j]=1;
				//graph[j][i]=1;
				edge1[k].from=i;
			    edge1[k].to=i+1;
			    edge1[k].weight=w2;
			    edge1[k].edgeindex=k;
			    heap1[p]=edge1[k].edgeindex;
		//	cout<<heap1[p]<< " ";
			    heap2[heap1[p]]=edge1[k].weight;
			     k++;p++;
  }

  noofedge=(k-1);
  size=(k-1);

	
	}
void generategraphwith6degree()
 {
	  noofedge=0;
	//cout<<"enter the graph matrix"<<endl;
	int k=1;int p=1;
	
	 for(int i=1;i<=vertex;i++)
		vertexcounter[i]=0;
	
	 for(int i=1;i<=vertex;i++)
		for(int j=1;j<=vertex;j++)
			graph[i][j]=0;

	int random1,random2;
	int counter=0;
	
	while(counter<(vertex*deg)/2)
	{
		random1=rand()%vertex+1;
		random2=rand()%vertex+1;
		if((vertexcounter[random1]<6)&&(vertexcounter[random2]<6)&&(random1!=random2)&&(graph[random1][random2]!=1))
		{
			int w1= rand()%100+1;
			    //graph[i][j]=1;
				//graph[j][i]=1;
				edge1[k].from=random1;
			    edge1[k].to=random2;
			    edge1[k].weight=w1;
			    edge1[k].edgeindex=k;
			    heap1[p]=edge1[k].edgeindex;
		//	cout<<heap1[p]<< " ";
			    heap2[heap1[p]]=edge1[k].weight;
			     k++;p++;

				seed();

				
		
				

			graph[random1][random2]=1;
			graph[random2][random1]=1;
			counter++;
			//int w= rand()%100+1;
		//	addedge(random1,random2,w);
			//cout<<counter<<" "<<random1;
			//cout<<endl;
		}

	}
	 for(int i=1;i<=4999;i++)
  {
	  int w2= rand()%100+1;
			    //graph[i][j]=1;
				//graph[j][i]=1;
				edge1[k].from=i;
			    edge1[k].to=i+1;
			    edge1[k].weight=w2;
			    edge1[k].edgeindex=k;
			    heap1[p]=edge1[k].edgeindex;
		//	cout<<heap1[p]<< " ";
			    heap2[heap1[p]]=edge1[k].weight;
			     k++;p++;
  }
	 noofedge=(k-1);
	            size=(k-1);


 }
















void generategraph()
{
	noofedge=0;
	//cout<<"enter the graph matrix"<<endl;
	int k=1;int p=1;
	for(int i=1;i<=vertex;i++)
	{
		for(int j=1;j<=vertex;j++)
		{
			cin>>graph[i][j];
		}
	}
	for(int i=1;i<=vertex;i++)
	{
		for(int j=i;j<=vertex;j++)
		{
			if(graph[i][j]!=0)
			{
				
			edge1[k].from=i;
			edge1[k].to=j;
			edge1[k].weight=graph[i][j];
			edge1[k].edgeindex=k;
			heap1[p]=edge1[k].edgeindex;
		//	cout<<heap1[p]<< " ";
			heap2[heap1[p]]=edge1[k].weight;
			k++;p++;

			}
		}
	}

	noofedge=(k-1);
	size=(k-1);
	//for(int i=1;i<=size;i++)
		//cout<<heap2[heap1[i]]<< " ";
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

void heapsort()
{
int tempsize=size;
 buildmaxheap(heap1,tempsize);
 for(int i=size;i>=2;i--)
 {
 int temp=heap1[1];
 heap1[1]=heap1[i];
 heap1[i]=temp;
 tempsize--;
 maxheapify(heap1,1,tempsize);
 }
}
void initmstpath()
{
	for(int i=1;i<=vertex;i++)
		for(int j=1;j<=vertex;j++)
			mstpath[i][j]=0;
}

void kruskal()
{

	
	for(int i=size;i>=1;i--)
	{
		int k=edge1[heap1[i]].edgeindex;
		int r1= find(edge1[k].from);
		int r2= find(edge1[k].to);
		if(r1!=r2)
		{
           mstpath[r1][r2]=edge1[k].weight;
		   mstpath[r2][r1]=edge1[k].weight;
		   union1(r1,r2);
		}
	}
}

int min(int x, int y)
{
	if(x<y)
		return x;
	else
		return y;
}
void bfs(int s,int t)
{
	int cost[6000];
	int path[6000];
	bool visited[6000];
    for(int i = 1; i <= vertex; i++)
        {visited[i] = false;	
        cost[i] = 0;}
    queue<int> queue;
	cost[s] = 99999;
    visited[s] = true;
    queue.push(s);

    while(!queue.empty())
    {
        s = queue.front();
        queue.pop();
        for(int y = 1; y <=vertex; y++)
        {
			if(mstpath[s][y]!=0 && !visited[y] && cost[s]!=0 && cost[y]<min(mstpath[s][y],cost[s])) {
					cost[y] = min(cost[s],mstpath[s][y]);
					visited[y] = true;
					queue.push(y);
        	}
		}
    }
	cout << "max bandwidth: " <<"between"<<s<<"and"<<t<<"is:"<< cost[t] << "\n";
}


int main()
{
   cout<<" This is the Modified kruskal Algorithm using heapsort for a Sparse graph"<<endl;
	seed();
	int s1,d1;
	s1=rand()%5000+1;
	d1=rand()%5000+1;
	makeset();
	generategraphwith6degree();
	heapsort();
	initmstpath();
	clock_t beg=clock();
	kruskal();
	
	bfs(s1,d1);
	 clock_t end=clock();
	double timeelapsed=0;
	timeelapsed=(double(end-beg))/CLOCKS_PER_SEC;
	cout<<"time elapsed :"<<timeelapsed<<endl;

	return 0;
}

