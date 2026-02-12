#include <iostream>
#include "containers/lists.h"
#include "containers/linkedlist.h"
#include "containers/queue.h"


using namespace std;

void DemoQueue(){
    cout << "---------- Demo Queue (FIFO) ---------" << endl;
    CQueue<AscendingTrait<int>> queue;

    queue.Push(15, 1);
    queue.Push(23, 2);
    queue.Push(37, 3);

    cout << "Tras 3 Push (15, 23, 37):" << endl;
    cout << queue << endl;

    cout << "Elemento al frente (Front): " << queue.Front() << endl;

    cout << "Tras el Pop (salida del 15)." << endl;
    queue.Pop();

    cout << "Cola despues del Pop:" << endl;
    cout << queue << endl;
}