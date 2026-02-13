#include <iostream>
#include "containers/lists.h"
#include "containers/stack.h"

using namespace std;

void DemoStack(){
    cout<< "--------- Demo Stack ---------" << endl;
    CStack<AscendingTrait<int>> stack;
    
    stack.Push(10, 1);
    stack.Push(20, 2);
    stack.Push(30, 3);
    
    cout << "Pila despues de 3 Push:" << endl;
    cout << stack << endl;
    
    cout << "Elemento en el Top: " << stack.Top() << endl;
    
    cout << "Haciendo Pop." << endl;
    int valorExtraido = stack.Pop();
    cout << "Valor extraido: " << valorExtraido << endl;
    
    cout << "Pila despues del Pop:" << endl;
    cout << stack << endl;
}

