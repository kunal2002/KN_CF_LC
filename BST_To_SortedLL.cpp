Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
	if(root == NULL) {
		return NULL;
	}
	Node<int>* left = constructLinkedList(root->left);
	Node<int>* temp = left;
	Node<int>* rootNode = new Node<int>(root->data);
	if(temp != NULL) {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = rootNode;
	}
	rootNode->next = constructLinkedList(root->right);
	if(left != NULL) return left;
	else return rootNode;
}
