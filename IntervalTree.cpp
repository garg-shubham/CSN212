#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> Interval

struct node
{
	int low,high,max;
	node* left_child,right_child;
}
node* first, temp ;

node * insert(node* root,Interval i)
{
	// Base Case
	if(root == NULL)
	{
		root = new node();
		root -> low = i.F;
		root -> high = i.S;
		root -> left_child = NULL;
		root -> right_child = NULL;
	}
	else if(i.F < root-> low)
	{
		root -> left_child = insert(root -> left_child,i);
	}
	else
	{
		root -> right = insert(root -> right_child , i);
	}
	if(root -> max < i.S)
		root -> max = i.S;

	return root;
}


int main()
{

}