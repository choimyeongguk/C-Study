#include <stdio.h>
#include <stdlib.h>

int GCD(int big, int small)
{
	if(small==0) return big;
	else GCD(small, big%small);
}

int main()
{
	int numTree, tree1, tree2, gcd, big, i, j;
	int result = 0;
	int* distance;
	
	scanf("%d", &numTree);
	distance = (int*)malloc((numTree-1)*sizeof(int));
	
	scanf("%d", &tree1);
	for(i=0;i<numTree-1;i++)
	{
		scanf("%d", &tree2);
		distance[i] = tree2 - tree1;
		tree1 = tree2;
	}
	
	big = distance[0]>distance[1] ? distance[0]:distance[1];
	gcd = GCD(big, distance[0]+distance[1]-big);
	for(i=2;i<numTree-1;i++)
	{
		big = gcd>distance[i] ? gcd:distance[i];
		gcd = GCD(big, gcd+distance[i]-big);
	}
	
	for(i=0;i<numTree-1;i++)
	{
		result += distance[i]/gcd -1;
	}
	printf("%d", result);
	
	free(distance);
	return 0;
}
