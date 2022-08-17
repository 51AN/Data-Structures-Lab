#include<bits/stdc++.h>
#define ll                                               long long int
#define ektu_chalak_na_hole_duniya_te_tika_boroi_kothin  (ios::sync_with_stdio(0),cin.tie(0));
#define ekdin_to_ferot_jetei_hobe                        return 0;
#define nl                                                "\n"


using namespace std;

ll fact(ll n) 
{
  if(n > 1)
    return n * fact(n - 1);
  else
    return 1;
}

int main()
{
    ektu_chalak_na_hole_duniya_te_tika_boroi_kothin;

    ll n;

    cin>>n;

    cout<<fact(n);

    ekdin_to_ferot_jetei_hobe;
}



