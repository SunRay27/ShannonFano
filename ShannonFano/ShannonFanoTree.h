#include <iostream>
#include "SFTNode.h"
#include "SFTreePrinter.h"
using namespace std;

template <class TKey>
class SFTree
{
private:
	SFTNode<TKey>* root;

public:

	~SFTree() { delete root; }
	SFTree(SFTNode<TKey>* root) : root(root) { }
	
	SFTNode<TKey>* GetRoot()
	{
		return root;
	}
	

	void Print()
	{
		SFTreePrinter<TKey> a;
		cout << endl << endl;
		a.PrintTree(root, nullptr, false);
	}
};
