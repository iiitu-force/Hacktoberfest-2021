import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class TreeSort {


    class Node
    {
        int key;
        Node left, right;

        public Node(int item)
        {
            key = item;
            left = right = null;
        }
    }

    // Root of BST
    Node root;

    // Constructor
    TreeSort()
    {
        root = null;
    }

    // This method mainly
    // calls insertRec()
    void insert(int key)
    {
        root = insertRec(root, key);
    }

    /* A recursive function to
    insert a new key in BST */
    Node insertRec(Node root, int key)
    {

        /* If the tree is empty,
        return a new node */
        if (root == null)
        {
            root = new Node(key);
            return root;
        }

        /* Otherwise, recur
        down the tree */
        if (key < root.key)
            root.left = insertRec(root.left, key);
        else if (key > root.key)
            root.right = insertRec(root.right, key);

        /* return the root */
        return root;
    }

    // A function to do
    // inorder traversal of BST
    void inorderRec(Node root)
    {
        if (root != null)
        {
            inorderRec(root.left);
            System.out.print(root.key + " ");
            inorderRec(root.right);
        }
    }
    void treeins(int arr[])
    {
        for(int i = 0; i < arr.length; i++)
        {
            insert(arr[i]);
        }

    }

    // Driver Code
    public static void main(String[] args) {
        TreeSort tree = new TreeSort();
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        int[] arr = new int[t];
        for (int k = 0; k < t; k++) {
            arr[k]=sc.nextInt();
        }
        tree.treeins(arr);
        tree.inorderRec(tree.root);
    }

    //Fast Reader Class
    static class FastReader {
        BufferedReader reader;
        StringTokenizer mStringTokenizer;

        public FastReader() {
            reader = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (mStringTokenizer == null || !mStringTokenizer.hasMoreElements()) {
                try {
                    mStringTokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return mStringTokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}


