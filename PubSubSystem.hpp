#ifndef PUB_SUB_SYSTEM_HPP
#define PUB_SUB_SYSTEM_HPP

#include <string>       // for name and ids
#include <vector>       // for storing subscribers list
#include <memory>       // to use std::unique_ptr

// PubSubSystem has to work with topic and subscribers
#include "Topic.hpp"
#include "Subscriber.hpp"

class PubSubSystem {
private:
    std::vector<std::unique_ptr<Topic>> topics;
    std::vector<std::unique_ptr<Subscriber>> subscribers;
    /*
    System has two lists, topics:- all topics, subscribers:- all subscribers.
    unique_ptr is for memory management. It automatically clears the memory. So no need to write 'delete'.
     */


    // counters to generate Ids for subscriber, publisher
    int subscriberIdCounter;
    int publisherIdCounter;

    //helper functions for searching topic by it's name, and subscriber by it's id.
    //return type is Topic*, Subscriber*, means it returns Object's address.
    Topic* findTopic(const std::string& topicName);
    Subscriber* findSubscriber(const std::string& subscriberId);

public:
    //constructor
    PubSubSystem();

    // it creates new topic, and returns it's pointer
    Topic* createTopic(
        const std::string& name,
        const std::string& description
    );

    // to remove a topic
    void removeTopic(const std::string& topicName);

    //creates subscriber and return it's pointer
    Subscriber* addSubscriber(const std::string& name);
    //removes subscriber
    void removeSubscriber(const std::string& subscriberId);

    //add subscriber to the topic's list
    bool subscribe(
        const std::string& subscriberId,
        const std::string& topicName
    );

    //remove subscriber from the topic's list
    bool unsubscribe(
        const std::string& subscriberId,
        const std::string& topicName
    );

    //publish message, will be used to send message to topic
    bool publish(
        const std::string& topicName,
        const std::string& content
    );

    //display topics and subscribers
    void displayTopics() const;
    void displaySubscribers() const;
};

#endif