#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <mutex>
#include "linkedlist.h"
#include "../general/types.h"
#include "../util.h"

template <typename Traits>
class CStack{
public:
    using value_type = typename Traits::value_type;

private:
    CLinkedList<Traits> m_list; // Composición
    mutable recursive_mutex m_mutex;

public:
    CStack() = default;

    //Constructor (copia y move)
    CStack(const CStack<Traits>& another) {
        lock_guard<recursive_mutex> lock(another.m_mutex);
        m_list = another.m_list; 
    }

    CStack(CStack<Traits>&& another) noexcept {
        lock_guard<recursive_mutex> lock(another.m_mutex);
        m_list = std::move(another.m_list);
    }

    void Push(value_type val, ref_type ref = -1) {
        lock_guard<recursive_mutex> lock(m_mutex);
        m_list.push_back(val, ref);
    }

    value_type Pop() {
        lock_guard<recursive_mutex> lock(m_mutex);
        return m_list.pop_back();
    }

    value_type& Top() {
        lock_guard<recursive_mutex> lock(m_mutex);
        return m_list[m_list.getSize() - 1];
    }

    bool IsEmpty() {
        lock_guard<recursive_mutex> lock(m_mutex);
        return m_list.getSize() == 0;
    }

    //Persistencia
    friend ostream& operator<<(ostream& os, CStack<Traits>& stack) {
        lock_guard<recursive_mutex> lock(stack.m_mutex);
        os << "--- STACK (Top at the end) ---" << endl;
        os << stack.m_list; 
        return os;
    }

    friend istream& operator>>(istream& is, CStack<Traits>& stack) {
        // Reutiliza la lectura de la lista
        is >> stack.m_list;
        return is;
    }
    
};


#endif // __STACK_H__