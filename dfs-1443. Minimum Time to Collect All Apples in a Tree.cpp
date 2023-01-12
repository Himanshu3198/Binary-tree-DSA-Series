class Solution
{
    public:
    set<vector < int>> vis;
    vector<int> solve(unordered_map<int, vector < int>> &tree, vector< bool > &apple, int node)
    {

        int count = 0, has = 0;
        for (auto &g: tree[node])
        {
            vector<int> t = { g,node};
            sort(t.begin(), t.end());
            if (vis.count(t)) continue;
            vis.insert(t);
            vector<int> v = solve(tree, apple, g);;
            if (v[0] == 1)
            {
                has = 1;
                count += (2 + v[1]);
            }
        }
        if (apple[node])
            has = 1;
        return {has,count};
    }
    int minTime(int n, vector<vector < int>> &edges, vector< bool > &hasApple)
    {

        unordered_map<int, vector < int>> tree;
        for (auto it: edges)
        {
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }

        vector<int> res = solve(tree, hasApple, 0);
        return res[1];
    }
};
