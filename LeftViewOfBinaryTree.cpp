vector<int> leftView(Node *root)
{
   // Your code here
   if(!root)    return {};
   queue<Node*> q;
   q.push(root);
   vector<int> ans;
   while(!q.empty())
   {
        int sz = q.size();
        for(int i = 0; i < sz; i++)
        {
            Node* node = q.front();
            q.pop();
            if(i == 0)
                ans.push_back(node->data);
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        } 
   }
   return ans;
}
