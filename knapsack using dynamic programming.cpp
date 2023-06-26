#include<stdio.h>
int knapsack(int n, float weight[], float profit[], float capacity) 
{
   float x[20], tp = 0,count=0;
   int i, j, u;
   u = capacity;
   count++;
   for (i = 0; i < n; i++)
   {
   	count++;
   	count++;
      x[i] = 0.0;
      count++;
   } 
 count++;
 count++;
   for (i = 0; i < n; i++)
    {
    	count++;
    	count++;
      if (weight[i] > u)
      count++;
         break;
	  {
	  	count++;
         x[i] = 1.0;
         count++;
         tp = tp + profit[i];
         count++;
         u = u - weight[i];
      }
   }
 count++;
 count++;
   if (i < n)
      x[i] = u / weight[i];
 
   tp = tp + (x[i] * profit[i]);

   printf("\nMaximum profit is:- %f", tp);
 count++;
}
int main() 
{
   float weight[20], profit[20], capacity;
   int num, i, j,count=0;
   float ratio[20], temp;
   printf("\nEnter the no. of objects:- ");
   count++;
   scanf("%d", &num);
 count++;
   printf("\nEnter the wts and profits of each object:- ");
   count++;
   count++;
   for (i = 0; i < num; i++) 
   {
   	count++;
   	count++;
      scanf("%f %f", &weight[i], &profit[i]);
      count++;
   }
 count++;
   printf("\nEnter the capacityacity of knapsack:- ");
   count++;
   scanf("%f", &capacity);
 count++;
 count++;
   for (i = 0; i < num; i++) 
   {
   	count++;
   	count++;
      ratio[i] = profit[i] / weight[i];
      count++;
   }
 count++;
   for (i = 0; i < num; i++)
    {
      for (j = i + 1; j < num; j++)
	   {
         if (ratio[i] < ratio[j])
		  {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }
 count++;
   knapsack(num, weight, profit, capacity);
   printf("\nTime complexity is %d\n",count);
   return(0);
}

OUTPUT:
Enter the no. of objects:- 4

Enter the wts and profits of each object:- 2 10
4 10
6 12
9 18

Enter the capacityacity of knapsack:- 16

Maximum profit is:- 80.000000
Time complexity is 34
