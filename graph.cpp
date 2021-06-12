#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    int v;
    map<T, list<pair<T, int>>> l;
    map<T, list<int>> l1;

public:
    Graph(int V)
    {
        v = V;
    }
    void addEdge(T src, T dest, int wth, bool bidirect)
    {
        l[src].push_back(make_pair(dest, wth));
        if (bidirect)
        {
            l[dest].push_back(make_pair(src, wth));
        }
    }
    void addEdgeUndirected(T x, T y)
    {
        l1[x].push_back(y);
        l1[y].push_back(x);
    }
    void addEdgeDirected(T x, T y)
    {
        l1[x].push_back(y);
    }
    void printDirectedGraph()
    {
        for (auto node : l1)
        {
            cout << node.first << " : ";
            for (auto nbr : l1[node.first])
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
    void printBiDirectedGraph()
    {
        for (auto n : l)
        {
            cout << n.first << " : ";
            for (auto a : n.second)
            {
                cout << "( " << a.first << " , " << a.second << " ) ";
            }
            cout << endl;
        }
    }
    void printGraph()
    {
        for (auto n : l)
        {
            cout << n.first << "->" << endl;
            for (auto nbr : n.second)
            {
                cout << nbr.first << " " << nbr.second << ",";
            }
            cout << endl;
        }
    }
    void bfsTraversal()
    {
        queue<int> q;
        bool visited[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }
        //0 as a src node.
        q.push(0);
        visited[0] = true;
        cout << "BFS Traversal : ";
        while (!q.empty())
        {
            int node = q.front();
            cout << node << ",";
            q.pop();
            for (auto nbr : l[node])
            {

                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                }
            }
        }
        cout << endl;
    }
    void dfs_helper(int src, map<T, bool> &visited)
    {
        visited[src] = true;
        cout << src << ",";
        for (auto i : l[src])
        {
            if (!visited[i.first])
            {
                dfs_helper(i.first, visited);
            }
        }
    }
    void dfsTraversal()
    {
        map<T, bool> visited;
        //0 as source.
        cout << "DFS Traversal : ";
        dfs_helper(0, visited);
    }
    bool isCycleUndirected()
    {
        // Code here
        vector<bool> visited(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && isCyclicConntected(i, visited))
            {
                return true;
            }
        }
        return false;
    }
    bool isCyclicConntected(int s, vector<bool> &visited)
    {
        vector<int> parent(v, -1);
        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : l1[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                    parent[v] = u;
                }
                else if (parent[u] != v)
                    return true;
            }
        }
        return false;
    }
    bool contain_cycle_directed()
    {
        bool *visited = new bool[v];
        bool *stack = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = stack[i] = false;
        }
        return contain_cycle_directed_helper(0, visited, stack);
    }
    bool contain_cycle_directed_helper(int src, bool *visited, bool *stack)
    {
        //mark visited and put in stack
        visited[src] = true;
        stack[src] = true;

        //visit all adjacent for cycle.
        for (int i : l1[src])
        {
            if (stack[i])
            {
                return true;
            }
            else if (!visited[i])
            {
                bool cyclemila = contain_cycle_directed_helper(i, visited, stack);
                if (cyclemila)
                {
                    return true;
                }
            }
        }
        //when you leave a node, it remains visited.
        //but not part of stack.

        stack[src] = false;
        return false;
    }
};
void bfsDfsCall();
void containCycleDirectedGraph();
void containCycleUnirectedGraph();
void search_in_maze();
vector<string> findPath(vector<vector<int>> &m, int n);
void dfsMaze(int i, int j, string s, vector<vector<int>> &m, int n, vector<vector<int>> &visited, vector<string> &v);
void minStepsByKnight();
int minStepToReachTarget(vector<int> KnightPos, vector<int> TargetPos, int n);
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor);
void floodFillHelper(vector<vector<int>> &image, vector<vector<int>> &vis, int sr, int sc, int x, int newColor, int m, int n);
int main()
{
    minStepsByKnight();
    return 0;
}

