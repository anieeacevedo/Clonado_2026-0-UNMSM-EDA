#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include ".../util.h"
#include ".../util.h"


template <typename _T>
struct TraitAsc{
    using T = _T;
    using compFunc = ; // Definir el iterador adecuado para la lista enlazada
}

template <typename Traits>

struct NodeLinkedList {
   using value_type = typename Traits::T;
   using iterator = typename Traits::iterator;


   public:

};

//using CLinkedList<Traits>::value_type = Traits::T


class CLinkedlist {

    

public:
    CLinkedList(){} 

    void push back(value type &val, Ref ref);
    void in
}

template <typename Traits>
    void CLinkedList<Traits>::push_back(value type &val, Ref ref){
        Node * pNewNode = new Node(val, ref);
        if (!m_pRoot)
        {
            m_pRoot = pNewNode;
        }
        else
        {
            NodeLinkedList<Traits>* pCurrent = m_pRoot;
            while (pCurrent->m_pNext != nullptr)
            {
                pCurrent = pCurrent->m_pNext;
            }
            pCurrent->m_pNext = new NodeLinkedList<Traits>(val, ref);
        }
    }














#endif // __LINKEDLIST_H__

//Crear el nodo, hacer q apunte al siguiente y 
//greater SI X es MENOR q Y ---> true
//less sI X es MAYOR q Y ----> true