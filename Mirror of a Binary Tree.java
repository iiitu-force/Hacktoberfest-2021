//Mirror of a Binary Tree

public class Main {

    static class node
    {
        int value;
        node left;
        node right;
    }

   static node createNode(int value)
   {
       node newNode=new node();
       newNode.value=value;
       newNode.left= null;
       newNode.right=null;
       return newNode;

   }

   static void inorder(node root)
   {
     if(root==null)
     {
         return;
     }

     //left root right

       inorder(root.left);
       System.out.print(" "+root.value);
       inorder(root.right);


   }

   static node mirrorify(node root)
   {

     if(root==null)
     {
         return null;
     }

   //create new mirror node from original tree node
      node mirrorNode=createNode(root.value);
      mirrorNode.right=mirrorify(root.left);
      mirrorNode.left=mirrorify(root.right);
      return mirrorNode;

   }

    public static void main(String[] args) {

        node tree=createNode(1);
        tree.right=createNode(3);
        tree.left=createNode(2);
        tree.left.left=createNode(4);
        tree.left.right=createNode(5);

        //Inorder of Original Tree
        System.out.print("Inorder of Original Tree:");
        inorder(tree);

        node mirror=null;
        mirror=mirrorify(tree);

        System.out.print("\nMirror of Original Tree:");
        inorder(mirror);

    }
}