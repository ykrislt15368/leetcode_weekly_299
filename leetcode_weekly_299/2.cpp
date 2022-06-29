//1-Dp checks with previos states i.e are 
//if space before state 
//if home before to before state
//Add up and multiply for combinations

class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    int countHousePlacements(int n) {
        ll sp=1;
        ll hs=1;
        ll tt=sp+hs;
        for(ll i=2;i<=n;i++)
        {
            hs=sp;
            sp=tt;
            tt=(hs+sp)%mod;
            
        }
        return (tt*tt)%mod;
    }
};
