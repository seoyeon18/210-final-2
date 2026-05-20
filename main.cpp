//Milestone3
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>

using namespace std;

struct CoffeeNode
{
    string name;
    string drink;
    CoffeeNode* next;
};

struct MuffinCustomer
{
    string name;
    string muffin;
};

int main()
{
    srand(time(0));

    string names[] = {"Seoyeon", "James", "Seongjun", "Alyssa", "Dayeon"};
    string drinks[] = {"Latte", "Mocha", "Americano", "Cappuccino", "Cold Brew", "Espresso"};
    string muffins[] = {"Blueberry", "Chocolate", "Banana", "chhese"};

    CoffeeNode* coffeeHead = nullptr;
    CoffeeNode* coffeeTail  = nullptr;
  
    deque<MuffinCustomer> muffinQueue;

    for (int i = 0; i < 3; i++)
    {
        CoffeeNode* newNode = new CoffeeNode;

        newNode->name = names[rand() % 5];
        newNode->drink = drinks[rand() % 6];
        newNode->next = nullptr;

        if (coffeeHead  == nullptr)
        {
            coffeeHead  = newNode;
            coffeeTail  = newNode;
        }
        else
        {
            coffeeTail->next = newNode;
            coffeeTail = newNode;
        }
        MuffinCustomer muffinCustomer;

        muffinCustomer.name = names[rand() % 5];
        muffinCustomer.muffin = muffins[rand() % 4];

        muffinQueue.push_back(muffinCustomer);
    }



    for (int round = 1; round <= 10; round++)
    {
        cout << "Round " << round << endl;

        if (coffeeHead != nullptr)
        {
            CoffeeNode* served = coffeeHead;

            cout << "Coffee booth served: " << served->name  << served->drink << endl;

            coffeeHead = coffeeHead->next;

            if (coffeeHead == nullptr)
            {
                coffeeTail = nullptr;
            }

            delete served;
        }
        else
        {
            cout << "coffee booth: no server"<< endl;
        } 

        if (rand() % 2 == 0)
        {
            CoffeeNode* newNode = new CoffeeNode;
            newNode->name = names[rand() % 5];
            newNode->drink = drinks[rand() % 6];
            newNode->next = nullptr;

            cout << "Coffee booth joined: " << newNode->name << newNode->drink << endl;


            if (coffeeHead == nullptr)
            {
                coffeeHead = newNode;
                coffeeTail = newNode;
            }
            else
            {
                coffeeTail->next = newNode;
                coffeeTail = newNode;
            }
        }
        else
        {
            cout << "no new customer" << endl;
        }
        
/////////////////////////////



//     CoffeeNode* current = coffeeHead;

//     while (current != nullptr)
//     {
//         cout << current->name << current->drink << endl;
//         current = current->next;
//     }

//     if (coffeeHead != nullptr)
//     {
//         CoffeeNode* served = coffeeHead;
//         cout << endl;
//         cout << "Served: " << served->name << served->drink << endl;

//         coffeeHead = coffeeHead->next;

//         if (coffeeHead == nullptr)
//         {
//             coffeeHead = nullptr;
//         }

//         delete served;
//     }

//     cout << endl;
//     cout << "Coffee booth queue after serving one customer:" << endl;

//     current = coffeeHead;

//     while (current != nullptr)
//     {
//         cout << current->name << current->drink << endl;
//         current = current->next;
//     }

//     cout << endl;
// }

    while (coffeeHead != nullptr)
    {
        CoffeeNode* temp = coffeeHead;
        coffeeHead = coffeeHead->next;
        delete temp;
    }

    return 0;
}

