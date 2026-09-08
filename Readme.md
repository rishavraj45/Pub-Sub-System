# Pub-Sub System in C++

A simple implementation of a **Publish-Subscribe (Pub-Sub) messaging system** using C++ and Object-Oriented Design.

The system allows publishers to publish messages to specific topics, while subscribers can subscribe to topics and receive messages published to those topics.

The main goal of this project is to understand how a basic Publish-Subscribe messaging system can be designed using C++ Object-Oriented Programming and Low-Level Design principles.

---

## Features

- Create and remove topics
- Create and remove subscribers
- Create multiple publishers
- Subscribe to topics
- Unsubscribe from topics
- Publish messages to topics
- Deliver messages to all subscribers of a topic
- Store received messages for each subscriber
- Activate/deactivate subscribers
- Activate/deactivate topics
- Automatic subscriber ID generation
- Uses smart pointers for memory management
- Demonstrates OOP and the Publish-Subscribe design pattern

---

## System Architecture

```text
                    PubSubSystem
                   /     |      \
                  /      |       \
                 ↓       ↓        ↓
             Topics  Subscribers Publishers
                |
                ↓
           Topic "Technology"
                |
          ┌─────┴─────┐
          ↓           ↓
       Subscriber  Subscriber
          |           |
          ↓           ↓
      Message Queue  Message Queue