# Password-Vault-CLI 🔐

A command-line password vault system built in **C++** using:

- Object-Oriented Programming (OOP)
- `std::unordered_map` for application storage
- `std::vector` for credential management
- Operator overloading (`<<`, `>>`)
- Pointer-based search system
- Menu-driven CLI interface
- Basic authentication layer

---

## 📚 Documentation References

### Unordered Map
- https://en.cppreference.com/w/cpp/container/unordered_map.html  
- https://cplusplus.com/reference/unordered_map/unordered_map/

### Vector
- https://en.cppreference.com/w/cpp/container/vector.html

---

## 🛠 Compilation & Execution

Compile and run using:

```bash
g++ main.cpp VaultSecurity.cpp SystemControllerDesign.cpp -o main && ./main
```

If additional `.cpp` files are added:

```bash
g++ *.cpp -o main && ./main
```

---

## 🚀 Features

- Add Application
- Remove Application
- Add Credential
- Delete Credential
- Search Credential
- Update Password
- Lock / Unlock Vault
- View Vault (Debug Mode)
- Display Number of Applications

---

## 🧠 Design Concepts Used

- Custom class modeling (`ApplicationName`, `ListOfContent`)
- Hash-based container storage
- Const-correctness
- Pointer safety
- Clean separation of security and storage layers
- Input validation

---

## 🔐 Future Improvements

- Password hashing
- Encryption layer
- File persistence
- Secure master key handling
- GUI or Web Interface version

---

## 📌 Project Status

Version 1.0 — Basic Functional CLI Vault  
Focus: Architecture & Core Functionality