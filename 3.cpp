//Kadanes algorithm for max subarray 
//Here we need to check max subarray swap and 
//that need to be add in array sum


class Solution {
public:
    int fun(vector<int>& n1,vector<int>& n2)
    {
        int sm=accumulate(n1.begin(),n1.end(),0);
        int rnsm=0;
        int cumax=0;
        int n=n1.size();
        
        for(int i=0;i<n;i++)
        {
            rnsm+=(n2[i]-n1[i]);
            if(rnsm<0) rnsm=0;
            cumax=max(cumax,rnsm);
            
        }
        return sm+cumax;
    }
    int maximumsSplicedArray(vector<int>& n1, vector<int>& n2) {
        return max(fun(n1,n2),fun(n2,n1));
        
    }
};
