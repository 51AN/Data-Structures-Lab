#include<bits/stdc++.h>
#define ll                                               long long int
#define ektu_chalak_na_hole_duniya_te_tika_boroi_kothin  (ios::sync_with_stdio(0),cin.tie(0));
#define ekdin_to_ferot_jetei_hobe                        return 0;
#define nl                                                "\n"


using namespace std;


int main()
{
    ektu_chalak_na_hole_duniya_te_tika_boroi_kothin;

    
    vector<ll>v;
    ll x = 0;

    while(1)
    {
        cin>>x;
        if(x<=0)
        {
            break;
        }
        v.push_back(x);

    }
            
    ll f[1000]={0};

    for(int i = 0 ; i<v.size(); i++)
    {
        ++f[v[i]];
    }  
    
    vector<pair<ll,ll>>vect;

    for(int i = 0 ; i<1000 ; i++)
    {
     vect.push_back( make_pair(f[i],i) );   
    }

    sort(vect.begin(),vect.end());

    for(int i = 999 ; i>=0 ; i--)
    {
        if(vect[i].first!=0)
        {
            if(vect[i].first == 1)
                cout<<vect[i].second<<" occurs : "<<vect[i].first<<" time"<<nl;
            else
                cout<<vect[i].second<<" occurs : "<<vect[i].first<<" times"<<nl;

        }
    }

        
        
    

    ekdin_to_ferot_jetei_hobe;
}