//Milestone1
#include <iostream>
#include <string>

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

    CoffeeNode* current = head;

    while (current != nullptr)
    {
        cout << current->name << "ordered" << current->drink << endl;
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

}