#ifndef SUBSCRIBER_HPP
#define SUBSCRIBER_HPP

#include <string>
#include <vector>
#include "ISubscriber.hpp"

class Subscriber : public ISubscriber {
private:
    // subscriber's datas
    std::string id;                    //subscriber's unique id
    std::string name;                  // subscriber's name
    std::vector<Message> messageQueue;      //list of messages this subscriber got
    bool active;                      // subscriber active or not

public:
    // Constructor subscriber banate waqt uski ID aur naam leta hai.
    Subscriber(const std::string& id, const std::string& name);

    std::string getId() const;
    std::string getName() const;
    bool isActive() const;
    //const ka matlab ye functions stored data ko change nahi karte.

    void receiveMessage(const Message& message) override;

    void displayMessages() const;             //stored messages dikhata hai
    void clearMessages();                     //message list ko empty karta hai
    void setActive(bool status);              //subscriber ko active ya inactive karta hai
    void displayInfo() const;                 //subscriber ki details dikhata hai.
};

#endif


/*
Overall flow: Topic message bhejta hai → subscriber ka receiveMessage() call hota hai → message uski queue mein store hota hai → displayMessages() se baad mein dekha ja sakta hai.
*/