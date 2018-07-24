#include <ArduinoEventsLib.h>
#include <Arduino.h>

CallbackItem::CallbackItem(functionPointer func, unsigned long t):
    timestamp{t},
    f{func},
    next{nullptr},
    prev{nullptr}
{

}

CallbackItem::~CallbackItem(){
}

Heap::Heap():
    first{ nullptr},
    __delay{0}
{

}

Heap::~Heap(){

    CallbackItem* it = first;

    while(it!=nullptr){
        CallbackItem* aux = it->next;
        delete it;
        it=aux;
    }

    first = nullptr;
}


void Heap::insert(functionPointer p){
    if(first){
        //if there are already elements in the heap
        //save the address of the first
        CallbackItem *aux = first;
        //introduce the new one as first
        CallbackItem* cb = new CallbackItem(p, millis() + __delay);
        first = cb;
        //set the previous first as second
        first->next = aux;
        first->next->prev = first;
    }else{
        //it is the first one
        CallbackItem* cb = new CallbackItem(p, millis() + __delay);
        first = cb;
    }
    __delay=0;
}

void Heap::remove(CallbackItem *cb){
    //If cb is the first iteam in the heap
    if(cb == first){
        if(cb->next){
            //if cb is NOT de last item in the heap
            first = cb->next;
        }else{
            //cb is the only element in the heap
            first = nullptr;
        }
    }else{
        //if cb is NOT de last item in the heap
        if (cb->next){
            cb->prev->next = cb->next;
            cb->next->prev = cb->prev;
        }else{
            //if cb is the last item in the heap
            cb->prev->next = nullptr;
        }
    }

    delete cb;

}

void Heap::eventloop(){
    CallbackItem* it = first;
    while(it!=nullptr){
        CallbackItem* aux = it;
        it = it->next;
        if(aux->timestamp < millis()){
            aux->f();
            remove(aux);
        }
    }
}

void Heap::delay(unsigned long int delay){
    __delay = delay;
}

