// 수학 //
// 1) 소수 판정법
/*
    1.  일반적인 코드로는 2~N까지 for문을 돌면서 완전탐색시  * O(N)의 시간복잡도를 갖는다.

    2.  합성수일 경우  가장 큰 약수는 root(N)이하 이다. 따라서 소수를 판정할때, root(N) 까지만 탐색하면되고,  따라서 시간복잡도는 O(root(N))으로 줄어들게 된다.
        즉, 2 ~ root(N)까지 탐색하여 약수가 존재하지않으면 소수라고 판정할 수 있게 된다.            * O(root(N)) 시간복잡도

        for(int i=2; i*i<=N; ++i)
        {
            if(N % i == 0)
                return;
        }
        cout<<"check";

    3.  범위 내에서의 소수 판정법 --- 에라토스테네스의 체 알고리즘

        일단 범위내의 수들은 true로 초기화해주고  for문을 진행한다.  -> 2는 소수므로 2 빼고 나머지 2의 배수들을 false 로
        -> 3은 소수므로 3빼고 나머지 3의 배수들을 false 로         -> 4는 소수가 아니므로 그냥 넘어간다.....   이런식으로 계속 진행

        근데 이러한 코드에서는 개선할 여지가 있다... 5의 경우 앞에서 10==2*5  15==3*5  20==2*2*5  로 모두 앞에서 2,3에 의해서 false로 더 작은 소인수에 의해 바뀐다.
        따라서 값 i(소수)부터가 아니라 i*i의 제곱부터의 범위의 i의 배수를 true로 바꾸어주면 된다는 것이다.    이와 같은 내용을 코드로 적으면 아래와 같다.

        #include <iostream>

        using namespace std;

        int main()
        {
            int check[101]={true,};             // 100까지의 범위의 소수를 구하려고 함
            check[1]=false;                     // 1은 소수가 아니므로 일단 false

            for(int i=2;i<=100;++i)             // 2부터 100까지 for문
            {
                if(check[i]==false)             // 소수가 아니라면 넘어감
                    continue;
                for(int j=i*i;j<=100;j+=i)      // 소수일 경우 그 값의 제곱부터 시작하여서 그값의 배수들을 false로 바꾼다.
                    check[j]=false;
            }                   
                                                // 위의 에라토스테네스의 체 for문이 종료되면 체로 거른 것 처럼 소수만 true, 소수가 아닌 것들은 false로 나뉘어 진다.
            for(int i=2;i<=100;++i)
            {
                if(check[i]==true)              // 이후 true인것 즉, 소수인 것들만 cout으로 출력한다.
                    cout<<i<<'\n';
            }

            return 0;
        }

        <<Tip>> 위의 경우 int(bool을 사용해도됨) array을 사용했는데,  vector<bool>을 사용할 경우 메모리와, 속도면에서 더 효율적이다.
*/

// 2) 소인수 분해
/*
    소인수 분해 알고리즘  N의 값을 소인수 분해 한다
    #include <iostream>

    using namespace std;

    int main()
    {
        int N;
        cin>>N;

        for(int i=2;i*i<=N;++i)             // 소수는 root(N)이하므로  이범위에서 for문을 돌림
        {
            while(N*i==0)                   // 나누었을때 떨어지는 i일 경우  계속 나누어보다가 나누어 떨어지지 않을 때까지 나눔
            {
                cout<<i<<" ";
                N/=i;
            }
        }
        if(N!=1)                            // 마지막에 1이 아닐 경우   즉, 소인수분해를 한번도 안했을 경우  cout << N;
            cout<<N;

        return 0;
    }
    // *** 이 코드만 봐서는 소수로만 나누어지는지에 대해서 의심이 들 수 있는데,    소수에 의해서만 나뉜다.
*/

// 3) 약수
/*
    1. 그냥 for문 전체로 돌려보기.... O(N)인데 좀 효율적이지 못함

    2. for문을 root(N)까지만 돌리기  (오냐하면 약수 하나를 알면 나머지를 알 수 있으므로 N == 구한것 * 알아내야하는 것 이므로  + N이 되는 약수를 반으로 쪼갤 경우 root(N)까지만 알면됨 )
        < code >
            vector<int> result;

            for(int i=1; i*i<=N; ++i)
            {
                if(N % i == 0)
                {
                    if(i*i == N)              <--- 이 경우만 예외처리  제곱수일 경우  2개가 중복해서 들어가는 것을 막기 위해서
                        result.push_back(i);
                    else
                    {
                        result.push_back(i);
                        result.push_back(N/i);
                    }
                }
            }
*/

// 4) 최대공약수 & 최소공배수     Greatest Common Divisor & Least Common Multiple       GCD & LCM
/*
    최대공약수, 최소공배수 구하는법    --> 유클리드호제법     시간복잡도 O(log(max(A,B)))

    <유클리드 호제법>
    숫자 A,B  A를 B로 나눈 나머지를 R이라고 하면  =>  GCD(A,B) == GCD(B,R)이라는 공식이다.  결국 마지막에 R이 0이 될떄의 B값이 최대공약수가 된다.
    ( 증명은 매우 복잡하므로.. 그냥 외워서 쓰는게 맞다.... )


    *** gcd()함수는 #include <numeric> 헤더에 있으므로 사용하면 된다.

    #include <numeric>

    using namespace std;

    int gcd(int a, int b)   * 최대공약수
    {
        if(a==0)
            return b;
        return gcd(a%b,a);
    }

    int lcM(int a, int b)   * 최소공배수
    {
        return a / gcd(a,b)*b;
    }
*/

// 5) 연립 합동 방정식
/*
    x조건, y조건을 만족시키는 해를 구해야하는 경우,  먼저 x부터, 또는 y부터 만족시키는 해를 찾고 그해중에서 나머지 조건도 만족하는 값을 찾는 것이 효율적이다.
*/

// 6) 이항계수  ( 조합,순열 )
/*
    일반적으로 알고있는 식을 그대로 for문으로 돌리게되면 되나, 숫자가 커질 경우 문제가 발생할 수 있다. 결과값은 overflow될 값이 아니지만, 계산하는 과정(곱셈)에서 overflow가 발생할 여지가 있기 때문이다.
    이때, 모듈러 역수를 이용하면 되지만, 또다른 방법이 있다.  바로 이항계수의 성질을 이용하는 것이다  ==> nCk = (n-1)Ck + (n-1)C(k-1) 을 이용하면 된다.
*/