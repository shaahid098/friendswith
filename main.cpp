#include <iostream>
#include <string>

struct Person {
    std::string name;
    Person *friendWith;

};
int main() {

    Person *hetanshi = new Person {"Hetanshi",nullptr};
    Person *justin = new Person  {"Justin",nullptr};

    hetanshi->friendWith = justin;

    std::cout << hetanshi->name << " is friends with "<<hetanshi->friendWith->name<<std::endl;

    Person *noor = new Person  {"Noor",hetanshi};

    std::cout << noor->name << " is friends with "<<noor->friendWith->name
                <<" who is friends with "<<noor->friendWith->friendWith->name<<std::endl;

    noor->friendWith->friendWith->friendWith = new Person  {"Millie",nullptr};

    std::cout << noor->name<<"'s friend's firend's friend is "
              <<noor->friendWith->friendWith->friendWith->name<<std::endl;

    Person *virgil = new Person  {"Virgil"};

    virgil->friendWith = noor->friendWith->friendWith->friendWith;
    noor ->friendWith->friendWith->friendWith= virgil;

    virgil->friendWith->friendWith = new Person {"Rapha",nullptr};

    Person * current_friend = noor;

    std::cout<<std::endl<<std::endl;

    while (current_friend->friendWith != nullptr) {
        std::cout<<current_friend->name <<" is friends with ";
        current_friend = current_friend->friendWith;
    }

    std::cout <<"nobody! " <<std::endl;

    return 0;
}