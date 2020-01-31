class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // initialize variables
        minLen = INT_MAX;
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        count.resize(n);

        // build graph
        buildGraph(edges);
        
        // test graph: below method tests whether the graph is constructed successfully
        //testGraph();
        
        for(int i = 0; i < n; i++)
            dijistra(i, n, distanceThreshold);
        
        // cout << "minLen: " << minLen << endl;
        // for(int i = 0; i < n; i++)
        //     cout << count[i] << endl;
        
        for(int i = n-1; i >= 0; i--)
            if(count[i] == minLen)
                return i;
        
        return -1;
    }
    
private:
    unordered_map<int, unordered_map<int, int>> graph;
    vector<int> count;
    int minLen;

    
    void testGraph() {
        for(auto& m : graph) {
            cout << "source: " << m.first << endl;
            for(auto& neighbor : m.second)
                cout << "[" << neighbor.first << ", " << neighbor.second << "]" << ", ";
            cout << endl;
        }
    }
    
    void buildGraph(vector<vector<int>>& edges) {
        for(auto& e : edges) {
            graph[e[0]][e[1]] = e[2];
            graph[e[1]][e[0]] = e[2];
        }
    }
    
    void dijistra(int source, int n, int threshold) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, source}); // this line caused the bug: variable source not hard-coded 0
        vector<int> dis(n, INT_MAX);
        dis[source] = 0;
        int num = 0;
        
        while(!pq.empty()) {
            auto u = pq.top().second; // cause bug without .second
            pq.pop();
            
            for(auto& nei : graph[u]) {
                int v = nei.first;
                int weight = nei.second;
                
                if(dis[u] != INT_MAX && dis[v] > dis[u] + weight) {
                    dis[v] = dis[u] + weight;
                    pq.push({dis[v], v});
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(dis[i] != 0 && dis[i] <= threshold)
                num++;
        }
        
        //cout << "num: " << num << endl;
        minLen = min(minLen, num);
        count[source] = num;
    }
};
