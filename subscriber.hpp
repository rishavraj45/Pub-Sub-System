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

    void receiveMessage(const Message& message) override;

    void displayMessages() const;
    void clearMessages();
    void setActive(bool status);
    void displayInfo() const;
};

#endif