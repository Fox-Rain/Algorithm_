// STL list                 연결리스트 stl

// push_back pop_back push_front pop_front  는 모두 O(1)

// list //
// list는 보통 이중연결리스트로 구현된다.  이중연결리스트로 구현되면 메모리상의 임의의 위치에 원소를 저장하더라도 참조가 가능하다.  
// 왜냐하면 이전원소의 링크를 통해 다음 원소로 추적해 나갈 수 있기 때문이다.
// 
// list는 덕분에 이러한 장점을 갖는다.    
// 1. 임의의 위치에 원소의 삽입과 삭제가 용이하다. (시간복잡도 상수시간)    
// 2. 서로다른 컨테이너 사이나 컨테이너 내부 원소들간의 '이동'이 매우 효율적이다. (선형으로 순차적으로 찾기않기에 상수시간) 서로 자리바꿈이 유리
// 3. 원소들을 앞에서뒤, 뒤에서 앞으로 참조해 나갈 수 있다.          
// 4. 다른 순차 컨테이너들 처럼 메모리 할당과 해제는 내부적으로 스스로 구현한다.
// 다른 표준순차 컨테이너 (vector deque)들과 비교해봤을때 리스트는 원소삽입, 삭제, 컨테이너 내부간의 원소의 이동등에서 훨씬 효울적이다.  
// 따라서 정렬 알고리즘처럼 원소의 이동이 번번히 일어날때 사용하면 효과적인 컨테이너이다.
// 
// 하지만 단점도 갖는데 단점으로는     
// 1. 원소들의 인덱스를 직접 참조하는것이 비효율적이라는 것이다. 
//    원소들마다 다음,또는 이전것들의 링크를 가지고있기에 처음부터 링크를 타고 원하는 index까지 가야 참조를 할 수 있다는 문제점이 있다.
// 2.또한 추가적으로 다른원소의 주소값을 보관해야 하므로, (x86 기준) 원소마다 추가적으로 8byte씩 메모리를 더 차지하게 되는 비효율적인 면이 있다.

// list를 자주 사용하는 경우 
// 1.저장할 데이터개수가 가변적일때  2. 저장된요소를 자주 검색하지 않을때  3.중간에 데이터 삽입 삭제가 빈번할때  4. 랜덤 엑세스를 자주하지 않을 때

// list는 Node기반의 컨테이너입니다.  
// list는 멤버함수에 vector,deque와는 다르게 정렬(sort,merge), 이어붙이기(splice)가 있습니다  임의접근([],at())등이 불가능합니다.

#include<iostream>
#include<list>

using namespace std;

