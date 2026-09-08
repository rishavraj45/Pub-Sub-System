#ifndef SUBSCRIBER_HPP
#define SUBSCRIBER_HPP

#include <string>
#include <vector>
#include "ISubscriber.hpp"

class Subscriber : public ISubscriber {
private:
    std::string id;
    std::string name;
    std::vector<Message> messageQueue;
    bool active;

public:
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