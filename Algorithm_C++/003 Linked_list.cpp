// 연결 리스트 //    *** 선형 자료구조
// 원소를 저장할 떼  원소뿐아니라 그다음 원소가 저장되는 주소를 함께 저장하는 구조이다. (배열과 다르게 선형적이지 않고 흩어져있다.)

// 연결 리스트 성질 //
// 1. k번째 원소를 찾기 위해서 O(k)의 시간복잡도를 갖는다.   공간에 연속적이지 않기 때문에 처음부터 거슬러 올라가야 하기 때문이다.
// 2. 임의의 원소를 추가/제거 하기 위해서 O(1)의 시간복잡도를 갖는다.  *** 배열과 다르게 추가/제거하는데 용이하다. *** 단,주소가 주어졌을때 O(1) 이고
//                                                              주어지지않았을 경우 찾아가는 경우 즉, O(n)의 시간복잡도가 필요하다.
// 3. Cache hit rate가 낮지만, 연속된 공간을 차지하지 않기 때문에 할당이 다소 쉽다.
// 4. 추가로 주소를 저장할 메모리가 필요하다.
// 즉, 연결 리스트의 경우 임의의 위치에 원소를 추가/제거 해야하는 경우가 많을 때 이용하면 좋다.

// 연결 리스트의 종류 //
// (단일 연결 리스트)           각 원소가 다음 원소의 주소를 가지고 있는 구조
// (이중 연결 리스트)           각 원소가 다음 원소의 주소와 이전 원소의 주소를 둘다 갖고있는 구조
// (원형 연결 리스트)           각 원소가 다음원소만 갖던, 둘다 갖던 상관이 없이  처음원소와 나중 원소가 이어져 있는 구조


// 이중 연결 리스트 구현 //
#include<iostream>

using namespace std;

struct Node
{
    Node *pre;
    Node *nxt;
    int data;
};

Node *head = nullptr;
Node *tail = nullptr;

// 노드 생성 function
void construct_Node(int data)
{
    Node *node;

    if(head == nullptr)         // 노드가 아예 생성되지 않았을 경우 (처음일 경우)
    {
        node = new Node;  // 노드 1개 동적할당
        
        node->pre = nullptr;
        node->nxt = nullptr;
        node->data = data;

        head = node;            // 헤드노드 세팅
        tail = node;            // 꼬리노드 세팅
    }
    else                        // 노드가 1개이상 존재 할 경우
    {
        node = new Node;  // 노드 1개 동적할당

        node->pre = tail;       // 연결할 이전 노드의 값을 pre값에 대입합
        node->nxt = nullptr;
        node->data = data;

        tail->nxt = node;       // 바로 앞 노드의 nxt값을 새로 생성되는 노드의 주소로 바꾸어줌

        tail = node;            // 꼬리노드를 방금 생성한 노드로 바꿈       ( 새로운 노드가 생성되어 뒤에 연결 되었으므로)
    }
}

// insert function          데이터와 삽입할 위치(몇번째 인덱스)를 파라미터로 받는다.
void insert(int data, int num)    
{
    Node *target = head;
    for (int i = 0; i < num; ++i)
        target = target->nxt;           // target 즉, 삽입할 주소를 찾음

    if(target==head)                    // 헤드노드에 삽입일 경우
    {
        Node *node = new Node;          // 삽입할 새노드 생성
        
        node->pre = nullptr;            // 첫노드가 되는 것이므로 pre = nullptr
        node->nxt = target;             // 원래 첫노드가 뒤로 연결되므로
        node->data = data;

        target->pre = node;             // 원래 head노드였던 것의 pre를 이제 새로들어온 head로 대입

        head = node;                    // 새로운 헤드값을 대입
    }
    else if(target==tail)               // 꼬리노드일 경우 삽입이 아니라 그냥 construct_Node function을 이용하면 된다.
        construct_Node(data);
    else                                // 꼬리노드가 아닐 경우  즉, 삽입일 경우
    {
        Node *node = new Node;          // 삽입할 새노드 생성하고

        node->pre = target->pre;        // 원래 그자리 노드의 pre pre에 대입
        node->nxt = target;             // 원래 그자리 노드의 값을 nxt에 대입
        node->data = data;

        target->pre->nxt = node;        // target노드에 이전 노드의 nxt값을 새로들어온 노드의 주소를 대입
        target->pre = node;             // 이후 밀려난 target노드의 pre 에는 삽입된 노드의 주소를 대입
    }
}

