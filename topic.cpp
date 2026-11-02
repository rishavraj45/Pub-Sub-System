#include "Topic.hpp"        //topic class ki declaration
#include <iostream>
#include <algorithm>        // to use std::find and std::remove here

// constructor: stores topic's name and description, and set the active status true
// means NEW TOPICS are active by default
Topic::Topic(const std::string& name, const std::string& description) : name(name), description(description), active(true) {}

// returns topic's name
std::string Topic::getName() const {
    return name;
}

// returns topic's description
std::string Topic::getDescription() const {
    return description;
}

// is topic active or not?
bool Topic::isActive() const {
    return active;
}

//add subscriber in a topic's list
void Topic::addSubscriber(ISubscriber* subscriber) {
    if (!subscriber) return;                 // means not pointing to any valid subscriber

    if (std::find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
        // topic ke subscribers ki list me iss subscriber ko add kar do
        subscribers.push_back(subscriber);
    }
}

//remove subscriber
void Topic::removeSubscriber(ISubscriber* subscriber) {
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
}

// publish message
void Topic::publishMessage(const Message& message) {
    // if topic is inative, don't send message further
    if (!active) return;

    // send message to each subscriber
    for (auto subscriber : subscribers) {
        subscriber->receiveMessage(message);
    }
}

// toggle topic between active/inactive
void Topic::setActive(bool status) {
    active = status;
}

// print topic's details
void Topic::displayInfo() const {
    std::cout << "Topic: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Status: " << (active ? "Active" : "Inactive") << std::endl;
    std::cout << "Subscribers: " << subscribers.size() << std::endl;
}


/*
Overall flow: PubSubSystem topic ko message deta hai → topic me pehle check hota hai ki ye topic active hai ya nahi → active hone par har subscriber ko message forward karta hai.
*/