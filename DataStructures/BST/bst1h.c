typedef struct treenode
{
        int data;
        struct treenode*left,*right;
}bst;
bst *root=NULL,*temp;
bst *insert(bst*,int);
void inorder(bst*);
void preorder(bst*);
void postorder(bst*);
bst *delete(bst*,int);
int search(bst*,int);
bst *findmin(bst*);
bst *findmax(bst*);