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
    int count=0; // �ʱ�ȭ
    for(int j=i+1; j<10; j++)
		{
      if(remain[i] == remain[j]) count++;
    }
    if (count == 0) result++; // ���� ���� ���� ��� ������ ���ش�
  }
    
  printf("%d", result);
  
  ���� : {0, 1, 1, 1, 2, 3, 4, 5} �� ���, ù ° 1�� �ڿ� �� 1�� �����Ƿ� ��ī��Ʈ. ��° 1�� ��������.
	�� ° 1�� �ڿ� 1�� �����Ƿ� ī��Ʈ. 
*/
