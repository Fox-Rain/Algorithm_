// 투 포인터 //
// 투 포인터 알고리즘이란?    배열에서 원래 이중for문 O(N^2)로 처리되어야하는 작업을 2개의 포인터의 움직임을 통해서 O(N) 선형시간으로 처리하도록 하는 알고리즘입니다.
/*
    여기서 말하는 포인터는 int* ptr이 라고 보기보다는 그냥 "커서"라고 생각하는 것이 편합니다. 이렇게 포인터(커서)를 사용하여서 어떻게 시간복잡도를 줄일 수 있는거냐면,
    이중for문의 경우, i,j에 대해서 각각돌면서,  i=0일때 구한 j의 0~N까지의 정보가 i=1 ... 에 쓰이지 않는다는 점에서 효율적이지 못하다고 볼 수 있습니다. 이러한 점에서 투 포인터를
    이용하게되면 앞에서 구한 정보를 사용하도록하고, 시간복잡도를 줄일 수 있는 것입니다.
    특히, 투포인터로 풀 수 있는 문제가 이분탐색으로 풀리고, 이분탐색으로 풀리는 문제가 투 포인터로 풀리는 경우가 많기 때문에 해결방법에 대해서 고민을 많이 해보는게 필요합니다.

    *** 투 포인터 알고리즘을 사용할 때 주의해야할 점은 -> 꼭 배열이 오름차순이나 내림차순으로 정렬되어 있어야한다는 점 입니다. (이분탐색과 동일하다   따라서 서로 풀리는 경우가 많읂 것)
        이분탐색과의 차이점이라면 시간복잡도가 O(NlogN)  vs  O(N)인데 별 차이가 없다.  투 포인터로만 풀리는 문제도 있으므로, 그래도 알아두는 것이 좋을 것 같은 알고리즘이다.


    < 예제 >
    https://www.acmicpc.net/problem/2230

    수 고르기
    시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
    2 초	128 MB	7584	2401	1705	29.730%
    문제
    N개의 정수로 이루어진 수열 A[1], A[2], …, A[N]이 있다. 이 수열에서 두 수를 골랐을 때(같은 수일 수도 있다), 그 차이가 M 이상이면서 제일 작은 경우를 구하는 프로그램을 작성하시오.

    예를 들어 수열이 {1, 2, 3, 4, 5}라고 하자. 만약 M = 3일 경우, 1 4, 1 5, 2 5를 골랐을 때 그 차이가 M 이상이 된다. 이 중에서 차이가 가장 작은 경우는 1 4나 2 5를 골랐을 때의 3이 된다.

    입력
    첫째 줄에 두 정수 N, M이 주어진다. 다음 N개의 줄에는 차례로 A[1], A[2], …, A[N]이 주어진다.

    출력
    첫째 줄에 M 이상이면서 가장 작은 차이를 출력한다. 항상 차이가 M이상인 두 수를 고를 수 있다.

    제한
    1 ≤ N ≤ 100,000
    0 ≤ M ≤ 2,000,000,000
    0 ≤ |A[i]| ≤ 1,000,000,000


    <<< SOL >>>
    #include <bits/stdc++.h>

    using namespace std;

    int N;          // 정수의 개수
    int M;          // M 이상의 차이를 갖어야한다.
    int A[100000];
    int result = INT_MAX;

    void two_pointer()
    {
        int st = 0;
        int ed = 0;

        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = ed; i < N; ++i)
            {
                if(A[i]-A[st]>=M)
                {
                    flag = true;
                    ed = i;
                    result = min(result, A[i] - A[st]);
                    break;
                }
            }
            st++;
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        cin >> N >> M;
        for (int i = 0; i < N;++i)
            cin >> A[i];
        sort(&A[0], &A[N]);

        two_pointer();
        cout << result;
        return 0;
    }

    일단 A[]는 정렬되어있기 때문에  st<ed 일 경우 A[ed]-A[st] > 0 이면서, ed가 커질 수록 값이 증가한다는 것을 알 수 있다.  이에 따라서 투 포인터를 통해 시간복잡도를 O(N)으로 줄일 수 있다.
*/  