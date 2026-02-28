#include "SystemControllerDesign.h"
#include <vector>
bool SystemControllerDesign::addApplication(const ApplicationName &app){
    // check if app already exist.
    if(storage.find(app) != storage.end()){
        std::cout << "Already Exist!" << std::endl;
        return false;
    } 
    storage[app] = std::vector<ListOfContent>();
    return true;
}
     
bool SystemControllerDesign::addCredential(const ApplicationName &app, const ListOfContent &content){
    if(storage.find(app) == storage.end()){
        return false;
    } else {
        storage[app].push_back(content);
        return true;
    }
}

bool SystemControllerDesign::removeApplication(const ApplicationName &app){
    if(storage.find(app) != storage.end()){
        storage.erase(app);
        return true;
    } else {
        return false;
    }
}

// bool SystemControllerDesign::removeCredential(const ApplicationName &app, const std::string &username, const std::string &email){
//     if(storage.find(app) != storage.end()){
//         int count = 0;
//         for(const auto &it : storage[app]){
//             if(it.getEmail() == email) {
//                 if(it.getUsername() == username){
//                     storage[app].erase(storage[app].begin() + count);
//                     return true;
//                 }
//             }
//             count++;
//         }
//     }

//     return false;
// }

// More Efficient method but same as above

bool SystemControllerDesign::removeCredential(const ApplicationName &app, const std::string &username, const std::string  &email){

    // try to find the application inside the Unordered Map
    auto appIt = storage.find(app);

    // if the application is not found, return false immediately.
    if(appIt == storage.end()){
        return false;
    }

    // appIt-> second gives us the vector<ListOfContent>
    // we store it as refernce so we don't repeatedly access storage[app]
    auto &credentials = appIt->second;

    // create an iterator that starts at the beginning of vector
    for(auto it = credentials.begin(); it != credentials.end(); ++it){
        // it is an iterator pointing to a ListOfContent Object;
        if(it->getEmail() == email && it->getUsername() == username){
            credentials.erase(it);
            return true;
        }
    }
    return false;
}

const ListOfContent* SystemControllerDesign::searchCredential(const ApplicationName& app, const std::string &username){
    auto appIt = storage.find(app);
    if(appIt == storage.end()){
        return nullptr;
    }
    auto &credentials = appIt->second;
    for(auto it = credentials.begin(); it != credentials.end(); ++it){
        if(it -> getUsername() == username) {
            return &(*it);
        }
    }
    return nullptr;
}

 bool SystemControllerDesign::updatePassword(const ApplicationName &app, const std::string &username, const std::string &newPassword){
    auto appIt = storage.find(app);
    if(appIt != storage.end()){
        auto &credential = appIt->second;
        for(auto it = credential.begin(); it != credential.end(); ++it){
            if(it->getUsername() == username){
                it->setPassword(newPassword);
                return true;
            }
        }
    }
    return false;
 }


int SystemControllerDesign::numberOfApplication() const{
    return storage.size();
}