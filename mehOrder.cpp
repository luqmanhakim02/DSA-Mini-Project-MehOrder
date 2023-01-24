#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <ctime>
#include <unistd.h>

using namespace std;

const int MAX_CUS = 10;

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
    Customer(string cn, string un, string p);
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
    Menu(string, string, double, string);
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
    int totalMenu();
};

class Order // contain all items/variable
{
public:
    string date;
    Menu cart;
    Customer cus;
    Order *next;
};

class OrderQueue // Declaration of Queue (insertion etc)
{
public:
    Order *backPtr, *frontPtr;
    void createQueue();
    void destroyQueue();
    bool isEmpty();
    void enQueue();
    void deQueue();
    Order getFront();
    Order getRear();
};

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

Customer::Customer(string cn, string un, string p)
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
    int error = 0;
    cin.ignore();
    do
    {
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

        if (customerName == "" || username == "" || password == "")
        {
            error = 1;
            cout << "ERROR PASSWORD, CONTAINING NULL VALUE. DO ENTER THE DETAIL AGAIN" << endl;
            system("PAUSE");
            system("CLS");
        }
        else
        {
            error = 0;
        }
    } while (error);
};

Menu::Menu()
{
    category = "";
    foodName = "";
    foodPrice = 0;
    description = "";
    next = NULL;
};

Menu::Menu(string cat, string name, double price, string desc)
{
    category = cat;
    foodName = name;
    foodPrice = price;
    description = desc;
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
    cout << "MENU LIST" << endl
         << endl;
    cout << "No  ";
    cout << left << setw(20) << "Category"
         << " ";
    cout << setw(40) << "Food Name"
         << " ";
    cout << setw(40) << "Description"
         << " ";
    cout << setw(10) << "Price" << endl;
    for (int i = 0; i < 113; i++)
        cout << "-";
    cout << endl;
    int number = 1;
    do
    {
        if (number < 10)
            cout << " ";
        cout << number << ". ";
        cout << setw(20) << currNode->category << " ";
        cout << setw(40) << currNode->foodName << " ";
        cout << setw(40) << currNode->description << " ";
        cout << setw(10) << currNode->foodPrice << endl;
        currNode = currNode->next;
        number++;
    } while (currNode);
    cout << endl;
    cout << endl;
};

int MenuList::totalMenu()
{
    Menu *currNode = head;
    int size = 0;
    while (currNode)
    {
        size++;
        currNode = currNode->next;
    }
    return size;
}

void mehOrderAnimation()
{
    cout << endl;
    cout << "   /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$  /$$$$$$$  /$$$$$$$  /$$$$$$$$ /$$$$$$$        /$$" << endl
         << flush;
    sleep(1);
    cout << "  | $$$    /$$$| $$_____/| $$  | $$       /$$__  $$| $$__  $$| $$__  $$| $$_____/| $$__  $$      | $$" << endl
         << flush;
    sleep(1);
    cout << "  | $$$$  /$$$$| $$      | $$  | $$      | $$  \\ $$| $$  \\ $$| $$  \\ $$| $$      | $$  \\ $$      | $$" << endl
         << flush;
    sleep(1);
    cout << "  | $$ $$/$$ $$| $$$$$   | $$$$$$$$      | $$  | $$| $$$$$$$/| $$  | $$| $$$$$   | $$$$$$$/      | $$" << endl
         << flush;
    sleep(1);
    cout << "  | $$  $$$| $$| $$__/   | $$__  $$      | $$  | $$| $$__  $$| $$  | $$| $$__/   | $$__  $$      |__/" << endl
         << flush;
    sleep(1);
    cout << "  | $$\\  $ | $$| $$      | $$  | $$      | $$  | $$| $$  \\ $$| $$  | $$| $$      | $$  \\ $$" << endl
         << flush;
    sleep(1);
    cout << "  | $$ \\/  | $$| $$$$$$$$| $$  | $$      |  $$$$$$/| $$  | $$| $$$$$$$/| $$$$$$$$| $$  | $$       /$$" << endl
         << flush;
    sleep(1);
    cout << "  |__/     |__/|________/|__/  |__/       \\______/ |__/  |__/|_______/ |________/|__/  |__/      |__/" << endl
         << flush;
    cin.get();
    system("CLS");
};

