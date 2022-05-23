import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

/*
 * @lc app=leetcode id=133 lang=java
 *
 * [133] Clone Graph
 */

// @lc code=start

// Definition for a Node.
// class Node {
//     public int val;
//     public List<Node> neighbors;
//     public Node() {
//         val = 0;
//         neighbors = new ArrayList<Node>();
//     }
//     public Node(int _val) {
//         val = _val;
//         neighbors = new ArrayList<Node>();
//     }
//     public Node(int _val, ArrayList<Node> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// }


class Solution {
    class Tuple {
        public Node a;
        public Node b;
        Tuple() {
            this.a = null;
            this.b = null;
        }
        Tuple(Node a, Node b) {
            this.a = a;
            this.b = b;
        }
    }
    public Node cloneGraph(Node node) {
        if(node == null) {
            return null;
        }
        Tuple[] queue = new Tuple[105];
        Node[] nodes = new Node[105];
        int head = 0, tail = 0;
        Node root = new Node(node.val);
        queue[head] = new Tuple(root, node);
        nodes[root.val] = root;
        while(head <= tail) {
            Node cloneNode = queue[head].a;
            Node originNode = queue[head].b;
            //System.out.println(cloneNode.val);
            ++head;
            for(Node childNode : originNode.neighbors) {
                Node cloneChildNode;
                if(nodes[childNode.val] != null) {
                    cloneChildNode = nodes[childNode.val];
                }
                else {
                    cloneChildNode = new Node(childNode.val);
                    nodes[cloneChildNode.val] = cloneChildNode;
                    queue[++tail] = new Tuple(cloneChildNode, childNode);
                }
                cloneNode.neighbors.add(cloneChildNode);
            }
        }
        return root;
    }
}
// @lc code=end

