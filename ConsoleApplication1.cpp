#include <iostream>
using namespace std;

template<class T>
class Nodo {
public:
    T valor;
    Nodo<T>* next;

    Nodo(T v, Nodo<T> *n = nullptr) {
        valor = v;
        next = n;
    }
};

template<class T>
class Pila {
public:
    Nodo<T>* top;

    Pila() {
        top = nullptr;
    }

    void push(T v);

    bool pop(T &v);
};

template<class T>
void Pila<T>::push(T v) {
    top = new Nodo<T>(v,top);
}

template<class T>
bool Pila<T>::pop(T& v) {
    if (!top) {
        return false;
    }
    else {
        v = top->valor;
        Nodo<T>* tmp = top;
        top = top->next;
        delete tmp;
        return true;
    }
    
}


int main()
{

    Pila<int> p;
    p.push(1);
    p.push(2);
    p.push(3);

    int valor;
    bool flag{ true };
    while (flag) {
        flag = p.pop(valor);
        if (flag) cout << valor << "\n";
    }



}
