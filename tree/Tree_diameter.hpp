/*
   @brief:Tree-Diameter
   author:Kiffaz
*/
template<typename T> struct tree_diameter {
    struct Edge {
        int to;
        T weight;
    };

    int n;
    std::vector<std::vector<Edge>> adj;

    tree_diameter(int size) : n(size), adj(size) {}

    void add_edge(int s, int t, T w, bool use_weight) {
        if (use_weight) {
            adj[s].push_back(Edge{t, w});
            adj[t].push_back(Edge{s, w});
        } else {
            adj[s].push_back(Edge{t, 1}); 
            adj[t].push_back(Edge{s, 1});
        }
    }

    std::pair<T, int> dfs(int v, int parent) {
        T max_dist = 0;
        int farthest_node = v;
        for (auto& edge : adj[v]) {
            if (edge.to != parent) {
                auto sub = dfs(edge.to, v);
                T dist = sub.first + edge.weight;
                if (dist > max_dist) {
                    max_dist = dist;
                    farthest_node = sub.second;
                }
            }
        }
        return {max_dist, farthest_node};
    }

    std::pair<T, std::vector<int>> get_diameter() {
        auto [_, first_farthest] = dfs(0, -1); 
        auto [max_dist, second_farthest] = dfs(first_farthest, -1); 

        std::vector<int> path;
        std::vector<bool> visited(n, false);
        std::function<bool(int, int)> find_path = [&](int current, int target) -> bool {
            visited[current] = true;
            path.push_back(current);
            if (current == target) return true;
            for (auto& edge : adj[current]) {
                if (!visited[edge.to] && find_path(edge.to, target)) {
                    return true;
                }
            }
            path.pop_back();
            return false;
        };

        find_path(second_farthest, first_farthest);

        return {max_dist, path};
    }
};
