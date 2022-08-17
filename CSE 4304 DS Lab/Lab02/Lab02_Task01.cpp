#include<bits/stdc++.h>
#define ll                                               long long int
#define ektu_chalak_na_hole_duniya_te_tika_boroi_kothin  (ios::sync_with_stdio(0),cin.tie(0));
#define ekdin_to_ferot_jetei_hobe                        return 0;
#define nl                                                "\n"


using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Dynamic_Array
{
public:
    int Size;
    int Capacity;
    int *arr;
    Dynamic_Array()
    {
        Size = 0;
        Capacity = 1;
        arr = new int[Capacity];
    }
    int Get(int i)
    {

        if ((i < 0 ) or (i >= Size))
        {
            cout << "Index out of Range" << endl;
            return -1;
        }
        return arr[i];

    }
    void Set(int i,int val)
    {
        if ((i < 0 ) or (i >= Size))
        {
            cout << " Index out of Range" << endl;
            return;
        }
        arr[i] = val;

    }
    void PushBack(int val)
    {
        if( Size == Capacity )
        {
            int *new_arr = new int(Capacity * 2);
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
    void Remove(int i)
    {
        if ((i < 0 ) or (i >= Size))
        {
            cout << "Index out of Range" << endl;
            
        }

        else
        {
            int j;
            for(j = i ; j < (Size - 1) ; j++)
            {
                arr[j] = arr[j+1]; 
            }
            arr[j+1] = 0;
            Size -= 1;
            
        }
        
    }


};


int main()
{
    Dynamic_Array arr;
    arr.PushBack(0);
    cout<<"Val: "<< arr.Get(0) <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    arr.PushBack(1);
    cout<<"Val: "<< arr.Get(1) <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    arr.PushBack(2);
    cout<<"Val: "<< arr.Get(2) <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;

    arr.Remove(1);
    cout<<"After remove"<<nl;
    cout<<"Val: "<< arr.Get(0) <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;
    cout<<"Val: "<< arr.Get(1) <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<<nl;



    // for(int i =0;i<16;i++)
    // {
    //     arr.PushBack(100 + i);
    //     cout <<"Val: "<< arr.Get(i) <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<< endl;
    // }

}