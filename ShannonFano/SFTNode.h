#pragma once
template <class TKey>
class SFTNode
{
	SFTNode<TKey>* right, * left;
	TKey key;
public:
	~SFTNode()
	{
		delete right;
		delete left;
	}
	SFTNode() : right(nullptr), left(nullptr), key(TKey()) {}
	SFTNode(TKey key) : key(key), right(nullptr), left(nullptr) {}
	SFTNode(TKey key, SFTNode* right, SFTNode* left, SFTNode* parent) : key(key), right(right), left(left) { }

	void SetRight(SFTNode* rightElement) { right = rightElement; }
	void SetLeft(SFTNode* leftElement) { left = leftElement; }
	void SetKey(TKey key) { this->key = key; }

	SFTNode* GetRight() { return right; }
	SFTNode* GetLeft() { return left; }
	TKey GetKey() { return key; }
};