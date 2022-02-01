#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 1024
#define INFINITY 1000
int n=8,cost=0,dist[8][8]={{0,2,0,0,0,0,6,0},
		 {2,0,7,0,2,0,0,0},
		 {0,7,0,3,0,3,0,0},
                 {0,0,3,0,0,0,0,2},
                 {0,2,0,0,0,2,1,0},
                 {0,0,3,0,2,0,0,2},
                 {6,0,0,0,1,0,0,4},
                 {0,0,0,2,0,2,4,0}};
int shortest_dist(int s,int t,int path[])
{
	int i,k,min;
	struct state
	{
		int pre;
		int length;
		int label;
	}
state[1024];

	struct state *p;
		for(p=&state[0];p<&state[n];p++)
	{
		p->pre=-1;
		p->length=INFINITY;
		p->label=0;
	}

state[0].length=0;
	state[0].label=1;
	state[0].pre=-1;
k=t;
	do
	{
	for(i=0;i<n;i++)
		if(dist[k][i]!=0 && state[i].label==0)
		{
			if(state[k].length+dist[k][i]<state[i].length)
			{
				state[i].pre=k;
				state[i].length=state[k].length+dist[k][i];
			}
		}

	k=0;
	min=INFINITY;
for(i=0;i<n;i++)
		
		if(state[i].label==0 && state[i].length<min)
		{
			min=state[i].length;
			k=i;
		}		
		state[k].label=1;
	}
while(k!=s);
i=0;
	k=s;
do
	{
		path[i++]=k;
		k=state[k].pre;
		cost+=state[k].length;
	}
while(k>=0);
return  i;
}
void main()
{
	int i,j,m,path[102],q,p;
	printf("\nEnter Number of nodes(1-8): ");
	scanf("%d",&n);
printf("\nEnter Source Vertex(1-8): ");
	scanf("%d",&p);

	printf("\nEnter Destination vertex(1-8): ");
	scanf("%d",&q);
	m=shortest_dist(q-1,p-1,path);
	for(i=0;i<m;i++)
	{
		printf(" %c-> ",path[i]+'A');
	}
	printf("\nCost is:  %d \n",cost);
}