void floodFillHelper(vector<vector<int>> &image, vector<vector<int>> &vis, int sr, int sc, int x, int newColor, int m, int n)
{
    if (sr < 0 || sc < 0 || sr >= m || sr >= n)
    {
        return;
    }
    if (image[sr][sc] != x or vis[sr][sc])
    {
        return;
    }
    vis[sr][sc] = 1;
    image[sr][sc] = newColor;
    floodFillHelper(image, vis, sr + 1, sc, x, newColor, m, n);
    floodFillHelper(image, vis, sr - 1, sc, x, newColor, m, n);
    floodFillHelper(image, vis, sr, sc + 1, x, newColor, m, n);
    floodFillHelper(image, vis, sr, sc - 1, x, newColor, m, n);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int x = image[sr][sc];
    int m = image.size();
    int n = image[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    floodFillHelper(image, vis, sr, sc, x, newColor, n, m);
    return image;
}
int minStepToReachTarget(vector<int> KnightPos, vector<int> TargetPos, int n)
{
    int x1 = KnightPos[0];
    int y1 = KnightPos[1];
    int x2 = TargetPos[0];
    int y2 = TargetPos[1];
    int a[1001][1001];
    //one possibilty is knight is already in target position.
    if (x1 == x2 and y1 == y2)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
    //find using bfs.
    queue<pair<int, int>> q;
    q.push(make_pair(x1 - 1, y1 - 1));
    while (!q.empty())
    {
        auto cur = q.front();
        int i = cur.first;
        int j = cur.second;
        q.pop();

        //now we will do 8 direction visiting from i and j.
        //considering it lies in board
        if ((i + 1 >= 0) and (i + 1 <= n) and (j + 2 >= 0) and (j + 2 <= n) and a[i + 1][j + 2] == 0)
        {
            a[i + 1][j + 2] = a[i][j] + 1;
            q.push(make_pair(i + 1, j + 2));
        }
        if ((i + 2 >= 0) and (i + 2 <= n) and (j + 1 >= 0) and (j + 1 <= n) and a[i + 2][j + 1] == 0)
        {
            a[i + 2][j + 1] = a[i][j] + 1;
            q.push(make_pair(i + 2, j + 1));
        }
        if ((i + 2 >= 0) and (i + 2 <= n) and (j - 1 >= 0) and (j - 1 <= n) and a[i + 2][j - 1] == 0)
        {
            a[i + 2][j - 1] = a[i][j] + 1;
            q.push(make_pair(i + 2, j - 1));
        }
        if ((i + 1 >= 0) and (i + 1 <= n) and (j - 2 >= 0) and (j - 2 <= n) and a[i + 1][j - 2] == 0)
        {
            a[i + 1][j - 2] = a[i][j] + 1;
            q.push(make_pair(i + 1, j - 2));
        }
        if ((i - 1 >= 0) and (i - 1 <= n) and (j - 2 >= 0) and (j - 2 <= n) and a[i - 1][j - 2] == 0)
        {
            a[i - 1][j - 2] = a[i][j] + 1;
            q.push(make_pair(i - 1, j - 2));
        }
        if ((i - 2 >= 0) and (i - 2 <= n) and (j - 1 >= 0) and (j - 1 <= n) and a[i - 2][j - 1] == 0)
        {
            a[i - 2][j - 1] = a[i][j] + 1;
            q.push(make_pair(i - 2, j - 1));
        }
        if ((i - 2 >= 0) and (i - 2 <= n) and (j + 1 >= 0) and (j + 1 <= n) and a[i - 2][j + 1] == 0)
        {
            a[i - 2][j + 1] = a[i][j] + 1;
            q.push(make_pair(i - 2, j + 1));
        }
        if ((i - 1 >= 0) and (i - 1 <= n) and (j + 2 >= 0) and (j + 2 <= n) and a[i - 1][j + 2] == 0)
        {
            a[i - 1][j + 2] = a[i][j] + 1;
            q.push(make_pair(i - 1, j + 2));
        }
    }
    return a[x2 - 1][y2 - 1];
}
void minStepsByKnight()
{
    vector<int> knightPos = {4, 5};
    vector<int> targetPos = {1, 1};
    cout << minStepToReachTarget(knightPos, targetPos, 2);
}
void dfsMaze(int i, int j, string s, vector<vector<int>> &m, int n, vector<vector<int>> &visited, vector<string> &v)
{
    if (i < 0 or j < 0 or i >= n or j >= n)
    {
        //check wheter location is not going out of bound.
        return;
    }
    if (m[i][j] == 0 or visited[i][j] == 1)
    {
        //check for not possible way or visited way.
        return;
    }
    if (i == n - 1 and j == n - 1)
    {
        v.push_back(s);
        return;
    }
    visited[i][j] = 1;

    dfsMaze(i - 1, j, s + "U", m, n, visited, v);
    dfsMaze(i + 1, j, s + "D", m, n, visited, v);
    dfsMaze(i, j - 1, s + "L", m, n, visited, v);
    dfsMaze(i, j + 1, s + "R", m, n, visited, v);

    visited[i][j] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> v;
    v.clear();
    vector<vector<int>> visited(5, vector<int>(5));
    if ((m[0][0] == 0) or (m[n - 1][n - 1] == 0))
        return v;
    string s = "";

    dfsMaze(0, 0, s, m, n, visited, v);
    sort(v.begin(), v.end());
    return v;
}
void search_in_maze()
{
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    vector<string> out = findPath(m, m.size());
    for (auto i : out)
    {
        cout << i << " ";
    }
}
void containCycleUnirectedGraph()
{

    Graph<int> g1(4);
    g1.addEdgeUndirected(0, 1);
    g1.addEdgeUndirected(0, 2);
    g1.addEdgeUndirected(1, 2);
    g1.addEdgeUndirected(2, 0);
    g1.addEdgeUndirected(2, 3);
    g1.addEdgeUndirected(3, 3);
    if (g1.isCycleUndirected())
    {
        cout << "Cycle" << endl;
    }
    else
    {
        cout << "No Cycle" << endl;
    }
}
void containCycleDirectedGraph()
{
    Graph<int> g1(7);
    g1.addEdgeDirected(0, 1);
    g1.addEdgeDirected(1, 2);
    g1.addEdgeDirected(2, 3);
    g1.addEdgeDirected(3, 4);
    g1.addEdgeDirected(4, 5);
    g1.addEdgeDirected(1, 5);
    g1.addEdgeDirected(5, 6);
    g1.addEdgeDirected(4, 2); //Back edge
    if (g1.contain_cycle_directed())
    {
        cout << "Contains cycle" << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }
}
void bfsDfsCall()
{
    Graph<int> g(10);
    g.addEdge(0, 1, 4, 1);
    g.addEdge(0, 7, 8, 1);
    g.addEdge(1, 7, 11, 1);
    g.addEdge(1, 2, 8, 1);
    g.addEdge(7, 8, 7, 1);
    g.addEdge(2, 8, 2, 1);
    g.addEdge(8, 6, 6, 0);
    g.addEdge(2, 5, 4, 0);
    g.addEdge(6, 5, 2, 0);
    g.addEdge(2, 3, 7, 0);
    g.addEdge(3, 3, 14, 0);
    g.addEdge(3, 4, 9, 0);
    g.addEdge(5, 4, 10, 0);
    g.addEdge(7, 6, 1, 0);
    g.bfsTraversal();
    g.dfsTraversal();
}