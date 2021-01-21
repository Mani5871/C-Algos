#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int lli;
unordered_map<lli, lli> arr;

lli fib(lli n)
{
    auto it = arr.find(n);
    
    if(it != arr.end())
        return arr[n];
    
    if(n <= 2)
        return 1;
    
    arr[n] = fib(n - 1) + fib(n - 2);
    
    return arr[n];
}


int main() {
    
    cout << fib(50) << endl; 
}