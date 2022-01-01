// vector                   vector의 경우 크기를 가변적으로 바꿀 수 있고 여러가지 메소드가 있어서 배열보다 편한점이 있는 STL이다.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};

    // range-based for loop
    for (int element : vec) // for(int element: vec)        element 에 vec vector의 원소들이 하나씩 "복사"되어서 들어간다.
        cout << element << " ";
    cout << '\n';

    for (int &element : vec) // for(int& element: vec)       &element 참조로 선언했으므로 vec vector의 원소들 그자체가 들어간다 따라서 vec에 변화를 줄 수 있음
    {
        cout << element << " ";
        element += 1;
    }
    cout << '\n';

    // *** Wrong *** for 문으로 값을 연속적으로 호출할 때 주의할 점
    for (int i = 0; i <= vec.size() - 1; i++) // 여기서 주의해야하는 이유는 vec.size() 의 메소드는 unsigned int 를 변환한다는 점 때문이다. 만약 vec.size() 값이 0 일 경우 0-1 = -1 로 즉 overflow가 발생할 수 도 있기 때문이다.
        cout << vec[i] << " ";

    return 0;
}