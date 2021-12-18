import java.sql.ShardingKey;
import java.util.Stack;

/*
 * @lc app=leetcode id=385 lang=java
 *
 * [385] Mini Parser
 */

// @lc code=start
/* *
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *		 // Constructor initializes an empty nested list.
 *		 public NestedInteger();
 *
 *		 // Constructor initializes a single integer.
 *		 public NestedInteger(int value);
 *
 *		 // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *		 public boolean isInteger();
 *
 *		 // @return the single integer that this NestedInteger holds, if it holds a single integer
 *		 // Return null if this NestedInteger holds a nested list
 *		 public Integer getInteger();
 *
 *		 // Set this NestedInteger to hold a single integer.
 *		 public void setInteger(int value);
 *
 *		 // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *		 public void add(NestedInteger ni);
 *
 *		 // @return the nested list that this NestedInteger holds, if it holds a nested list
 *		 // Return empty list if this NestedInteger holds a single integer
 *		 public List<NestedInteger> getList();
 * }
 */
class Solution {

	public NestedInteger deserialize(String s) {
		Stack<NestedInteger> stack = new Stack<>();
		if (s.charAt(0) != '[') {
			return new NestedInteger(Integer.parseInt(s));
		}

		int index = 0;
		while (index < s.length()) {
			if (s.charAt(index) == '[') {
				NestedInteger next = new NestedInteger();
				stack.push(next);
				index++;
			} else if (s.charAt(index) == ']') {
				NestedInteger top = stack.pop();
				if (stack.size() > 0) {
					NestedInteger cur = stack.peek();
					cur.add(top);
				} else {
					return top;
				}
                index++;
			} else if (isNumberBegin(s.charAt(index))) {
				NestedInteger cur = stack.peek();
				int sign = 1;
				if (s.charAt(index) == '-') {
					sign = -1;
					index++;
				}
				int singleValue = 0;
				while (s.charAt(index) >= '0' && s.charAt(index) <= '9') {
					singleValue = singleValue * 10 + s.charAt(index++) - '0';
				}
				cur.add(new NestedInteger(sign * singleValue));

			}
            else {
                index++;
            }
		}
		return null;
	}

	private static boolean isNumberBegin(char ch) {
		if (ch == '-') {
			return true;
		}
		if (ch >= '0' && ch <= '9') {
			return true;
		}
		return false;
	}
}
// @lc code=end
