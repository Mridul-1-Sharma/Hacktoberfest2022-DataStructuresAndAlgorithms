// Problem name: Phase Shift
// Problem link: https://codeforces.com/contest/1735/problem/C


#include<bits/stdc++.h>
using namespace std;
int t, n, poz, i;
char s[100005];
bool taken[35];
unordered_map<char, char> M;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    //t = 1;
    while(t --)
    {
        memset(taken, false, sizeof(taken));
        M.clear();
        cin >> n;
        poz = 0;
        for(i = 1; i <= n; i ++)
        {
            cin >> s[i];
            if(M.find(s[i]) == M.end())
            {
                for(poz = 0; poz < 26; poz ++)
                    if(taken[poz] == false && char(97 + poz) != s[i])
                    {
                        bool ok = true;
                        int ct = 0;
                        char aux = char(97 + poz);
                        while(M.find(aux) != M.end())
                        {
                            ct ++;
                            if(ct == 25)
                                break;
                            aux = M[aux];
                            if(aux == s[i])
                            {
                                ok = false;
                                break;
                            }
                        }
                        if(ok == false)
                            continue;
                        taken[poz] = true;
                        M[s[i]] = char(97 + poz);
                        break;
                    }
            }
            cout << M[s[i]];
        }
        cout << "\n";
    }
    return 0;
}