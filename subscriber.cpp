#include "Subscriber.hpp"
#include <iostream>

//make the subscriber active by default
Subscriber::Subscriber(const std::string& id, const std::string& name) : id(id), name(name), active(true) {}

//return id, name, and active status of subscriber
std::string Subscriber::getId() const {
    return id;
}

std::string Subscriber::getName() const {
    return name;
}

bool Subscriber::isActive() const {
    return active;
}

//when topic sends message, this function gets called.
//then checks active status of subscriber
void Subscriber::receiveMessage(const Message& message) {
    // if subscriber is active, send him the message
    if (active) {
        messageQueue.push_back(message);
    }
}

//display messages for subscriber
void Subscriber::displayMessages() const {
    std::cout << "\nMessages for " << name << ":" << std::endl;

    if (messageQueue.empty()) {
        std::cout << "No messages" << std::endl;
        return;
    }

    // for each message of messageQueue
    for (const auto& message : messageQueue) {
        message.displayInfo();      // prints message's topic, content, time
        std::cout << "------------------------" << std::endl;
    }
}

//remove every stored message of subscriber
void Subscriber::clearMessages() {
    messageQueue.clear();
}

void Subscriber::setActive(bool status) {
    active = status;
}

//prints subscriber's name, id, status, count of messages
void Subscriber::displayInfo() const {
    std::cout << "Subscriber: " << name << " (ID: " << id << ")" << std::endl;

    std::cout << "Status: " << (active ? "Active" : "Inactive") << std::endl;

    std::cout << "Messages: " << messageQueue.size() << std::endl;
}


/*
Overall flow: Topic receiveMessage() call karta hai → subscriber active hua toh message apni queue mein store karta hai → baad mein displayMessages() se woh messages dikha sakta hai.
*/