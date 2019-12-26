#include <bits/stdc++.h>
using namespace std;

vector<vector <pair<int, int>>> adj;
int ans = 0;
vector <int> bpath;
bool reach = 0;
int n, p, k;
int count = 0;
vector<vector<int>> adjmat;


int logic(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr[arr.size() - k - 1];
}

void analyzep(vector<int>& path)
{
    reach = 1;
    vector<int> pathe;
    for (int i = 0; i < path.size() - 1; i++) {
        pathe.push_back(adjmat[path[i]][path[i + 1]]);
    }
    if (bpath.empty() || path.size() == k) {
        bpath = pathe; return;
    }
    if (bpath.size() == k) return;
    int mbpath, mpath;
    mpath = logic(pathe);
    mbpath = logic(bpath);
    if (mpath < mbpath) bpath = pathe;
    ans = min(mbpath, mpath);
    return;
}

int notVisited(int x, vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return 0;
    return 1;
}

void findpaths(int start, int end)
{
    queue<vector<int> > q;
    vector<int> path;
    path.push_back(start);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];
        if (last == end) analyzep(path);
        for (int i = 0; i < adj[last].size(); i++) {
            if (notVisited(adj[last][i].first, path)) {
                vector<int> newpath(path);
                newpath.push_back(adj[last][i].first);
                q.push(newpath);
            }
        }
    }
}

int main(void) {
    cin >> n >> p >> k;
    adj.resize(n);
    adjmat.assign(n, vector<int>(n, 0));
    for (int i = 0; i < p; i++) {
        int a, b, w;
        cin >> a >> b >> w; a--; b--;
        adj[a].push_back({ b,w });
        adj[b].push_back({ a,w });
        adjmat[a][b] = w;
        adjmat[b][a] = w;
    }
    findpaths(0, n - 1);
    if (!reach) {
        cout << -1; return 0;
    }
    cout << ans;
}