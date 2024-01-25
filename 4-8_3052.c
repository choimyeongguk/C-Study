#include <stdio.h>

int main()
{
	int i, num=0;
	int arr[10];
	int remainder[42] = {0};
	
	for(i=0;i<10;i++)
	{
		scanf("%d", &arr[i]);
		arr[i] = arr[i]%42;
		remainder[arr[i]] = 1;
	}
	for(i=0;i<42;i++)
	{
		if(remainder[i]==1) num++;
	}
	printf("%d", num);
	
	return 0;
}

/*   
	for(int i=0; i<10; i++)
	{
    int count=0; // 초기화
    for(int j=i+1; j<10; j++)
		{
      if(remain[i] == remain[j]) count++;
    }
    if (count == 0) result++; // 같은 수가 없을 경우 개수를 세준다
  }
    
  printf("%d", result);
  
  예시 : {0, 1, 1, 1, 2, 3, 4, 5} 일 경우, 첫 째 1은 뒤에 또 1이 나오므로 노카운트. 둘째 1도 마찬가지.
	셋 째 1은 뒤에 1이 없으므로 카운트. 
*/
