#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

class RestaurantOwner
{
private:
    string restaurantName, username, password;

public:
    RestaurantOwner();
    RestaurantOwner(string rn, string un, string p);
    void setrestaurantName(string rn);
    void setusername(string un);
    void setpassword(string p);
    string getrestaurantName() const;
    string getusername() const;
    string getpassword() const;
};

class Customer
{
private:
    string customerName;
    string username;
    string password;

public:
    Customer();
    Customer(string cn, string un, string p, string a);
    string getcustomerName() const;
    string getusername() const;
    string getpassword() const;
    void setcustomerName(string cn);
    void setusername(string un);
    void setpassword(string p);
    void create();
};

class Menu
{
public:
    string category;
    string foodName;
    double foodPrice;
    string description;
    Menu *next;
    Menu();
};

class MenuList
{
public:
    Menu *head;
    MenuList();
    void insertNode(Menu *);
    void deleteNode();
    bool isEmpty();
    void editNode();
    void displayList();
};

class Order // contain all items/variable
{
public:
    string date;
    Menu cart;
    Customer cus;
};

class OrderQueue // Declaration of Queue (insertion etc)
{
public:
    Order *backPtr, frontPtr;
    void createQueue();
    void destroyQueue();
    bool isEmpty();
    void enQueue();
    void deQueue();
    int getFront();
    int getRear();
};

int main()
{
    system("color 0B");
    MenuList listMenu;
    

    Menu *ayam = new Menu;
    ayam->category = "Kategori1";
    ayam->description = "ayam goreng";
    ayam->foodName = "AYAM";
    ayam->foodPrice = 4.5;

    Menu *ikan = new Menu;
    ikan->category = "Kategori2";
    ikan->description = "ikan sambal";
    ikan->foodName = "ikan";
    ikan->foodPrice = 2345;

    Menu *itik = new Menu;
    itik->category = "Kategor3";
    itik->description = "itik sambal";
    itik->foodName = "itik";
    itik->foodPrice = 95;

    listMenu.insertNode(ayam);
    listMenu.insertNode(ikan);
    listMenu.insertNode(itik);
    //listMenu.deleteNode();
    //listMenu.editNode();
    //listMenu.displayList();



    int customer = 0;
    Customer cus[2];

    while(customer<2 && customer >= 0)
    {
        cus[customer].create();
        customer++;
    }
    

    system("PAUSE");
}

RestaurantOwner::RestaurantOwner()
{
    restaurantName = "Makima's Kitchen";
    username = "admin00";    // admin username
    password = "dsaproject"; // admin password
};

RestaurantOwner::RestaurantOwner(string rn, string un, string p)
{
    restaurantName = rn;
    username = un;
    password = p;
};

void RestaurantOwner::setrestaurantName(string rn)
{
    restaurantName = rn;
};

void RestaurantOwner::setusername(string un)
{
    username = un;
};

void RestaurantOwner::setpassword(string p)
{
    password = p;
};

string RestaurantOwner::getrestaurantName() const
{
    return restaurantName;
};

string RestaurantOwner::getusername() const
{
    return username;
};

string RestaurantOwner::getpassword() const
{
    return password;
};

Customer::Customer()
{
    customerName = "";
    username = "";
    password = "";
};

Customer::Customer(string cn, string un, string p, string a)
{
    customerName = cn;
    username = un;
    password = p;
};

string Customer::getcustomerName() const
{
    return customerName;
};

string Customer::getusername() const
{
    return username;
};

string Customer::getpassword() const
{
    return password;
};

void Customer::setcustomerName(string cn)
{
    customerName = cn;
};

void Customer::setusername(string un)
{
    username = un;
};

void Customer::setpassword(string p)
{
    password = p;
};

