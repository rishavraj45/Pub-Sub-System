#include "Topic.hpp"
#include <iostream>
#include <algorithm>

Topic::Topic(const std::string& name, const std::string& description)
    : name(name), description(description), active(true) {}

std::string Topic::getName() const {
    return name;
}

std::string Topic::getDescription() const {
    return description;
}

bool Topic::isActive() const {
    return active;
}

void Topic::addSubscriber(ISubscriber* subscriber) {
    if (!subscriber) return;

    if (std::find(subscribers.begin(), subscribers.end(), subscriber)
        == subscribers.end()) {
        subscribers.push_back(subscriber);
    }
}

void Topic::removeSubscriber(ISubscriber* subscriber) {
    subscribers.erase(
        std::remove(subscribers.begin(), subscribers.end(), subscriber),
        subscribers.end()
    );
}

void Topic::publishMessage(const Message& message) {
    if (!active) return;

    for (auto subscriber : subscribers) {
        subscriber->receiveMessage(message);
    }
}

void Topic::setActive(bool status) {
    active = status;
}

void Topic::displayInfo() const {
    std::cout << "Topic: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Status: "
              << (active ? "Active" : "Inactive") << std::endl;
    std::cout << "Subscribers: "
              << subscribers.size() << std::endl;
}