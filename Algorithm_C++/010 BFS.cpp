// BFS //
// 다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘

// BFS 과정 //
// 1. 시작하는 칸을 큐에 넣고 방문했다는 표시(visited)을 남김
// 2. 큐에서 원소를 꺼내어서 그 원소와 인접해있는 칸들 중 방문하지않은(unvisited)칸들을 큐에 다시넣음
// 3. 큐가 빌때까지 이 과정을 반복함
// 모든칸이 큐에 1번씩 들어가게 되므로 (다 visited 해야하므로) 칸이 N개 일 경우에    *시간복잡도 O(N)

// BFS를 구현할때 쓰이는 STL //
// #include <utility>           pair        <-- 두개의 자료형을 묶어서 한번에 저장이 가능하다.  (좌표에 사용하는 식으로 씀)
/*
    #include <utility>
    #include <iostream>

    using namespace std;

    int main()
    {
        pair<int, int> t1 = make_pair(1, 3);
        pair<int, int> t2 = {1, 7};

        cout << t1.first << " " << t1.second << '\n';   //  1 3             first, second 로 값에 접근

        if(t1<t2)            // pair의 대소구분은 1. first값을 비교해서 큰걸 고르고  2. 만약 first가 같다면 second를 비교하여서 고른다
            cout << "t1<t2";

        return 0;
    }
*/

// BFS 구현 //
// 구현시 조심해야 할 점 //
// 1. 시작점은 처으부터 방문 표시 하기
// 2. 큐에서 빼낼 떄 방문표시를 하는 것이 아니라, 큐에 넣을 때 방문표시를 해야한다.     (전자와 같이 코딩시 예제가 큰것의 경우  메모리초과나 시간초과가 일어날 수 있다.)/
// 3. 영역안에 들어가는지 파악하기 (런타임 에러 막기위해서)
#include <iostream>
#include <utility>  
#include <queue>

int board[5][5]={               // 지나갈 수 있는길 0   없는길 1
    {0,1,1,1,1},
    {0,1,1,1,1},   
    {0,0,0,1,1},
    {1,1,0,0,1},
    {1,1,1,0,0}
};
bool visited[5][5]={false,};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;                              // 지나갈 수 있는 길을 count하는 변수

    queue<pair<int, int>> Q;                    // queue

    Q.push(make_pair(0, 0));                    // 큐에 첫 시작점 0,0 push
    visited[0][0] = true;                      // 0,0 방문했으므로 true
    count++;

    while(Q.empty()!=true)                      // 큐가 빌 때 까지 무한루프
    {
        pair<int, int> position = Q.front();    // 큐에서 하나꺼내와서 position에 대입
        Q.pop();                                // 이후 꺼내온 큐의 원소를 pop

        for (int i = 0; i < 4;++i)
        {
            // dx dy  즉, 상하좌우로 위치를 한칸씩 이동하는 x,y변수
            int position_x = position.first + dx[i];
            int position_y = position.second + dy[i];

            if(0<=position_x && position_x<5 && 0<=position_y && position_y<5)      // 상하좌우 이동한 위치가 영역 안의 경우  (런타임에러 막기위해서)
            {
                if(board[position_x][position_y]==0 && visited[position_x][position_y]==false ) // 지나갈 수 있는 길 + unvisited 일 경우
                {
                    count++;
                    visited[position_x][position_y] = true; // visited했으므로 true로 바꾸어주고
                    Q.push(make_pair(position_x, position_y));
                }
            }
            else                                                                    // 영역을 벗어날 경우 불가능-> continue
                continue;
        }
    }

    cout << "visitable boardblock is " << count << '\n';        // 9 출력

    return 0;
}