// erase function           삭제할 위치(몇번째)를 파라미터로 받는다.
void erase(int num)
{
    Node *target = head;
    for (int i = 0; i < num;++i)
        target = target->nxt;

    if(target==head)                        // target이 헤드노드 일 경우
    {  
        if(head!=tail)                      // 노드가 2개 이상 존재 할  경우
        {
            target->nxt->pre = nullptr;     // 첫 노드를 삭제하고 이후 노드를 헤드 노드처럼 바꾸기
            head = target->nxt;

            delete target;                  // 이후 삭제함 (삭제할 노드의 동적할당을 제거함)
        }
        else                                // 노드가 1개뿐일 때
        {
            head = nullptr;                 // 노드가 아예 존재하지 않게 되므로 nullptr
            tail = nullptr;                 // 노드가 아예 존재히지 않게 되므로 nullptr

            delete target;                  // 노드삭제
        }
    }
    else if(target==tail)                   // target이 꼬리노드 일 경우
    {
        target->pre->nxt = nullptr;         // 연결되어있는 이전노드의 nxt를 nullptr로 ( 왜냐하면 뒤에 노드가 삭제되므로)
        tail = target->pre;                 // 이후 맨뒤 꼬리노드가 삭제됬으므로 다시 새로운 꼬리노드를 tail에 대입

        delete target;                      // 노드삭제
    }
    else                                    // target이 꼬리노드도 헤드노드도 아닐 경우
    {
        target->pre->nxt = target->nxt;     // target 왠쪽과 오른쪽 노드를 연결
        target->nxt->pre = target->pre;     // target 왼쪽과 오른쪽 노드를 연결

        delete target;                      // 노드삭제
    }
}

// 연결리스트의 data값을 순차적으로 출력하는 function
void squentially_Print()                
{
    Node *current_node = head;

    while(current_node!=tail)
    {
        cout << current_node->data << '\n';
        current_node = current_node->nxt;
    }
    cout << current_node->data << '\n';
    cout << '\n';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5;++i)          // 데이터값을 0,1,2,3,4 차례대로 넣은 연결리스트를 생성함
        construct_Node(i);

    // insert example
    insert(7, 0);
    squentially_Print();                // 7,0,1,2,3,4

    insert(77, 5);
    squentially_Print();                // 7,0,1,2,3,4,77

    insert(777, 3);                     // 7,0,1,777,2,3,4,77
    squentially_Print();


    // erase example
    erase(0);
    squentially_Print();                // 0,1,777,2,3,4,77

    erase(6);
    squentially_Print();                // 0,,1,777,2,3,4

    erase(2);
    squentially_Print();                // 0,1,2,3,4

    return 0;
}

// < 복기 > 
// 1. 함수안에서 동적할당 되는 경우 함수가 종료된다고 해서 동적할당이 알아서 해제되지 않는다.
// 2. 구현할때 "경계"를 잘 생각해봐야 한다. 경계에서 예외나 따로 케이스를 나누어야하는 경우가 많기 때문이다.
// 3. delete는 동적할당된 것을 해제한다고 알고 있다.  즉, 그 메모리에 저장되어있는 값을 없애는 것이 아니라, 그 메모리를 다른 프로세스에서 접근할 수
//    있도록 할당을 해제해주는것.       따라서 그 메모리에 값이 변화하는건 아님. 그대로 남아있음.