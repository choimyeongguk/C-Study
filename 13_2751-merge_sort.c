/*
 * [ b h i g a d c f e ]
 * [ b h i g ] [ a d c f e ]
 * [ b h ] [ i g ] [ a d ] [ c f e ]
 * [ b h ] [ i g ] [ a d ] [ c ] [ f e ]
 * [ b h ] [ g i ] [ a d ] [ c ] [ e f ]
 * [ b g h i ] [ a d ] [ c e f ]
 * [ b g h i ] [ a c d e f ]
 * [ a b c d e f g h i ]
 *
 * ���� ������ ũ�� [����->����->����]���� �̷������.
 * [����]�� �迭�� �� ���� �ɰ��� ��
 * [����]�� �ɰ��� �迭�� ���� �����ϴ� ��
 * [����]�� ���ĵ� ������ �迭�� �ٽ� ��ġ�� ���̴�. 
 * �̶�, ������ �Ǵٽ� ���� [����->����->����]���� �̷������.
 * ������ �迭�� ���̰� 1�� �� ������ �ݺ��Ѵ�.
 * Ŀ�ٶ� [����->����->����] ������ �Ǵٽ� ���� [����->����->����]�� �����ϹǷ� ����Լ��� ���� �����Ѵ�. 
 */ 
#include <stdio.h>

void merge(int a[], int low, int mid, int hight)    //�и��� �迭 ���� �� ���� �Լ�
{
	int b[1000000];
	int i = low;        //���� ����
	int j = mid + 1;    //������ ����
	int k = 0;          //�迭 b�� �ε��� ��
	
	while(i <= mid && j <= hight)
	{
		if(a[i] <= a[j])        //�и��� ���� �迭�� ������ �迭 ��
        {	
			b[k] = a[i];
            k++;
			i++;
		}
		else
        {	b[k] = a[j];
            k++;
			j++;
		}
	}
	while(i <= mid)             //������ ���� ���� �迭�� �ִٸ� �迭 b�� ���� ä���
    {	b[k] = a[i];
        k++;
		i++;
	}
	while(j <= hight)           //������ ���� ������ �迭�� �ִٸ� �迭 b�� ���� ä���
    {	b[k] = a[j];
        k++;
		j++;
	}
	k--;
    
	while(k >= 0)               //�迭 b ������ �迭 a ���뿡 �����
	{
		a[low + k] = b[k];
		k--;
	}
}
void mergeSort(int a[], int low, int hight)    //�迭�� ��Ҹ� �����ϴ� �Լ�
{
	
	int mid;
	if(low < hight)
	{
		//���� 
		mid = (low + hight) / 2;
		
		//���� 
		mergeSort(a, low, mid);  //���� �迭�� ��� �и� �� ��� �Լ� ó�� 
		mergeSort(a, mid + 1, hight);  //������ �迭�� ��� �и� �� ��� �Լ� ó�� 
		// �迭�� ���̰� 2�� �Ǽ� low�� hight�� ���̰� 1�̸�, mid�� ���� low�� ������.
		// �� �ɰ��� �迭�� ���̰� 1�� �Ǵ� ��!
		// �׷��� �Ǹ� �ٽ� mergeSort()�� �־��� ��, low<hight�� �������� ���ϹǷ� �ƹ��ϵ� �Ͼ�� ����. 
		
		//���� 
		merge(a, low, mid, hight); //�и��� �迭 ���� �� ���� �Լ�
	}
}
int main(void)
{
	int arr[1000000];
	int i, cnt;        //cnt : �Է� Ƚ��
	
	scanf("%d", &cnt);
	
	for(i = 0 ; i < cnt; i++)
		scanf("%d", &arr[i]);
    
	mergeSort(arr, 0, cnt - 1);    //�迭�� ��Ҹ� �����ϴ� �Լ�
	
    for(i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
}
