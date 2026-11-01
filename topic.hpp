#ifndef TOPIC_HPP
#define TOPIC_HPP

#include <string>              //topic ka name and description store krne k liye
#include <vector>              //subscribers ki list store krne k liye
#include "ISubscriber.hpp"     //subscriber interface because, topic ko subscribers k sath kaam krna h

class Topic {
private:
    std::string name;             //topic's name
    std::string description;      //topic's description
    std::vector<ISubscriber*> subscribers;        //subscriber's list who are following this topic
    bool active;                     // topic abhi active hai ya nhi?

public:
    // Constructor. Jab naya topic banega, uska naam aur description diye jayenge.
    Topic(const std::string& name, const std::string& description);

    std::string getName() const;
    std::string getDescription() const;
    bool isActive() const;

    void addSubscriber(ISubscriber* subscriber);         //add subscriber in topic's list
    void removeSubscriber(ISubscriber* subscriber);      //remove subscriber from topic's list

    void publishMessage(const Message& message);
    // Is function ko message diya jaata hai. Topic apni subscriber list ke logon ko woh message bhej sakta hai—usually har subscriber ka receiveMessage() call karke.

    void setActive(bool status);            //'setActive' topic ko active ya inactive krta h
    void displayInfo() const;           //display topic's details
};

#endif



/*
Overall: Topic message ko khud create nahi karta. Woh subscribers ki list rakhta hai aur publisher se aaya message un tak pahunchane ka kaam karta hai.
*/