#include <iostream>
using namespace std;
 
struct node
{
    int val;
    node* leftChild;
    node* rightChild;
};
 
class SplayTree
{
    public:
        SplayTree()
        {
        }
        // Zig(node rotates to the right)
        node* Zig_Right(node* node2)
        {
            node* node1 = node2->leftChild;
            node2->leftChild = node1->rightChild;
            node1->rightChild = node2;
            return node1;
        }
 
        // Zag(node rotates to the left)
        node* Zig_Left(node* node2)
        {
            node* node1 = node2->rightChild;
            node2->rightChild = node1->leftChild;
            node1->leftChild = node2;
            return node1;
        }
 
        // An implementation of top-down splay tree
        node* Splay(int val, node* root)
        {
            if (!root)
                return NULL;
            node head;
            // head.rightchild points to L tree; head.leftChild points to R Tree 
            head.leftChild = head.rightChild = NULL;
            node* LeftTreeMax = &head;
            node* RightTreeMin = &head;
            while (true)
            {
                if (val<root->val)
                {
                    if (!root->leftChild)
                        break;
                    if (val<root->leftChild->val)
                    {
                        root = Zig_Right(root);// One rotation of zig
                        if (!root->leftChild)
                            break;
                    }
                    // move to R Tree 
                    RightTreeMin->leftChild = root;
                    RightTreeMin = RightTreeMin->leftChild;
                    root = root->leftChild;
                    RightTreeMin->leftChild = NULL;
                }
                else if (val > root->val)
                {
                    if (!root->rightChild)
                        break;
                    if (val > root->rightChild->val)
                    {
                        root = Zig_Left(root);//one rotation of zag
                        if (!root->rightChild)
                            break;
                    }
                    // move to L Tree
                    LeftTreeMax->rightChild = root;
                    LeftTreeMax = LeftTreeMax->rightChild;
                    root = root->rightChild;
                    LeftTreeMax->rightChild = NULL;
                }
                else
                    break;
            }
            //organize the trees
            LeftTreeMax->rightChild = root->leftChild;
            RightTreeMin->leftChild = root->rightChild;
            root->leftChild = head.rightChild;
            root->rightChild = head.leftChild;
            return root;
        }
 
        node* New_Node(int val)
        {
            node* tempNode = new node;
            tempNode->val = val;
            tempNode->leftChild = tempNode->rightChild = NULL;
            return tempNode;
        }
 
        node* Insert(int val, node* root)
        {
            static node* tempNode = NULL;
            if (!tempNode)
                tempNode = New_Node(val);
            else
                tempNode->val = val;
            if (!root)
            {
                root = tempNode;
                tempNode = NULL;
                return root;
            }
            root = Splay(val, root);
            
            //BST operations here
            if (val<root->val)
            {
                tempNode->leftChild = root->leftChild;
                tempNode->rightChild = root;
                root->leftChild = NULL;
                root = tempNode;
            }
            else if (val > root->val)
            {
                tempNode->rightChild = root->rightChild;
                tempNode->leftChild = root;
                root->rightChild = NULL;
                root = tempNode;
            }
            else
                return root;
            tempNode = NULL;
            return root;
        }
 
        node* Delete(int val, node* root)
        {
            node* tempNode;
            if (!root)
                return NULL;
            root = Splay(val, root);
            if (val != root->val)
                return root;
            else
            {
                if (!root->leftChild)
                {
                    tempNode = root;
                    root = root->rightChild;
                }
                else
                {
                    tempNode = root;
                    root = Splay(val, root->leftChild);
                    root->rightChild = tempNode->rightChild;
                }
                delete(tempNode);
                return root;
            }
        }
 
        node* Search(int val, node* root)
        {
            return Splay(val, root);
        }
        //in order traversal
        void InOrder(node* root)
        {
            if (root)
            {
                InOrder(root->leftChild);
                cout<< root->val <<" ";
                InOrder(root->rightChild);
            }
        }
};
 
int main()
{
    SplayTree splay;
    int arr[4] = {7,6,15,14};
    int x, n;
    node *root = NULL;

    for(int i = 0; i<4 ; i++)
        root = splay.Insert(arr[i], root);

    while(true)
    {
        cout<<"\n(1) Insertion "<<endl;
        cout<<"(2) Search"<<endl;
        cout<<"(3) Deletion"<<endl;
        cout<<"(4) Display"<<endl;
        cout<<"(5) Exit"<<endl;
        cout<<"Enter operation to be done : ";
        cin>>n;
        switch(n)
        {
        case 1:
            cout<<"Enter insertion value : ";
            cin>>x;
            root = splay.Insert(x, root);
            cout<<"\nAfter Insertion: "<<endl;
            splay.InOrder(root);
            break;
        case 2:
            cout<<"Enter value to be searched: ";
            cin>>x;
            root = splay.Search(x, root);
            cout<<"\nAfter Search "<<endl;
            splay.InOrder(root);
            break;
        case 3:
            cout<<"Enter Deletion value : ";
            cin>>x;
            root = splay.Delete(x, root);
            cout<<"\nAfter Deleteion: "<<endl;
            splay.InOrder(root);
            break;
        case 4:
            cout<<"Displaying tree : \n";
            splay.InOrder(root);
            break;
        case 5:
            exit(true);
        default:
            cout<<"!--Unrecognized request--!";
        }
    }
    cout<<"\n";
    return 0;
}