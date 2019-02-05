//Liudmila Zyrianova
//CSCI 335
//09/30/2018
//Programming Assignment 1

#ifndef MY_MEMORY_H
#define MY_MEMORY_H

#include <iostream>

using namespace std;

template <typename T>

class my_unique_ptr {
private:
    T *ptr = nullptr;
public:
    my_unique_ptr () = default;     // Default constructor that initializes the object to point to nullptr.

    explicit my_unique_ptr (T * nptr);      // Constructor that takes a pointer Type * as a parameter and sets the object to point there. We say that the newly created object takes ownership of the pointed memory.

    my_unique_ptr (my_unique_ptr<T> && nmyptr)  ;        // Move constructor that takes my_unique_ptr object and constructs a new object from it.

    my_unique_ptr (const my_unique_ptr& nmyptr) = delete;     // Copy constructor should be explicitly disabled/deleted

    ~my_unique_ptr();       //Destructor that releases/deletes the block of memory pointed by the object.

    T & operator* ();     //Dereference operator * that returns a reference to the item pointed by the object.

    T * operator -> ();      //Operator -> that returns the pointer to the object.

    my_unique_ptr<T>& operator= (my_unique_ptr&& nmyptr)  ;    //Move assignment operator.

    my_unique_ptr<T>& operator= (const my_unique_ptr & nmyptr)= delete;      //Copy assignment operator must be explicitly disabled/deleted
};







template <typename T>

class my_shared_ptr {
private:
    T *ptr= nullptr;
    int *counter_ptr = nullptr;
public:
    my_shared_ptr () = default;     // Default constructor that sets all inner pointers to nullptr.

    explicit my_shared_ptr (T * nptr) ;        // Constructor that takes Type * as a parameter and sets the object to point there.
                                                       //The object considers itself to be the first my_shared_ptr object to point to that block of memory.
                                                                      //So the counter should be set to 1.

    my_shared_ptr (my_shared_ptr && nmyshptr)  ;        // Move constructor. Since the original rvalue wont point to the block of memory no more, the counter should remain the same

    my_shared_ptr (my_shared_ptr& nmyshptr) ;     // Copy constructor. Since the original object already points to the block of memory and now the newly created object points there too, you must increase the counter by 1.

    T & operator* ()  ;      //Dereference operator * that returns a reference to the item pointed by the object.

    T * operator -> () ;        //Operator -> that returns the pointer to the object. It allows to use the my_shared_ptr object for class member access.

    my_shared_ptr<T>& operator= (my_shared_ptr&& nmyshptr)  ;    //Move assignment operator.  If prior to the assignment the my_shared_ptr object was already pointing somewhere, the counter for the old block of memory should be decreased by 1, and if it reaches 0, the old block of memory should be released/deleted.

    my_shared_ptr<T>& operator= (my_shared_ptr& nmyshptr) ;      //Copy assignment should also increase the counter for the newly pointed block of memory.

    ~my_shared_ptr();  //Destructor that releases/deletes the block of memory pointed by the object.

};

#include "my_memory.cpp"

#endif

