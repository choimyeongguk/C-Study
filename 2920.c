#include <stdio.h>#include <math.h>
int main()
{
	int i,s=0,a[8],x;
	scanf("%d",&a[0]);
	
	for(i=1;i<8;i++)
	{
		scanf("%d",&a[i]);
		x=a[i]-a[i-1];
		s=abs(s)>abs(x)?s:x;
	}
	if(s==1) printf("ascending");
	else printf("%s", s==-1?"descending":"mixed");
}
