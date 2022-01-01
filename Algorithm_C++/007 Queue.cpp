// 큐 //
// 한쪽 끝에서 원소를 넣고, 반대쪽 끝에서 원소를 뺄 수 있는 구조로 휴지심을 생가하면 된다.  (먼저들어간게 먼저나오는 구조 FIFO)
// DFS 등 다른 알고리즘에 붙어서 활용하는 경우가 많다.  

// 큐의 성질 //
// 1. 원소의 추가/제거  O(1)    추가되는곳을 rear, 제거되는곳을 front라고 부른다.
// 2. 제일 앞,뒤 원소 확인  O(1)        스텍과 다르게 두곳에서 확인할 수 있음
// 3. 제일 앞,뒤 말고는 원소를 원칙적으로 확인/변경할 수 없다.

// 큐 구현 //
#include <iostream>

using namespace std;

struct queue
{
    int data[100000];
    int head = 0;       // front        헤드는 처음원소 front의 위치를 가르킴
    int tail = 0;       // rear         테일은 지금들어있는 가장 최근의 원소의 인덱스의 바로 다음 인덱스를 가르킴
};

queue que;

void push(int data)
{
    que.data[que.tail++] = data;
}

void pop()
{
    que.head++;
}

int front()
{
    return que.data[que.head];
}

int back()
{
    return que.data[que.tail - 1];
}

void print()
{
    for (int i = que.head; i <que.tail;++i)
        cout << que.data[i] << " ";
    cout << '\n';
}

int main()
{
    push(1);
    push(2);
    push(3);
    print();

    pop();
    print();

    cout << front() << '\n';
    cout << back() << '\n';

    return 0;
}