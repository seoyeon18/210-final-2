// Milestone4
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

struct CoffeeNode
{
    string name;
    string drink;
    CoffeeNode *next;
};

struct MuffinCustomer
{
    string name;
    string muffin;
};

struct BraceletCustomer
{
    string name;
    string bracelet;
};

struct StickerCustomer
{
    string name;
    string sticker;
};

int main()
{
    srand(time(0));

    string names[] = {"Seoyeon", "James", "Seongjun", "Alyssa", "Dayeon"};
    string drinks[] = {"Latte", "Mocha", "Americano", "Cappuccino", "Cold Brew", "Espresso"};
    string muffins[] = {"Blueberry", "Chocolate", "Banana", "chhese"};
    string bracelets[] = {"Rainbow", "Heart", "Star", "Flower"};
    string stickers[] = {"Cat", "Dog", "Flower", "Space"};


    CoffeeNode *coffeeHead = nullptr;
    CoffeeNode *coffeeTail = nullptr;

    deque<MuffinCustomer> muffinQueue;

    vector<BraceletCustomer> braceletQueue;

    queue<StickerCustomer> stickerQueue;

    for (int i = 0; i < 3; i++)
    {
        CoffeeNode *newNode = new CoffeeNode;

        newNode->name = names[rand() % 5];
        newNode->drink = drinks[rand() % 6];
        newNode->next = nullptr;

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
        MuffinCustomer muffinCustomer;

        muffinCustomer.name = names[rand() % 5];
        muffinCustomer.muffin = muffins[rand() % 4];

        muffinQueue.push_back(muffinCustomer);

        BraceletCustomer braceletCustomer;

        braceletCustomer.name = names[rand() % 5];
        braceletCustomer.bracelet = bracelets[rand() % 4];

        braceletQueue.push_back(braceletCustomer);

        StickerCustomer stickerCustomer;
    }

    for (int round = 1; round <= 10; round++)
    {
        cout << "Round " << round << endl;

        if (coffeeHead != nullptr)
        {
            CoffeeNode *served = coffeeHead;

            cout << "Coffee booth served: " << served->name << served->drink << endl;

            coffeeHead = coffeeHead->next;

            if (coffeeHead == nullptr)
            {
                coffeeTail = nullptr;
            }

            delete served;
        }
        else
        {
            cout << "coffee booth: no server" << endl;
        }

        if (rand() % 2 == 0)
        {
            CoffeeNode *newNode = new CoffeeNode;
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

        if (!muffinQueue.empty())
        {
            cout << "Muffin booth served: " << muffinQueue.front().name
                 << muffinQueue.front().muffin << endl;

            muffinQueue.pop_front();
        }
        else
        {
            cout << "Muffin booth served: no customer" << endl;
        }

        if (rand() % 2 == 0)
        {
            MuffinCustomer muffinCustomer;

            muffinCustomer.name = names[rand() % 5];
            muffinCustomer.muffin = muffins[rand() % 4];

            muffinQueue.push_back(muffinCustomer);

            cout << "Muffin booth joined: " << muffinCustomer.name
                 << " ordered " << muffinCustomer.muffin << endl;
        }
        else
        {
            cout << "Muffin booth joined: no new customer" << endl;
        }
        if (!braceletQueue.empty())
        {
            cout << "Bracelet booth served: " << braceletQueue.front().name
                 << " with " << braceletQueue.front().bracelet << endl;

            braceletQueue.erase(braceletQueue.begin());
        }
        else
        {
            cout << "Bracelet booth served: no customer" << endl;
        }

        if (rand() % 2 == 0)
        {
            BraceletCustomer braceletCustomer;

            braceletCustomer.name = names[rand() % 5];
            braceletCustomer.bracelet = bracelets[rand() % 4];

            braceletQueue.push_back(braceletCustomer);

            cout << "Bracelet booth joined: " << braceletCustomer.name
                 << " ordered " << braceletCustomer.bracelet << endl;
        }
        else
        {
            cout << "Bracelet booth new customer" << endl;
        }

        if (!stickerQueue.empty())
        {
            cout << "Sticker booth served: " << stickerQueue.front().name
                 << "with" << stickerQueue.front().sticker << endl;

            stickerQueue.pop();
        }
        else
        {
            cout << "Sticker booth no customer" << endl;
        }

        cout << endl;
    }

    while (coffeeHead != nullptr)
    {
        CoffeeNode *temp = coffeeHead;
        coffeeHead = coffeeHead->next;
        delete temp;
    }

    return 0;
}
