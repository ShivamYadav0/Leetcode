class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
          // Creating adjacency list
        std::vector<std::pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            // Adding adjacent nodes and their corresponding success probabilities to the adjacency list
            adj[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            adj[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }

        // Use maxHeap for path with the maximum probability
        std::priority_queue<std::pair<double, int>> pq;
        pq.push({ 1.0, start }); // {probability, node}

        // Store the maximum probability of reaching each node from the starting node
        std::vector<double> dist(n, INT_MIN);
        dist[start] = 1;

        // Dijkstra's algorithm
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            double probability = current.first;
            int node = current.second;

            // Check adjacent nodes
            for (auto neighbor : adj[node]) {
                int adjNode = neighbor.first;
                double edgeWeight = neighbor.second;

                // If a greater probability is found, update the probability of the adjacent node
                if (dist[adjNode] < probability * edgeWeight) {
                    dist[adjNode] = probability * edgeWeight;
                    pq.push({ dist[adjNode], adjNode });
                }
            }
        }

        // If there is no path from start to end, return 0.00000
        if (dist[end] == INT_MIN) {
            return 0.00000;
        } else {
            // Return the maximum probability of reaching the target node
            return dist[end];
        }
    }
};