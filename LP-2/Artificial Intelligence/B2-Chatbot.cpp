#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class SimpleChatbot
{
public:
    string getResponse(const string &user_input) {
        if (containsKeyword(user_input, "hello"))
            return "Hi there!";
        else if (containsKeyword(user_input, "how are you"))
            return "I'm doing well, thank you!";
        else if (containsKeyword(user_input, "bye"))
            return "Goodbye!";
        else
            return "I'm not sure how to respond to that.";
    }

private:
    bool containsKeyword(const string &input, const string &keyword) {
        size_t found = input.find(keyword);
        return (found != string::npos);
    }
};

int main()
{
    SimpleChatbot chatbot;
    string user_input;

    cout << "Simple Chatbot: Hello! Type 'bye' to exit." << endl;

    while (true) {
        cout << "You: ";
        getline(std::cin, user_input);

        if (user_input == "bye") {
            cout << "Simple Chatbot: Goodbye! Have a great day!" << endl;
            break;
        }

        string response = chatbot.getResponse(user_input);
        cout << "Simple Chatbot: " << response << endl;
    }

    return 0;
}
