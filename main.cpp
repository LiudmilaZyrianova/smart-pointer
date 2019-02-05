//Liudmila Zyrianova
//CSCI 335
//09/30/2018
//Programming Assignment 1
/*
#include <iostream>
#include <string>
#include <utility>
#include "my_memory.h"

using unique = my_unique_ptr<std::string>;
using shared = my_shared_ptr<std::string>;

void lol(shared *p1, shared *p2)
{
    *p1 = *p2;
    cout << **p1 << endl;
}

int main()
{
    {
        unique u1{new std::string("some string of significant length\n")};
        unique u2{std::move(u1)};
        unique u3;
        std::cout << *u2;

        u3 = std::move(u2);

        std::cout << "the size of the string is " << u3->size() << std::endl;


        shared s1{new std::string("another string of significant length\n")};
        shared s2{std::move(s1)};
        shared s3{new std::string("kek another string of significant length\n")};
        shared s4{s3};
        shared s5;
        s5 = s3;
        std::cout << *s2;
        s2 = s3;
        //lol(&s4, &s3);
        s4 = move(s3);
        s4 = s3;
//        shared *pp = new shared {new string("super test")};
        {
            shared popa(nullptr);
            //cout << *popa << endl;
            shared kaka;
            kaka = popa;

        }

        std::cout << "the size of the string is " << (*s4).size() << std::endl;
    }
    cout << "Everything is ok kek" << endl;
    return 0;
}*/



#include <iostream>
#include <string>
#include <utility>
#include "my_memory.h"


using unique = my_unique_ptr<std::string>;
using shared = my_shared_ptr<std::string>;

int main()
{
    unique u1{ new std::string("some string of significant length\n") };
    unique u2{ std::move(u1) };
    unique u3;

    std::cout << *u2;

    u3 = std::move(u2);

    std::cout << "the size of the string is " << u3->size() << std::endl;


///////////////////////////////////////////////////////////////////////

    shared s1{ new std::string("another string of significant length\n") };
    shared s2{ std::move(s1) };
    shared s3;
    shared s4{ s3 };

    std::cout << *s2;

    s3 = std::move(s2);
    s4 = s3;

    std::cout << "the size of the string is " << s4->size() << std::endl;

    return 0;
}