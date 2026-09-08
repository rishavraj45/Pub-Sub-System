#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include <string>

class PubSubSystem;

class Publisher {
private:
    std::string id;
    std::string name;

public:
    Publisher(const std::string& id, const std::string& name);

    std::string getId() const;
    std::string getName() const;

    void publish(
        PubSubSystem& system,
        const std::string& topicName,
        const std::string& content
    );
};

#endif