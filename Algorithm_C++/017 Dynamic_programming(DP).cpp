// dynamic programming DP //
// 여러개의 하위 문제를 먼저 푼 후, 그 결과를 쌓아 올려주면서 주어진 문제를 해결하는 알고리즘   Ex) 피보나치
// 푸는방법 -> 1. 테이블 정의하기    2. 점화식 찾기    3. 초기값 설정하기   (대부분 코딩테스트에서는 점화식만 잘 찾게되면 쉽게 풀리는 DP유형이 많다.)


/*
https://www.acmicpc.net/problem/1463

1로 만들기 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
0.15 초 (하단 참고)	128 MB	180948	57942	36785	31.831%
문제
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

< SOL >
첫번째로 테이블을 정의하자면  D[i] = i 를  1로 만들기 위해서 필요한 최소한의 연산 수 이다.
다음으로 점화식을 찾아보기 위해서 작은 값들을 넣어본다.
D[12] -> 3으로 나눌 수 있을 경우 D[4]+1
      -> 2로 나눌 수 있을 경우 D[6]+1
      -> -1 할 경우 D[11]+1             즉, 3,2나눌 수 있을때는 3가지  2나 3으로만 나눌 수 있을 때는 2가지  둘다 안될시에 1가지 중에서 가장 작은 값을 선택해주면 된다.

즉, 점화식은 D[i] = min(D[i/3]+1, D[i/2]+1, D[i-1]+1) 이 된다.
이후 마지막으로 초기값을 설정해주면 되는데 이경우는 D[0]=1만 있으면 된다.

위와 같이 정한 것을 코드로 작성하게 되면 아래와 같이 나타낼 수 있다.


#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int table[1000001];
    table[1] = 0;
    for (int i = 2; i <= N;++i) // 1은 table[1]=0 로 초기값으로 들어갔으므로 2부터 시작      아래의 코드를 보게되면 -1, 2로나누거나 3으로 나누는것에 대해서 최소값이 테이블에 들어가게 된다
    {
        table[i] = table[i - 1] + 1;    // -1 하는 경우를 일단 table에 넣음
        if(i%2==0)
            table[i] = min(table[i], table[i / 2] + 1); // 2 로 나눌 수 있는 경우
        if(i%3==0)
            table[i] = min(table[i], table[i / 3] + 1); // 3 로 나눌 수 있는 경우
    }
    cout<<table[N];

    return 0;
}
*/

/*
https://www.acmicpc.net/problem/9095

1, 2, 3 더하기 다국어 한국어   
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초 (추가 시간 없음)	512 MB	71775	46485	31014	62.901%
문제
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.

< SOL >
첫번째 테이블 설정하면 D[i] i를 1,2,3으로 나타낼 수 있는 가짓수
다음으로 점화식을 찾아보자면
초기값으론 D[1] = 1    D[2] = 2    D[3] = 4
D[4] = D[1]+D[2]+D[3]
D[5] = D[2]+D[3]+D[4]..
즉 D[i] = D[i-3]+D[i-2]+D[i-1] 이 점화식이 된다.


#include <iostream>

using namespace std;

int arr[11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for (int i = 4; i <= 10;++i)
        arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];

    int T;
    cin >> T;
    for (int c = 0; c < T;++c)
    {
        int n;
        cin>>n;
        cout << arr[n] << '\n';
    }

    return 0;
}
*/

/*
https://www.acmicpc.net/problem/2579

계단 오르기
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	105274	36073	26125	34.498%
문제
계단 오르기 게임은 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임이다. <그림 1>과 같이 각각의 계단에는 일정한 점수가 쓰여 있는데 계단을 밟으면 그 계단에 쓰여 있는 점수를 얻게 된다.



<그림 1>

예를 들어 <그림 2>와 같이 시작점에서부터 첫 번째, 두 번째, 네 번째, 여섯 번째 계단을 밟아 도착점에 도달하면 총 점수는 10 + 20 + 25 + 20 = 75점이 된다.



<그림 2>

계단 오르는 데는 다음과 같은 규칙이 있다.

계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
마지막 도착 계단은 반드시 밟아야 한다.
따라서 첫 번째 계단을 밟고 이어 두 번째 계단이나, 세 번째 계단으로 오를 수 있다. 하지만, 첫 번째 계단을 밟고 이어 네 번째 계단으로 올라가거나, 첫 번째, 두 번째, 세 번째 계단을 연속해서 모두 밟을 수는 없다.

각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.

입력
입력의 첫째 줄에 계단의 개수가 주어진다.

둘째 줄부터 한 줄에 하나씩 제일 아래에 놓인 계단부터 순서대로 각 계단에 쓰여 있는 점수가 주어진다. 계단의 개수는 300이하의 자연수이고, 계단에 쓰여 있는 점수는 10,000이하의 자연수이다.

출력
첫째 줄에 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값을 출력한다.


< SOL >
#include <iostream>

using namespace std;

int score[300];
int max_score[300];
int cnt[300][3];    // 뒤에 [3] 은 지금까지 밟은 계단의 개수를 나타내는 것으로 [1],[2]만 존재함

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;      // 계단 수
    cin >> N;

    for (int i = 0; i < N;++i)
    {
        int info;
        cin >> info;
        score[i] = info;
    }

    cnt[0][1] = score[0];
    cnt[0][2] = 0;
    cnt[1][1] = score[1];
    cnt[1][2] = score[0] + score[1];
    for (int i = 2; i < N;++i)
    {
        cnt[i][1] = max(cnt[i - 2][1], cnt[i - 2][2]) + score[i];   // 2칸 한번에 넘는 경우 -> 그전의 계단 오른 횟수가 1이던 2이던 상관없으므로 그중 큰 것
        cnt[i][2] = cnt[i - 1][1] + score[i];   //  1칸 넘는 경우 -> 그전의 계단 오른 횟수가 2이상이면 불가능하므로, 1이던것에 + 현재계단 가중치
    }
    cout << max(cnt[N - 1][1], cnt[N - 1][2]);

    return 0;
}
 이번 문제의 경우 2차원배열을 사용해야했다.  계단을 오른 개수에 따라서 경우의수가 달라지기 때문이다.
*/

/*

*/