#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
unordered_map<lli, lli> map1;
vector<lli> ans;
lli cnt;

lli howSum(vector<lli>arr, lli n, lli k)
{
   
    if(n == 0)
    {
        cnt ++;
        map1[n] = cnt;
        return map1[n];
    }
    
    auto it = map1.find(n);
    
    if(it != map1.end())
        return map1[n];
    
        
    for(lli i = k; i != arr.size(); i ++)
    {
        lli j = n - arr[i];
        if(j >= 0)
            howSum(arr, j, i);
    }
}

int main() {
    
    vector<lli>arr = {1, 2, 3};
    
    howSum({2, 4}, 6, 0);
    cout << cnt << endl;
    
    cnt = 0;
    map1.clear();
    
    howSum({1, 2, 3}, 4, 0);
    cout << cnt << endl;
    
    cnt = 0;
    map1.clear();
    
    howSum({2, 3, 5, 6}, 10, 0);
    cout << cnt << endl;
}