#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
unordered_map<lli, bool> map1;

bool canSum(vector<lli>arr, lli n)
{
   
    if(n == 0)
        return true;
        
    auto it = map1.find(n);
    
    if(it != map1.end())
        return map1[n];
        
    for(lli i = 0; i != arr.size(); i ++)
    {
        lli j = n - arr[i];
        if(j >= 0)
            if(canSum(arr, j))
            {
                map1[n] = true;
                return true;
            }
                
    }
    
    map1[n] = false;
    
    return false;
}


int main() {
    
    vector<lli>arr = {1, 2, 3};
    
    cout << canSum({2}, 5) << endl;
    
}