
public class GraphNode {
    public int key;
    public List<GraphNode> neighbors;

    public GraphNode(int key) {
        this.key = key;
        this.neighbors = new ArrayList<GraphNode>();
    }
}

public class Solution {
    public boolean isBipartite(List<GraphNode> graph) {
        if (graph.size() == 0) {
            return true;
        }
        Map<GraphNode, Integer> map = new HashMap<>();
        for (GraphNode node : graph) {
            Queue<GraphNode> queue = new LinkedList<>();
            if (!map.containsKey(node)) {
                queue.offer(node);
                map.put(node, 0);
            } else {
                continue;
            }
            while (!queue.isEmpty()) {
                GraphNode temp = queue.poll();
                int color = map.get(temp);
                for (GraphNode neib : temp.neighbors) {
                    if (!map.containsKey(neib)) {
                        map.put(neib, color == 0 ? 1 : 0);
                        queue.offer(neib);
                    } else if (map.get(neib) == color) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}