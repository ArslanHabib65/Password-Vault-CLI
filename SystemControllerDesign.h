#ifndef SYSTEMCONTROLLERDESIGN_H
#define SYSTEMCONTROLLERDESIGN_H

#include <unordered_map>
#include "ApplicationName.h"
#include "ListOfContent.h"
#include <vector>

class SystemControllerDesign {
    friend std::ostream& operator <<(std::ostream& out, const SystemControllerDesign &controller){
        for(const auto& pair : controller.storage){
            out << "Application: " << pair.first.getName() << std::endl;
            for(const auto& content : pair.second){
                out << "  Username: " << content.getUsername() << std::endl;
                out << "  Email: " << content.getEmail() << std::endl;
                out << "  Password: " << content.getPassword() << std::endl;
            }
        }
        return out;
    }
    public: 
        bool addApplication(const ApplicationName &app);
        bool addCredential(const ApplicationName &app, const ListOfContent &content);
        bool removeApplication(const ApplicationName &app);
        bool removeCredential(const ApplicationName &app, const std::string &username, const std::string &email);
        const ListOfContent* searchCredential(const ApplicationName& app, const std::string &username);
        bool updatePassword(const ApplicationName &app, const std::string &username, const std::string &newPassword);
        int numberOfApplication() const;
    private:
        std::unordered_map<ApplicationName, std::vector<ListOfContent>> storage;
};
#endif