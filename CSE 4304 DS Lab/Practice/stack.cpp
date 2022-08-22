#include<bits/stdc++.h>
#define ll                                               long long int
#define ektu_chalak_na_hole_duniya_te_tika_boroi_kothin  (ios::sync_with_stdio(0),cin.tie(0));
#define ekdin_to_ferot_jetei_hobe                        return 0;
#define nl                                                "\n"

using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int Size;
    int Capacity;
    int *arr;
    Stack()
    {
        Size = 0;
        Capacity = 1;
        arr = new int[Capacity];
    }
    
    int Top()
    {

        if(empty())
        {
            cout<<"There are no elements "<<nl;
            return -1;
        }
        else
        {
            return arr[Size-1];
        }

    }

    void Push(int val)
    {
        if( Size == Capacity )
        {
            int *new_arr = new int[Capacity * 2];
            for(int i = 0 ; i < Size ; i++)
            {
                new_arr[i] = arr[i];
            }
            delete(arr);
            arr = new_arr;
            Capacity = 2 * Capacity;
        }
        arr[Size] = val;
        Size++;
    }

    int Get_Size()
    {
        return Size;
    }
    int Get_Capacity()
    {
        return Capacity;
    }
    void pop()
    {

        if(empty())
        {
            cout<<"There are no elements"<<nl;
        }
        else
        {
    
            arr[Size-1] = 0;
            Size -= 1;
            if((2*Size) == Capacity)
            {
                Capacity = Capacity/2;
            }
        }
    }

    bool empty()
    {
        if(Size == 0)
            return true;
            
        else
            return false;
    }


};


int main()
{
    Stack arr;

    arr.pop();
    arr.Top();

    arr.Push(0);
    cout<<"Val: "<< arr.Top() <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    arr.Push(1);
    cout<<"Val: "<< arr.Top() <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    arr.Push(2);
    cout<<"Val: "<< arr.Top() <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    arr.Push(3);
    cout<<"Val: "<< arr.Top() <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    arr.Push(4);
    cout<<"Val: "<< arr.Top() <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    arr.Push(5);
    cout<<"Val: "<< arr.Top() <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    arr.Push(6);
    cout<<"Val: "<< arr.Top() <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    arr.Push(7);
    cout<<"Val: "<< arr.Top() <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    arr.Push(8);
    cout<<"Val: "<< arr.Top() <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    

    arr.pop();
    cout<<"After pop"<<nl;
    cout<<"Val: "<< arr.Top() <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    cout<<"Val: "<< arr.Top() <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;

    



    // for(int i =0;i<16;i++)
    // {
    //     arr.Push(100 + i);
    //     cout <<"Val: "<< arr.Get(i) <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<< endl;
    // }

}