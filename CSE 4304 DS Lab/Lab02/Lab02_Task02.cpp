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
    int *Get_array()
    {
        return arr;
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
            if((2*Size) == Capacity)
            {
                int *new_arr = new int[Capacity / 2];
                for(int i = 0 ; i < Size ; i++)
                {
                    new_arr[i] = arr[i];
                }
                delete(arr);
                arr = new_arr;
                Capacity = Capacity/2;
            }
            
        }
        
    }


};


int *digits(Dynamic_Array arr)
{
    bool carry = false;
    for(int i = (arr.Get_Size() - 1 ); i >= 0 ; i-- )
    {
        int sum = 0;
        sum = arr.Get(i);
        if(i == (arr.Get_Size() - 1 ))
        {
            sum += 1;
        }
        if(carry)
        {
            sum += 1;
            carry = false;
        }
        if(sum > 9)
        {
            
            carry = true;
            if(i == 0)
                arr.Set(i,1);
            else
                arr.Set(i,0);

        }



        else
        {
            arr.Set(i,sum);
           
            
            break;
        }

    }
    if(carry)
    {
        arr.PushBack(0);
    }
    arr.PushBack(-1);
    return arr.Get_array();

}

int main()
{
    Dynamic_Array arr;

    cout<<"Number of digits : "<<nl;
    int size = 0 ;
    cin>>size;
    int x = 0 ;
    for(int i = 0 ; i<size ; i++)
    {
        
        cin>>x;
        arr.PushBack(x);
    }

    int *new_a = digits(arr);

    for(int i = 0 ;  ; i++)
    {
        if(new_a[i] == -1)
        {
            break;
        }
        cout<< new_a[i] << " ";
        
    }

    

    

}