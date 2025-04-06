#include <iostream>
#include "LinkedList.h"
#include "LinkedQueue.h"
#include "ArrayStack.h"
#include "priQueue.h"

using namespace std;

// template <class T>
// void merge(Node<T>* &h1 , Node<T>* &h2 , Node<T>* &b1 , Node<T>* &b2 )
// {
//     Node<T>* S , L , R;

//     if(h1->item <= h2->item)
//     {
//         S = h1;
//         L = h2;
//     }
//     else
//     {
//         S = h2;
//         L = h1;
//     }

//     h1 = S;
//     h2 = nullptr;

//     if(b1->item >= b2->item)
//     {
//         b2 = nullptr;
//     }
//     else
//     {
//         b1 = b2;
//         b2 = nullptr;
//     }

//     while(L)
//     {
//         R = S->next;
//         while(R && R->item <= L->item)
//         {
//             S = R;
//             R = R->next;
//         }

//         S->next = L;
//         L = R;
//         S = S->next;
//     }
// }

// int N_ways(int n , int c)
// {
//     if(n < 0)
//     {
//         return 0;
//     }
//     if(n == 0)
//     {
//         return 1;
//     }
//     if(c > 7)
//     {
//         return 0;
//     }
//     if(c == 7)
//     {
//         return N_ways(n-1 ,0);
//     }

//     return N_ways(n-1 , 0) + N_ways(n-2 , 2) + N_ways(n-3 ,3);
// }

// Not Recursive
//  template <class T>
//  void to_the_end(Node<T>* head)
//  {
//      Node<T>* End = head;

//     while(End->next)
//     {
//         End = End->next;
//     }

//     Node<T>* ptr1 , ptr2;

//     ptr1 = h;

//     while()
//     {
//         ptr2 = ptr1->next;
//         ptr1->next = End;
//         ptr1 = ptr2;
//     }
// }

// Recursive one
//  template <class T>
//  void to_the_end(Node<T>* head)
//  {
//      /// You forget the empty list check !!!
//      if(head->next == nullptr)
//      {
//          return;
//      }

//     Node<T*> End = head;
//     while(End->next)
//     {
//         End = End->next;
//     }

//     Node<T>* temp = head->next;
//     head->next = End;

//     to_the_end(temp);
// }

// مكسل اكتب
//  move the smallest
//  Find the Smallest first using two nodes
//  You need previous pointer to this node
//  you will remove it from the list (not delete)
//  make it as the fisrt node in the list

int main()
{

    return 0;
}
