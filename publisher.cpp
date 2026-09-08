#include "Publisher.hpp"
#include "PubSubSystem.hpp"

Publisher::Publisher(const std::string& id, const std::string& name)
    : id(id), name(name) {}

std::string Publisher::getId() const {
    return id;
}

std::string Publisher::getName() const {
    return name;
}

void Publisher::publish(
    PubSubSystem& system,
    const std::string& topicName,
    const std::string& content
) {
    system.publish(topicName, content);
}