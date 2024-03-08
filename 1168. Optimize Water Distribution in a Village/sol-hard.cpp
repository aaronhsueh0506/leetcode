class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for(int i=1;i<=n;i++){
            pipes.push_back({0,i,wells[i-1]});
        }
        sort(pipes.begin(), pipes.end(), cmp);

        vector<int> root(n+1);
        for(int i=0; i<n+1; i++) root[i] = i;
        int res = 0;
        for(auto& pipe: pipes){
            int rx = find(root, pipe[0]), ry = find(root, pipe[1]);
            if(rx!=ry){
                root[ry] = rx;
                res += pipe[2];
                n--;
            }
            if(n==0) break;
        }
        return res;
    }

    int find(vector<int>& root, int i){
        return root[i] == i ? i : root[i]=find(root, root[i]);
    }

    static bool cmp(vector<int>& l1, vector<int>& l2){
        return l1[2]<l2[2];
    }
};
