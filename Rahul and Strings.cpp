/* NOT WORKING */



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
    string a, b;
    read(a, b);

    int nA = a.size(), nB = b.size();
    vi coords;

    string uA;
    FOR(nA) {
        if(a[i] >= 'A' && a[i] <= 'Z') {
            uA += a[i];
            coords.pb(i);
        }
    }

    coords.pb(nA);


    vt<string> tobefounds;

    int j = 0;
    for(int i = 0; i < nA; i++) {
        tobefounds.pb("");
        while(b[j] != uA[i]) {
            tobefounds[i] += b[j];

            j++;

            if(j == nB) {
                write('0');
                return;
            }

        }
    }

    tobefounds.pb("");

    for(; j < nB; j++) tobefounds[nA] += b[j];

    // chars to be found
    // substr in A
    // find all chars in order


    
    int aptr = 0;
    FOR(tobefounds.size()) {
        int tfptr = 0;

        tf = tobefounds[i];

        if(tf == "") continue;
        // lower tf
        tf.tolower();


        while(tfptr < tf.size()) {
            // find if tf is substr of A till some letter of uA
            while(a[aptr] != tf[tfptr]) {
                aptr++;

                if(aptr == coords[i]) {
                    write('0');
                    return;
                }
            }
            tfptr++;
        }

        aptr = coords[i]+1;
    }

    write('1');
}



int main()
{
    int testCases;
    cin >> testCases;
    
    FORVAR(testCases, testIndex) {
        ANS_DATA = "";
        solve();
        cout << ANS_DATA << endl;
    }
}