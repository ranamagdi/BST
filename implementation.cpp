#include"BST.h"
//constructor
BST::BST() :root(0) {}
//check is empty
  bool BST::empty() {
	return root == 0;
}
//deconstructor
BST::~BST() {
	remove_all(root);
}

//help to remove all node using with deconstructor
void BST:: remove_all(BinNodePointer temp) {
	if (temp != nullptr) {
		if (temp->left != nullptr) {
			remove_all(temp->left);
		}
		if (temp->right != nullptr) {
			remove_all(temp->right);
		}
		
		delete temp;
	}
	
}
void BST::copy_help(BinNodePointer src, BinNodePointer &dest)
{
	

	if (src != 0) {
		dest = new BinNode(src->data);
		copy_help(src->left, dest->left);
		copy_help(src->right, dest->right);
	}
}

//copy constructor
BST::BST(const BST&src) {
	copy_help(src.root, this->root);
}

//search helper
bool BST:: search_help( BinNodePointer temp,   DataType item) {
	if (temp != 0) {
		if (temp->data == item) { return true; }
		if (item < temp->data) { return search_help(temp->left, item); }
		if (item > temp->data) { return search_help(temp->right, item); }
	}
	return false;

}
//search using recursion
bool BST::search() {
	DataType item;
	cout << "enter number to be found " << endl;
	cin >> item;

	return search_help(root, item);


}
//--help of insert--
void BST:: insert_help(BinNodePointer temp, DataType value)
{
	if (value < temp->data)
	{
		if (temp->left == nullptr) {
			temp->left = new BinNode(value);
		}
		else {
			insert_help(temp->left, value);
		}
	}
	else if (value>temp->data) {
		if (temp->right == nullptr) {
			temp->right = new BinNode(value);
		}
		else {
			insert_help(temp->right, value);
		}
	}
	else {
		cout << "item already in tree you can not insert";
		exit(1);
	}



}
//insert
//by recursion
void BST::insert( DataType  item) {
	if (empty())
	{
		root = new BinNode(item);

	}
	else { insert_help(root, item); }


	//---by loop---
	/* if (empty()) {
	root = new BinNode(item);
	return;}
	BinNodePointer temp = root;
	BinNodePointer parent = nullptr;
	while (temp!=nullptr)
	{
	parent = temp;
	if (item < temp->data)
	{
	temp = temp->left;
	}
	else if (item >temp->data)
	{
	temp = temp->right;
	}
	else {
	cout << "the node is already exist";
	exit(1);
	}
	}
	if (item < parent->data) { parent->left = new BinNode(item); }
	else if (item > parent->data) { parent->right = new BinNode(item); }
	*/
}
//--help to find maximum--
DataType BST:: max_help(BinNodePointer temp) {
	if (temp->right == nullptr)return temp->data;
	else {
		return max_help(temp->right);
	}
}
//find maximum using recursion
DataType BST::get_max() {
	return max_help(root);
	//by loop
	//BinNodePointer temp = root;
	/*	while (temp->right != nullptr)
	{
	temp = temp->right;

	}
	return temp->data;*/
	//by recursion

}
//--help to find minimum--
DataType BST:: min_help(BinNodePointer temp) {
	if (temp->left == nullptr) { return temp->data; }
	else {
		return min_help(temp->left);
	}
}
//find minimum by using recursion
DataType BST::get_min() {
	return min_help(root);
	//by loop:
	//BinNodePointer temp = root;
	/*while (temp->left != nullptr)
	{
	temp = temp->left;

	}
	return temp->data;*/
	//by recursion


}
//help to disply preorder
void  BST::preorder(BinNodePointer temp) {
	if (temp == nullptr)return;
	cout << temp->data << " ";
	preorder(temp->left);
	preorder(temp->right);
}

//display by preorder
void BST::display_preorder(ostream & out) {
	if (!empty())
	{
		preorder(root);
	}
}
//help to disply inorder
void BST:: inorder(BinNodePointer temp) {
	if (temp == nullptr)return;

	inorder(temp->left);
	cout << temp->data << " ";
	inorder(temp->right);
}
//display by inorder
void BST::display_inorder(ostream & out) {
	if (!empty())
	{
		inorder(root);
	}
}
//help to disply postorder
void BST:: postorder(BinNodePointer temp) {
	if (temp == nullptr)return;
	postorder(temp->left);
	postorder(temp->right);
	cout << temp->data << " ";
}
//display by postorder
void BST::display_postorder(ostream & out) {
	if (!empty())
	{
		postorder(root);
	}
}
//help to rempve
 BST::BinNodePointer BST:: remove_help(BinNodePointer parent, DataType value) {
	//check empty or not
	 if (empty()) {
		 cout << "illegal delete number not found it";
		 exit(1);
	 }
	
	//search about tne node
	if (value < parent->data) { parent->left = remove_help(parent->left, value); }
	else if (value > parent->data) { parent->right = remove_help(parent->right, value); }
	//find the node 
	else {
		//have one or no child
		if (parent->left == nullptr) {
			BinNodePointer temp = parent->right;
			delete parent;
			return temp;
		}
		else if (parent->right == nullptr) {
			BinNodePointer temp = parent->left;
			delete parent;
			return temp;
		}
		// have 2 child
		else {
			//Left node 
			DataType maxvalue = max_help(parent->left);        /*int minvalue=min_help(parent->right);
															   parent->data=minvalue;
			  											  parent->left=remove_help(parent->right,minvalue)*/
			parent->data = maxvalue;
			parent->left = remove_help(parent->left, maxvalue);


		}
	}

	return parent;
	
	
}

 //remove using recursion
 void BST::remove( DataType  item)
 {
	 remove_help(root, item);
 }
 
 

 


 // get hight helper
int BST::hight_help(BinNodePointer temp) {
	 if (temp == nullptr)return -1;
	int sub_left = hight_help(temp->left);
	int sub_right = hight_help(temp->right);
	 return 1 + max(sub_left, sub_right);
 }

 //get hight
 DataType BST::get_hight() {
	 if (root == nullptr)
		 return -1;
	 else {
		 return hight_help(root);
	 }
 }
 
 //ouput stream
 ostream & operator<<(ostream & out,  BST & bst)
 {
	bst.display_inorder(out);
	bst.display_postorder(out);
	 bst.display_preorder(out);
	 
	 return out;
 }