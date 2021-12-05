#include <bits/stdc++.h>
#include <string>
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>

#define vi vector<int>
#define vvi vector<vector<int>>
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()


vi dfs(int a, int b, vt<bool>& vis, unordered_map<int, vi> mp) {
    vis[a] = 1;
    if(a == b) return vi{b};

    vi neighbours = mp[a];
    for(int neighbour : neighbours) {
        if(!vis[neighbour]) {

            vi latterList = dfs(neighbour, b, vis, mp);
            if(latterList.size() == 1) return vi{};

            vi nodeList;
            nodeList.reserve(1 + latterList.size());
            nodeList.insert(nodeList.end(), all(vi{a}));
            nodeList.insert(nodeList.end(), all(latterList));

            return nodeList;
        }
    }

    return vi{};
}


vi reverseFunction(vi nodes, vi& height) {
    vi selectedHeights;
    for(int i = 0; i < nodes.size(); i++) {
        selectedHeights.pb(height[nodes[i] - 1]);
    }

    reverse(all(selectedHeights));

    for(int i = 0; i < selectedHeights.size(); i++) {
        height[nodes[i] - 1] = selectedHeights[i];
    }
}

vi treeQuery(int n, int q, vvi& edges, vi& height, vvi& queries) {
    unordered_map<int, vi> mp;
    vi finalVt;

    for(vi edge : edges) {
        if(mp.find(edge[0]) == mp.end()) {
            mp[edge[0]] = vi{edge[1]};
        } else {
            mp[edge[0]].pb(edge[1]);
        }

        if(mp.find(edge[1]) == mp.end()) {
            mp[edge[1]] = vi{edge[0]};
        } else {
            mp[edge[1]].pb(edge[0]);
        }
    }

    for(vi q : queries) {
        if(q[0] == 1) {
            reverseFunction(dfs(q[1], q[2], vt<bool>(n+1, 0), mp), height);
        }
        else {
            vi path = dfs(q[1], q[2], vt<bool>(n+1, 0), mp);
            int sum = 0;
            for(int i = 0; i < path.size(); i++) {
                sum += height[path[i]];
            }
            finalVt.pb(sum);
        }
    }

    return finalVt;
}