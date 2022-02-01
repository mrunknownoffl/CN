#include<stdio.h>

int min(int x,int y)
{
	if(x < y)
	{
		return x;
	}
	else
		return y;
}

int main()
{
	int drop=0, mini, nsec, cap, count = 0;
int i,inp[25],process;
	printf("Enter the Bucket Size:\n");
	scanf("%d",&cap);
	printf("Enter the Processing Rate:\n");
	scanf("%d",&process);
	printf("Enter The No. Of Seconds You Want To Stimulate:\n");
	scanf("%d",&nsec);

	for(i=0;i<nsec;i++)
	{
		printf("Enter the Size of the Packet Entering at %d  sec:\n",i+1);
		scanf("%d",&inp[i]);
	}

	printf("\nSeconds|Packet Recieved|Packet Sent|PacketLeft|Packet Dropped|\n");
	printf("\n");
	
	for(i=0;i<nsec;i++)
	{
		count+=inp[i];
		if(count>cap)
		{
			drop=count-cap;
			count=cap;
		}
		printf("%d",i+1);
		printf("\t%d",inp[i]);
		mini=min(count,process);
		printf("\t%d",mini);
		count=count-mini;
		printf("\t%d",count);
		printf("\t%d\n",drop);
		drop=0;
	}


	for(;count!=0;i++)
	{
		if(count>cap)
		{
			drop=count-cap;
			count=cap;
		}
		printf("%d",i+1);
		printf("\t0");
		mini=min(count,process);
		printf("\t%d",mini);
		count=count-mini;
		printf("\t%d",count);
		printf("\t%d\n",drop);
		
	}	
}
