// 스택 //
// 한쪽끝내서만 넣거나 뺄 수 있는 자료구조    (먼저들어간 원소가 제일 나중에 나오는 FILO 구조라고도 한다.)
// 1. 원소추가, 원소제거, 제일 상단 원소 확인 O(1)       (단, 한쪽 끝에만 추가나 제거할 수 있다.)   <--- 끝의 원소는 확인/변경이 O(1)로 장점
// 2. 제일 상단이 아닌 나머지는 추가,제거,확인이 원칙적으로 불가능함.

// 스택 구현 // 
#include <iostream>

using namespace std;

struct stack            // 스택 구조체
{
    int data[100000];      // 스택 쌓는 데이터 장소
    int pos = 0;        // pos  다음데이터가 들어갈 index를 지시함. ( + 스택에 있는 데이터의 개수와도 동일)
};

stack STACK;

// push function
void push_back(int data)        
{
    STACK.data[STACK.pos] = data;
    STACK.pos++;
}

// pop function
void pop_back()                 
{
    if(STACK.pos>0)
        STACK.pos--;
}

// top function
int top()                       
{
    if(STACK.pos>0)
        return STACK.data[STACK.pos - 1];
}

void print()
{
    for (int i = 0; i < STACK.pos;++i)
        cout << STACK.data[i] << " ";
    cout << '\n';
}

int main()
{

    return 0;
}