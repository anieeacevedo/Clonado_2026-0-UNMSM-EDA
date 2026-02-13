#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
#include <mutex>
#include "linkedlist.h"
#include "../general/types.h"
#include "../util.h"

template <typename Traits>
class CQueue{
public:
    using value_type = typename Traits::value_type;

private:
    CLinkedList<Traits> m_list;
    mutable recursive_mutex m_mutex;

public:
    CQueue() = default;

    // Constructor (copia y move)
    CQueue(const CQueue<Traits>& another) {
        lock_guard<recursive_mutex> lock(another.m_mutex);
        m_list = another.m_list;
    }

    CQueue(CQueue<Traits>&& another) noexcept {
        lock_guard<recursive_mutex> lock(another.m_mutex);
        m_list = std::move(another.m_list);
    }

    // FIFO
    void Push(value_type val, ref_type ref = -1) {
        lock_guard<recursive_mutex> lock(m_mutex);
        m_list.push_back(val, ref); 
    }

    value_type Pop() {
        lock_guard<recursive_mutex> lock(m_mutex);
        return m_list.pop_front(); 
    }

    value_type& Front() {
        lock_guard<recursive_mutex> lock(m_mutex);
        return m_list[0]; 
    }

    friend ostream& operator<<(ostream& os, CQueue<Traits>& queue) {
        lock_guard<recursive_mutex> lock(queue.m_mutex);
        os << "--- QUEUE (Front at the beginning) ---" << endl;
        os << queue.m_list;
        return os;
    }

    friend istream& operator>>(istream& is, CQueue<Traits>& queue) {
        is >> queue.m_list;
        return is;
    }
};


#endif // __QUEUE_H__