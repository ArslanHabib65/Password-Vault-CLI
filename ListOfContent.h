#ifndef LISTOFCONTENT_H
#define LISTOFCONTENT_H
#include <iostream>
class ListOfContent {
    friend std::istream& operator >>(std::istream& in, ListOfContent &list) {
        std::cout << "Enter the User Name: ";
        list.username = userName(in);
        std::cout << "Enter the Email: ";
        in >> list.email;
        std::cout << "Enter the Password: ";
        list.password = StrongPasswordCheck(in, list.username);
        return in;
    }

    friend std::ostream& operator <<(std::ostream& os, const ListOfContent &list){
        os << "Username: " << list.username << "\n";
        os << "Email: " << list.email << "\n";
        os << "Password: " << list.password << "\n";
        return os;
    }
    public: 
        ListOfContent() = default;
        ListOfContent(std::string username, std::string password) :
         username(username), email(), password(password) {}
        ListOfContent(std::string username, std::string email, std::string password) :
         username(username), email(email), password(password) {}

        const std::string &getUsername() const {
            return username;
        }

        const std::string &getEmail() const {
            return email;
        }

        const std::string &getPassword() const {
            return password;
        }

        void setUserName(const std::string &u) {
            username = u;
        }

        void setEmail(const std::string &e) {
            email = e;
        }
        void setPassword(const std::string &p){
            password = p;
        }

        bool operator==(const ListOfContent &other) {
            return username == other.username && 
            email == other.email && password == other.password;
        }
    private:
        std::string username;
        std::string email;
        std::string password;

        std::string static userName(std::istream &in) {
            std::string input;
            while(true){
                in >> input;
                if(input.find(' ') != std::string::npos){
                    std::cout << "Username cannnot contain spaces. Try again: ";
                } else if (input.empty()){
                    std::cout << "Username cannot be empty. Try again: ";
                } else {
                    return input;
                }
            }
        }

        std::string static StrongPasswordCheck(std::istream &in, const std::string& username){
            std::string input;
            while (true){
                in >> input;
                if(input.find(username) != std::string::npos){
                    std::cout << "Password cannot contain username.\n Try again: ";
                } else if (input.length() < 10){
                    std::cout << "Password too short.\n Try again: ";
                } else {
                    return input;
                }
            }
        }


};

namespace std {
    template <>
        struct hash<ListOfContent> {
            size_t operator() ( const ListOfContent &content) const {
                size_t h1 = hash<std::string>() (content.getUsername());
                size_t h2 = hash<std::string> () (content.getEmail());
                size_t h3 = hash<std::string> () (content.getPassword());

                return h1 ^ (h1 << 1) ^ (h3 << 2);
            }
        };
    }
#endif