class Solution {
public:
    // Time Complexity:- O((V+E)^2)
    // Space Complexity:- O(V)
    void FindSubtreeXor(int v, int p, vector <int> adj[], vector <int>& subtreeXor){
        for(auto& u : adj[v]){
            if(u != p){
                FindSubtreeXor(u, v, adj, subtreeXor);
                //Computing every node as root from 0 as root node 
                subtreeXor[v] ^= subtreeXor[u];
            }
        }
    }
    
    int Calculate(int v, int p, vector <int> adj[], vector <int>& nums, int totalXor, int firstXor, int& ans){
        int subtreeXor = nums[v];
         //Edge Between Rooot node of component 2 and Component1 already removed so verify this edge is not included for all posibilities  in Component 1   
        for(auto& u : adj[v]){
            if(u != p){
                int childXor = Calculate(u, v, adj, nums, totalXor, firstXor, ans);
                
                subtreeXor ^= childXor;
                
                int secondXor = childXor, thirdXor = totalXor ^ secondXor;
                ans = min(ans, max({firstXor, secondXor, thirdXor}) - min({firstXor, secondXor, thirdXor}));                
            }
        }
        
        return subtreeXor;
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), ans = INT_MAX;
        
        queue <int> q;
        vector <int> adj[n], vis(n), subtreeXor(nums.begin(), nums.end());
         //trees xors with initial values
         
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        FindSubtreeXor(0, -1, adj, subtreeXor);
        // Computing treexor values of evry node as 0 as root node of entire tree
        
        q.push(0); // Bfs from root node 
        vis[0] = 1;
        //We have remove every one edge its result in two components 
        //then from one component cross over with every combination of other component
        //We have n-1 edges so n-1 components i.e these n-1 components are cross over with every possibility of anther component.
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            for(auto& u : adj[v]){
                if(!vis[u]){    //This statement helps in not reconsidering checked edge again
                    q.push(u);
                    vis[u] = 1;
                    
                    // keep subtree rooted at u as it is
                    int rem = subtreeXor[0] ^ subtreeXor[u];
                    
                    
                    //Total xor is xor of another component removing this children node as root node  componenet
                    int xo = Calculate(v, u, adj, nums, rem, subtreeXor[u], ans);
                    // Function cheking break edge in another component acheived by dfs
				}
            }
        }
        
        return ans;   
    }
};
