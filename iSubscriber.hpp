#ifndef ISUBSCRIBER_HPP
#define ISUBSCRIBER_HPP

#include "Message.hpp"      //subscriber jab message receive karega, toh usko Message object milega. so included Message.hpp

// only abstract function class => so ISubscriber is a interface
// named I for interface
class ISubscriber {
public:
    virtual void receiveMessage(const Message& message) = 0;
        /*void : function koi value return nahi krega
          receiveMessage() : ye function message receive krne k liy h
          const Message& message : function ko ek message oject diya jayega
          const : function message ko modify nhi karega*/

    // destructor : gets called when object destroys
    virtual ~ISubscriber() = default;
};

#endif


/*Maan lo tumhare system mein John, Alice aur Bob subscribers hain. Teeno ko messages receive karne hain, lekin teeno ka message receive karne ka tareeka alag ho sakta hai.

Tum chahte ho ki teeno mein ek common function ho: receiveMessage().

Isi kaam ke liye ISubscriber interface banaya gaya hai.*/