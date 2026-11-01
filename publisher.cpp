#include "Publisher.hpp"
#include "PubSubSystem.hpp"

//constructor
// Publisher:: ka matlab hai ki ye function Publisher class ka hai.
// Constructor ka naam bhi class ke naam jaisa hi hota hai.
// const std::string& id  , Ye constructor ko publisher ki ID receive karne deta hai.
Publisher::Publisher(const std::string& id, const std::string& name)
    : id(id), name(name) {}

// Pehla id class ka variable hai.
// Doosra id constructor ko mili value hai.

// getter function
std::string Publisher::getId() const {
    return id;
}

std::string Publisher::getName() const {
    return name;
}

void Publisher::publish(PubSubSystem& system, const std::string& topicName, const std::string& content) {
    system.publish(topicName, content);
}