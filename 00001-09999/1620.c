#include <stdio.h>
#include <string.h>
#include <math.h>

#define ROW 100000
#define COL 21

void mergeSort(char* pokemonDict, int* pokemonNum, int start, int end)
{
	int mid, i;
	if(start<end)
	{
		mid = (start+end)/2;
		mergeSort(pokemonDict, pokemonNum, start, mid);
		mergeSort(pokemonDict, pokemonNum, mid+1, end);
		
		char dict[ROW][COL];
		int num[ROW];
		int s = start;
		int e = mid+1;
		int index = 0;
		
		while(s<=mid && e<=end)
		{
			if(strcmp(pokemonDict+s*COL, pokemonDict+e*COL)<=0)
			{
				for(i=0;i<=strlen(pokemonDict+s*COL);i++)
				{
					dict[index][i] = *(pokemonDict+s*COL+i);
				}	
				num[index] = *(pokemonNum+s);
				index++; s++;
			}
			else
			{
				for(i=0;i<=strlen(pokemonDict+e*COL);i++)
				{
					dict[index][i] = *(pokemonDict+e*COL+i);
				}
				num[index] = *(pokemonNum+e);
				index++; e++;
			}
		}
		while(s<=mid)
		{
			for(i=0;i<=strlen(pokemonDict+s*COL);i++)
			{
				dict[index][i] = *(pokemonDict+s*COL+i);
			}
			num[index] = *(pokemonNum+s);
			index++; s++;
		}
		while(e<=end)
		{
			for(i=0;i<=strlen(pokemonDict+e*COL);i++)
			{
				dict[index][i] = *(pokemonDict+e*COL+i);
			}
			num[index] = *(pokemonNum+e);
			index++; e++;
		}
		index--;
		
		while(index>=0)
		{
			for(i=0;i<=strlen(dict[index]);i++)
			{
				*(pokemonDict+(start+index)*COL+i) = dict[index][i];
			}
			*(pokemonNum+(start+index)) = num[index];
			index--;
		}
	}
}

int binarySearch(char* pokemonDict, int* pokemonNum, int start, int end, char* target)
{
	if(start<=end)
	{
		int mid = (start+end)/2;
		if(strcmp(target, pokemonDict+mid*COL)<0)
		{
			binarySearch(pokemonDict, pokemonNum, start, mid-1, target);
		}
		else if(strcmp(target, pokemonDict+mid*COL)>0)
		{
			binarySearch(pokemonDict, pokemonNum, mid+1, end, target);	
		}
		else return pokemonNum[mid];
	}
}

int main()
{
	int N, M, num, i, j;
	char test[COL];
	char pokemon[ROW][COL];
	char pokemonDict[ROW][COL];
	int pokemonNum[ROW];
	
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++) pokemonNum[i] = i+1;
	for(i=0;i<N;i++)
	{
		scanf("%s", &pokemon[i]);
		for(j=0;j<=strlen(pokemon[i]);j++) pokemonDict[i][j] = pokemon[i][j];
	}
	
	mergeSort(pokemonDict, pokemonNum, 0, N-1);
	
	for(i=0;i<M;i++)
	{
		scanf("%s", test);
		if(test[0]<58)  // 입력값이 숫자라면 
		{
			num = 0;
			for(j=0;j<strlen(test);j++)
			{
				num += (test[j]-48)*pow(10, strlen(test)-j-1);
			}
			printf("%s\n", pokemon[num-1]);
		}
		else
		{
			printf("%d\n", binarySearch(pokemonDict, pokemonNum, 0, N-1, test));
		}
	}
	
	return 0;
}
