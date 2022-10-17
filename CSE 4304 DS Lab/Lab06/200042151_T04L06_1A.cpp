#include<bits/stdc++.h>
#define ll                                               long long int
#define fastIO  (ios::sync_with_stdio(0),cin.tie(0));
#define re                        return 0;
#define nl                                                "\n"
#define f(i,n)                                           for(int i = 0 ; i < n ; i ++)
#define f1(i,n)                                          for(int i = 1 ; i <= n ; i ++)
#define fb(i,n)                                          for(int i = n - 1 ; i => 0 ; i --)
#define v(i)                                             vector<int>v[i];
#define sortv(a)                                         sort(a.begin(),a.end())
#define test(t)                                          ll t; cin>>t; while(t--)
#define YES                                              cout<<"YES"<<endl
#define NO                                               cout<<"NO"<<endl


using namespace std;

class BST {
    
    struct node {
        int data;
        node* left;
        node* right;
        node* parent;
    };

    node* root;

    node* insert(int x, node* t)
    {

        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
            t->parent = NULL;
        }
     
        else if(x < t->data){

            node* leftChild = insert(x, t->left);
            t->left = leftChild;
            leftChild->parent = t;
            // t->left = insert(x, t->left);
            }
        else if(x > t->data){
            node* rightChild = insert(x, t->right);
            t->right = rightChild;
            rightChild->parent = t;
            // t->right = insert(x, t->right);
            }
        return t;
    }


    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

    int subtree_size(node* t){
            int x = 0;
            int y = 0 ;
            if(t != nullptr){
                x=subtree_size(t->left);
                y=subtree_size(t->right);
                return x + y + 1;
            }
            return 0;
        }

    int previous_reservations(node* t){
            int cnt = 0;
            cnt += subtree_size(t->left);
            while(t->parent != nullptr && t->parent->right == t){
                t = t->parent;
                cnt += (subtree_size(t->left) + 1);
            }
            return cnt;
        }

public:
    BST() {
        root = NULL;
    }


    void insert(int x) {
        root = insert(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    void search(int x) {
        root = find(root, x);
    }

    int reservations(int x){
        return previous_reservations(find(root,x));
    }
};
 





int main()
{
    fastIO;
    
    BST airLine;
    

    while(true){
        int x;
        cin>>x;
        if(x == -1){
            break;
        }
        airLine.insert(x);

    }

    test(t){
        int n;
        cin>>n;
        cout<<airLine.reservations(n)<<nl;
    }

    // airLine.display();

    re;
}