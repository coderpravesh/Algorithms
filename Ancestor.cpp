class TreeAncestor {
    vector<vector<int>> up;
    int LOG = 20;
public:

    TreeAncestor(int n, vector<int>& parent) {
        up = vector<vector<int>> (n, vector<int> (LOG, -1));
        for (int j = 0; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (!j) {
                    up[i][j] = parent[i];
                } else {
                    if (up[i][j-1] == -1) continue; 
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                node = up[node][i];
                k -= 1 << i;
            }

            if (node == -1 || !k) {
                return node;
            }
        }
        return node;
    }
};