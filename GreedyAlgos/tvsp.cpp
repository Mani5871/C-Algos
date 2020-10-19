#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int num, dis;
    Node *left, *right;
};

Node *root, *ptr, *ptr1;
int delta, cnt, n;

struct Node* create(int num, int dis)
{
    ptr = new Node();
    ptr -> num = num;
    ptr -> dis = dis;
    ptr -> left = ptr -> right = NULL;
    return ptr;
}

void insert(int parent, int num, int dis)
{
   
    if(root == NULL)
    {
        Node *temp = create(num, dis);
        root = temp;
        return;
    }
   
    queue <struct Node*> q;
    q.push(root);
   
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
       
        if(temp -> left != NULL)
        {
            q.push(temp -> left);
        }

        if(temp -> num == parent)
        {
            if(temp -> left == NULL)
            {
                temp -> left = create(num, dis);
                return;
            }
            if(temp -> right == NULL)
            {
                temp -> right = create(num, dis);
                return;
            }
        }
        if(temp -> right != NULL)
        {
            q.push(temp -> right);
        }
    }
}

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

void tvsp(Node *root)
{
    int delay;
   
    if(!root)
        return;
    if(root -> left)
        tvsp (root -> left);
    if(root -> right)
        tvsp (root -> right);
 
    int max1;
   
   
    if(root -> left == NULL && root -> right != NULL)
        max1 = root -> right -> dis;
       
    else if(root -> right == NULL && root -> left != NULL)
        max1 = root -> left -> dis;
       
    else if(root -> left != NULL && root -> right != NULL)
    {
        max1 = max (root -> left -> dis, root -> right -> dis);
    }
       
    else if(root -> left == NULL && root -> right == NULL)
    {
        max1 = 0;
        delay = 0;
        goto l;
    }
   
    delay = max1 + root -> dis;
    l: int i = 1;
   
    cout << " Delay of " << root -> num << " is " << delay << endl;
     
    if(delay > delta)
    {
        cnt++;
        cout<<"Booster has to be placed at node "<<root -> dis<<endl;
    }
    else
        root -> dis = max(delay, root -> dis);
}

int main()
{
    int flag = 1;
    while(flag)
    {
        //printf("Enter node number\n");
        int num, parent, distance;
        cin>>num;
       
        //printf("Enter parent node\n");
        cin>>parent;
       
        //printf("Enter distance from parent node\n");
        cin>>distance;
       
        insert(parent, num, distance);
       
        //printf("Enter 1 to insert node or 0 to quit\n");
        cin>>flag;
       
        n++;
       
    }
    //printf("Enter threshold value\n");
    cin>>delta;
    tvsp(root);
    cout<<cnt<<" Boosters are required";
}

