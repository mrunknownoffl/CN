#include<stdio.h>
#include<string.h>
char input[10][20];
int get_input();
void make_frames(int);
int count_chars(int s);
void main()
{
	int no_of_words=get_input();
	make_frames(no_of_words);
}
int get_input()
{
	int answer;
	int i=0;
	do{
		printf("\nEnter the Word:");
		scanf("%s",input[i]);
		fflush(stdin);
		printf("\nDo you want to continue: (yes: 1 or no: 0)?:");
		scanf("%d",&answer);
		i++;
	}
while(answer!=0);
	return i;
}
void make_frames(int num_words){
	int i=0;
	printf("\nThe Transmitted Data is:\n\t");
	
for(;i<num_words;i++)
		printf("%d%s",(count_chars(i)+1),input[i]);
	printf("\n\n");
}
int count_chars(int index)
{
	int i=0;
	while(input[index][i]!='\0')
		i++;
	return i;
}
