#include<stdio.h>
int main()
{
	int num,r,sum=0,temp;
	int count=0;
	printf("enter the number: ");
	count++;
	scanf("%d",&num);
	count++;
	for(temp=num;num!=0;num=num/10)
	{
		count++;
		count++;
		r=num%10;
		count++;
		sum=sum+(r*r*r);
		count++;
	}
	count++;
	if(sum==temp)
	{
		printf("the entered number is armstrong number\n");
		count++;
	}
	else
	{
		printf("the entered number is not an armstrong number\n");
		count++;
	}
	count++;
	printf("time complexity:%d",count);
	count++;
}

