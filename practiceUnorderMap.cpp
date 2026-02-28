#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Person {
    public:
        string name;
        int age;
};
void printUnorderPair(const unordered_map<string, int> &map){
    for(const auto& pair: map){
        cout << "key: " << pair.first << " Content: " << pair.second << endl;
    }
}
void printVector(const vector<int> & v) {
    for(const auto &value: v){
        cout << " " << value;
    }
    cout << endl;
}

void reversePrintVector(const vector<int> &v){
    for(auto it = v.rbegin(); it != v.rend(); ++it){
        cout << " " << *it;
    }
    cout << endl;
}

int main() {
    unordered_map<string, int> scores;
    scores.insert({"Alice", 90});
    scores.insert({"Bob", 80});
    cout << scores.size() << endl; // 2
    cout << scores["Charlie"] << endl; // 0
    cout << scores.size() << endl; // 3
    // printUnorderPair(scores);

    if  (scores.find("David") != scores.end()) {
        cout << "User found" << endl;
    } else {
        cout << "User not found" << endl;
    }

    auto it = scores.find("Bob");
    if(it != scores.end()){
        cout << "Found: " << it->first << " -> " << it->second << endl;
    } else {
        cout << "Not found" << endl; 
    }

    auto x = 5;
    auto y = 10;
    cout << (x * y) << endl;

    cout << "Vector Practice" << endl;
    vector<int> v;
    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.push_back(25);
    printVector(v);
    cout << endl;

    cout << v.size() << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;

    // Modify Element
    v[3] = 100;
    printVector(v);
    v.pop_back();
    printVector(v);
    v.insert(v.begin() + 1, 7);
    printVector(v);
    v.erase(v.begin() + 2);
    printVector(v);

    cout << "Reverse Vector Print" << endl;
    reversePrintVector(v);

    vector<Person> p;
    p.push_back({"Arslan", 24});
    p.push_back({"Noor", 28});
    p.push_back({"Umar", 19});

    for(const auto &it: p){
        cout << it.name << " " << it.age << endl;
    }
    p.erase(p.begin() + 1);
    for(const auto &it: p){
        cout << it.name << " " << it.age << endl;
    }


    int xy = 10;
    int *ip = &xy;
    cout << *ip << endl;
    return 0;
}
