#include <iostream>
#include "ApplicationName.h"
#include "ListOfContent.h"
#include "VaultSecurity.h"
#include "SystemControllerDesign.h"
#include <unordered_map>
#include <cctype>

using namespace std;

bool accessGranted(VaultSecurity &securityKey, const string &inputkey){
    return securityKey.unlock(inputkey);
}

void prompt(){
    cout << "\n====== VAULT MENU ======\n" << endl;
    cout << "A - Add Application" << endl;
    cout << "B - Remove Application" << endl;
    cout << "C - Add Credential" << endl;
    cout << "D - Delete Credential" << endl;
    cout << "S - Search Credentials for a Given Application" << endl;
    cout << "U - Update Password" << endl;
    cout << "L - Lock Vault" << endl;
    cout << "N - Number fo Applications" << endl;
    cout << "V - View Vault (Debug Mode)" << endl;
    cout << "Q - Quick" << endl;
}


bool validChoice(char c) {
    char listOfValidInputChar[] = { 'a', 'b', 'c', 'd', 's', 'u', 'l', 'n', 'v', 'q' };
    int length = sizeof(listOfValidInputChar) / sizeof(listOfValidInputChar[0]);
    for(int i = 0; i < length; i++){
        if(c == listOfValidInputChar[i]){
            return true;
        }
    }
    return false;
}


int main(){
    std::cout << R"(

 __        __   _                            _          __      __           _ _   
 \ \      / /__| | ___ ___  _ __ ___   ___  | |_ ___    \ \    / /__ _ _   _| | |_ 
  \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \    \ \/\/ / _ \ | | | | | __|
   \ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |    \_/\_/  __/ | |_| | | |_ 
    \_/\_/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/                |_|____/|_|\__|

                           W E L C O M E   T O   V A U L T

)" << std::endl;
    SystemControllerDesign storage;
    VaultSecurity security("1234@");
    cout << "Enter Master Key: ";
    string inputKey;
    cin >> inputKey;

    bool running = true;
    // check the user enter Valid securityKey
    if(accessGranted(security, inputKey)){
        prompt();
        while(running){
            cout << "Enter the Choice: ";
            string input;
            getline(cin >> ws, input);
            if(input.empty()){
                cout << "Choice cannot be empty. Try again!" << endl;
                continue;
            } 
            char choice = tolower(input[0]);

            if(!validChoice(choice)) {
                cout << "You picked invalid choice character!" << endl;
                continue;   
            }
        
            switch(choice){
                case 'a': {
                    ApplicationName app;
                    std::cin >> app;
                    bool result = storage.addApplication(app);
                    if(result){
                        cout << "Application Added Successfully!" << endl;
                    } else {
                        cout << "Application Already Exists!" << endl;
                    }
                    break;
                }

                case 'b': {
                    string appName;
                    cout << "Enter the Name of App to Remove: ";
                    getline(cin >> ws, appName); 
                    bool result = storage.removeApplication(ApplicationName(appName));
                    if(result){
                        cout << "Application Removed Successfully!" << endl;
                    } else {
                        cout << "Application Not Found!" << endl;
                    }
                    break;
                }

                case 'c': {
                    ApplicationName app;
                    cin >> app;
                    ListOfContent content;
                    cin >> content;
                    if(storage.addCredential(app, content)){
                        cout << "Credential Added Successfully!" << endl;
                    } else {
                        cout << "Failed to Add Credential!" << endl;
                    }
                    break;
                }

                case 'd': {
                    ApplicationName app;
                    cin >> app;
                    string username, email;
                    cout << "Enter the username: ";
                    cin >> username;
                    cout << "Enter the email: ";
                    cin >> email; 
                    if (storage.removeCredential(app, username, email)){
                        cout << "Credential remove successfully!" << endl;
                    } else {
                        cout << "Failed to remove the Credential" << endl;
                    }
                    break;
                }

                case 's': {
                    ApplicationName app;
                    cin >> app;
                    string username;
                    cout << "Enter the username: ";
                    cin >> username;
                    const ListOfContent* credential =
                    storage.searchCredential(app, username);

                    if (credential == nullptr) {
                        cout << "No such Credential exists for given app." << endl;
                    } else {
                        cout << *credential;
                    }
                    break;
                }

                case 'u': {
                    ApplicationName app;
                    cin >> app;

                    string username;
                    cout << "Enter the username: ";
                    cin >> username;

                    string newpassword;
                    cout << "Enter the New Password: ";
                    cin >> newpassword;

                    if (storage.updatePassword(app, username, newpassword)) {
                        cout << "Password Updated Successfully." << endl;
                    } else {
                        cout << "Wrong App name or Username." << endl;
                    }
                    break;
                }

                case 'l':
                    prompt();
                break;

                case 'n':
                    cout << "Number of Applications: " << storage.numberOfApplication() << endl;
                break;

                case 'v': {
                    cout << storage << endl;
                    break;
                }
                case 'q':
                    running = false;
                    break;

                default:
                    cout << "Enter ther Wrong Choice, Try again!" << endl;
                    break;
            }
        }
    }
    return 0;
}


