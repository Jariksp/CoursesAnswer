#include <iostream>

#include "TSaveManager.h"
#include "TSaveInfo.h"

void Print(const std::vector<std::shared_ptr<TSaveInfo>>& InputVector) {
    for(auto elem : InputVector) std::cout << elem->Date() << "\n";
}

void Print(std::unique_ptr<TSaveManager>& object) { for(auto savedConteiner : object->vSavedInfoContainer) std::cout << savedConteiner->Date() << "\n"; }

int main() {

    auto SavingManager = std::make_unique<TSaveManager>();
    SavingManager->AddDate(std::make_shared<TSaveInfo>(12,11,2022));
    SavingManager->AddDate(std::make_shared<TSaveInfo>(12,6,2013));
    SavingManager->AddDate(std::make_shared<TSaveInfo>(2,10,1923));
    SavingManager->AddDate(std::make_shared<TSaveInfo>(29,2,2123));
    SavingManager->AddDate(std::make_shared<TSaveInfo>(22,1,2032));
    SavingManager->AddDate(std::make_shared<TSaveInfo>(9,10,2013));
    SavingManager->AddDate(std::make_shared<TSaveInfo>(3,6,1981));
    SavingManager->AddDate(std::make_shared<TSaveInfo>(9,4,2034));
    SavingManager->AddDate(std::make_shared<TSaveInfo>(13,5,2032));
    SavingManager->AddDate(std::make_shared<TSaveInfo>(16,9,2119));
    SavingManager->AddDate(std::make_shared<TSaveInfo>(20,11,1392));
    SavingManager->AddDate(std::make_shared<TSaveInfo>(10,18,2029));

    Print(SavingManager);
    std::cout << "\n";

    std::cout << "By month in descent order \n";
    auto byMonth = [](auto a,auto b) { return a->Month() > b->Month();  };
    Print(SavingManager->Sort(byMonth));  
    std::cout << "\n";

    std::cout << "Holding objects by odd days \n";
    std::function<bool(std::shared_ptr<TSaveInfo>)> OddDay = [](auto a)->bool { return a->Day() % 2 == 0; };
    Print(SavingManager->Map(OddDay));
    std::cout << "\n";
                   
    std::cout << "Remove Object (12,11,2022) \n";
    auto ptr1 = std::make_shared<TSaveInfo>(12,11,2022);
    SavingManager->RemoveDate(ptr1);
    Print(SavingManager);
    std::cout << "\n";
 
    return 0;
}








