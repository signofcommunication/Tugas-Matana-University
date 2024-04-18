#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

struct Neighbor {
  int vertex;
  int weight;
};

class Graph {
public:
  int V;
  std::vector<std::vector<Neighbor>> adjList;

  Graph(int V) : V(V), adjList(V) {}

  void addEdge(int u, int v, int weight) {
    adjList[u].push_back({v, weight});
  }

  std::vector<int> dijkstra(int source) {
    std::vector<int> distance(V, INF);
    std::vector<bool> visited(V, false);

    distance[source] = 0;

    for (int count = 0; count < V - 1; count++) {
      int u = minDistance(distance, visited);

      visited[u] = true;

      for (auto neighbor : adjList[u]) {
        int v = neighbor.vertex;
        int weight = neighbor.weight;

        if (!visited[v] && distance[u] != INF && distance[u] + weight < distance[v]) {
          distance[v] = distance[u] + weight;
        }
      }
    }

    return distance;
  }

private:
  int minDistance(const std::vector<int>& distance, const std::vector<bool>& visited) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
      if (!visited[v] && distance[v] <= min) {
        min = distance[v];
        min_index = v;
      }
    }

    return min_index;
  }
};

int main() {
  int V = 9;
  Graph graph(V);

  graph.addEdge(0, 1, 4);
  graph.addEdge(0, 7, 8);
  graph.addEdge(1, 2, 8);
  graph.addEdge(1, 7, 11);

  int source = 0;

  std::vector<int> distance = graph.dijkstra(source);

  for (int i = 0; i < V; i++) {
    std::cout << "Jarak dari " << source << " ke " << i << " adalah "
              << distance[i] << std::endl;
  }

  return 0;
}
