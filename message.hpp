#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <ctime>

class Message {
    // Message class ek message ki details store karti hai.
private:
    // message's topic(sports/tech), actual message, when was message created
    std::string topic;
    std::string content;
    std::time_t timestamp;

public:
    // Constructor message banate waqt topic aur content leta hai
    Message(const std::string& topic, const std::string& content);

    //these functions returns message's topic, content, timestamp
    std::string getTopic() const;
    std::string getContent() const;
    std::time_t getTimestamp() const;

    void displayInfo() const;      //function to display message
};

#endif


/*
Overall: Message ek chhota data object hai jo batata hai ki message kis topic ka hai, usmein kya likha hai, aur woh kab bana. Topic ise subscribers tak pahunchata hai, aur Subscriber ise apni message queue mein store karta hai.
*/