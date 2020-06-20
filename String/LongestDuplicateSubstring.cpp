#include <bits/stdc++.h>
#define p 10000007
int pre[100003];

using namespace std;

int isValid(string s, int len)
{
    map <int, vector <int> > m;
    int h = 0;

    for (int i = 0; i < len; i++) {
        h = (h*26 + (s[i]-'a')) % p;
    }

    m[h].push_back(0);

    for (int i = len; i < s.length(); i++) {
        h = ((h - pre[len-1] * (s[i-len]-'a')) % p + p)%p;
        h = (h*26 + (s[i]-'a')) % p;

        if (m.find(h) != m.end()) {
            for (int j = 0; j < m[h].size(); j++) {
                string temp = s.substr(m[h][j], len);
                string curr = s.substr(i-len+1, len);

                if (temp.compare(curr) == 0) {
                    return i-len+1;
                }
            }
        }

        m[h].push_back(i-len+1);
    }

    return -1;
}

string longestDupSubstring(string s)
{
    if (s.length() == 0) {
        return "";
    }

    pre[0] = 1;

    for (int i = 1; i < s.length(); i++) {
        pre[i] = (26 * pre[i-1]) % p;
    }

    int lo = 1, hi = s.length();
    string ans = "";

    while (lo <= hi) {
        int mid = (lo+hi) / 2;
        int start = isValid(s, mid);

        if (start > 0) {

            if (mid > ans.length()) {
                ans = s.substr(start, mid);
            }

            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }

    return ans;
}

int main()
{
    string s = "banana";
    cout<<longestDupSubstring(s)<<endl;

    return 0;
}
