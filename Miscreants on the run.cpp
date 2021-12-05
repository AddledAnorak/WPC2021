/* TLE */


#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <stack>

using namespace std;

#define FOR(n) for(int i = 0; i < n; i++)
#define FORVAR(n, var) for(int var = 0; var < n; var++)
#define EACH(var, list_) for (auto& var: list_)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
string ANS_DATA = "";


// to_string
string to_string(char c) {
    return string(1, c);
}

string to_string(bool b) {
	return b ? "true":"false";
}

string to_string(const char* s) {
	return string(s);
}

string to_string(string s) {
	return s;
}


// write
template<class T> void write(T data) {
    ANS_DATA += to_string(data);
}

template<class T> void write(vt<T> vec) {
    EACH(data, vec) {
        write(data);
        write(' ');
    }
}

template<class A, class B> void write(map<A, B> mp) {
    EACH(data, mp) {
        write("<" + to_string(data.first) + "," + to_string(data.second) + ">");
    }
}

template<class T, class... Rest>
void write(T first, Rest... rest) {
    write(first);
    write(' ');
    write(rest...);
}



// read
template<class T> void read(T& var) {
    cin >> var;
}

template<class T> void read(vt<T>& vec) {
    EACH(item, vec) {
        read(item);
    }
}

template<class T, class... Rest>
void read(T& first, Rest&... rest) {
    read(first);
    read(rest...);
}


// MAX
template<class T> T MAX(T first) {
    return first;
}

template<class T> T MAX(vt<T> nums) {
    return *max_element(all(nums));
}

template<class T, class... Rest>
T MAX(T first, Rest... rest) {
    return max(first, MAX(rest...));
}


// MIN
template<class T> T MIN(T first) {
    return first;
}

template<class T> T MIN(vt<T> nums) {
    return *min_element(all(nums));
}

template<class T, class... Rest>
T MIN(T first, Rest... rest) {
    return min(first, MAX(rest...));
}




/* TLE */

bool dfs(int a, int b, int n, unordered_map<int, vi>& stairs) {
    vi vis(n+1, 0);
    stack<int> s;
    s.push(a);
    int curr;

    while(!s.empty()) {
        curr = s.top();
        s.pop();

        if(curr == b) return 1;
        vis[curr] = 1;

        for(int num : stairs[curr]) {
            if(vis[num] == 0) 
                s.push(num);
        }
    }

    return 0;
}

bool type1(int a, int b, int p, int q, unordered_map<int, vi> stairs, int n) {
    stairs[p].erase(remove(all(stairs[p]), q), stairs[p].end());
    stairs[q].erase(remove(all(stairs[q]), p), stairs[q].end());

    return dfs(a, b, n, stairs);
}

bool type2(int a, int b, int c, unordered_map<int, vi> stairs, int n) {
    stairs[c].clear();

    return dfs(a, b, n, stairs);
}

void solve() {
    /* TLE */
    
    int n, e;
    read(n, e);

    unordered_map<int, vi> stairs;

    int a, b;
    FOR(e) {
        read(a, b);

        if(stairs.find(a) == stairs.end()) {
            stairs[a] = vi{b};
        } else stairs[a].pb(b);

        if(stairs.find(b) == stairs.end()) {
            stairs[b] = vi{a};
        } else stairs[b].pb(a);
    }

    int Q, c, p, q, type;
    read(Q);

    FOR(Q) {
        read(type);
        if(type == 1) {
            read(a, b, p, q);
            write(type1(a, b, p, q, stairs, n)? "yes" : "no");
        }
        else {
            read(a, b, c);
            write(type2(a, b, c, stairs, n)? "yes" : "no");
        }

        write('\n');
    }
}


/* TLE */
int main()
{
    ANS_DATA = "";
    solve();
    cout << ANS_DATA << endl;
}