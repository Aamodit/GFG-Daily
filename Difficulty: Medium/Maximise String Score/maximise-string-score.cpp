class Solution {
public:
    int solve(int ind,string &s,vector<vector<int>> &adj,
              vector<int> &pref,vector<vector<int>> &nextPos,vector<int> &dp) {

        if(ind==s.size()-1){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }

        int best=0;
        int curr=s[ind]-'a';

        // try every reachable target character
        for (int targetChar:adj[curr]){
            
            int jumpInd=nextPos[ind][targetChar - 'a'];
            
            if(jumpInd==-1){
                continue;
            }

            int gain;
            if (targetChar == s[ind]){
                // jump to same character → ignore its own ASCII
                gain=pref[jumpInd]-pref[ind+1];
            } 
            else{
                // jump to different character
                gain=pref[jumpInd]-pref[ind];
            }

            gain+=solve(jumpInd,s,adj,pref,nextPos,dp);
            best=max(best,gain);
        }

        return dp[ind]=best;
    }

    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n=s.size();

        // allow self jumps for all characters
        for(char c = 'a'; c <= 'z'; c++){
            jumps.push_back({c, c});
        }
            

        // next index of each character from every index
        vector<vector<int>> nextPos(n,vector<int>(26, -1));
        vector<int> last(26, -1);
        
        for(int i=n-1;i>=0;i--){
            for(int c=0;c<26;c++){
                nextPos[i][c]=last[c];
            }
                
            last[s[i]-'a']=i;
        }

        // adjacency list for valid transitions char → char
        vector<vector<int>> adj(26);
        
        for (auto &p:jumps) {
            adj[p[0]-'a'].push_back(p[1]);
        }

        // prefix sum of ASCII values of characters
        vector<int> pref(n+1,0);
        for (int i=0;i<n; i++){
            pref[i+1]=pref[i]+s[i];
        }
            

        vector<int> dp(n, -1);
        return solve(0,s,adj,pref,nextPos,dp);
        
    }
};