#include "BinaryTree.h"
#include "BinaryNode.h"

template <typename T>
class BinaryNodeTree : public BinaryTreeInterface<T>
{
public:
	BinaryNode<T>* rootPtr;
	BinaryNodeTree();
	BinaryNodeTree(const T rootItem, const BinaryNodeTree<T>* leftTreePtr = nullptr, const BinaryNodeTree<T>* rightTreePtr = nullptr);
	BinaryNodeTree(const BinaryNodeTree<T>& aTree); //copy constructor
	virtual ~BinaryNodeTree();

	//-------------
	// Public Interface methods section
	//-------------
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	T getRootData() const throw(PrecondViolatedExcep);
	void setRootData(const T& newData);
	bool add(const T& newData); // Adds a node
	bool remove(const T& data); // Removes a node
	void clear();
	T getEntry(const T& anEntry) const throw(NotFoundException);
	bool contains(const T& anEntry) const;

	void preorderTraverse() const;
	void inorderTraverse() const;
	void postorderTraverse() const;
	void levelorderTraverse() const;

	//-------------
	// Protected utility helper (recursive) methods
	//-------------
	int getHeightHelper(BinaryNode<T>* subTreePtr) const;
	int getNumberOfNodesHelper(BinaryNode<T>* subTreePtr) const;
	void destroyTree(BinaryNode<T>* subTreePtr);
	BinaryNode<T>* balancedAdd(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr);
	BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T target, bool& success);
	BinaryNode<T>* moveValuesUpTree(BinaryNode<T>* subTreePtr);
	BinaryNode<T>* findNode(BinaryNode<T>* treePtr, const T& target, bool& success) const;
	BinaryNode<T>* copyTree(const BinaryNode<T>* treePtr) const;

	void preorder(BinaryNode<T>* treePtr) const;
	void inorder(BinaryNode<T>* treePtr) const;
	void postorder(BinaryNode<T>* treePtr) const;
	void levelorder(BinaryNode<T>* treePtr) const;
};

template <typename T>
inline BinaryNode<T>* BinaryNodeTree<T>::copyTree(const BinaryNode<T>* treePtr) const
{
	BinaryNode<T>* newTreePtr = nullptr;
	if (treePtr)
	{
		newTreePtr = new BinaryNode<T>*(treePtr->getItem());

		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}
	return newTreePtr;
}

template <typename T>
inline BinaryNodeTree<T>::BinaryNodeTree(const BinaryNodeTree<T>& aTree)
{
	rootPtr = copyTree(aTree.rootPtr);
}

template <typename T>
inline void BinaryNodeTree<T>::destroyTree(BinaryNode<T>* subTreePtr)
{
	if (subTreePtr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	}
}

template<typename T>
inline BinaryNodeTree<T>::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}

template<typename T>
inline int BinaryNodeTree<T>::getHeightHelper(BinaryNode<T>* subTreePtr) const
{
	if (subTreePtr)
	{
		int left = getHeightHelper(subTreePtr->getLeftChildPtr());
		int right = getHeightHelper(subTreePtr->getRightChildPtr());
		return 1 + std::max(x, y);
	}
	else
		return 0;
}

template<typename T>
inline int BinaryNodeTree<T>::getHeight() const
{
	return getHeightHelper(rootPtr);
}

template<typename T>
inline int BinaryNodeTree<T>::getNumberOfNodesHelper(BinaryNode<T>* subTreePtr) const
{
	if (subTreePtr)
	{
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodes(subTreePtr->getRightChildPtr());
	}
	else
		return 0;
}

template<typename T>
inline int BinaryNodeTree<T>::getNumberOfNodes() const
{
	getNumberOfNodesHelper(rootPtr);
}

template<typename T>
inline BinaryNode<T>* BinaryNodeTree<T>::balancedAdd(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr)
{
	if (subTreePtr == nullptr)
		return newNodePtr;
	BinaryNode<T>* leftPtr = subTreePtr->getLeftChildPtr();
	BinaryNode<T>* rightPtr = subTreePtr->getRightChildPtr();
	if (getHeightHelper(rightPtr) < getHeightHelper(leftPtr))
	{
		leftPtr = balancedAdd(leftPtr, newNodePtr);
		subTreePtr->setLeftChildPtr(leftPtr);
	}
	else
	{
		rightPtr = balanced(rightPtr, newNodePtr);
		subTreePtr->setRightChildPtr(rightPtr);
	}

	return subTreePtr;
}

template<typename T>
inline bool BinaryNodeTree<T>::add(const T& newData)
{
	BinaryNode<T>* newNodePtr = new BinaryNode(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);
	return true;
}

template<typename T>
inline void BinaryNodeTree<T>::preorder(BinaryNode<T>* treePtr) const
{
	if (treePtr)
	{
		// Do something supposedly, print
		std::cout << treePtr->getItem() << " ";
		preorder(treePtr->getLeftChildPtr());
		preorder(treePtr->getRightChildPtr());
	}
}

template<typename T>
inline void BinaryNodeTree<T>::postorder(BinaryNode<T>* treePtr) const
{
	if (treePtr)
	{
		postorder(treePtr->getLeftChildPtr());
		postorder(treePtr->getRightChildPtr());
		// Do something supposedly, print
		std::cout << treePtr->getItem() << " ";
	}
}

template<typename T>
inline void BinaryNodeTree<T>::inorder(BinaryNode<T>* treePtr) const
{
	if (treePtr)
	{
		inorder(treePtr->getLeftChildPtr());
		// Do something supposedly, print
		std::cout << treePtr->getItem() << " ";
		inorder(treePtr->getRightChildPtr());
	}
}

template<typename T> //BF Traverse
inline void BinaryNodeTree<T>::levelorder(BinaryNode<T>* treePtr) const
{
	std::queue<BinaryNode<T>*> Nodesqueue;
	Nodesqueue.push(rootPtr);

	while (!Nodesqueue.empty())
	{
		BinaryNode<T>* currentPtr = Nodesqueue.front();
		// Do something supposedly, print
		std::cout << currentPtr->getItem() << " ";
		if (currentPtr->getLeftChildPtr())
			Nodesqueue.push(currentPtr->getLeftChildPtr());
		if (currentPtr->getRightChildPtr())
			Nodesqueue.push(currentPtr->getRightChildPtr());
		Nodesqueue.pop();
	}
}

