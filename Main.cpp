#include"BST.h"

int main() {
	BST b; 
	b.insert(15);
	b.insert(6);
	b.insert(3);
	b.insert(9);
	b.insert(8);
	b.insert(20);
	b.insert(25);
	b.display_inorder(cout);
	cout << endl;
	
	

	cout << endl;
	cout <<"the max is  "<< b.get_max();
	cout << endl;
	cout <<"the min is  "<< b.get_min();
	cout << endl;

	if (b.search() == true)cout << "found it" << endl;
	else cout << "not found it" << endl;
	cout << "enter the number its want to delete" << endl;
	int t;
	cin >> t;
	b.remove(t);
	b.display_postorder(cout);
	cout << endl;
	
	BST b1(b);
	b1.display_preorder(cout);
	cout<<"the hight of tree is  "<<b.get_hight()<<endl;
	
	cout << endl;
	
	

}
