#include "PubSubSystem.hpp"
#include <iostream>
#include <algorithm>

PubSubSystem::PubSubSystem()
    : subscriberIdCounter(1), publisherIdCounter(1) {}

Topic* PubSubSystem::createTopic(
    const std::string& name,
    const std::string& description
) {
    if (findTopic(name)) {
        return nullptr;
    }

    topics.push_back(
        std::make_unique<Topic>(name, description)
    );

    return topics.back().get();
}

void PubSubSystem::removeTopic(const std::string& topicName) {
    topics.erase(
        std::remove_if(
            topics.begin(),
            topics.end(),
            [&](const std::unique_ptr<Topic>& topic) {
                return topic->getName() == topicName;
            }
        ),
        topics.end()
    );
}

Subscriber* PubSubSystem::addSubscriber(const std::string& name) {
    std::string id = "SUB" + std::to_string(subscriberIdCounter++);

    subscribers.push_back(
        std::make_unique<Subscriber>(id, name)
    );

    return subscribers.back().get();
}

void PubSubSystem::removeSubscriber(
    const std::string& subscriberId
) {
    Subscriber* subscriber = findSubscriber(subscriberId);

    if (!subscriber) {
        return;
    }

    for (auto& topic : topics) {
        topic->removeSubscriber(subscriber);
    }

    subscribers.erase(
        std::remove_if(
            subscribers.begin(),
            subscribers.end(),
            [&](const std::unique_ptr<Subscriber>& sub) {
                return sub->getId() == subscriberId;
            }
        ),
        subscribers.end()
    );
}

bool PubSubSystem::subscribe(
    const std::string& subscriberId,
    const std::string& topicName
) {
    Subscriber* subscriber = findSubscriber(subscriberId);
    Topic* topic = findTopic(topicName);

    if (!subscriber || !topic) {
        return false;
    }

    topic->addSubscriber(subscriber);

    return true;
}

bool PubSubSystem::unsubscribe(
    const std::string& subscriberId,
    const std::string& topicName
) {
    Subscriber* subscriber = findSubscriber(subscriberId);
    Topic* topic = findTopic(topicName);

    if (!subscriber || !topic) {
        return false;
    }

    topic->removeSubscriber(subscriber);

    return true;
}

bool PubSubSystem::publish(
    const std::string& topicName,
    const std::string& content
) {
    Topic* topic = findTopic(topicName);

    if (!topic || !topic->isActive()) {
        return false;
    }

    Message message(topicName, content);

    topic->publishMessage(message);

    return true;
}

void PubSubSystem::displayTopics() const {
    std::cout << "\nAvailable Topics:\n";

    for (const auto& topic : topics) {
        topic->displayInfo();
        std::cout << "------------------------\n";
    }
}

void PubSubSystem::displaySubscribers() const {
    std::cout << "\nRegistered Subscribers:\n";

    for (const auto& subscriber : subscribers) {
        subscriber->displayInfo();
        std::cout << "------------------------\n";
    }
}

Topic* PubSubSystem::findTopic(
    const std::string& topicName
) {
    for (auto& topic : topics) {
        if (topic->getName() == topicName) {
            return topic.get();
        }
    }

    return nullptr;
}

Subscriber* PubSubSystem::findSubscriber(
    const std::string& subscriberId
) {
    for (auto& subscriber : subscribers) {
        if (subscriber->getId() == subscriberId) {
            return subscriber.get();
        }
    }

    return nullptr;
}