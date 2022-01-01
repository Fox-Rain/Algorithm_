// STL stack

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // stack 선언 
    stack<int> stac;

    // stack에 값 추가
    stac.push(1);

    // stack에 꼭대기값 리턴
    stac.top();

    // stack에 크기
    stac.size();

    // stack에 값 제거
    stac.pop();

    // stack에 값이 존재하는지 유무확인
    stac.empty();               // 비어있으면 True, 비어있지 않을 경우 False

    return 0;
}