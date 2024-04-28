#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 500000

int main()
{
	int N, numBroken, tmp, len, i, j;
	int l, r, numL=0, numR=0, minBut = 0, maxBut = 9, chk = 0;
	int minPress, minPressL = MAX, minPressR = MAX; 
	char target[7];
	char minSet[7], minSetL[7], minSetR[7];
	char remocon[10] = { 0 };
	
	scanf("%s", target);
	len = strlen(target);
	for(N=0, i=0;i<len;i++)  // ��ǥ ��ȣ�� ���������� ��ȯ 
	{
		N += (target[i]-48) * pow(10, len-i-1);
	}
	
	scanf("%d", &numBroken);
	if(numBroken>0)
	{
		for(i=0;i<numBroken;i++)
		{
			scanf("%d", &tmp);
			remocon[tmp] = 1;  // ���峭 ��ư ���� 
		}
		while(remocon[minBut]==1) minBut++;  // ���� �� �ִ� ���� ���� ��ư 
		while(remocon[maxBut]==1) maxBut--;  // ���� �� �ִ� ���� ū ��ư 
	}
	
	for(i=0;i<len;i++)
	{
		if(remocon[target[i]-48]==0)  // ��� ���� 
		{
			minSet[i] = target[i];
			minSetL[i] = target[i];
			minSetR[i] = target[i];
		}
		else  // ��� �Ұ��� -> �ش� ���ں��� ���� ���� ū ���� ������ ���� 
		{
			l = target[i]-48; r = l;
			
			while(remocon[l]==1)
			{
				l--;
				if(l<0) break; 
			}
			while(remocon[r]==1)
			{
				r++;
				if(r>9)
				{
					r = -1;
					break;
				}
			}
			
			if(l<0 && r<0)
			{
				chk = -1;
				break;
			}
			
			if(l>=0)  // ���ʿ� ���� �����ϴ� ��� 
			{
				minSetL[i] = l+48;
				for(j=1;j<=len-i-1;j++)
				{
					minSetL[i+j] = maxBut+48;
				}
			}
			if(r>=0)  // �����ʿ� �����ϴ� ��� 
			{
				minSetR[i] = r+48;
				for(j=1;j<=len-i-1;j++)
				{
					minSetR[i+j] = minBut+48;
				}
			}
			chk = 1;
			break;
		}
	}
	
	if(chk==0)  // ���� ��ư ������ target�� ���� �� �ִ� ��� 
	{
		tmp = abs(N-100);
		minPress = len<tmp ? len:tmp;
	}
	else if(chk==1)  // left�� right�� ������ ��� 
	{
		if(l>=0)
		{
			for(i=0;i<len;i++)
			{
				numL += (minSetL[i]-48) * pow(10, len-i-1);
			}
			minPressL = len + abs(N-numL);
			if(minSetL[0]=='0') minPressL--;
		
//			for(i=0;i<len;i++) printf("%c ", minSetL[i]);
//			printf(", numL = %d, minPressL = %d\n", numL, minPressL);
			
			for(tmp=0, i=0;i<len;i++)
			{
				if(minSetL[i]!='0')
				{
					tmp++;
					break;
				}
			}
			if(tmp==0) minPressL = 1 + N;
		}
		if(r>=0)
		{
			for(i=0;i<len;i++)
			{
				numR += (minSetR[i]-48) * pow(10, len-i-1);
			}
			minPressR = len + abs(N-numR);
			if(minSetR[0]=='0') minPressR--;
			
//			for(i=0;i<len;i++) printf("%c ", minSetR[i]);
//			printf(", numR = %d, minPressR = %d\n", numR, minPressR);
			
			for(tmp=0, i=0;i<len;i++)
			{
				if(minSetR[i]!='0')
				{
					tmp++;
					break;
				}
			}
			if(tmp==0) minPressL = 1 + N;
		}
		
		minPress = minPressL<minPressR ? minPressL:minPressR;
//		printf("minPressL = %d, minPressR = %d, minPress = %d\n", minPressL, minPressR, minPress);
		tmp = abs(N-100);
		minPress = minPress<tmp ? minPress:tmp;
//		printf("minPress = %d\n", minPress);
	}
	else minPress = abs(N-100);
	
	printf("%d", minPress);
	
	return 0;
}
