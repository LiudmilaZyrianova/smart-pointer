//Liudmila Zyrianova
//CSCI 335
//09/30/2018
//Programming Assignment 1

#ifndef MY_MEMORY_IMPL__
#define MY_MEMORY_IMPL__

#include <iostream>
#include "my_memory.h"

using namespace std;


template <typename T>
my_unique_ptr<T> :: my_unique_ptr (T * nptr) : ptr (nptr) {};      // Constructor that takes a pointer Type * as a parameter and sets the object to point there. We say that the newly created object takes ownership of the pointed memory.

template <typename T>
my_unique_ptr<T> :: my_unique_ptr (my_unique_ptr<T> && nmyptr) : ptr (nmyptr.ptr) {            // Move constructor that takes my_unique_ptr object and constructs a new object from it.
    nmyptr.ptr = nullptr;
};

template <typename T>
my_unique_ptr<T> ::~my_unique_ptr() {       //Destructor that releases/deletes the block of memory pointed by the object.
    delete ptr;
}

template <typename T>
T & my_unique_ptr<T> ::operator* ()  {      //Dereference operator * that returns a reference to the item pointed by the object.
        return *ptr;
    }

template <typename T>
T * my_unique_ptr<T> ::operator -> () {        //Operator -> that returns the pointer to the object.
        return ptr;
    }

template <typename T>
my_unique_ptr<T>& my_unique_ptr<T> ::operator= (my_unique_ptr&& nmyptr)   {     //Move assignment operator.
    if (&nmyptr != this) {
        delete ptr;
        ptr = nmyptr.ptr;
        nmyptr.ptr = nullptr;
    }
    return *this;
}








template <typename T>
my_shared_ptr<T>::my_shared_ptr ( T * nptr) : ptr (nptr) {        // Constructor that takes Type * as a parameter and sets the object to point there.
    if (nptr == nullptr){                                        //The object considers itself to be the first my_shared_ptr object to point to that block of memory. So the counter should be set to 1.
        counter_ptr = nullptr;
    } else {
        counter_ptr = new int;
        *counter_ptr = 1;
    }

};

template <typename T>
my_shared_ptr<T>::my_shared_ptr (my_shared_ptr && nmyshptr)  : ptr (nmyshptr.ptr), counter_ptr (nmyshptr.counter_ptr) {        // Move constructor. Since the original rvalue wont point to the block of memory no more, the counter should remain the same
    nmyshptr.ptr = nullptr;
    nmyshptr.counter_ptr = nullptr;

};

template <typename T>
my_shared_ptr<T>::my_shared_ptr (my_shared_ptr& nmyshptr) {     // Copy constructor. Since the original object already points to the block of memory and now the newly created object points there too, you must increase the counter by 1.
    if (nmyshptr.counter_ptr != nullptr){
        ptr = nmyshptr.ptr;
        counter_ptr = nmyshptr.counter_ptr;
        *counter_ptr = *counter_ptr + 1;
    } else {
        ptr = nullptr;
        counter_ptr = nullptr;
    }
};

template <typename T>
T & my_shared_ptr<T>::operator* ()  {      //Dereference operator * that returns a reference to the item pointed by the object.
    return *ptr;
}

template <typename T>
T * my_shared_ptr<T>::operator -> () {        //Operator -> that returns the pointer to the object. It allows to use the my_shared_ptr object for class member access.
    return ptr;
}

template <typename T>
my_shared_ptr<T>& my_shared_ptr<T>::operator= (my_shared_ptr&& nmyshptr)  {     //Move assignment operator. If prior to the assignment the my_shared_ptr object was already pointing somewhere, the counter for the old block of memory should be decreased by 1, and if it reaches 0, the old block of memory should be released/deleted.
    if (&nmyshptr != this){
        if (counter_ptr == nullptr) {
        } else if (*counter_ptr > 1) {
            *counter_ptr = *counter_ptr - 1;
        } else if (*counter_ptr == 1) {
            delete ptr;
            delete counter_ptr;
        }
        ptr = nmyshptr.ptr;
        counter_ptr = nmyshptr.counter_ptr;
        nmyshptr.ptr = nullptr;
        nmyshptr.counter_ptr = nullptr;
    }
    return *this;
}

template <typename T>
my_shared_ptr<T>& my_shared_ptr<T>::operator= (my_shared_ptr& nmyshptr) {      //Copy assignment should also increase the counter for the newly pointed block of memory.
    if (&nmyshptr != this){
        if (counter_ptr == nullptr) {
        } else if (*counter_ptr > 1) {
            *counter_ptr = *counter_ptr - 1;
        } else if (*counter_ptr == 1) {
            delete ptr;
            delete counter_ptr;
        }
        ptr = nmyshptr.ptr;
        counter_ptr = nmyshptr.counter_ptr;
        if (nmyshptr.counter_ptr != nullptr) { *counter_ptr = *counter_ptr + 1; }
    }
    return *this;
}

template <typename T>
my_shared_ptr<T>::~my_shared_ptr() {    //Destructor that releases/deletes the block of memory and the counter if no other shared pointer points there .
    if ((counter_ptr == nullptr)||(*counter_ptr == 1)) {
        delete ptr;
        delete counter_ptr;
    } else {
        *counter_ptr = *counter_ptr - 1;
    }
}

#endif

