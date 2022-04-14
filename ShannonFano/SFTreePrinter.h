#pragma once
template <class TKey>
class SFTreePrinter
{
	struct DrawNode
	{
		DrawNode* previous;
		string printValue;

		DrawNode(DrawNode* previous, string printValue)
		{
			this->previous = previous;
			this->printValue = printValue;
		}
	};
	void DrawNodeRecursive(DrawNode* p)
	{
		if (p == nullptr)
			return;

		DrawNodeRecursive(p->previous);
		cout << p->printValue;
	}



	List<DrawNode*> drawNodes;
public:

	SFTreePrinter()
	{
	}
	void PrintTree(SFTNode<TKey>* currentNode, DrawNode* previousDrawNode, bool isLeft)
	{
		if (currentNode == nullptr)
			return;

		string prevValue = "    ";
		DrawNode* drawNode = new DrawNode(previousDrawNode, prevValue);
		drawNodes.Add(drawNode);
		PrintTree(currentNode->GetRight(), drawNode, true);

		//draw root
		if (!previousDrawNode)
			drawNode->printValue = "——";
		else if (isLeft)
		{
			//right node
			drawNode->printValue = ".——";
			prevValue = "   |";
		}
		else
		{
			//left node
			drawNode->printValue = "`——";
			previousDrawNode->printValue = prevValue;
		}

		DrawNodeRecursive(drawNode);

		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);



		cout << " " << currentNode->GetKey() << endl;

		if (previousDrawNode)
			previousDrawNode->printValue = prevValue;

		drawNode->printValue = "   |";

		PrintTree(currentNode->GetLeft(), drawNode, false);
	}

	~SFTreePrinter()
	{
		for (size_t i = 0; i < drawNodes.GetSize(); i++)
			delete drawNodes[i];
	}
};