void makimaKitchen()
{
    cout << endl;
    cout << " ___  ___  ___   _   __ _____ ___  ___  ___   _  _____   _   __ _____  _____  _____  _   _  _____  _   _ " << endl;
    cout << " |  \\/  | / _ \\ | | / /|_   _||  \\/  | / _ \\ ( )/  ___| | | / /|_   _||_   _|/  __ \\| | | ||  ___|| \\ | |" << endl;
    cout << " | .  . |/ /_\\ \\| |/ /   | |  | .  . |/ /_\\ \\|/ \\ `--.  | |/ /   | |    | |  | /  \\/| |_| || |__  |  \\| |" << endl;
    cout << " | |\\/| ||  _  ||    \\   | |  | |\\/| ||  _  |    `--. \\ |    \\   | |    | |  | |    |  _  ||  __| | . ` |" << endl;
    cout << " | |  | || | | || |\\  \\ _| |_ | |  | || | | |   /\\__/ / | |\\  \\ _| |_   | |  | \\__/\\| | | || |___ | |\\  |" << endl;
    cout << " \\_|  |_/\\_| |_/\\_| \\_/ \\___/ \\_|  |_/\\_| |_/   \\____/  \\_| \\_/ \\___/   \\_/   \\____/\\_| |_/\\____/ \\_| \\_/" << endl;
    cout << endl;
}

MenuList listOfMenu()
{
    MenuList listMenu;

    Menu *menu1 = new Menu("American", "Chicken Burger", 3.50, "Main dish, Non-Vegan, Halal");
    Menu *menu2 = new Menu("American", "Beef Burger", 3.50, "Main dish, Non-vegan, Halal");
    Menu *menu3 = new Menu("American", "Macaroni & Cheese", 5.00, "Main dish, Non-Vegan, Halal");
    Menu *menu4 = new Menu("Itailan", "Spaghetti Carbonara", 5.00, "Main dish, Non-Vegan, Halal");
    Menu *menu5 = new Menu("Italian", "Spaghetti Aglio Olio", 5.00, "Main dish, Non-vegan, Halal");
    Menu *menu6 = new Menu("Chinese/Italian", "Tofu Spinach Lasagna", 6.00, "Main dish, Vegan, Halal");
    Menu *menu7 = new Menu("Western", "Special Makima Steak", 10.00, "Main dish, Non-vegan, Halal");
    Menu *menu8 = new Menu("Western", "Special Makima Beef Ribs", 12.00, "Main dish, Non-Vegan, Halal");
    Menu *menu9 = new Menu("Vegan Food", "Salad", 3.00, "Side Dish, Vegan, Halal");
    Menu *menu10 = new Menu("Dessert", "Cheeesy Fried Potato Wedges", 4.00, "Side Dish, Vegan, Halal");
    Menu *menu11 = new Menu("Dessert", "Dairy free Vanilla Ice Cream", 2.00, "Dessert, Vegan, Halal");
    Menu *menu12 = new Menu("Dessert", "Special caramel Chocolate Ice Cream", 4, "Dessert, Non-Vegan, Halal");
    Menu *menu13 = new Menu("Alcohol", "Chardonnay Wine", 10.00, "Drink, Vegan, NON-HALAL");
    Menu *menu14 = new Menu("Soft Drink", "Sprite", 2.00, "Drink, Vegan, Halal");
    Menu *menu15 = new Menu("Special Drink", "Ice Chocolate", 4.00, "Drink, Non-Vegan, Halal");
    Menu *menu16 = new Menu("Fresh Drink", "Ice Lemon Tea", 2.00, "Drink, Vegan, Halal");
    listMenu.insertNode(menu1);
    listMenu.insertNode(menu2);
    listMenu.insertNode(menu3);
    listMenu.insertNode(menu4);
    listMenu.insertNode(menu5);
    listMenu.insertNode(menu6);
    listMenu.insertNode(menu7);
    listMenu.insertNode(menu8);
    listMenu.insertNode(menu9);
    listMenu.insertNode(menu10);
    listMenu.insertNode(menu11);
    listMenu.insertNode(menu12);
    listMenu.insertNode(menu13);
    listMenu.insertNode(menu14);
    listMenu.insertNode(menu15);
    listMenu.insertNode(menu16);

    return listMenu;
}

void OrderQueue::createQueue()
{
    backPtr = NULL;
    frontPtr = NULL;
}

void OrderQueue::destroyQueue()
{
    Order *temp = frontPtr;
    while (temp)
    {
        frontPtr = temp->next;
        delete temp;
        temp = frontPtr;
    }
}

