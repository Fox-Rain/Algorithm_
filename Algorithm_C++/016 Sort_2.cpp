#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

vector<int> vec = {9, 5, 3, 2, 4, 1, 1, 3, 6, 7};
vector<int> radix_vec = {132, 413, 553, 323, 105, 330, 355, 948, 999, 347};

// (1) Counting_Sort    < 시간복잡도 O(N+K)  공간복잡도 .. 커질 수 있음 >    ( 들어올 숫자의 범위를 알아야 한다는 단점 말고는 최고의 정렬이다. 단, 들어오는 숫자의 범위가 커지게 된다면 그만큼 테이블이 커지고 
//                                                                       메모리를 많이 먹게 되므로, 범위가 대략 1000만 이하일 때 사용한다고 보면 된다.)  메모리 512MB 기준 1.2억개 까지 table 가능
//                                                                       또한, 음수가 들어올 경우 약간의 코드 수정이 필요하다.. 즉, 1.숫자범위 안다. 2.숫자범위가 크지않다. ---> CountingSort
void counting_Sort(vector<int> vec) // 이 경우는 0~1000000 일 경우임
{
    int table[1000001]={0,};
    for (int i = 0; i < vec.size();++i)
        table[i]++;
    for (int i = 0; i < 1000001;++i)
    {
        for (int j = 0; j < table[i];++j)
            cout << i;
    }
}


// (2) Radix_Sort    < 시간복잡도 O()
void radix_Sort(vector<int> radix_vec)
{
    int max = INT_MIN;
    queue<int> Q[10];
    for (int i = 0; i < radix_vec.size();++i)
    {
        if(max<radix_vec[i])
            max = radix_vec[i];
        Q[radix_vec[i] % 10].push(radix_vec[i]);
    }

    string str = to_string(max);
    int n = pow(10, str.size() - 1);

    for (int i = 1; i <= n;i*=10)
    {
        for (int j = 0; j < 10;++j)
        {
            for (int k = 0; k < Q[j].size();++k)
            {
                int cur =Q[j].front();
                Q[j].pop();

                if(cur>=i)
                    Q[(cur/i)%10].push(cur);
                else
                    Q[0].push(cur);
            }
        }
    }

    int index = 0;
    for (int i = 0; i < 10; ++i)
    {
        while(Q[i].empty()!=true)
        {
            int cur =Q[i].front();
            Q[i].pop();

            radix_vec[index++] = cur;
        }
    }

        for (auto e : radix_vec)
            cout << e << "  ";
}

// < comparsion_sort >          vs          < non-comparsion_sort >
//   quick sort                               counting sort
//   bouble sort..                            radix sort

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}