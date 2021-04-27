
public class TreeNode {
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

class Solution {
    int[] preorder;
    int[] inorder;
    
    TreeNode work(int l1, int r1, int l2, int r2){
        //System.out.println(l1 + " " + r1 + " " + l2 + " " + r2);
        if(r1 <= l1 || r2 <= l2) return null;
        TreeNode cur = new TreeNode(preorder[l1]);
        if(l1 + 1 == r1) return cur;
        int x = l2;
        for(int i = l2; i <  r2; i++){
            if(inorder[i] == preorder[l1]){
                x = i;
                break;
            }
        }
        cur.left = work(l1 + 1, l1 + 1 + x - l2, l2, x);
        cur.right = work(l1 + 1 + x - l2, r1, x + 1, r2);
        return cur;
    }
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length == 0) return null;
        this.preorder = preorder;
        this.inorder = inorder;
        
        return work(0, preorder.length, 0, inorder.length);
    }
}