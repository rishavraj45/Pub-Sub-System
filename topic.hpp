#ifndef TOPIC_HPP
#define TOPIC_HPP

#include <string>
#include <vector>
#include "ISubscriber.hpp"

class Topic {
private:
    std::string name;
    std::string description;
    std::vector<ISubscriber*> subscribers;
    bool active;

public:
    Topic(const std::string& name, const std::string& description);

    std::string getName() const;
    std::string getDescription() const;
    bool isActive() const;

    void addSubscriber(ISubscriber* subscriber);
    void removeSubscriber(ISubscriber* subscriber);

    void publishMessage(const Message& message);

    void setActive(bool status);
    void displayInfo() const;
};

#endif