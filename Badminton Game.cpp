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



void solve() {
    int v, n;

    read(v);
    vi vScores(v);
    FOR(v) {
        read(vScores[i]);
    }

    read(n);
    vi nScores(n);
    FOR(n) {
        read(nScores[i]);
    }

    int totalScoreBeforeFirstHalf = 0;
    EACH(t, vScores) if(t <= 1440) totalScoreBeforeFirstHalf++;
    EACH(t, nScores) if(t <= 1440) totalScoreBeforeFirstHalf++;

    write(totalScoreBeforeFirstHalf, '\n');

    int t1, t2;
    int i = 0, j = 0;

    vi relChanges;
    int relScores = 0;
    int prevSign = 0;

    while(i < v || j < n) {
        t1 = i < v? vScores[i] : 4000;
        t2 = j < n? nScores[j] : 4000;

        if(t1 < t2) {
            relChanges.pb(1);
            i++;
        } else {
            relChanges.pb(-1);
            j++;
        }
    }

    prevSign = relChanges[0];
    int comebacks = 0;

    EACH(change, relChanges) {
        relScores += change;

        if(relScores * prevSign < 0) {
            comebacks++;
            prevSign *= -1;
        }
    }

    write(comebacks);
}



int main()
{
    ANS_DATA = "";
    solve();
    cout << ANS_DATA << endl;
}