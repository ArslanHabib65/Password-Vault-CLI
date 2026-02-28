#include "VaultSecurity.h"
#include <functional>

std::size_t VaultSecurity::hashKey(const std::string &key){
    std::hash<std::string> hasher;
    return hasher(key);
}

VaultSecurity::VaultSecurity(const std::string &masterKey){
    hashedKey = hashKey(masterKey);
    unlocked = false;
}

bool VaultSecurity::unlock(const std::string &inputKey) {
    if(hashKey(inputKey) == hashedKey){
        unlocked = true;
        return true;
    } else {
        return false;
    }
}

void VaultSecurity::lock(){
    unlocked = false;
}

  bool VaultSecurity::isUnlocked() const{
    return unlocked;
  }