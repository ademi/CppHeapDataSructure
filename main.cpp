#include <iostream>
#include "heap.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    vector<int> v{9,10,8,7,3,5,4,6,2,1,2};  //Generic vector of random int 
    vector<int> result;                     //a buffer to hold the resulting heap
    result.reserve(v.size()+1); 
    heap<int> *h=new heap<int>(v);
    h->add(25);
    h->get_vector(result);
    for(vector<int>::iterator it=result.begin();it!=result.end();++it)
        cout<<*it<<"\t";
    cout<<endl;
    while(!h->empty()){cout<<h->pop()<<endl;}
    return 0;
}

