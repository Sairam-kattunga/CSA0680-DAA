#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 1000
#define MAX_CONTAINERS 100
int num_items, num_containers;
int items[MAX_ITEMS];
int containers[MAX_CONTAINERS];
int cmp(const void *a, const void *b) 
{
    return *(int *)b - *(int *)a;
}
int container_loading() 
{
    qsort(items, num_items, sizeof(int), cmp);
    int num_used_containers = 0;
    for (int i = 0; i < num_items; i++) 
	{
        int j;
        for (j = 0; j < num_used_containers; j++) 
		{
            if (containers[j] >= items[i]) 
			{
                containers[j] -= items[i];
                break;
            }
        }
        if (j == num_used_containers) 
		{
            if (num_used_containers == num_containers) 
			{
                return 0; 
            }
            containers[num_used_containers++] = 1 - items[i]; 
        }
    }
    return num_used_containers; 
}
int main()
{
    printf("Enter the number of items and containers: ");
    scanf("%d %d", &num_items, &num_containers);
    printf("Enter the sizes of the items:\n");
    for (int i = 0; i < num_items; i++) 
	{
        scanf("%d", &items[i]);
    }
    int num_used_containers = container_loading();
    if (num_used_containers == 0) 
	{
        printf("Loading failed, not enough containers\n");
    } else 
	{
        printf("Loading successful, used %d containers\n", num_used_containers);
    }
    return 0;
}
