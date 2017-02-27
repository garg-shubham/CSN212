# Interval tree implemented using BST

The BST class contains the following functions:

## insert(node* root,Interval i)
    Inserts an interval in the tree rooted at this node. Returns node.
## OverlapCheck(int x,int y, Interval i)
    Checks whether interval [x,y] & interval i overlap or not. Returns bool.
## SearchInterval(node *root,Interval i)
    Searchs in tree rooted at this node whether interval i overlaps with any node or not.
## display(node *root)
    Inorder traversal of tree.
## LeftMostNode( node *root)
    Returns left most node of tree rooted at node 'root'.
##  Update_MAX_Value(node *root)
    Updates Max value of every node in tree rooted at this node.
## DeleteInterval(node *root ,Interval i)
    Deletes node with Interval i from tree rooted at node 'root' (if exists).
