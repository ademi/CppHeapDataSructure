
/* 
 * File:   heap.h
 * Author: ademi
 *
 * Created on July 9, 2016, 12:23 PM
 */
#ifndef _heap_h
#define _heap_h
#include <iterator>
#include <vector>

using namespace std;
typedef long unsigned int luint;

template<typename T>
class heap{
        vector<T> data;
        luint parentof(luint index);
        luint childof(luint index);
        void bubbleup(luint index);
        void bubbledown(luint index);
    public:
        heap(){}
        heap(const vector<T>&v);
        void add(T a);
        void get_vector(vector<T>&temp);
        bool empty();
        T pop();
};
template<typename T> bool heap<T>::empty(){return (this->data.empty());}
template<typename T> luint heap<T>::parentof(luint index){
    return (index>>1);//taking advantage of the fact that dividing odd int gives out floored result
}
template<typename T> luint heap<T>::childof(luint index){
    return (index<<1);
}
//template<typename T> heap<T>::heap()
template<typename T> heap<T>::heap(const vector<T>&v){
    this->data.reserve(v.size());
    for(typename vector<T>::const_iterator it=v.begin();it!=v.end();it++)
        this->add(*it);
}
template<typename T> void heap<T>::bubbleup(luint index){
    T element = this->data.at(index-1);
    luint parent = this->parentof(index);
    luint current= index;
    while(current>1){
        if(this->data.at(parent-1)>element){
            this->data.at(current-1)=this->data.at(parent-1);
            current =parent;
            parent =this->parentof(current);
            
        }
        else break;
    }
    
    this->data.at(current-1)=element;
}
template<typename T> void heap<T>::bubbledown(luint index){
    T element = this->data.at(index-1);
    luint current=index;
    luint child =this->childof(current);
    luint size =this->data.size();
    while(child<=size){
        if(child<size&&(this->data.at(child-1)>this->data.at(child)))child++; //set child to the larger leaf.
        if(element>=this->data.at(child-1)){
            this->data.at(current-1)=this->data.at(child-1);
            current =child;
            child =this->childof(current);
        }
        else break;
    }
    this->data.at(current-1)=element;
}
template<typename T> void heap<T>::add(T d){
    this->data.push_back(d);
    this->bubbleup(this->data.size());
}
template<typename T>T heap<T>::pop(){
    T result =this->data[0];
    this->data[0]=this->data.back();
    this->data.pop_back();
    if(!this->data.empty())this->bubbledown(1);
    return result;
}
template<typename T> void heap<T>::get_vector(vector<T>&temp){
    temp.reserve(this->data.size());
    copy(this->data.begin(),this->data.end(),back_inserter(temp));
}
#endif