bool OrderQueue::isEmpty()
{
    return (frontPtr == NULL);
}

void OrderQueue::enQueue()
{
    Order *newPtr;
    
    if (isEmpty())
    {
        frontPtr = backPtr = newPtr;
    }
    else
    {
        newPtr->next = NULL;
        backPtr->next = newPtr;
        backPtr = newPtr; 
    }
}

void OrderQueue::deQueue()
{

    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
    }

    Order *tempPtr;

    tempPtr = frontPtr;
    frontPtr = frontPtr->next;
    tempPtr->next = NULL;

     if (!frontPtr)
        backPtr = NULL;
    
    delete tempPtr;
}

Order OrderQueue::getFront()
{
     if (isEmpty()) {
        cout << "Queue is Empty" << endl;
    }
    return *frontPtr;
}

Order OrderQueue::getRear()
{
     if (isEmpty()) {
        cout << "Queue is Empty" << endl;
    }
    return *backPtr;
}


int main()
{
    int choice;
    int proceed = 1;
    int customer = 0;
    MenuList listMenu = listOfMenu();
    RestaurantOwner admin;
    Customer cus[MAX_CUS];
    //Order kitchenOrder;
    OrderQueue kitchenOrder;

    system("color 0B");
    mehOrderAnimation();

menu_utama:

    system("cls");
    makimaKitchen();

    cout << "\n+----------------------------------------------+" << endl;
    cout << "+------------ Choose any option    ------------+" << endl;
    cout << "+----------------------------------------------+" << endl
         << endl;
    cout << "1. Restaurant Owner" << endl;
    cout << "2. New Customer " << endl;
    cout << "3. Existing Customer " << endl;
    cout << "4. Exit " << endl
         << endl;
    cout << "OPTION --> ";
    cin >> choice;


    while (proceed == 1)
    {

        switch (choice)
        {
        case 1:
        {
            system("cls");
            string owner_name, owner_pass;
            cout << "+--------------------------------------------+" << endl;
            cout << "+----- Please Insert Username & Password ----+" << endl;
            cout << "+--------------------------------------------+" << endl;
            cout << "Username: ";
            cin >> owner_name;
            cout << "Password: ";
            cin >> owner_pass;
            if (owner_name == admin.getusername() && owner_pass == admin.getpassword())
            {
                int choice_admin;
                do
                {

                    cout << "+----------------------------------------------+" << endl;
                    cout << "+------- HI, WELCOME TO YOUR RESTAURANT -------+" << endl;
                    cout << "+----------------------------------------------+" << endl;
                    cout << "+------ Please CHOOSE what you want to do -----+" << endl;
                    cout << "+----------------------------------------------+" << endl;
                    cout << setfill(' ') << setw(20) << left << "\n1. Add Menu" << endl;
                    cout << setfill(' ') << setw(20) << left << "2. Delete Menu" << endl;
                    cout << setfill(' ') << setw(20) << left << "3. Edit Menu" << endl;
                    cout << setfill(' ') << setw(20) << left << "4. Display Menu List" << endl;
                    cout << setfill(' ') << setw(20) << left << "5. Fulfill Order" << endl;
                    cout << setfill(' ') << setw(20) << left << "6. Logout and Exit" << endl;

                    cin >> choice_admin;

                    switch (choice_admin)
                    {
                    case 1:
                    {
                        system("cls");
                        string tempCategory, tempName, tempDescription;
                        double tempPrice;
                        cout << "+----------------------------------------------+" << endl;
                        cout << "+------------------ ADD MENU ------------------+" << endl;
                        cout << "+----------------------------------------------+" << endl;
                        cout << "ENTER NEW MENU DETAIL" << endl;
                        cin.ignore();
                        cout << "CATEGORY: ";
                        getline(cin, tempCategory);
                        cout << "NAME: ";
                        getline(cin, tempName);
                        cout << "DESCRIPTION: ";
                        getline(cin, tempDescription);
                        cout << "PRICE: ";
                        cin >> tempPrice;

                        Menu *newMenu = new Menu(tempCategory, tempName, tempPrice, tempDescription);
                        listMenu.insertNode(newMenu);
                        listMenu.displayList();
                        break;
                    }

                    case 2:
                        system("cls");
                        cout << "+----------------------------------------------+" << endl;
                        cout << "+----------------- DELETE MENU ----------------+" << endl;
                        cout << "+----------------------------------------------+" << endl;
                        listMenu.deleteNode();
                        break;

                    case 3:
                        system("cls");
                        cout << "+----------------------------------------------+" << endl;
                        cout << "+------------------ EDIT MENU -----------------+" << endl;
                        cout << "+----------------------------------------------+" << endl;
                        listMenu.editNode();
                        break;

                    case 4:
                        listMenu.displayList();
                        break;

                    case 5:
                        cout << "+----------------------------------------------+" << endl;
                        cout << "+---------------- FULFILL ORDER ---------------+" << endl;
                        cout << "+----------------------------------------------+" << endl;

                        // FULFILL ORDER GUNAKAN DEQUEUE

                    case 6:
                        goto menu_utama;
                        break;

                    default:
                        cout << "WRONG INPUT" << endl;
                        break;
                    }

                } while (choice_admin != 6);
            }
            else
            {
                cout << "+----------------------------------------------+" << endl;
                cout << "+---------------- WARNING!!! ------------------+" << endl;
                cout << "+----------------------------------------------+" << endl;
                cout << "+------ WRONG USERNAME & PASSWORD INSERT ------+" << endl;
                cout << "+----------------------------------------------+" << endl;
                system("PAUSE");
            }
            goto menu_utama;
            break;
        }
        case 2:

            cus[customer].create();
            customer++;
            cout << "Customer Details Added" << endl;
            system("PAUSE");
            goto menu_utama;
            break;

        case 3:
        {
            double totalPrice = 0;
            string cusUsername, cusPassword;
            int successfulLogin = 0, customerIndex;
            cin.ignore();

            cout << "\nPlease enter your username: ";
            getline(cin, cusUsername);
            cout << "\nPlease enter your password: ";
            getline(cin, cusPassword);

            for (int i = 0; i < MAX_CUS; i++)
            {
                if ((cusUsername == cus[i].getusername()) && cusPassword == cus[i].getpassword())
                {
                    successfulLogin = 1;
                    customerIndex = i;
                }
            }
            if (successfulLogin == 0)
            {
                cout << "\nWrong Username or Password, press enter to go back" << endl;
                system("PAUSE");
            }

            if (successfulLogin == 1)
            {
                system("cls");
                int choicecustomer;
                do
                {
                    system("cls");
                    makimaKitchen();

                    cout << "\n+----------------------------------------------+" << endl;
                    cout << "+------------ Choose any option :D ------------+" << endl;
                    cout << "+----------------------------------------------+" << endl
                         << endl;
                    cout << "1. VIEW MENU LIST" << endl;
                    cout << "2. ADD MENU TO ORDERING QUEUE AND PAY" << endl;
                    cout << "3. LOGOUT AND EXIT" << endl;
                    cin >> choicecustomer;
                    switch (choicecustomer)
                    {
                    case 1:
                        system("cls");
                        makimaKitchen();
                        listMenu.displayList();
                        system("PAUSE");
                        break;
                    case 2:

                        system("cls");
                        makimaKitchen();
                        listMenu.displayList();
                        cout << endl;

                        int menuIndex;
                        cout << "Enter the menu index [1..." << listMenu.totalMenu() << "] you wish to order ";
                        cin >> menuIndex;

                        // kitchenOrder enqueue
                       // Order *tempOrder = new Order;
                        // NEED TO ENQUEUE THE MENU

                        Menu *temp = listMenu.head;
                        int index;
                        for (int i = 0; i < listMenu.totalMenu(); i++)
                        {
                            temp = new Menu(i);
                            temp = temp->next;
                        }
                        

                        cout << "Thank you for your order. You can proceed to your cart for purchase purposes" << endl;
                        system("PAUSE");
                        goto menu_utama;
                        break;

                    case 3:
                        goto menu_utama;
                        break;

                    default:
                        cout << "WRONG INPUT. PLEASE PRESS YOUR KEYBOARD PROPERLY" << endl;
                        system("PAUSE");
                        break;
                    }

                } while (choicecustomer != 3);
            }
            goto menu_utama;
            break;
        }
        case 4:
            cout << "Thank you for using the system" << endl;
            system("PAUSE");
            proceed = 0;
            break;

        default:
            cin.clear();
            cin.ignore();
            goto menu_utama;
            break;
        }
    }
    return 0;
}
