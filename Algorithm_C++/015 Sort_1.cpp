#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec = {5, 3, 2, 9, 4, 1, 8, 10, 6, 7};

// (1) Bouble Sort     < 시간복잡도 O(N^2) >           ( selection sort, insertion sort, bouble sort 모두 O(N^2)로 N이 커질 경우 매우 느려진다. )
// 맨앞부터 2개씩 비교해가면  끝에 숫자가 1개씩 정렬되고,  N-1번 실행하면 정렬이 된다.    https://ko.wikipedia.org/wiki/거품_정렬
void bouble_Sort(vector<int> vec)
{
    for (int i = 0; i < vec.size() - 1;++i)
    {
        for (int j = 0; j < vec.size() - 1 - i;++j)
        {
            if(vec[j]>vec[j+1])
                swap(vec[j], vec[j + 1]);
        }
    }

    for (int i = 0; i < vec.size();++i)
        cout << vec[i] << " ";
    cout << '\n';
}


// (2) Merge Sort    < 시간복잡도 O(NlogN)  공간복잡도 O(N) >    ( N이 매우 커져도 위의 bouble sort, sele... 등 보다 훨씬 빠르다.)  단, 추가적인 메모리를 사용해야 한다는 점이 단점이다.
// 계속해서 배열을 쪼갠뒤 재귀적으로 배열끼리 비교하면서 정렬을 채워나가는 정렬 방법이다.    https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html  
void merge(int* arr, int first, int mid, int last)
{
	int* sorted = new int[last - first + 1];
	int i, j, k;
	i = first;		// First arr idx
	j = mid + 1;	// Second arr idx
	k = 0;			// Sorted arr idx

	while (i <= mid && j <= last)
	{
		if (arr[i] <= arr[j]) sorted[k++] = arr[i++];
		else sorted[k++] = arr[j++];
	}

	if (i > mid) 
		while (j <= last) sorted[k++] = arr[j++];
	else
		while (i <= mid) sorted[k++] = arr[i++];

	for (i = first, k = 0; i <= last; i++, k++) arr[i] = sorted[k];

	delete[] sorted;
}

void mergeSort(int *arr, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}


// (3) Quick Sort    < 시간복잡도 O(NlogN)  공간복잡도 O(1) >    (시간복잡도가 NlogN으로 mergeSort와 같은데,cache hit rate가 높은 이유도 있고해서 대부분 mergeSort보다 약간 빠르다. 그런데 큰 문제점이 
//                                                            하나있는데 pivot에 따라서 최악의 경우 O(N^2)로 O(NlogN)을 보장해주지 못하는 경우가 존재한다. 따라서, mergeSort를 지향하는게 좋고, 
//                                                            특히 STL을 못쓰는 경우라서 정렬알고리즘을 구현해서사용해야하는 경우, 절대 quickSort로 구현해서는 안된다.  최악의 경우가 존재하므로, 
//                                                            시간초과가 발생할 수 있기 때문이다.)
// quickSort는...                                             https://ko.wikipedia.org/wiki/퀵_정렬
void quick_Sort(int start_idx, int end_idx)
{
    if(start_idx>=end_idx)
        return;
    else
    {
        int pivot = start_idx;
        int left = start_idx + 1;
        int right = end_idx;

        while(left<=right)
        {
            while(left <= end_idx && vec[left] <= vec[pivot])
            {   left++;    } 
            while(right > start_idx && vec[right] >= vec[pivot])
            {   right--;    }

            if(left<right)
            {
                int temp = vec[left];
                vec[left] = vec[right];
                vec[right] = temp;
            }
            else
            {
                int temp = vec[start_idx];
                vec[start_idx] = vec[right];
                vec[right] = temp;
                pivot = right;
            }
        }
        quick_Sort(start_idx, pivot - 1);
        quick_Sort(pivot + 1, end_idx);
    }
}


//             < mergeSort >           vs          < quickSort >            
// 시간복잡도     O(NlogN)                           O(NlogN) 최악시 O(N^2)           <<< 최악의 경우가 존재하므로 STL을 안쓰고 정렬을 구현해 쓸 경우 quickSort말고 다른 O(NlogN)정렬을 써야한다.
// 공간복잡도     O(N)                               O(1)                            <<< mergeSort의 경우, 나눈 배열을 저장해야할 공간이 필요하므로, O(N)로 더 공간복잡도가 크다.
// stableSort   O                                  X                               <<< stable Sort란 동일한 값의 원소가 존재할 경우 그 동일한 원소끼리의 순서가 유지되는 정렬을 말한다.
//                                                                                     Ex) 3,5,1(1),1(2),1(3)     --->    1(1),1(2),1(3),3,5   (이런식으로 동일한 크기 원소 순서 유지)
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}