// Minimum spanning tree (MST)   최소 신장 트리 알고리즘 //
/*
    ANCHOR 신장 트리
        신장트리는 주어진 방향성이 없는 그래프의 부분 그래프 중 모든 정점을 포함하는 그래프를 말합니다. (부분그래프란 주어진 그래프에서 일부정점과 간선만 택해서 구성한 그래프입니다.)
        신장트리도 트리의 종류이기 때문에 "무방향이면서 사이클이 없는 연결 그래프"입니다. 또한, 당연히 "정점이 V개일 경우 간선은 V-1개"를 갖는다는 특성이 있습니다.


    ANCHOR 최소 신장 트리
        신장트리 중에서 (선택된)간선들의 가중치의 합이 최소가 되는 신장트리를 말합니다.  최소신장트리는 동일한 그래프에서 한개로 결정되지 않고 여러개 일 수 있습니다.



    ANCHOR 크루스칼 알고리즘
        크루스칼 알고리즘은 쉽게 요약하면 가장 비용이 낮은 간선으로부터 시작하여서 간선을 크기 순으로 살펴보며 서로 떨어져 있던 정점들을 합쳐나가서 총 V-1개의 간선을 택하는 알고리즘입니다.

        < 크루스칼 알고리즘 순서 >
        1. 간선의 크기의 오름차순으로 정렬하고 제일 낮은 비용의 간선을 선택
        2. 현재 선택한 간선이 정점 u,v를 연결하는 간선이라고 할 때, 만약 u,v가 같은 그룹이라면 그냥 넘어가고, 다른 그룹이라면 같은 그룹으로 만들고 현재 선택한 간선을 최소신장트리에 추가한다.
        3. 최소신장트리에 v-1개의 간선을 추가하였다면 과정을 종료하고, 그렇지 않다면 그 다음으로 비용이 적은 간선을 선택한 후 2번 과정을 반복한다.

        * 크루스칼 알고리즘은 Union Find 라는 알고리즘을 모르면 효율적으로 구현할 수 없습니다.

        <알고리즘 풀이>
        처음으론 각 정점에 색이 칠해져있는데 이 색이 바로 그룹을 나타냅니다. "맨 처음에는 모든 정점들이 서로 다른 그룹에서  시작합니다."
        이후 먼저 간선을 크기의 오름차순 순으로 정렬합니다. (실제 코드를 구현할 떄에는 간선을 크기 순서로 선택하기 위한 정렬과정이 필요합니다.)
        이후 선택되지 않은 것들 중 크기가 작은 간선을 택하고 같은 그룹인지 아닌지를 비교하고 최소신장트리에 추가할지 말지 결정합니다. (간선의 크기가 같은게 여러개일 경우 아무거나 선택해도 상관없습니다.)
        계속해서 선택되지 않은 간선을 택하고 최소신장트리에 추가... v-1개의 간선이 최소신장트리에 추가될 때까지 반복합니다. (트리가 되기 위해서는 간선이 v-1개여야하므로)


        ANCHOR 크루스칼 알고리즘을 잘 이해했다면 이 알고리즘은 그냥 사이클을 만들어내지 않는 선에서 비용이 작은 간선부터 최소신장트리에 편입시키는 그리디 알고리즘을 알 수 있습니다.
        ANCHOR 같은 그룹의 정점을 연결하는 간선은 최소신장트리에 넣지 않는 이유는 넣게 될 경우 해당 간선에 의해서 사이클이 만들어지기 떄문입니다.


        ANCHOR 그렇다면 특정 두 정점이 같은 그룹인지 다른 그룹인지는 어떻게 판단할 수 있을까요?

            ANCHOR 1.Flood Fill
                최소 신장트리에 편입시킨 간선을 별도로 관리하고 있다고 할 때, 정점 A,B가 같은 그룹인지를 판단하려면 최소신장트리에 편입한 간선들만 가지고 A -> B로 방문할 수 있는지 확인하면 됩니다.
                그런데 이 과정에서 필요한 시간복잡도는 O(V)입니다. 따라서 각각 추가하려고 할때마다 이 과정을 거치게되면 최종적으로 시작복잡도 O(ElgE + VE)는 비효율적이게 됩니다.

            ANCHOR 2.Union Find
                특정 두 정점이 같은 그룹인지 다른 그룹인지를 사실상 상수 시간으로 확인할 수 있어 Flood Fill보다 훨씬 효율적입니다.
                Union Find 를 통해서 크루스칼 알고리즘을 구현하게 되면  O(ElgE)로 효율적으로 해결이 가능합니다.

        < code >
            #include <iostream>

            using namespace std;

            int v,e;
            tuple <int,int,int> edge[10001];        // tuple <간선비용, 정점1, 정점2> edge[100001];     ANCHOR 크루스칼 알고리즘의 경우 간선을 크기 순으로 정렬해야하는 과정이 필요하기 때문에  전부 배열에 저장합니다.

            sort(edge,edge+e);                      // 간선을 오름차순으로 정렬

            int main()
            {
                int cnt = 0;

                for(int i = 0; i < e; ++i)
                {
                    int cost, a, b;
                    tie(cost, a, b) = edge[i];

                    if(!is_diff_group(a, b))                    // is_diff_group (a,b)   a,b가 같은 그룹이면 false, 다른 그룹이면 true를 리턴
                        continue;                               // 같은 그룹이라면 for문으로 넘어가고 (continue),  다른 그룹이라면 아래의 코드를 실행한다.

                    cout << cost << " " << a << " " << b;       // 다른그룹일 경우므로 비용과, 정점1, 정점2를 화면에 출력
                    cnt++;                                      // 다른그룹일 경우 cnt +1   (cnt가 v-1이 될 경우 종료 할 것이므로)

                    if(cnt == v-1)                              // cnt == v-1일 떄 for문을 break 탈출
                        break;
                }
            }



    ANCHOR 프림 알고리즘
        프림 알고리즘은 Union find가 필요했던 크루스칼 알고리즘과 다르게 우선순위 큐를 사용해서 구현할 수 있습니다.    그렇지만 크루스칼 알고리즘에 비해 구현이 복잡하다는 단점이 있습니다.
        크루스칼 알고리즘이 가장 비용이 낮은 간선 부터 시작하여서 서로 떨어져 있던 정점들을 합쳐나가며 총 V-1개의 간선을 택하는 알고리즘이었다면, "프림 알고리즘은 한 정점에서 시작하여서 확장해 나가는 알고리즘 입니다."
        프림 알고리즘 또한 매 순간마다 가장 비용이 낮은 간선을 택하므로 그리디 알고리즘에 한 종류입니다.

        <프림 알고리즘 순서>
        1. 임의의 정점을 선택하여서 최소신장트리에 추가한다.
        2. 최소신장트리에 포함된 정점과 포함되지 않은 정점을 잇는 간선들을 모두 비교하여서 비용이 가장 작은 간선을 택하고 그와 이어지는 정점을 최소신장트리에 추가한다.
        3. 최소신장트리에 V-1개의 간선이 추가될 때까지 2의 과정을 반복한다.

        <알고리즘 풀이>
        일단 첫번째로 아무 정점이나 택하여서 최소신장트리에 추가합니다.
        이후 최소신장트리에 편입해있는 정점과 편입해있지 않으면서 이어진 정점들의 간선의 비용들을 비교하여서 최소인 비용의 간선에 이어져있는 정점을 최소신장트리에 추가합니다.
        이후 앞의 과정을 최소신장트리의 간선이 V-1개가 될때 까지 반복합니다.

        ANCHOR 구현시 위와같이 그대로 구현한다면 V-1번에 걸쳐서 최소신장트리에 포합된 정점과 포함되지 않은 정점을 모두 조사하고 최소비용인 간선을 추가하는 식으로 구현할 수 있으나,  시간복잡도가 O(VE)로 많이 비효율적입니다.


        ANCHOR 프림 알고리즘의 구현
            1. 임의의 정점을 최소신장트리에 추가하고, 해당 정점과 연결된 모든 간선을 우선순위 큐에 추가한다.
            2. 우선순위 큐에서 비용이 가장 작은 간선을 선택하고 이를 꺼냅니다.
            3. 해당 선택한 간선이 잇는 정점둘이 모두 최소신장트리에 포함되는 정점이라면 아무것도 하지 않고 넘어가고, 한정점은 포함되고 다른 정점은 포함되지 않을 경우  포함되지 않은 정점과 그 간선을 최소신장트리에 포함시킨다.
               이후 이번에 포함시킨 정점과 이어지는 최소신장트리에 포함되지 않는 정점을 찾고 다시 그 간선들을 모두 우선순위쿠에 집어 넣는다.
            4. 위의 2,3과정을 최소신장트리의 간선이 V-1개가 될 때 까지 반복한다.

            ANCHOR 우선순위 큐를 사용하게 되면 간선을 적절히 넣어두면 매 순간마다 최소신장트리에 포함된 정점과 포함되지 않은 정점을 연결하는 간선 중 최소를 효율적으로 알아 낼 수 있습니다. (시간복잡도 O(ElogE))

        <code>
            #include <bits/stdc++.h>

            using namespace std;

            int v, e;

            vector<pair<int, int>> adj[10001];          // pair <간선비용, 정점번호> adj[10001];        adj[i] => i마다 연결된 정점과 그 간선의 비용을 저장하는 vector
            bool check[10001];                          // check[i]  i번 정점이 최소신장트리에 편입되어있는지 유무를 체크하는 배열
            int cnt =0;                                 // 지금까지 선택된 간선의 수  cnt  == v-1 일 경우 종료

            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> p_queue;          // 여기서 tuple<int,int,int> --> tuple <비용, 정점1, 정점2>

            int main()
            {
                ios_base::sync_with_stdio(0);
                cin.tie(0);

                check[1] = true;                                              // 일단 임의의 정점 (여기서는 1) 최소신장트리에 편입시킨다. check[i] = true;

                for(auto nxt: adj[1])                                         // for문을 돌리면서 일단 최소신장트리에 편입된 1에 연결된 간선들을 모두 우선순위큐에 push
                    p_queue.push({nxt.first, 1, nxt.second});                 // tuple<비용, 정점1, 정점2> 형식으로 우선순위큐에 추가

                while(cnt <v-1)                                               // v-1개의 간선이 추가되기 전까지 반복 (추가될 경우 루프 종료)
                {
                    int cost, a, b;
                    tie(cost, a, b) = p_queue.top();                          // 우선수위 큐에서 맨 위 (여기서는 간선의 비용이 가장 작은 것)의  간선비용, 정점1, 정점2 값을 가져오고
                    p_queue.pop();                                            // pop한다.

                    if(check[b])                                              // 만약 b가 최소신장트릴에 포함되어 있다면, (a는 당연히 포함되어있음) 정점 2개가 모두 편입됬다는 것이므로 그냥 넘어간다. continue
                        continue;

                    cout << cost << " " << a << " " << b << '\n';             // 포함되어 있지 않다면   출력하고
                    check[b] = true;                                          // 최소신장트리에 포함시키고
                    cnt++;                                                    // 간선수 cnt +1

                    for(auto nxt:adj[b])                                      // 이후 이 새로들어온 정점과 연결된 정점들을 확인하고 최소신장트리에 편입되어 있지 않다면 그 모든 간선들을 우선순위큐에 추가한다.
                    {
                        if(!check[nxt.second])
                            p_queue.push({nxt.first, 1, nxt.second});
                    }
                }

                return 0;
            }

    ANCHOR 문제를 해결할 떄
        특정그래프 알고리즘이 적용될 수 있을 것 같지만 상황이 100% 맞아 떨어지지 않을 경우, 적절하게 그래프를 리모델링하는 아이디어가 필요합니다.



    ANCHOR std::tie()
        int cost, a, b;

        tuple<int,int,int> value;

        tie(cost,a,b) = value;          // tie를 쓰게되면 한번에 tuple, pair의 값들을 받아와서 변수에 저장할 수 있다.
*/
