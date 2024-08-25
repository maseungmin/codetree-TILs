#include <bits/stdc++.h>

using namespace std;

int q,n,m,t,start;
bool checkId[30001];
int dist[2001];

struct edgeInfo
{
    int u;
    int w;
};

vector<edgeInfo>edge[2001];

struct packageInfo
{
    int id;
    int revenue;
    int dest;
    int cost;
};

struct Cmp1 {
    bool operator()(edgeInfo a, edgeInfo b) {
        return a.w > b.w;
    }
};

struct Cmp2 {
    bool operator()(packageInfo a, packageInfo b) {
        if (a.cost != b.cost)return a.cost < b.cost;
        return a.id > b.id;
    }
};

priority_queue<packageInfo,vector<packageInfo>,Cmp2>packages;


void dijkstra()
{
    for(int i=0; i<2001; i++)
    {
        dist[i] = INT_MAX;

    }
    dist[start] = 0;
    priority_queue<edgeInfo,vector<edgeInfo>,Cmp1>pq;
    pq.push({ start,0 });
    while (!pq.empty()) {
        edgeInfo now = pq.top();
        pq.pop();
        for (int i = 0; i < edge[now.u].size(); i++) {
            edgeInfo next = edge[now.u][i];
            if (dist[next.u] <= dist[now.u] + next.w)continue;
            pq.push(next);
            dist[next.u] = dist[now.u] + next.w;
        }
    }


}

void input()
{
    cin >> q;
    while(q--)
    {
        cin >> t;
        if(t==100)
        {
            int v,u,w;
            cin >> n >> m;
            for(int i=0; i<m; i++)
            {
                cin >> v >> u >> w;
                edge[v].push_back({u,w});
                edge[u].push_back({v,w});
            }
            dijkstra();

        }
        if(t==200)
        {
            int id, revenue, dest, cost;
            cin >> id >> revenue >> dest;
            if(dist[dest]==INT_MAX)
            {
                cost = -1;
            }
            else
            {
                cost = revenue - dist[dest];
            }
            packages.push({ id,revenue,dest,cost });
            checkId[id] = true;
        }
        if(t==300)
        {
            int id;
            cin >> id;
            checkId[id]=false;
        }
        if(t==400)
        {
            if(packages.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                while (!packages.empty()) {
                    packageInfo now = packages.top();
                    if (!checkId[now.id]) {
                        packages.pop();
                    }
                    else {
                        break;
                    }
                }
                if (packages.empty()) {
                    cout << -1 << '\n';
                    continue;
                }
                packageInfo now = packages.top();
                if (now.cost < 0) {
                    cout << -1 << '\n';
                }
                else {
                    packages.pop();
                    checkId[now.id] = false;
                    cout << now.id<<'\n';
                }      
            }
        }
        if(t==500)
        {
            cin >> start;
            dijkstra();
            priority_queue<packageInfo, vector<packageInfo>, Cmp2>temp;
            while (!packages.empty()) {
                packageInfo now = packages.top();
                packages.pop();
                if (!checkId[now.id])continue;
                temp.push(now);
            }
            while (!temp.empty()) {
                packageInfo now = temp.top();
                int cost = 0;
                int dest = now.dest;
                int revenue = now.revenue;
                if (dist[dest] == INT_MAX) {
                    cost = -1;
                }
                else {
                    cost = revenue - dist[dest];
                }
                now.cost = cost;
                packages.push(now);
                temp.pop();
            }
        }
    }
}


int main()
{
    input();
}