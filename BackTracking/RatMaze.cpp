#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    if(x <= n && y <= n && arr[x][y] == 1)
        return true;
    return false;
}

bool Rat(int **arr, int x, int y, int **sol, int n)
{
    if(x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        return true;
    }
        
    if(isSafe(arr, x, y, n))
    {
        sol[x][y] = 1;
        
        if(Rat(arr, x, y + 1, sol, n))
            return true;
            
        if(Rat(arr, x + 1, y, sol, n))
            return true;
        
        sol[x][y] = 0;
        return false;
    }
    
}

int main()
{
    int n;
    cin >> n;
    
    int i, j, k;
    
    int ** a = new int *[n];
    
    for(i = 0; i < n; i ++)
    {
        a[i] = new int[n];
    }
    
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            cin >> a[i][j];
    
    int ** sol = new int *[n];
    
    for(i = 0; i < n; i ++)
    {
        sol[i] = new int[n];
    }    
    
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            sol[i][j] = 0;
    
    if(Rat(a, 0, 0, sol, n))
    {
        cout << "Rat Escaped" << endl;
        
        for(i = 0; i < n; i ++)
        {
            for(j = 0; j < n; j ++)
                cout<<sol[i][j] << " ";
            cout << endl << " ";
        }
        
    }
    else
        cout <<"Rat not escaped" << endl;
}

