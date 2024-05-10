#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M, k, cnt, i;
	char* S;
	
	scanf("%d", &N);
	scanf("%d", &M);
	S = (char*)calloc(M+1, sizeof(char));
	scanf("%s", S);
	
	for(k=0,cnt=0, i=0;i<M-2;i++)
	{
		if(S[i]=='O') continue;
		
		//S[i] == 'I'
		if(S[i+1]=='O' && S[i+2]=='I')
		{
			k++;
			i++;
			if(k==N)
			{
				cnt++;
				k--;
			}
		}
		else k = 0;
	}
	
	printf("%d", cnt);
	
	free(S);
	return 0;
}
