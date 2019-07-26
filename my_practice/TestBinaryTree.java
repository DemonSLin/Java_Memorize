package www.lsl.com.july;

import sun.reflect.generics.tree.Tree;

public class TestBinaryTree {
    class TreeNode{
        char val;
        TreeNode left;//存储左孩子的引用
        TreeNode right;//存储右孩子的引用
        public TreeNode(char val){
            this.val=val;
            this.left=null;
            this.right=null;
        }
    }
    //根据字符串创建二叉树 ABC##DE#G##F###
    public int i=0;//遍历字符串
    TreeNode createTestTree(String s){
        TreeNode root=null;
        if(s.charAt(i)!='#'){
            root=new TreeNode(s.charAt(i));
            i++;
            root.left=createTestTree(s);
            root.right=createTestTree(s);
        }else{
            i++;
        }
        return root;
    }
    // 结点个数
    int getSize(TreeNode root){
        if(root==null){
            return 0;
        }
        return getSize(root.left)+getSize(root.right)+1;
    }
    // 叶子结点个数
    int getLeafSize(TreeNode root){
        if(root==null){
            return 0;
        }
        if(root.left==null&&root.right==null){
            return 1;
        }
        return getLeafSize(root.left)+getLeafSize(root.right);
    }
    // 第 k 层结点个数
    int getKLevelSize(TreeNode root, int k){
        if(k==1){
            return 1;
        }
        if(k==0){
            return 0;
        }
        return getKLevelSize(root.left,k-1)
                +getKLevelSize(root.right,k-1);
    }
    // 查找，依次在二叉树的 根、左子树、右子树 中查找 value，
    // 如果找到，返回结点，否则返回 null
    TreeNode find(TreeNode root, int value){
        
        return null;
    }
    //二叉树的高度
    int height(TreeNode root){
        if(root==null){
           return 0;
        }else{
            int leftHeight=height(root.left);
            int rightHeight=height(root.right);
            return(leftHeight>rightHeight?leftHeight:rightHeight)+1;
        }

        /*return Math.max(height(root.left),height(root.right))+1;*/
    }
    void binaryTreePrevOrder(TreeNode root){
    if(root==null){

        return;
    }
    System.out.print(root.val+" ");
    binaryTreePrevOrder(root.left);
    binaryTreePrevOrder(root.right);
    }
    //二叉树的中序遍历
    void binaryTreeInOrder(TreeNode root){
        if(root==null){
            return;
        }
        binaryTreePrevOrder(root.left);
        System.out.println(root.val+" ");
        binaryTreePrevOrder(root.right);
    }
    //二叉树的后序遍历
    void binaryTreePostOrder(TreeNode root){
        if(root==null){
            return;
        }
        binaryTreePrevOrder(root.left);
        binaryTreePrevOrder(root.right);
        System.out.println(root.val+" ");
    }
    //二叉树的前序遍历非递归
    void binaryTreePrevOrderNonR(TreeNode root){

    }
    //二叉树的中序遍历非递归
    void binaryTreeInOrderNonR(TreeNode root){

    }
    //二叉树的后序遍历非递归
    void binaryTreePostOrderNonR(TreeNode root){

    }
    //二叉树的层序遍历
    void binaryTreeLevelOrder(TreeNode root){

    }
}
