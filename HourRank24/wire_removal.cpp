#include <bits/stdc++.h>

using namespace std;

struct Node {
	int node_num;
	int distance;
	int num_children;
	vector<Node> other_nodes;
};

bool* visited;
long long current_depth = -1;
long double sum_distances = 0;

int dfs(Node adj_list[],int node) {
	int num_children = 1;
	++current_depth;
	visited[node] = true;
	adj_list[node].distance = current_depth;
	sum_distances += current_depth;
	for(int i = 0; i < adj_list[node].other_nodes.size(); ++i) {
		if(visited[adj_list[node].other_nodes[i].node_num] == false)
			num_children += dfs(adj_list,adj_list[node].other_nodes[i].node_num);
	}
	adj_list[node].num_children = num_children-1;
	--current_depth;
	return num_children;
}

int main() {
    int n;
    cin >> n;
	
	Node adj_list[n+1]; //1 indexed adjacency list
	visited = new bool[n+1];
	for (int i=0; i<n+1; ++i)
		visited[i] = false;

    for(int a0 = 0; a0 < n-1; a0++){
        int x;
        int y;
        cin >> x >> y;
		Node Nx = {x,0,0};
		Node Ny = {y,0,0};
		adj_list[x].other_nodes.push_back(Ny);
		adj_list[y].other_nodes.push_back(Nx);
    }
	dfs(adj_list,1);

	double expected_connected = 0;
	for(int i = 1; i <= n; ++i) {
		expected_connected += adj_list[i].distance / double(sum_distances) * (adj_list[i].num_children+1);
	}
	expected_connected = n - expected_connected;
	printf("%f", expected_connected);

    return 0;
}
