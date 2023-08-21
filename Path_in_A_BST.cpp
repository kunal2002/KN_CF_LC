Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
	if(root == NULL)
		return NULL;
	if(root->data == data)
	{
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	vector<int>* left = getPath(root->left , data);
	if(left != NULL)
	{
		left->push_back(root->data);
		return left;
	}
	vector<int>* right = getPath(root->right, data);
	if(right != NULL)
	{
		right->push_back(root->data);
		return right;
	}
	return NULL;
}
