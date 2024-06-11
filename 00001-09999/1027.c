#include <stdio.h>

int main()
{
	int N, cnt, max, i, j;
	double m, tmp;
	int h[51];
	int n[51];
	
	scanf("%d", &N);
	for(i=1;i<=N;i++) scanf("%d", &h[i]);
	
	if(N==1)
	{
		printf("0");
		return 0;
	}
	
	max = 1;
	for(i=1;i<=N;i++)
	{
		cnt = 0;
		// 왼쪽
		if(i>=3)
		{
			cnt++;
			m = h[i]-h[i-1];  // 첫 기울기 
			for(j=i-2;j>=1;j--)
			{
				tmp = (double)(h[i]-h[j])/(i-j);
				if(tmp<m)
				{
					cnt++;
					m = tmp;
				}
			}
		}
		else cnt += i==1 ? 0:1;
		
		// 오른쪽
		if(i<=N-2)
		{
			cnt++;
			m = h[i+1]-h[i];
			for(j=i+2;j<=N;j++)
			{
				tmp = (double)(h[j]-h[i])/(j-i);
				if(tmp>m)
				{
					cnt++;
					m = tmp;
				}
			}
		}
		else cnt += i==N ? 0:1;
		
		// 최댓값 갱신 
		max = max>cnt ? max:cnt;
	}
	printf("%d", max);
	return 0;
}
