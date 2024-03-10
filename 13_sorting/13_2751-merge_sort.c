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
 * 병합 정렬은 크게 [분할->정복->결합]으로 이루어진다.
 * [분할]은 배열을 두 개로 쪼개는 것
 * [정복]은 쪼개진 배열을 각각 정렬하는 것
 * [결합]은 정렬된 각각의 배열을 다시 합치는 것이다. 
 * 이때, 정복은 또다시 작은 [분할->정복->결합]으로 이루어진다.
 * 분할을 배열의 길이가 1이 될 때까지 반복한다.
 * 커다란 [분할->정복->결합] 과정은 또다시 작은 [분할->정복->결합]을 포함하므로 재귀함수를 통해 구현한다. 
 */ 
#include <stdio.h>

void merge(int a[], int low, int mid, int hight)    //분리된 배열 정렬 및 병합 함수
{
	int b[1000000];
	int i = low;        //왼쪽 시작
	int j = mid + 1;    //오른쪽 시작
	int k = 0;          //배열 b의 인덱스 값
	
	while(i <= mid && j <= hight)
	{
		if(a[i] <= a[j])        //분리된 왼쪽 배열과 오른쪽 배열 비교
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
	while(i <= mid)             //비교하지 않은 왼쪽 배열이 있다면 배열 b에 전부 채우기
    {	b[k] = a[i];
        k++;
		i++;
	}
	while(j <= hight)           //비교하지 않은 오른쪽 배열이 있다면 배열 b에 전부 채우기
    {	b[k] = a[j];
        k++;
		j++;
	}
	k--;
    
	while(k >= 0)               //배열 b 내용을 배열 a 내용에 덮어쓰기
	{
		a[low + k] = b[k];
		k--;
	}
}
void mergeSort(int a[], int low, int hight)    //배열의 요소를 분할하는 함수
{
	
	int mid;
	if(low < hight)
	{
		//분할 
		mid = (low + hight) / 2;
		
		//정복 
		mergeSort(a, low, mid);  //왼쪽 배열의 요소 분리 후 재귀 함수 처리 
		mergeSort(a, mid + 1, hight);  //오른쪽 배열의 요소 분리 후 재귀 함수 처리 
		// 배열의 길이가 2가 되서 low와 hight의 차이가 1이면, mid의 값이 low와 같아짐.
		// 즉 쪼개진 배열의 길이가 1이 되는 것!
		// 그렇게 되면 다시 mergeSort()에 넣었을 때, low<hight를 만족하지 못하므로 아무일도 일어나지 않음. 
		
		//결합 
		merge(a, low, mid, hight); //분리된 배열 정렬 및 병합 함수
	}
}
int main(void)
{
	int arr[1000000];
	int i, cnt;        //cnt : 입력 횟수
	
	scanf("%d", &cnt);
	
	for(i = 0 ; i < cnt; i++)
		scanf("%d", &arr[i]);
    
	mergeSort(arr, 0, cnt - 1);    //배열의 요소를 분할하는 함수
	
    for(i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
}