int main()
{
	// list 선언, 초기화       list <자료형> 리스트명
	list<int> list1; // lt1이라는 비어있는 리스트를 생성
	list<string> list2(10); // default=0으로 초기화되어있는 10개의 원소를 가진 리스트를 생성    <<< 여기서는 <string>의 list므로 ""으로 초기화 된다.
	list<int>list3(3, 2); // 2로 초기화된 값을 3개 가지고있는 리스트를 생성
	list<int>list3_copy(list3); // ()안에 또다른 리스트를 넣게되면 그리스트를 복사하여 저장한다.
	list<int>list4 = { 1,2,3,4 }; // 이런식으로 초기화를 한번에 할 수도 있다.



	// list 멤버함수 //
	list<int>list5;

	// .assign(m,n)    n으로 초기화된 원소 m개를 할당한다.    다른것들이 list에 들어있었다면 삭제하고 앞에처럼 채운다.
	list5.assign(3, 5);
	list<int>::iterator itr5;

	for (itr5 = list5.begin(); itr5 != list5.end(); ++itr5)
		cout << *itr5 << endl; // 5 5 5 출력

	// .front()    맨앞의 원소를 반환

	// .back()     맨뒤의 원소를 반환

	// .begin()    맨앞의 원소를 가르키는 iterator을 반환

	// .end()      맨마지막 다음의 원소를 가르키는 iterator을 반환      list는  head -> 1번노드 -> 2번노드 -> ... -> 마지막노드 -> head    따라서 .end()는  head를 가르키는 iterator을 반환한다.

	// .rbegin(),    .rend()     반대 순서로 접근할때 이용하는 iterator

	// .push_back() .pop_back() .push_front() .pop_front ..

	// .insert( iterator ,	k)   iterator가 가르키는 곳에 k을 대입합.

	// .erase(iterator)    itertator가 가르키는 원소를 삭제함

	// .size()   원소의 개수를 반환함

	// .remove(k)    K와 같은 원소를 '모두' 제거합니다.
	list5.remove(5); // 5 5 5  에서 5를 모두 삭제하므로    원소가 아예 다 사라지게 된다.

	cout << list5.empty() << endl; // 따라서 .empty()을 하게되면 true 1이 출력된다.

	// .remove_if(predicate) predicate에서 true를 리턴하는 원소를 모두 제거합니다.    predicate는 인자를 1개만 갖으며 리턴형이 bool인 함수입니다.
	list<int>list6 = { 1,2,3,4,5 }; // 1 2 3 4 5 
	list6.remove_if([](int i) {return i % 2; }); // 이런식으로 사용할 수 있다.

	list<int>::iterator itr6;
	for (itr6 = list6.begin(); itr6 != list6.end(); ++itr6)
		cout << *itr6 << endl; // 2 4 출력 

	// .reverse()   원소들의 순차열을 뒤집습니다.
	list<int>list7 = { 1,2,3,4,5 };
	list7.reverse();

	list<int>::iterator itr7;
	for (itr7 = list7.begin(); itr7 != list7.end(); itr7++)
		cout << *itr7 << endl; // 5 4 3 2 1

	// .sort()     default로는 오름차순으로 정렬하고,   함수(두개의 인자를 받으며 bool리턴형인 함수)를 통하여 자신이 원하는 조건에 맞추어 정렬할 수도 있다.
	list<int>list8 = { 1,3,2,5,7 };
	list<int>::iterator itr8;

	list8.sort(); // default
	for (itr8 = list8.begin(); itr8 != list8.end(); itr8++)
		cout << *itr8 << endl; // 1 2 3 5 7

	list8.sort([](int i, int j) {return i > j; }); // 함수를 통해서 정렬방법을 바꿀 수 있다.
	for (itr8 = list8.begin(); itr8 != list8.end(); itr8++)
		cout << *itr8 << endl; // 7 5 3 2 1

	// .swap()     ()괄호안의 list와 서로 바꿉니다.

	// .splice()
	// (1)
	list<int>list9 = { 1,2,3,4,5 };
	list<int>list9_splice = { 7,7,7 };
	list<int>::iterator itr9;

	list9.splice(list9.begin(), list9_splice); // .splice(넣을곳의 iterator, 넣을 list)
	for (itr9 = list9.begin(); itr9 != list9.end(); ++itr9)
		cout << *itr9; // 77712345
	cout << endl;

	// (2)
	list<int>list10 = { 1,2,3,4,5 };
	list<int>list10_splice = { 10,15,18 };
	list<int>::iterator itr10;

	list10.splice(list10.end(), list10_splice, ++list10_splice.begin()); // .splice(넣을곳의 iterator, 넣을list, 넣을 list중 넣을 원소의 iterator)   *** 여기서 주의하게 볼것은 list에서는 list10.begin()+1이런식의 연산이
	for (itr10 = list10.begin(); itr10 != list10.end(); ++itr10)         // 불가능하다는 것이다.  ++,--을 통해 iterator을 ケ穗 수밖에 없다.  (데이터들이 물리적으로 붙어있는것이 아니기 때문)
		cout << *itr10; // 1234515
	cout << endl;

	// (3)
	list<int>list11 = { 1,2,3,4,5,6 };
	list<int>list11_splice = { 43,23,77 };
	list<int>::iterator itr11;

	list11.splice(++list11.begin(), list11_splice, list11_splice.begin(), ++list11_splice.begin()); // .splice(넣을곳의 iterator, 넣을 list, 넣을 list의 시작 iterator, 넣을 list의 마지막 iterator)
	for (itr11 = list11.begin(); itr11 != list11.end(); ++itr11)
		cout << *itr11; // 14323456
	cout << endl;

	// .unique()
	list<int>list12 = { 1,2,3,3,3,4,5 };
	cout << list12.size() << endl; // 처음엔 7

	list12.unique(); // 인접한 원소가 같으면 유일하게 만듭니다. (하나빼고 같은것들은 삭제)

	cout << list12.size() << endl; // 5
	list<int>::iterator itr12;
	for (itr12 = list12.begin(); itr12 != list12.end(); ++itr12)
		cout << *itr12; // 1 2 3 4 5
	cout << endl;

	// .merge()
	// (1)
	list<int>list13 = { 1,3,7,11 }; // 정렬되어있는 list
	list<int>list13_merge = { 4,5,13,25 }; // 정렬되어있는 list
	list13.merge(list13_merge); // list13에 ()안의 리스트와 합병하여 정렬한다.      *** 단, 두 리스트는 각각 정렬이 되어있어야 한다.

	list<int>::iterator itr13;
	for (itr13 = list13.begin(); itr13 != list13.end(); ++itr13)
		cout << *itr13;
	cout << endl;

	// (2)
	list<int>list14 = { 1,3,4,5 };
	list<int>list14_merge = { 2,3,4,6,9 };
	list14.merge(list14_merge, [](int i, int j) {return i > j; }); // 이항 함수를 넣어서 자신이 원하는 조건에 따라 합병 정렬도 가능하다.

	return 0;
}