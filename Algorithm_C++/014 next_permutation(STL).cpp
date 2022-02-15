// #include <algorithm>             next_permutation()
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vec;
    for (int i = 0; i < 5; ++i)
        vec.push_back(i + 1);

    while(next_permutation(vec.begin(),vec.end()))      // next_pernutation(순열시작, 순열끝, compare(함수 없어도됨))
    {
        for(auto e:vec)
            cout << e << '\n';
    }
    // Ex) vec   1 2 3 일 경우             1 3 2       2 1 3       2 3 1       3 1 2       3 2 1   까지 출력한뒤  false를 리턴하므로 while문이 끝난다.
    
    return 0;
}
// 첫번째 인자가 구하고자 하는 순열의 시작, 두번째 인자가 순열의 끝
// bool prev_permutation (BidirectionalIterator first, BidirectionalIterator last);

// 아래처럼 직접 비교함수를 넣어줘도 됩니다.
// bool prev_permutation (BidirectionalIterator first, BidirectionalIterator last, Compare comp);

//  next_permutation() 함수는 안에들어온 배열이나 벡터를 다음 순열로 바꾸고 (ex) 1 2 3 4 -> 1 2 4 3)   true를 리턴한다.
//  그러다가 모든 순열로 바꾸었다면 (사전순으로 모든 순열을 한번씩 들렸다면) false를 리턴한다.

// < next_permutation을 조합에 이용 >
/*
함수의 이름에서 볼 수 있듯 이 함수를 가지고 순열을 잘 처리할 수 있는데 만약 조합이 필요하다면 어떻게 해야할지 고민해봅시다. 
예를 들어 1 2 3 4에서 수 2개를 순서 없이 뽑는 모든 경우를 출력하는 문제와 같은 상황입니다. 그럴 때에도 이 함수를 이용하면 되는데 오른쪽의 코드를 확인해보겠습니다. 
바로 0과 1을 이용해 next_permutation을 돌리는 방법으로 해결하면 됩니다. 4개에서 2개를 뽑는게 아니라 5개에서 3개를 뽑는 문제라면 배열 a를 {0, 0, 0, 1, 1}로 두면 되겠습니다. 
이와 같이 next_permutation을 쓰면 순열과 조합이 필요할 때 아주 정확하고 또 타이핑을 아끼면서 구현을 해낼 수 있습니다.

즉, {0,0,0,1,1}의 순열을 구하고 0은 뽑음을 1은 뽑지않음을 나타낸다고 보고 조합을 결정하면 됩니다.
*/