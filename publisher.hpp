//Publisher.hpp publisher ka structure batata hai. Ye nahi batata ki message actually kaise publish hota hai. Uske liye Publisher.cpp dekhna hoga.

// called header guards
#ifndef PUBLISHER_HPP   //ifndef ka matlab hai if not defined.
#define PUBLISHER_HPP

#include <string>   //hum apne publisher ka naam aur ID store karenge.

class PubSubSystem;
// Abhi humne PubSubSystem class ka complete code nahi likha hai. Sirf uska naam bataya hai.  Kyuki publisher ko message bhejne ke liye PubSubSystem ki zaroorat padegi. Lekin publisher ki header file mein poori system class ka code likhne ki zaroorat nahi hai.

class Publisher {
private:        //can't directly access below variables, outside this class
    // Private rakhne ka purpose hai ki publisher ka data directly bahar se change na ho.
    std::string id; 
    std::string name;

public:
    // constructor:- Constructor ek special function hota hai jo object banate waqt automatically call hota hai.
    // constructor publisher ka ID aur naam set karne ke liye hai.
    Publisher(const std::string& id, const std::string& name);

    std::string getId() const;       //Ye ek function hai jo publisher ki ID return karega.   const ka matlab hai ki ye function publisher ke data ko change nahi karega.

    std::string getName() const;     //publisher ka naam return karega.

    // getId() aur getName() ko getter functions kehte hain, kyunki ye private variables ki values bahar provide karte hain.
    // getter functions are only defined here, their full code in publisher.cpp

    void publish(
        // Ye hamare publisher ka main function hai. Isko teen cheezein chahiye:

        PubSubSystem& system,                 // Jis PubSubSystem mein message bhejna hai
        const std::string& topicName,         // Kis topic par message bhejna hai
        const std::string& content            // Message kya hai

        /*Publisher ko ye nahi pata ki Technology topic par John aur Bob subscribed hain. Publisher sirf system ko message bhejta hai. System aur topic decide karte hain ki message kisko milega.*/
    );
};

#endif      //closes header guard



/*
Ab poori file ka simple meaning
Publisher.hpp bas ye batata hai:
- Publisher ke paas ID aur naam hoga.
- Publisher banate waqt uski ID aur naam set honge.
- Uski ID aur naam baad mein read kar sakte hain.
- Publisher kisi topic par message bhej sakta hai.
Is file mein message bhejne ka actual code nahi hai. Woh Publisher.cpp mein hoga.
 */