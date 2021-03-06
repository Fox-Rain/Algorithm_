// 해시 알고리즘 //
// 해시란?    키에 대응하는 값을 저장하는 자료구조를 말합니다.
/*
    일반적으로 값들을 저장하고 찾고 빼내는 것을 배열로 구현하게되면, 값을 추가하는데 O(1),    값을 찾는데 O(N) (선형탐색),    값을 제거하는데 O(N)의 시간복잡도가 걸리게 됩니다. 즉, 효율적이지 못하다고 볼 수 있습니다
    그런데 해시 자료구조에서는 삽입,제거,추가,찾기가 모두 O(1)의 시간복잡도로 해결이 가능합니다.

    해시 자료구조에는 해시함수라는 함수가 사용됩니다.    해시함수는 마치, 우리가 16자리수의 숫자를 기억하고 분류할떄, 몇몇자리만 기억하고 구분하여 분류하듯이 "임의 길이의 데이터를 고정된 길이의 데이터로 대응시키는 함수"
    입니다.
    Ex)    1232 4414 3432 1234   APPLE            <--- 데이터의 뒷 4자리만 취함.
           2434 3342 5344 1515   BANANA
           1999 3425 4458 6753   MELON

           1234  ...    1515   ...       6753
           APPLE        BANANA           MELON


    즉, 해시 자료구조란,    키를 적당한 배열의 인덱스로 보내는 해시함수를 두고 위와같이 테이블 식으로 자료를 저장하는 알고리즘입니다.   이렇게 해시 테이블을 구현하게되면 모든 연산을 O(1)에 해결할 수 있습니다.
    그런데 문제가 하나 있습니다. 해시함수로 키값을 바꾸는 해싱과정에서 중복(충돌) 즉, 다른 여러키가 해시값 하나를 갖게되는 경우 "해시충돌"이 발생할 수 있습니다.  이를 잘 해결하는 것이 해시테이블의 성능에 영향을 줍니다.

    * 따라서 해시의 충돌을 아래와 같은 2가지의 방법으로 피할 수 있습니다.
    1) Chaining         각각 해시테이블의 해시값마다 배열(or 연결리스트)를 두어서 여럴키가 해시값을 하나 갖을때의 값들을 모두 저장하는 방식으로 구현하는 방법입니다.
                        그러나 문제점이 있습니다. 해시값마다 중복되는 값이 많을 경우 해시값에 존재하는 값들을 모두 선형탐색하므로, 시간적으로 효율성이 떨어질 수 있습니다.  최악의 경우 모든 자료들의 해시값이
                        동일할 경우 시간복잡도가 O(N)까지 떨어질 수 있습니다.  *** 그렇기 떄문에 해시에서는 각 키마다 해시값이 균등하게 퍼지는 것이 퍼포먼스적으로 효율적이므로, 해시함수를 잘 구현하는것이 중요합니다.

    2) Open addressing  해시테이블에 값이 벌써 존재한다면, 그뒤로 한칸찍 이동하면서 첫번째로 비어져있는 칸에 키값+값을 추가하는 방식입니다.
                        값을 탐색할때는 첫번째로 해시값에 존재하는 값을 확인하고, 찾는 값이 아니라면, 비어있는 해시값이 나올때까지 이동하면서 탐색하는 방식입니다.
                        값을 지우는 연산을 할 때에는, 탐색이 유지되도록 지운부분에 dummy값이든 값을 넣어주어야합니다.
                        *오픈어드레싱의 경우, 충돌발생시 값을 저장하는 방식에 따라서 또 3가지로 나뉩니다.

    2-1) Linear Probing ->      충돌 발생시 1칸씩 이동하는 방식
                                연속적으로 연결되어 이동하므로 cache hit rate가 높다.
                                clustering이 생겨서 성능에 감소될 수 있다.     군집이 연결되어있으므로, 빈칸을 찾을때까지 이동해야하는 횟수가 매우 커질 수 있다.

    2-2) Quadratic Probing ->   충돌 발생시 1,3,5,.. 칸씩 이동하는 방식
                                cache hit rate가 높지는 않으나 clustering을 줄일 수 있다는 장점이 있다.
                                단, 해시값이 여전히 같다면, 똑같이 clustering이 생길 수 밖에 없는 구조이다.   ( 따라서 해쉬함수를 구현하는게 가장 주요한 포인트일 것이다...)

    2-3) Double Probing ->      충돌 발생시 이동할 칸의 수를 다시 해시함수를 통해서 계산하는 방식
                                clustering을 효율적으로 피할 수 있다.
                                단, cache hit rate가 낮다.


    <<< Hash STL >>>
    unordered_set<자료형> 변수명;  ... 집합과 같다.  여기의 원소들을 제거하거나,추가,찾기등을 할 수 있다. (단, unordered_set은 중복을 허용하지 않는다.)   또한 해시 특성상 들어간 원소들이 뒤죽박죽 존재합니다.

    unordered_multiset<자료형> 변수명;      unordered_set과 동일한데, 중복이 허용된다는 점이 다르다.   multiset에서 주의할점은, *** erase함수 사용시 값 1개가 지워지는 것이 아니라 그 값과 같은 값을
                                         모두 지워버리므로 주의해야한다.

    unordered_map<키값 자료형, 값의 자료형> 변수명;    키값을 통해서 값을 찾을 수 있습니다.  또한 중복키는 허용되지 않습니다.
*/