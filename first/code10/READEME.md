题目描述
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees. 

Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST.  You are supposed to output the level order traversal sequence of that tree.  The sample is illustrated by Figure 1 and 2.




输入描述:
Each input file contains one test case.  For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree.  The next N lines each contains the left and the right children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, and 0 is always the root.  If one child is missing, then -1 will represent the NULL child pointer.  Finally N distinct integer keys are given in the last line.

