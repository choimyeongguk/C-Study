#include <stdio.h>

int d(int x)
{
	int num = 10;
	int result = x;
	while(x>0)
	{
		result += x%num;
		x /= num;
	}
	return result;
}

int main()
{
	int i, j, chk;
	for(i=1;i<=10000;i++)
	{
		for(chk=0,j=1;j<i;j++)
		{
			if(d(j)==i)
			{
				chk++;
				break;
			}
		}
		
		if(!chk) printf("%d\\n", i);
	}
	
	return 0;
}
