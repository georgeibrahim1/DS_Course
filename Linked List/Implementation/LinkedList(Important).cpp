#include<iostream>
using namespace std;

template<typename T>
class Node
{
private:
    T data;
    Node<T>* next;

public:
    void setData(T data)
    {
        this->data = data;
    }
    T getData()
    {
        return data;
    }
    void setNext(Node<T>* next) //if new -> pass it directly (Node<T>* = new Node<T> Obj) , if not new -> &node
    {
        this->next = next;
    }
    Node<T>* getNext()
    {
        return next;
    }

};

template<typename T>
class LinkedList
{
private:
    Node<T>* head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    int getCurrentSize()
    {
        if(isEmpty())
        {
            return 0;
        }

        Node<T>* ptr = head;
        int Size = 0;
        while(ptr)
        {
            Size++;
            ptr = ptr->getNext();
        }
        return Size;
    }

    bool isEmpty()
    {
        Node<T>* ptr = head;
        if(ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool add_without_order_byNode(Node<T>* node) // No Void
    {
        if(isEmpty())
        {
            return false;
        }
        node->setNext(head);
        head = node;
        return true;
    }

    bool add_without_order_byData(T Data)
    {
        if(osEmpty())
        {
            return false;
        }
        Node<T>* newNodePtr = new Node<T>();
        newNodePtr->setData(Data);
        newNodePtr->setNext(head);
        head = newNodePtr;
        return true;
    }

    Node<T>* getPointerTo_v1(T data)
    {
        Node<T>* ptr = head;
        while(ptr)
        {
            if(ptr->getData() == data)
            {
                return ptr;
            }
            ptr = ptr->getNext();
        }
        return nullptr;
    }

    Node<T>* getPointerTo_recursive(Node<ItemType>* curPtr, const T& target) //It will take the headptr by value
    {
        if (curPtr == nullptr) 
        return nullptr;

        if (curPtr->getData() == target) 
        return curPtr;

        return getPointerTo_recursive(curPtr->getNext(), target);
    }

    bool contains(T data)
    {
        return (getPointerTo_v1(data) != nullptr);
    }    

    int GetFrequencyOf(T data)
    {
        int freq = 0;
        Node<T>* ptr = head;

        while(ptr)
        {
            if(ptr->getData() == data)
            {
                freq++;
            }
            ptr = ptr->getNext();
        }

        return freq;
    }

    Node<T>* getPreviousPointer(const T& data)
    {
        if(isEmpty())
        {
            return nullptr;
        }
        if(head->getData() == data)
        {
            return nullptr;
        }
        
        Node<T>* Ptr= head;

        while(Ptr->getNext())
        {
            
            if (Ptr->next->getData() == data)
            {
                return Ptr;
            }
            Ptr = Ptr->getNext();           
        }

        return nullptr;

    }
    
    bool remove(const T& data) //DONE : Complete
    {
        if(head != nullptr && head->getData() == data)
        {
            Node<T>* TheNode = getPointerTo_v1(data);
            head = head->getNext();
            TheNode->setNext(nullptr);
            return true;
        }
        Node<T>* NodePtr = getPointerTo_v1(data);
        Node<T>* PrevPtr = getPreviousPointer(data);
        if(NodePtr && PrevPtr)
        {
            PrevPtr->setNext(NodePtr->getNext());
            NodePtr->setNext(nullptr);
            return true;
        }
        
        return false;
        

    }

    //DONE : Clear the List
    void Clear()
    {
        while (head != nullptr)
        {
            Node<T>* nodeTobeDeleted = head;
            head = head->getNext();

            nodeTobeDeleted->setNext(nullptr);
            delete nodeTobeDeleted;
        }
    }

    //DONE : Destructor needs the Clear()
    ~LinkedList()
    {
        Clear();
    }

    LinkedList(const LinkedList& OriginalList) //DONE : Copy Constructor for the Deep Copy
    {
        if(OriginalList.head == nullptr)
        {
            head = nullptr;
        }
        else
        {
            head = new Node<T>(); //Empty Node -> Calls the default Constructor

            T OriginalheadData = OriginalList.head->getData();

            head->setData(OriginalheadData); // We can make a non-default constructor instead of all these

            Node<T>* HelperPointerinOriginal = OriginalList.head;
            Node<T>* HelperPointerinNewList = head;

            while(HelperPointerinOriginal->next)
            {
                HelperPointerinOriginal = HelperPointerinOriginal->next; // This will make the loop iterate all the nodes

                Node<T>* NewNodePtr = new Node<T>();

                T newData = HelperPointerinOriginal->getData();

                NewNodePtr->setData(newData);

                HelperPointerinNewList->setNext(NewNodePtr);

                HelperPointerinNewList = HelperPointerinNewList->getNext();
            }

            HelperPointerinNewList->setNext(nullptr); //Last Node

        }
    }

    //Recurcion Functions : 

    //DONE : GetFreqof()
    int GetFreqof_Recursive(const T& data , Node<T>* Ptr , int& Frequency) //Will equal head , also for frequency-> must be initialized with zero
    {
        if(Ptr == nullptr)
        {
            return Frequency;
        }
        if(Ptr->getData() == data)
        {
            Frequency++;
        }
        return GetFreqof_Recursive(data, Ptr->getNext(),Frequency);
    }

    //DONE : Clear()
    void Clear_Recursively(Node<T>* Ptr)
    {
        if(Ptr == nullptr)
        {
            return;
        }
        else
        {
            Node<T>* nodeTobeDeleted = Ptr;
            Ptr = Ptr->getNext();
            nodeTobeDeleted->setNext(nullptr);
            delete nodeTobeDeleted;
            Clear_Recursively(Ptr);
        }
    }

    //By ChatGPT: 
    //template <typename T>
    //void Clear_Recursively(Node<T>* Ptr)
    //{
    //    if (Ptr == nullptr) // Base case: Stop when reaching the end
    //    {
    //        return;
    //    }

    //    Node<T>* nextNode = Ptr->getNext(); // Save next node before deletion
    //    delete Ptr; // Delete current node
    //    Clear_Recursively(nextNode); // Move to next node
    //}



};