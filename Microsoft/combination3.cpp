class Solution {
public:
    void solve(int &sum, int level, int k, int n, vector<vector<int>> &ans, vector<int> &ds, int idx){
        
        if(level==k){
            if(sum==n){
                ans.push_back(ds);
            }
            return;
        }

        for(int i=idx; i<=9; i++){
            sum+=i;
            ds.push_back(i);
            solve(sum, level+1, k, n, ans, ds, i+1);
            sum-=i;
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        int sum=0;
        solve(sum, 0, k, n, ans, ds, 1);
        return ans;
    }
};