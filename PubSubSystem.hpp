#ifndef PUB_SUB_SYSTEM_HPP
#define PUB_SUB_SYSTEM_HPP

#include <string>
#include <vector>
#include <memory>

#include "Topic.hpp"
#include "Subscriber.hpp"

class PubSubSystem {
private:
    std::vector<std::unique_ptr<Topic>> topics;
    std::vector<std::unique_ptr<Subscriber>> subscribers;

    int subscriberIdCounter;
    int publisherIdCounter;

    Topic* findTopic(const std::string& topicName);
    Subscriber* findSubscriber(const std::string& subscriberId);

public:
    PubSubSystem();

    Topic* createTopic(
        const std::string& name,
        const std::string& description
    );

    void removeTopic(const std::string& topicName);

    Subscriber* addSubscriber(const std::string& name);
    void removeSubscriber(const std::string& subscriberId);

    bool subscribe(
        const std::string& subscriberId,
        const std::string& topicName
    );

    bool unsubscribe(
        const std::string& subscriberId,
        const std::string& topicName
    );

    bool publish(
        const std::string& topicName,
        const std::string& content
    );

    void displayTopics() const;
    void displaySubscribers() const;
};

#endif