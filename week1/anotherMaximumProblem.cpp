#include<bits/stdc++.h>

using namespace std;
#define ll long long int

int main(){
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
    }
    map < ll , ll > m;
    ll large_left[n];
    ll large_right[n];
    stack < ll > s;
    s.push(0);
    large_left[0] = -1;
    ll i = 1;
    while(i < n)
    {
        while(!s.empty() && a[s.top()] < a[i])
        s.pop();

        if(!s.empty())
        large_left[i] = s.top();
        else
        large_left[i] = -1;
        s.push(i);
        i++;
    }
    while(!s.empty())
    s.pop();
    s.push( n - 1);
    large_right[n - 1] = n;
    i = n - 2;
    while(i >= 0)
    {
        while(!s.empty() && a[s.top()] <= a[i])
        s.pop();

        if(!s.empty())
        large_right[i] = s.top();
        else
        large_right[i] = n;

        s.push(i);
        i--;

    }
    while(!s.empty())
    s.pop();
    for(int i =0 ; i < n ; i ++)
    {
        if(m.find(a[i]) == m.end())
        {
            m[a[i]] = ( i - large_left[i]) * (large_right[i] - i);
        }
        else{
            m[a[i]] += ( i - large_left[i]) * (
                large_right[i] - i);
        }
    }
    int t;
    cin >> t;
    while( t-- )
    {
        ll x;
        cin >> x;
        cout << m[x] << endl;
    }

}
