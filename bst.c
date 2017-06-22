//Operations for a binary search tree


#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int key;
	struct Node *left, *right;


};
static int iteration =0 ;	//To count the number of iterations of search

//To create a new node
struct Node *newNode(struct Node *node,int k)		
{
	struct Node *new_node =(struct Node*)malloc(sizeof(struct Node));
	new_node->key = k;
	new_node->left = new_node->right = NULL;
	return(new_node);
}

//Inorder Traversal
void inorder(struct Node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);
}


//Minimum value 
struct Node *minValue(struct Node *node)
{
	struct Node *current = node; 
	
	while(current->left!=NULL)
		current = current->left;

	return current;
}

//Delete Node function
struct Node *deleteNode(struct Node *root, int key)
{
	if(root==NULL)
		return root;
	if(root->key<key)			//if key is greater than the root then follow the right path
		root->right = deleteNode(root->right,key);
	else if(root->key>key)			//if key is less than the root then follow the left path
		root->left = deleteNode(root->left,key);


	else
	{
		if(root->left == NULL)					//if the left is NULL the right node becomes the new root.
		{
			struct Node *temp = root->right;
			free(root);
			return temp;


		}

		else if(root->right == NULL)				//if the right is NULL the left node becomes the new root.
		{

			struct Node *temp = root->left;
			free(root);
			return temp;
		}


		struct Node *temp = minValue(root->right);	//we need value just greater than the node to be deleted, so the minimum value in the right subtree

		root->key = temp->key;
		

		root->right = deleteNode(root->right, temp->key);
	}
return root;
}


struct Node *insert(struct Node *node,int key)
{
	if(node==NULL)
		return newNode(node,key);

	if(key<node->key)			//if key is less than the current node's key then insert in the left 
		node->left = insert(node->left,key);

	else if(key>node->key)			//if key is more than the current node's key then insert in the right
		node->right = insert(node->right,key);
}



struct Node *search(struct Node *node, int key)
{	iteration++;
	if(node==NULL || node->key == key)		
		return node;
	else if(key>node->key)			//if the key is greater than the current node's key then search in right subtree
		return search(node->right,key);

	else if(key<node->key)			//if the key is less than the current node's key then search in left subtree
		return search(node->left,key);
}


int main()
{
	
	 /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 

	struct Node *temp = NULL;
	temp=search(root,70);
	printf("\n%d Found in %d iterations\n",temp->key,iteration);
	
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    return 0;
	
}
