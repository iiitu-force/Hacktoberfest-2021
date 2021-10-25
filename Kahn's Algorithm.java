// A Java program to print Topological order using Kahn's Algorithm

import java.util.*;

class Graph {

    int V;

    List<Integer> adj[];

    public Graph(int V)
    {
        this.V = V;
        adj = new ArrayList[V];
        for (int i = 0; i < V; i++)
            adj[i] = new ArrayList<Integer>();
    }

    public void addEdge(int u, int v)
    {
        adj[u].add(v);
    }

    public void topologicalSort()
    {

        int indegree[] = new int[V];

        for (int i = 0; i < V; i++) {
            ArrayList<Integer> temp
                    = (ArrayList<Integer>)adj[i];
            for (int node : temp) {
                indegree[node]++;
            }
        }

        Queue<Integer> q
                = new LinkedList<Integer>();
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.add(i);
        }

        int count = 0;

        LinkedList<Integer> topological_Order = new LinkedList<Integer>();
        while (!q.isEmpty()) {

            int u = q.poll();
            topological_Order.add(u);


            for (int node : adj[u]) {
              
                if (--indegree[node] == 0)
                    q.add(node);
            }
            count++;
        }

        if (count != V) {
            System.out.println("There is a cycle in the graph");
            return;
        }

       
        for (int i : topological_Order) {
            System.out.print(i + " ");
        }
    }
}

class Main {
    public static void main(String args[])
    {
      
        Graph g = new Graph(6);
        g.addEdge(5, 2);
        g.addEdge(5, 0);
        g.addEdge(4, 0);
        g.addEdge(4, 1);
        g.addEdge(2, 3);
        g.addEdge(3, 1);

        System.out.println("Topological Sort :- ");
        g.topologicalSort();
    }
}