#ifndef EVENTHEAP_H
#define EVENTHEAP_H

typedef void (*functionPointer)(void);

class CallbackItem
{
public:
    CallbackItem(functionPointer func, unsigned long t);
    ~CallbackItem();

    unsigned long timestamp;
    functionPointer f;
    CallbackItem* next;
    CallbackItem* prev;

};

class Heap
{
public:
    Heap();
    ~Heap();
    CallbackItem* first;
    void insert(functionPointer);
    void remove(CallbackItem *);
    void eventloop();
    void delay(unsigned long int delay);

private:
    unsigned long int __delay;
};

#endif // EVENTHEAP_H
