template <typename T>
class BinaryNode
{
private:
	T item; // Data portion
	BinaryNode<T>* leftChildPtr; // Pointer to left child
	BinaryNode<T>* rightChildPtr; // Pointer to right child
public:
	BinaryNode();
	BinaryNode(const T& anItem, BinaryNode<T>* leftPtr = nullptr, BinaryNode<T>* rightPtr = nullptr);
	void setItem(const T& anItem);
	T getItem() const;
	bool isLeaf() const;
	BinaryNode<T>* getLeftChildPtr() const;
	BinaryNode<T>* getRightChildPtr() const;
	void setLeftChildPtr(BinaryNode<T>* leftPtr);
	void setRightChildPtr(BinaryNode<T>* rightPtr);
};