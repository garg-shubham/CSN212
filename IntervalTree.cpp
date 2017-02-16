#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair

typedef pair<int,int> Interval;


struct node
{
	int low,high,MAX;		// lower bound, upper bound and max of subtree
	node *left_child , *right_child;
};

node *first, *temp ;

node * insert(node* root,Interval i)
{
	// If sub tree is empty
	if(root == NULL)
	{
		root = new node();
		root -> low = i.F;
		root -> high = i.S;
		root -> left_child = NULL;
		root -> right_child = NULL;
	}
	//

	//inserting with lower bound of interval as key for BST
	else if(i.F < root-> low)
	{
		root -> left_child = insert(root -> left_child,i);
	}
	else
	{
		root -> right_child = insert(root -> right_child , i);
	}
	//

	// Updating Max Value
	if(root -> MAX < i.S)
		root -> MAX = i.S;
	//

	return root;
}

bool OverlapCheck(int x,int y, Interval i)
{
	// Check if interval [x,y] and i overlap or not
	if(x <= i.S && i.F <= y)
		return true;
	return false;
}

void SearchInterval(node *root,Interval i)
{
	// If subtree is empty i.e. whole tree has been searched
	if(root == NULL)
	{
		cout<<"Interval Overlap not found\n";
		return;
	}
	//

	// Checking if Overlap is found at root node
	if (OverlapCheck(root ->low , root -> high, i))
	{
		cout<<"Overlap found at ["<<root -> low<<","<<root -> high<<"]\n";
		return;
	}
	//

	//else find which subtree to travrerse next
	if (root -> left_child != NULL)
	{
		if(root -> left_child -> MAX >= i.F)
			SearchInterval(root -> left_child, i);
		return;
	}

	SearchInterval(root -> right_child, i);
	return;
}

void display(node *root)
{
	if(root == NULL)
		return;

	//inorder traversal for display

	display(root -> left_child);
	cout<<"["<<root->low <<","<< root -> high <<"] Max:"<<root->MAX<<"\n";
	display(root -> right_child);

	//
}

//for finding left most node in a subtree
node * LeftMostNode( node *root)
{
	node *temp2;
	temp2 = root;
	while(temp2 -> left_child != NULL)
		temp2 = temp2 -> left_child;
	return temp2;
}

// Needed to be done after deletion
void Update_MAX_Value(node *root)
{
	if(root ==NULL)
		return;
	
	Update_MAX_Value(root -> left_child);
	Update_MAX_Value(root -> right_child);

	// MAX is max(leftchild max, rightchild max, root high)
	// writing max function on the basis of which of these three exist
	if(root -> right_child !=NULL)
	{
		if(root -> left_child != NULL)
			root -> MAX = max(root -> left_child -> MAX, max(root -> right_child -> MAX, root -> high));
		else
			root -> MAX = max(root -> right_child -> MAX , root -> high);
	}
	else
	{
		if( root -> left_child != NULL)
			root -> MAX = max(root -> left_child -> MAX , root -> high);
		else
			root -> MAX = root -> high;
	}
	//
	return;
}

node * DeleteInterval(node *root ,Interval i)
{
	// if Interval does not exist in tree
	if(root ==NULL)
		return root;
	
	if(i.F < root -> low)
		root -> left_child = DeleteInterval(root-> left_child , i);
	
	else if (i.F > root -> low)
		root -> right_child = DeleteInterval(root -> right_child , i);

	// if all the above conditions are false so current node is the interval
	else
	{
		// if only child exists
		if( root -> left_child == NULL)
		{
			temp = root -> right_child;
			root = NULL;
			return temp;
		}

		else if (root -> right_child == NULL)
		{
			temp = root -> left_child;
			root = NULL;
			return temp;
		}
		//

		//else
		temp = LeftMostNode(root -> right_child);
		root -> low = temp -> low;
		root -> high = temp -> high;
		
		// making pair to pass in DeleteInterval function
		Interval mp;
		mp.F = temp -> low;
		mp.S = temp -> high;
		//

		root -> right_child = DeleteInterval(root -> right_child, mp);

		// Updating MAX 
		Update_MAX_Value(root);
		//

		return root;
	}
}

int main()
{
	// initial conditon for tree
	first =NULL;
	//
	Interval p;
 
	first = insert(first , MP(15,20));
	first = insert(first , MP(10,30));
	first = insert(first , MP(17,19));
	first = insert(first , MP(5,20));
	first = insert(first , MP(12,15));
	first = insert(first , MP(30,40));

	display(first);
	cout<<"Search interval (14,16)"<<"\n";
	
	p.F = 14;
	p.S = 16;
	SearchInterval(first , p);
	cout<<"Search interval (21,23)\n";
	p.F = 21;
	p.S = 23;
	SearchInterval(first , p);

	cout<<"Enter Inerval to Delete\n";
	cin>>p.F>>p.S;
	DeleteInterval(first , p);
	cout<<"Inorder display:\n";
	display(first);
	return 0;
}