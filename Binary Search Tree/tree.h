template<typename DATA_TYPE> struct TreeNode
{
	TreeNode(const DATA_TYPE& value, TreeNode* left = NULL, TreeNode* right = NULL)
	{
		Value = value;
		Left = left;
		Right = right;
	}

	DATA_TYPE Value;
	TreeNode* Left;
	TreeNode* Right;

	bool IsLeaf() const
	{
		return Left == NULL && Right == NULL;
	}


	void Delete(TreeNode<DATA_TYPE>*& tree, DATA_TYPE item)
	{
		if (tree == NULL) 	// empty tree or not in the tree
			return;

		if (item < tree->Value)          // Go Left
			Delete (tree->Left, item);
		else if (item > tree->Value)     // Go Right
			Delete(tree->Right, item);
		else                            // end of the line 
			Remove(item, tree);
	}




	void Insert(DATA_TYPE insertData, TreeNode<DATA_TYPE>*& node)
	{
		int nothing=0;
		// Base case
		if (node == NULL)
			node = new TreeNode<DATA_TYPE>(insertData);
		else
			if (node->Value == insertData) 
				nothing = nothing; //do nothing-more elegant way of doing nothing?
		// Recursion
			else 
				if (node->Value > insertData)
					return Insert(insertData, node->Left);
				else
					return Insert(insertData, node->Right);
	}

	void Remove(DATA_TYPE deleteData, TreeNode<DATA_TYPE>*& node)
	{


		TreeNode<DATA_TYPE> *temp;
		temp = node;

		// Base case
		if (node == NULL) //dumbass
			return; // Not found, nothing to delete
		else{
			if (node->Value == deleteData){
				// Case 1-
				if (node->IsLeaf())
				{ 
					delete node;
					node = NULL;
				}

				//Case 2- If the root only has one child- if a root only has one child, left or right has to be null AND left and right are not null- problems may arise here
				else if  (node->Left == NULL) // subcase 2-1-root only has right child 
				{
					node = node->Right; // set the root=child
					delete temp;
				}
				else if  (node->Right == NULL) // subcase 2-2-root only has left child 
				{
					 node = node->Left;// set the root=child 
					 delete temp;
				}

				else // Case 3
				{
					//dhttp://faculty.winthrop.edu/dannellys/csci271/binary_tree_delete.htm
					TreeNode<DATA_TYPE> *RMN;
					RMN =  node;
					RMN = node->Left;          // find right-most node of left sub-tree
					while (RMN->Right != NULL)
						RMN = RMN->Right;
					node->Value = RMN->Value;    // set root->Data = RMN->Data
					Delete(node->Left, deleteData);   // recursively delete from root->Left
				}					

			}//end if 	so


			// Recursion
			else if (node->Value > deleteData)
				Delete(node->Left, deleteData); // recursively delete from left sub-tree
			else
				Delete(node->Right, deleteData); // recursively delete from right sub-tree

		}//end if
				

	}



	// inorder print function 
	void InOrderPrint ( TreeNode<DATA_TYPE>*& node) 
	{
		if (node != NULL)
		{
			if (node->Left) 
				InOrderPrint(node->Left);

			cout << node->Value << " ";

			if (node->Right)
				InOrderPrint(node->Right);
		}
		else
			return;
	}



};
