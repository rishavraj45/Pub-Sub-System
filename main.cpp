#include <iostream>

#include "PubSubSystem.hpp"
#include "Publisher.hpp"

int main() {
    PubSubSystem system;

    // Create topics
    system.createTopic(
        "Technology",
        "Tech news and updates"
    );

    system.createTopic(
        "Sports",
        "Sports news and scores"
    );

    system.createTopic(
        "Weather",
        "Weather updates"
    );

    // Create subscribers
    Subscriber* john = system.addSubscriber("John");
    Subscriber* alice = system.addSubscriber("Alice");
    Subscriber* bob = system.addSubscriber("Bob");

    // Create publishers
    Publisher techPublisher("PUB1", "Tech Publisher");
    Publisher sportsPublisher("PUB2", "Sports Publisher");

    // Subscribe users
    system.subscribe(john->getId(), "Technology");
    system.subscribe(john->getId(), "Weather");

    system.subscribe(alice->getId(), "Sports");

    system.subscribe(bob->getId(), "Technology");
    system.subscribe(bob->getId(), "Sports");

    // Display system
    system.displayTopics();
    system.displaySubscribers();

    // Publish messages
    std::cout << "\nPublishing messages...\n";

    techPublisher.publish(
        system,
        "Technology",
        "New AI breakthrough!"
    );

    sportsPublisher.publish(
        system,
        "Sports",
        "Team A wins championship!"
    );

    techPublisher.publish(
        system,
        "Weather",
        "Sunny weather expected"
    );

    // Display messages
    std::cout << "\nSubscriber Messages:\n";

    john->displayMessages();
    alice->displayMessages();
    bob->displayMessages();

    // Unsubscribe John
    std::cout << "\nJohn unsubscribes from Weather...\n";

    system.unsubscribe(
        john->getId(),
        "Weather"
    );

    techPublisher.publish(
        system,
        "Weather",
        "Storm warning!"
    );

    std::cout << "\nJohn's updated messages:\n";

    john->displayMessages();

    return 0;
}