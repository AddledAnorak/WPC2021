/* INCOMPLETE!! */


#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>

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




void addToMap(string s, unordered_map<string, vt<string>>& mp, string val) {
    if(mp.find(s) == mp.end()) {
        mp[s] = vt<string>{val};
    }
    else {
        mp[s].pb(val);
    }
}

bool checkAndAddToMap(string s, unordered_map<string, string>& vals, string val, unordered_map<string, vt<string>>& vars, unordered_map<string, bool>& vis) {
    vis[s] = 1;

    if(vals.find(s) == vals.end()) {
        vals[s] = val;
    } else {
        if(vals[s] != val) return 0;
    }

    bool ret;
    EACH(var, vars[s]) {
        if(vis.find(var) == vis.end()) {
            ret = checkAndAddToMap(var, vals, val, vars, vis);
        }

        if(!ret) return 0;
    }

    return 1;
}

bool isNum(string s) {
    EACH(c, s) {
        if(c < '0' || c > '9') return 0;
    }

    return 1;
}

void solve() {
    unordered_map<string, vt<string>> vars;
    unordered_map<string, string> vals;

    int n;
    read(n);

    vt<string> s1, s2;
    string dummy;
    FOR(n) {
        read(dummy);
        s1.pb(dummy);
    }
    FOR(n) {
        read(dummy);
        s2.pb(dummy);
    }

    
    FOR(n) {
        if(s1[i] == s2[i]) continue;

        if(!isNum(s1[i]) && !isNum(s2[i])) {
            addToMap(s1[i], vars, s2[i]);
            addToMap(s2[i], vars, s1[i]);
        }

        else if(!isNum(s1[i]) && isNum(s2[i])) {

            bool ret = checkAndAddToMap(s1[i], vals, s2[i], vars, unordered_map<string, bool>{});
            e.clear();
            if(!ret) {
                write("false");
                return;
            }

        }

        else if(isNum(s1[i]) && !isNum(s2[i])) {

            bool ret = checkAndAddToMap(s2[i], vals, s1[i], vars, unordered_map<string, bool>{});
            e.clear();
            if(!ret) {
                write("false");
                return;
            }

        }

         else {
            if(s1[i] != s2[i]) {
                write("false");
                return;
            }
         }
    }

    write("true");
}



int main()
{
    ANS_DATA = "";
    solve();
    cout << ANS_DATA << endl;
}