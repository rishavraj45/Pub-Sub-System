#include "Message.hpp"
#include <iostream>
/*
:: tells the compiler which class or namespace a name belongs to
Message::getTopic()  --> getTopic() function belongs to the Message class.
*/

//ye message class ka constructor hai, takes topic and content to create message
Message::Message(const std::string& topic, const std::string& content) : topic(topic), content(content) {
    // : topic(topic), content(content) --> it stores both values in the class variables

    // std::time() gives current time
    timestamp = std::time(nullptr);
}

//return stored topic name
std::string Message::getTopic() const {
    return topic;
}

// returns message's text
std::string Message::getContent() const {
    return content;
}

// returns message's creation time
std::time_t Message::getTimestamp() const {
    return timestamp;
}


// prints message's details on console
void Message::displayInfo() const {
    std::cout << "Topic: " << topic << std::endl;
    std::cout << "Content: " << content << std::endl;
    std::cout << "Time: " << std::ctime(&timestamp);
    // std::ctime() needs address of time instead of value. So &timestamp for address of timestamp variable.
}


/*
Overall: Message.cpp message banata hai, uska topic/content/time store karta hai, aur zaroorat par ye details display karta hai.
*/