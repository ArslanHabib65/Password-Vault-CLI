#ifndef VAULTSECURITY_H
#define VAULTSECURITY_H
#include <string>

class VaultSecurity {
    public:
        VaultSecurity(const std::string &masterKey);
        bool unlock(const std::string &inputKey);
        void lock();
        bool isUnlocked() const;
    private:
        std::size_t hashedKey;
        bool unlocked;

        std::size_t hashKey(const std::string &key);
};




#endif