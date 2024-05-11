import random

# Define responses based on rules
keywords = {
    "hi": 1,
    "hii":1,
    "namaste":1,
    "hello" :1,
    "hey":1,
    "how are you?": 2,
    "bye": 3,
    "product":4,
    "item":4,
    "goods":4,
    "website":4,
    "app":4,
    "order":5,
    "update":5,
    "delivery" :5,
    "arrival":5,
    "status": 5,
    "refund": 6,
    "return":6,
    "money back":6,
    "exchange":6,
    "cancel":6,
    "shipping": 7,
    "delay":7,
    "package":7,
    "parcel":7,
    "Track":7,
    "payment methods":8,
    "payment":8,
    "pay":8,
    "checkout":8,
    "purchase":12,
    "buy":12,
    "credit card":8,
    "card":8,
    "transfer":8,
    "thank you": 9,
    "thx": 9,
    "thanx":9,
    "thanks":9,
    "tysm": 9,
    "complaint":10,
    "okay":11,
  

}
rules = {
    1 : ["Hello! How can I assist you today?", "Hi there! What can I help you with?","Hi! I'm here to help. What can I do for you?"],
    2 : ["Fine ,hope you are also doing well"],
    3 : ["Goodbye! Have a great day!", "Visit again!"],
    4 : [ "We are actually Delivering Food items"],
    5 : ["To check your order details, please log in to your account on our website,and go to orders section"],
    6 : ["For refund or cancellation, please contact our customer support team on 91235"],
    7 : ["Our standard shipping time is 3-5 business days."],
    8 : ["We accept various payment methods including credit cards, PayPal,COD,UPI and bank transfer."],
    9 : ["You're welcome!", "If you have any more questions, feel free to ask."],
    10 : ["I'm sorry For the inconvinience. Please provide more details so I can assist you better."],
    11 : ["Great, let me know if you need any further assistance!"],
    12 : ["visit on www.zomato.com to order food items"]
}

def rule_based_chatbot(user_input):
    # Convert input to lowercase for case-insensitive matching
    user_input = user_input.lower().split()
    #print(user_input)
    # Check if the user input matches any rule
    for word in user_input:
        # print("word",word)
        for keyword, resid in keywords.items():
            if word == keyword:
                # print(word," u",user_input, " res" , resid, " rand" , random.choice(rules[resid]))
                return random.choice(rules[resid])

    # If no rule matches, respond with a default message
    return "I'm sorry, I didn't understand that. Please try again ?"

# Main loop for interacting with the chatbot
def main():
    print("Welcome to Zomato Customer Support Chatbot!")


    while True:
        user_input = input("You: ")
        if user_input.lower() == 'bye':
            print(rule_based_chatbot(user_input))
            break
        else:
            print("Chatbot:", rule_based_chatbot(user_input))

if __name__ == "__main__":
    main()
