#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Vertex {
public:
    int num;                    // 辺の番号
    bool flag;                  // 以前訪れたかどうか
    vector<int> adj;            // 隣接リスト
    int parent;                 // 幅優先木の親のnum
};

int dist[101];
void bfs(map<int, Vertex>& graph, Vertex s) {
    queue<Vertex> que;

    /* スタートの頂点について初期化 */
    dist[s.num] = 0;
    graph[s.num].flag = true;
    graph[s.num].parent = -1;
    
    que.push(s);
    while (!que.empty()) {
        Vertex u = que.front(); que.pop();
        for (auto i = 0; i < u.adj.size(); i++) {
            Vertex v = graph[u.adj[i]];
            if (!v.flag) {
                graph[u.adj[i]].flag = true;
                graph[u.adj[i]].parent = u.num;
                dist[v.num] = dist[u.num]+1;
                que.push(v);
            }
        }
    }
}

/* 最短経路を表示 */
/* constにするとエラーになってしまう */
void print_path(map<int, Vertex>& graph, Vertex s, Vertex v) {
    if (v.num == s.num) {
        cout << s.num;
    } else if (v.parent == -1) {
        cout << s.num << "から" << v.num << "への道は存在しない。" << endl;
    } else {
        print_path(graph, s, graph[v.parent]);
        cout << " -> " << v.num;
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < 101; i++) {
        dist[i] = -1;
    }

    map<int, Vertex> graph; // 頂点の番号->頂点
    for (int i = 0; i < n; i++) {
        Vertex v;
        int num, k;
        cin >> num >> k;
        v.flag = false;
        v.num = num;
        for (int j = 0; j < k; j++) {
            int tmp;
            cin >> tmp;
            v.adj.push_back(tmp);
        }
        graph[num] = v;
    }

    bfs(graph, graph[1]);
    for (int i = 1; i <= n; i++) {
        cout << i << " " << dist[i] << endl;
    }

    /* 最短経路を表示 */
    /*
    for (auto it = graph.begin(); it != graph.end(); it++) {
        print_path(graph, graph[1], it->second);
        cout << endl;
    }
    */

    return 0;
}