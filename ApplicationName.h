#ifndef APPLICATIONNAME_H
#define APPLICATIONNAME_H
#include <iostream>
class ApplicationName {
    friend std::istream& operator >>(std::istream& in, ApplicationName& app){
        std::cout << "Enter the Name of App: ";
        std::getline(in >> std::ws, app.name);
        return in;
    }
    
    public:
        ApplicationName() : name() {} 
        ApplicationName(std::string name) : name(name) {}

         const std::string &getName() const {
            return name;
        }

        bool operator== (const ApplicationName & a) const{
            return name == a.name;
        }
    private:
        std::string name;      
};

namespace std {
    template<>
    struct hash<ApplicationName> {
        size_t operator()(const ApplicationName& app) const {
            return hash<string>()(app.getName());
        }
    };
}
#endif