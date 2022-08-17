#include<bits/stdc++.h>
#define ll                                               long long int
#define ektu_chalak_na_hole_duniya_te_tika_boroi_kothin  (ios::sync_with_stdio(0),cin.tie(0));
#define ekdin_to_ferot_jetei_hobe                        return 0;
#define nl                                                "\n"


using namespace std;


int main()
{
    ektu_chalak_na_hole_duniya_te_tika_boroi_kothin;

    int v[1000] = {0};
    int i = 0, high =0;
    while(1)
    {

        int x;
        cin>>x;
        if(x<0)
        {
            high = i;

            break;

        }
        v[i] = x;
        ++i;
    }

    int n;
    cin>>n;
    
    int low = 0,  index = 0;
    bool foundIndex = false;
    while (low <= high) 
    {
    int mid = low + (high - low) / 2;

    if (v[mid] == n)
      {
        index = mid;
        foundIndex = true;
      }


    if (v[mid] < n)
      low = mid + 1;

    else
      high = mid - 1;
    }


    if(!foundIndex)
    {
        index = -1;
    }
        
    cout<<index;
    

    ekdin_to_ferot_jetei_hobe;
}