void Customer::create()
{
    system("cls");

    //cin.ignore();
    cout << "+------------------------------------+" << endl;
    cout << "+     Create  Customer's Account     +" << endl;
    cout << "+------------------------------------+" << endl;
    cout << endl;
    cout << setw(20) << left << "Enter your name [eg: Luqman] : ";
    getline(cin, customerName);
    cout << setw(20) << left << "Enter your username : ";
    getline(cin, username);
    cout << setw(20) << left << "Enter your password : ";
    getline(cin, password);
};

Menu::Menu()
{
    category = "";
    foodName = "";
    foodPrice = 0;
    description = "";
    next = NULL;
};

MenuList::MenuList()
{
    head = NULL;
};

void MenuList::insertNode(Menu *node)
{
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        Menu *tempNode = head;
        while (tempNode->next)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = node;
    }
};

void MenuList::deleteNode()
{
    int position = 0;
    int sizeOfList = 0;

    displayList();
    cout << "Enter the node number you wish to delete => ";
    cin >> position;

    Menu *tempNode = head;

    while (tempNode)
    {
        sizeOfList++;
        tempNode = tempNode->next;
    }
    delete tempNode;

    if (sizeOfList == 0)
    {
        cout << "EMPTY LIST, CANT DELETE ANYTHING BEGOK";
    }
    else if (position > sizeOfList)
    {
        cout << "NODE DOESNT EXIST";
    }
    else
    {
        if (position == 0)
        {
            cout << "POSITION 0 DOES NOT EXIST BRUH" << endl;
            return;
        }
        else if (position == 1)
        {
            head = head->next;
            delete tempNode;
            return;
        }
        else
        {
            Menu *previousNode;
            Menu *nextNode = head;
            while (position-- > 1)
            {
                previousNode = nextNode;
                nextNode = nextNode->next;
            }
            previousNode->next = nextNode->next;
            delete nextNode;
        }
    }
};

bool MenuList::isEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
};

void MenuList::editNode()
{
    int position = 0;
    int sizeOfList = 0;

    displayList();
    cout << "Enter the node number you wish to edit its content => ";
    cin >> position;
    cin.ignore();
    Menu *tempNode = head;

    while (tempNode)
    {
        sizeOfList++;
        tempNode = tempNode->next;
    }
    delete tempNode;

    if (sizeOfList == 0)
    {
        cout << "EMPTY LIST, CANT EDIT ANYTHING BRUH";
    }
    else if (position > sizeOfList)
    {
        cout << "NODE DOESNT EXIST";
    }
    else
    {
        if (position == 0)
        {
            cout << "POSITION 0 DOES NOT EXIST BRUH" << endl;
            return;
        }

        string tempCat, tempName, tempDesc;
        double tempPrice;

        cout << "ENTER NEW MENU =>" << endl;
        cout << "CATEGORY - ";
        getline(cin, tempCat);
        cout << "NAME - ";
        getline(cin, tempName);
        cout << "DESCRIPTION - ";
        getline(cin, tempDesc);
        cout << "Price - ";
        cin >> tempPrice;

        if (position == 1)
        {
            head->category = tempCat;
            head->foodName = tempName;
            head->foodPrice = tempPrice;
            head->description = tempDesc;
            return;
        }
        else if (position > 1)
        {
            tempNode = head;
            while (position-- > 1)
            {
                tempNode = tempNode->next;
            }

            tempNode->category = tempCat;
            tempNode->foodName = tempName;
            tempNode->foodPrice = tempPrice;
            tempNode->description = tempDesc;
        }

        else
        {
            cout << "HOW ARE YOU EVEN HERE?";
        }
    }
};

void MenuList::displayList()
{
    Menu *currNode = head;
    cout << "MAKIMA'S KITCHEN MENU LIST" << endl;

    int number = 1;
    do
    {
        cout << number << ". ";
        cout << currNode->category << " ";
        cout << currNode->foodName << " ";
        cout << currNode->description << " ";
        cout << currNode->foodPrice << endl;
        currNode = currNode->next;
        number++;
    } while (currNode);
    cout << endl;
    cout << endl;
};