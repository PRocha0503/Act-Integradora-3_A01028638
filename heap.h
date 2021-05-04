#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <fstream>
#include "entrada.h"
using std::vector;
using std::cout;
using std::endl;


class Heap{
    private:
        vector<entrada> vect;
        int n;
        void heapify(int,int);
    public:
        Heap();
        Heap(vector<entrada>);
        void heapSort();
        void intercambiar(int, int);
        void printVector();
        void sacarLista(int,int,string);
        int size();
        vector<entrada> getVector();
        
};
Heap::Heap(){
    vect = {};
    n = vect.size();
}
Heap::Heap(vector<entrada> vec){
    vect = vec;
    n = vect.size();
}

void Heap::heapify(int size,int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < size && vect[l] < vect[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < size && vect[r] < vect[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        intercambiar(i, largest);
 
        // Recursively heapify the affected sub-tree
        heapify(size, largest);
    }
}

void Heap::heapSort()
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n,i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) { ;
        // Move current root to end
        intercambiar(0, i);
 
        // call max heapify on the reduced heap
        heapify(i,0);
    }
}


void Heap::intercambiar(int i,int j){
    entrada temporal;
    temporal = vect[i];
    vect[i] = vect[j];
    vect[j] = temporal;
}


void Heap::printVector(){
    for(int i = 0;i<n;i++){
        cout<<vect[i]<<endl;;
    }
}


void Heap::sacarLista(int in,int fi,string nombre){
    // for(int i = in;i<fi;i++){
    //     cout<<vect[i]<<endl;
    // }
    std::ofstream outfile (nombre);
    for(int i = in;i<fi;i++){
        outfile<<vect[i]<<endl;
    }
    outfile.close();
}

int Heap::size(){
    return vect.size();
}

vector<entrada> Heap::getVector(){
    return vect;
}

#endif