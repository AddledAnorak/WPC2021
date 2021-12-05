/* CHECK THIS CODE!  COULD BE SPACING ISSUE */




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
#define FORVAR(var, n) for(int var = 0; var < n; var++)
#define EACH(var, list_) for (auto& var: list_)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define W '.'
#define L 'X'

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


/* CHECK THIS CODE!  COULD BE SPACING ISSUE */
char futureSeas(int i, int j, int r, int c, vt<vt<char>>& grid) {
    int numSeas = 0;

    if(i == 0 || i == r-1) numSeas++;
    else {
        if(grid[i-1][j] == W) numSeas++;
        if(grid[i+1][j] == W) numSeas++;
    }

    if(j == 0 || j == c-1) numSeas++;
    else {
        if(grid[i][j-1] == W) numSeas++;
        if(grid[i][j+1] == W) numSeas++;
    }

    return numSeas >= 3? W : L;
}

/* CHECK THIS CODE!  COULD BE SPACING ISSUE */
void solve() {
    int r, c;
    read(r, c);

    vt<vt<char>> grid(r, vt<char>(c));
    FOR(r) {
        read(grid[i]);
    }

    vt<vt<char>> ans(r, vt<char>(c));

    FOR(r) {
        FORVAR(j, c) {
            if(grid[i][j] == W) {
                ans[i][j] = W;
                continue;
            }

            ans[i][j] = futureSeas(i, j, r, c, grid);
        }
    }


    int minR = r, maxR = 0;
    int minC = c, maxC = 0;


    // getting minR and maxR
    for(int i = 0; i < r; i++) {
        if(ans[i] == vt<char>(c, W)) continue;
        minR = i;
        break;
    }

    for(int i = r-1; i >= 0; i--) {
        if(ans[i] == vt<char>(c, W)) continue;
        maxR = i;
        break;
    }





    // getting minC and maxC
    for(int i = minR; i <= maxR; i++) {


        for(int j = 0; j < c; j++) {
            if(ans[i][j] == L) {
                minC = min(minC, j);
                break;
            }
        }

        for(int j = c-1; j >= 0; j--) {
            if(ans[i][j] == L) {
                maxC = max(maxC, j);
                break;
            }
        }

    }

/* CHECK THIS CODE!  COULD BE SPACING ISSUE */

    // output-ing
    for(int i = minR; i < maxR; i++) {
        for(int j = minC; j <= maxC; j++) {
            write(ans[i][j]);
        }
        write('\n');
    }
    for(int j = minC; j <= maxC; j++) {
        write(ans[maxR][j]);
    }

}


/* CHECK THIS CODE!  COULD BE SPACING ISSUE */
int main()
{
    ANS_DATA = "";
    solve();
    cout << ANS_DATA << endl;
}


