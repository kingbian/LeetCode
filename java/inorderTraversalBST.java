import com.sun.source.tree.Tree;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
public class inorderTraversalBST {

    public static void main(String[] args) {

        TreeNode root = new TreeNode(20);
        root.left = new TreeNode(10);
        root.right = new TreeNode(30);
        root.left.left = new TreeNode(5);
        root.left.right = new TreeNode(15);

        /*
                20
             10     30
           5   15

         */


        for (int i : inorderTraversal( root)){
            System.out.print(i+ " ");
        }



    }

   static public List<Integer> inorderTraversal( TreeNode root) {
       List<Integer> list = new ArrayList<>();
       Stack<TreeNode> stack = new Stack<>();


       TreeNode current = root;

       while (current !=null || !stack.isEmpty()){

           while ( current != null){// go through the left subtree until no node
               stack.push(current);
               current = current.left;
           }

           current = stack.pop(); // get the current value;
           list.add(current.val); //add to the list

           current= current.right;// go through the right subtree


       }

        return list;

    }
}
