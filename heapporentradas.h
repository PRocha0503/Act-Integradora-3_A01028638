#ifndef HEAPPORENTRADAS_H
#define HEAPPORENTRADAS_H
#include "heap.h"
#include <typeinfo>
struct CantidadHeap{
    int cantidad;
    std::vector<entrada> entradas;
};

class HeapPorEntradas{
    private:
        std::vector<CantidadHeap> entradas;
        void intercambiar(int, int);
        void heapify(int,int);
    public: 
        HeapPorEntradas(vector<entrada>);
        void heapSort();
        void printHeap();
        int maxCant();
        void sacarLista(int,int,string);
        int getSize();
        void printMaxEntradas();
        void getEntradasInfo(int);

};
bool operator>(CantidadHeap entrada1, CantidadHeap entrada2){
    if(entrada1.cantidad>entrada2.cantidad){
        return true;
    }
    else if(entrada1.cantidad==entrada2.cantidad){
        if(entrada1.entradas[0]>entrada2.entradas[0]){
            return true;
        }
    }
    return false;
}


bool operator<(CantidadHeap entrada1, CantidadHeap entrada2){;
    if(entrada1.cantidad<entrada2.cantidad){
        return true;
    }
    else if(entrada1.cantidad==entrada2.cantidad){
        if(entrada1.entradas[0]<entrada2.entradas[0]){
            return true;
        }
    }
    return false;
}

bool operator>=(CantidadHeap entrada1, CantidadHeap entrada2){
    if(entrada1.cantidad>=entrada2.cantidad){
        return true;
    }
    else if(entrada1.cantidad==entrada2.cantidad){
        if(entrada1.entradas[0]>=entrada2.entradas[0]){
            return true;
        }
    }
    return false;
}

bool operator<=(CantidadHeap entrada1, CantidadHeap entrada2){
    if(entrada1.cantidad<=entrada2.cantidad){
        return true;
    }
    else if(entrada1.cantidad==entrada2.cantidad){
        if(entrada1.entradas[0]<=entrada2.entradas[0]){
            return true;
        }
    }
    return false;
}

bool operator==(CantidadHeap entrada1, CantidadHeap entrada2){
    if(entrada1.cantidad==entrada2.cantidad){
        return true;
    }
    else if(entrada1.cantidad==entrada2.cantidad){
        if(entrada1.entradas[0]==entrada2.entradas[0]){
            return true;
        }
    }
    return false;
}

bool operator!=(CantidadHeap entrada1, CantidadHeap entrada2){
    if(entrada1.cantidad!=entrada2.cantidad){
        return true;
    }
    else if(entrada1.cantidad!=entrada2.cantidad){
        if(entrada1.entradas[0]!=entrada2.entradas[0]){
            return true;
        }
    }
    return false;
}

HeapPorEntradas::HeapPorEntradas(vector<entrada> vect){
    int i = 0;
    while(i<vect.size()){
        CantidadHeap elemento;
        elemento.entradas.push_back(vect[i]);
        elemento.cantidad = 1;
        int ip1 = convertirIP(vect[i].ip);
        if(i+1 != vect.size()){
            int ip2 = convertirIP(vect[i+1].ip);
            while(ip1==ip2){
                elemento.entradas.push_back(vect[i+1]);
                elemento.cantidad ++;
                i++;
                ip1 = convertirIP(vect[i].ip);
                if(i+1==vect.size()){
                    break;
                };
                ip2 = convertirIP(vect[i+1].ip);
                }
        }
        entradas.push_back(elemento);
        i++;
    }
}

int HeapPorEntradas::getSize(){
    return entradas.size();
}

void HeapPorEntradas::heapify(int size,int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < size && entradas[l] < entradas[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < size && entradas[r] < entradas[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        intercambiar(i, largest);
 
        // Recursively heapify the affected sub-tree
        heapify(size, largest);
    }
}

void HeapPorEntradas::heapSort()
{
    // Build heap (rearrange array)
    for (int i = entradas.size() / 2 - 1; i >= 0; i--)
        heapify(entradas.size(),i);
 
    // One by one extract an element from heap
    for (int i = entradas.size() - 1; i > 0; i--) { ;
        // Move current root to end
        intercambiar(0, i);
 
        // call max heapify on the reduced heap
        heapify(i,0);
    }
}

void HeapPorEntradas::intercambiar(int i,int j){
    CantidadHeap temporal;
    temporal = entradas[i];
    entradas[i] = entradas[j];
    entradas[j] = temporal;
}

void HeapPorEntradas::printHeap(){
    for(int i = 0;i<entradas.size();i++){
        std::cout<<entradas[i].cantidad<<"  "<<entradas[i].entradas[0].ip<<std::endl;
    }
}


int HeapPorEntradas::maxCant(){
    int max = 0;
    for(int i = 0;i<entradas.size();i++){
        if(entradas[i].cantidad>max){
            max = entradas[i].cantidad;
        }
    }

    return max;
}

void HeapPorEntradas::sacarLista(int in,int fi,string nombre){
    // for(int i = in;i<fi;i++){
    //     cout<<vect[i]<<endl;
    // }
    std::ofstream outfile (nombre);
    for(int i = in;i<fi;i++){
        outfile<<entradas[i].cantidad<<"  "<<entradas[i].entradas[0].ip<<endl;
    }
    outfile.close();
}

void HeapPorEntradas::printMaxEntradas(){
    cout<<"Los 5 ips con mas entradas son:"<<endl;
    for(int i = 0;i < 5;i++) {
        cout<<entradas[i].cantidad<<"  "<<entradas[i].entradas[0].ip<<endl;
    }
}

void HeapPorEntradas::getEntradasInfo(int n){
    for(int i = 0;i<entradas[n].entradas.size();i++){
        cout<<entradas[n].entradas[i]<<endl;
    }
}

#endif