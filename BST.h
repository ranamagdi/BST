#include<algorithm>
#include<iostream>
#include <iomanip>

using namespace std;
typedef int DataType;

class BST {

private:
	class BinNode {
	public:

		DataType data; BinNode * left; BinNode * right;
		BinNode() {}
	BinNode(DataType value) { data = value; left = right = nullptr; }//if this constructor does not exist so i will write this when i need to create new node and put data in this node:
	           private:
    /***** Node class *****/
    class BinNode
    {
    public:
        DataType data;
        BinNode * left;
        BinNode * right;
        
        // BinNode constructors
        // Default -- data part is default DataType value; both links are null.
        BinNode()
        : left(0), right(0)
        {}
        
        // Explicit Value -- data part contains item; both links are null.
        BinNode(DataType item)
        : data(item), left(0), right(0)
        {}
        
    };// end of class BinNode declaration
    typedef BinNode* BinNodePointer;
                                                            // BinNodePointer newnode= new BinNode;
	                                                                    //   newNode-> data=value;
	                                                                    //   newNode->left=newNode->right=nullptr;
	                                                                    
	};
	typedef BinNode * BinNode;
	BinNode root = nullptr;
	//copy constructor help
	void copy_help(BinNodePointer src, BinNodePointer &dest);
	

		//search helper
		bool search_help(BinNodePointer temp,  DataType  item);
		//--help of insert--
		void insert_help(BinNodePointer temp, DataType value);


		//--help to find maximum--
		DataType max_help(BinNodePointer temp);
		//--help to find minimum--
		DataType min_help(BinNodePointer temp);
		//help to disply preorder
		void preorder(BinNodePointer temp);
		//help to disply inorder
		void inorder(BinNodePointer temp);
		//help to disply postorder
		void postorder(BinNodePointer temp);
		//help to rempve
		BinNode remove_help(BinNodePointer parent, DataType value);
		//help to remove all node using with deconstructor
		void remove_all(BinNodePointer temp);
		// get hight helper
		DataType hight_help(BinNodePointer temp);
		





public:
	//constructor
    BST();
	//deconstructor
	~BST();
	//copy constructor
	BST(const BST&src);
	//check is empty
	 bool empty();
	//insert
	//by recursion
	void insert( DataType  item);
	//remove using recursion
	void remove(DataType item);
	//search using recursion
	bool search();
	//find maximum using recursion
  DataType get_max();
	//find minimum by using recursion
	DataType get_min();
	//display by preorder
	void display_preorder(ostream & out);
	//display by postorder
	void display_postorder(ostream & out);
	//display by inorder
	void  display_inorder(ostream& out);
	
	//get hight
	int get_hight();
	

};
ostream & operator<<(ostream & out,  BST & aLList);



