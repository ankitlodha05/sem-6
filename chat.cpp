#include <iostream>
#include <string>
#include <map>

using namespace std;

string curr_next;

class CustomerServiceChatbot
{
private:
    map<string, map<string, string>> context; // Map to store context

public:
    CustomerServiceChatbot()
    {
        // Initialize context with default values
        context["apple"] = {{"color", "red"}, {"type", "fruit"}, {"price", "$2.00"}, {"usages", "snacks"}, {"benefits", "nutritious"}};
        context["banana"] = {{"color", "yellow"}, {"type", "fruit"}, {"price", "$1.50"}, {"usages", "smoothies"}, {"benefits", "energy"}};
        context["orange"] = {{"color", "orange"}, {"type", "fruit"}, {"price", "$1.80"}, {"usages", "juices"}, {"benefits", "vitamin C"}};
        context["potato"] = {{"color", "brown"}, {"type", "vegetable"}, {"price", "$0.80"}, {"usages", "fries"}, {"benefits", "carbohydrates"}};
        context["tomato"] = {{"color", "red"}, {"type", "vegetable"}, {"price", "$1.20"}, {"usages", "soups"}, {"benefits", "lycopene"}};
        context["carrot"] = {{"color", "orange"}, {"type", "vegetable"}, {"price", "$0.90"}, {"usages", "salads"}, {"benefits", "vitamin A"}};
        context["current_context"] = {{"context", "None"}}; // Initialize current item to None
    }

    void handleUserInput(const string &userInput)
    {

        // Check if user input contains a keyword from context
        for (const auto &pair : context)
        {
            if (userInput.find(pair.first) != string::npos)
            {
                // Update current context
                context["current_context"] = pair.second;
                curr_next = pair.first;

                // Provide response based on context
                cout << "Chatbot: ";
                if (userInput == pair.first)
                { // Check if userInput is exactly equal to the keyword
                    cout << "Color of " << pair.first << " is " << pair.second.at("color") << "." << endl;
                    cout << "Type of " << pair.first << " is " << pair.second.at("type") << "." << endl;
                    cout << "Price Per Kg of " << pair.first << " is " << pair.second.at("price") << "." << endl;
                    cout << "Usages of " << pair.first << " is " << pair.second.at("usages") << "." << endl;
                    cout << "Benefits of " << pair.first << " is " << pair.second.at("benefits") << "." << endl;
                }
                else
                {
                    int count = 0;
                    if (userInput.find("color") != string::npos)
                    {
                        cout << "Color of " << pair.first << " is " << pair.second.at("color") << "." << endl;
                        count++;
                    }
                    if (userInput.find("type") != string::npos)
                    {
                        cout << "Type of " << pair.first << " is " << pair.second.at("type") << "." << endl;
                        count++;
                    }
                    if (userInput.find("price") != string::npos)
                    {
                        cout << "Price Per Kg of " << pair.first << " is " << pair.second.at("price") << "." << endl;
                        count++;
                    }
                    if (userInput.find("usages") != string::npos)
                    {
                        cout << "Usages of " << pair.first << " is " << pair.second.at("usages") << "." << endl;
                        count++;
                    }
                    if (userInput.find("benefits") != string::npos)
                    {
                        cout << "Benefits of " << pair.first << " is " << pair.second.at("benefits") << "." << endl;
                        count++;
                    }
                    if(count == 0){
                        cout << "Yes i do have " << pair.first <<endl;
                        count++;
                    }
                    
                }
                return;
            }
        }

        // If no context matches, use previously stored context
        if (context["current_context"]["context"] != "None")
        {
            bool flag = false;
            cout << "Chatbot: ";
            if (userInput.find("color") != string::npos)
            {
                cout << "Color of " << curr_next << " is "
                     << context["current_context"].at("color") << "." << endl;
                flag = true;
            }
            if (userInput.find("type") != string::npos)
            {
                cout << "Type of " << curr_next << " is "
                     << context["current_context"].at("type") << "." << endl; // Access price directly from the context
                flag = true;

            }
            if (userInput.find("price") != string::npos)
            {
                cout << "Price of " << curr_next << " is "
                     << context["current_context"].at("price") << "." << endl; // Access price directly from the context
                flag = true;

            }
            if (userInput.find("usages") != string::npos)
            {
                cout << "Usages of " << curr_next << " is "
                     << context["current_context"].at("usages") << "." << endl; // Access price directly from the context
                flag = true;

            }
            if (userInput.find("benefits") != string::npos)
            {
                cout << "Benefits of " << curr_next << " is "
                     << context["current_context"].at("benefits") << "." << endl; // Access price directly from the context
                flag = true;
            }
            if(!flag)
            {
                cout << "I'm sorry, I didn't understand your query. Could you please rephrase?" << endl;
            }
        }
        else
        {
            cout << "Chatbot: I'm sorry, I didn't understand your query. Could you please provide more context?" << endl;
        }
    }
};

int main()
{
    CustomerServiceChatbot chatbot;

    cout << "Welcome to Customer Service Chatbot" << endl;
    cout << "You can start chatting. Type 'bye' to exit." << endl;

    string userInput;
    while (true)
    {
        cout << "User: ";
        getline(cin, userInput);

        if (userInput == "bye")
        {
            cout << "Chatbot: Goodbye! Have a great day!" << endl;
            break;
        }

        chatbot.handleUserInput(userInput);
    }

    return 0;
}