//Milestone2
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct CoffeeNode
{
    string name;
    string drink;
    CoffeeNode* next;
};

int main()
{
    srand(time(0));

    string names[] = {"Seoyeon", "James", "Seongjun", "Alyssa", "Dayeon"};
    string drinks[] = {"Latte", "Mocha", "Americano", "Cappuccino", "Cold Brew", "Espresso"};

    CoffeeNode* head = nullptr;
    CoffeeNode* tail = nullptr;
  

    for (int i = 0; i < 3; i++)
    {
        CoffeeNode* newNode = new CoffeeNode;

        newNode->name = names[rand() % 6];
        newNode->drink = drinks[rand() % 6];
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    for (int round = 1; round <= 10; round++)
    {
        cout << "Round " << round << endl;

        if (head != nullptr)
        {
            CoffeeNode* served = head;

            cout << "Coffee booth served: " << served->name  << served->drink << endl;

            head = head->next;

            if (head == nullptr)
            {
                tail = nullptr;
            }

            delete served;
        }
        else
        {
            cout << "coffee booth: no server";
        } 

        if (rand() % 2 == 0)
        {
            CoffeeNode* newNode = new CoffeeNode;

            

            if (head == nullptr)
            {
                
            }
            else
            {
                
            }
        }
        else
        {
            cout << "no new customer" << endl;
        }




    CoffeeNode* current = head;

    while (current != nullptr)
    {
        cout << current->name << current->drink << endl;
        current = current->next;
    }

    if (head != nullptr)
    {
        CoffeeNode* served = head;
        cout << endl;
        cout << "Served: " << served->name << served->drink << endl;

        head = head->next;

        if (head == nullptr)
        {
            tail = nullptr;
        }

        delete served;
    }

    cout << endl;
    cout << "Coffee booth queue after serving one customer:" << endl;

    current = head;

    while (current != nullptr)
    {
        cout << current->name << current->drink << endl;
        current = current->next;
    }

    while (head != nullptr)
    {
        CoffeeNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

