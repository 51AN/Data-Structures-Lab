#include<bits/stdc++.h>
#define ll                                               long long int
#define ektu_chalak_na_hole_duniya_te_tika_boroi_kothin  (ios::sync_with_stdio(0),cin.tie(0));
#define ekdin_to_ferot_jetei_hobe                        return 0;
#define nl                                                "\n"

using namespace std;

struct node
{
    int val;
    node * next;
};

class Singly_linked_list{
public:
    node *head, *tail;

    Singly_linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void PushBack(int n)
    {
        node *tmp = new node;
        tmp->val = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            node* addTemp = head;
            while (addTemp->next != NULL)
            {
                addTemp = addTemp->next;
            }
            addTemp->next = tmp;
        }

    }

    void display()
    {
        node *cur = head;

        while(cur != nullptr)
        {
            cout << cur->val << nl;
            cur = cur->next;
        }
        cout<<endl;
    }

    void Reverse()
    {
        
        node *current, * prev, * next;
        current = head;
        prev = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        

    }


    void Pop_front(node *&head)
    {
        if(head == nullptr)
        {
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
        
    }


    void show_second_half()
    {
        node *fast = head, *slow = head;

        while(fast != nullptr)
        {

            fast = fast->next;
            if(fast == nullptr)
                break;
            fast = fast->next;

            slow = slow->next;

        }

        head = slow;

    }



};







int main()
{
    Singly_linked_list a;
    
    int n,val;
    cout<<"Enter the length of linked list"<<nl;
    cin>>n;

    for(int i = 0; i<n; i++ )
    {
        cin>>val;
        a.PushBack(val);
    }
    
    a.show_second_half();

    a.display();




}