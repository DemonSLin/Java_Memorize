package www.lsl.com.july;

public class Solution {
        StringBuilder SB=new StringBuilder();
        public String tree2str(TestBinaryTree.TreeNode t) {
            if(t==null)
                return "";
            help(t);
            return SB.toString();
        }
        private void help(TestBinaryTree.TreeNode t){
            if(t==null)
                return;
            if(t.left==null && t.right==null)
                SB.append(t.val);
            else if(t.right==null){
                SB.append(t.val).append("(");
                help(t.left);
                SB.append(")");
            }
            else
            {
                SB.append(t.val).append("(");
                help(t.left);
                SB.append(")(");
                help(t.right);
                SB.append(")");
            }
        }
}
