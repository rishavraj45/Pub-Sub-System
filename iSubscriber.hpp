#ifndef ISUBSCRIBER_HPP
#define ISUBSCRIBER_HPP

#include "Message.hpp"

class ISubscriber {
public:
    virtual void receiveMessage(const Message& message) = 0;
    virtual ~ISubscriber() = default;
};

#endif