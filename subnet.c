int main()
{
	int num_nodes=0;
	int i=0,j=0;
	int path_len,hops[MAX_NODES];

	printf("enter the number of nodes:");
	scanf("%d",&num_nodes);
	fflush(stdin);
	printf("enter the connection matrix, 0 if not connected\n");
	printf("otherwise,the distance\n");
	for(;i<num_nodes;i++)
	{
		printf("enter the distances for node num:%d\n",i);
		for(j=0;j<num_nodes;j++)
		{
			if(i==j)
			{
				dist[i][j]=0;
				continue;
			}
			printf("distance from %d to %d= ",i,j);
			scanf("%d",&dist[i][j]);
			fflush(stdin);
			if(dist[i][j]==0) 
				dist[i][j]=INFINITY;
		}
	}

	printf("\nenter the root node");
	scanf("%d",&i);
	run_prim(i,num_nodes,hops);
	for(j=0;j<num_nodes;j++)
	{
		for(i=0;i<hops[j];i++)
			printf("->%d",path[j][i]);
		printf("\n");
	}
	return 0;
}
void run_prim(int s,int n,int *hops)
{
	struct state
	{
	int prev;
		int length;
		enum {perm,tent} label;
	}
state[MAX_NODES];
	int i,j,k,min;
	int count=0;
	struct state *p;
	for(p=&state[0];p<&state[n];p++)
	{
		p->prev= -1;
		p->length= INFINITY;
		p->label= tent;
	}	
	state[s].length= 0;state[s].label= perm;
	k=s;
	do
	{
	for(i=0;i<n;i++)
			if(dist[k][i]!=0&&state[i].label==tent)
			{
if(state[k].length+dist[k][i]<state[i].length)
{
state[i].prev=k;
state[i].length=state[k].length+dist[k][i];
				}
			}
k=0;
		min=INFINITY;
		for(i=0;i<n;i++)
			if(state[i].label==tent&&state[i].length<min)
			{
				min=state[i].length;
				k=i;
			}
		state[k].label=perm;
		count++;
	}while(count<n);

	for(j=0;j<n;j++)
	{
		i=0;k=j;
		do	
		{	
			path[j][i++]=k;
			k=state[k].prev;		
		}

		while(k>=0);
		hops[j]=i;
	}
}