#include <iostream>
#include "datamodel.h"
#include <string>
#include <vector>
using namespace std;

vector<Product> allProducts = {
    Product(1,"iPhone 14 Pro Max",140000),
    Product(2,"iPhone 14 Pro",130000),
    Product(3,"iPhone 14",70000),
    Product(4,"iPad Pro",80000),
    Product(4,"Macbook Air",90000),
    Product(6,"Macbook Pro",180000),
    Product(7,"Airpods",16000),
    Product(8,"Airpods Gen 3",19000),
    Product(9,"Airpods Pro",26000),
    Product(10,"Airpods Max",55000),
    Product(11,"Pencil",10000)
};



Product* chooseProduct(string choice) 
{
    // string productList;
    // cout << "Available Products " << endl;
    // for(auto product : allProducts){
    //     productList.append(product.getDisplayName());
    // }
    // cout << productList << endl;
    cout << "---------------------" << endl;
    // cout << "Enter product name : " << endl;
    

    for(int i = 0 ; i < allProducts.size() ; i++)
    {
        if((allProducts[i].getName()) == choice)
        {
            return &allProducts[i]; 
        }
    }
    /*We changed the return type to ptr so that we can return NULL if the 
    entry is not found */

    cout << "Product Not Found!" << endl;
    return NULL;
}

bool checkout(Cart &cart)
{
    if(cart.isEmpty())
    {
        return false;
    }
    
    int total = cart.getTotal();
    cout << "Pay in cash : " << endl;

    int paid;
    cin >> paid;

    if(paid>=total)
    {
        cout << "Collect change : " << paid-total << endl;
        cout << "Thank you for shopping with us ✨" << endl;
        return true;
    }
    else{
        cout << "Not enough cash 💵 " << endl;
        return false;

    }
}

int main()
{

    
    char action;
    Cart cart;
    while(true)
    {
        string choice;   
        cout << "Select an action - (a)dd an item , (v)iew item , (r)emove , (c)heck out " << endl;
        cin >> action;
        cin.ignore(); //To ignore the remaining characters in the i/p buffer.
        if(action == 'a')
        {
            string productList;
            cout << "Available Products " << endl;
            for(auto product : allProducts){
                productList.append(product.getDisplayName());
            }
            cout << productList << endl;
            cout << "Enter product name :";
            
            getline(cin,choice);
            Product* product = chooseProduct(choice);
            if(product!=NULL)
            {
                cout << "Added to cart : " << product->getDisplayName() << endl;
                cart.addProducts(*product); 
            }
        }
        else if(action == 'v')
        {
            cout << "---------------------" << endl;
            cout << cart.viewCart();
            cout << "---------------------" << endl;
        }
        else if(action == 'r')
        {
            
            string productList;
            cout << "Available Products " << endl;
            for(auto product : allProducts){
                productList.append(product.getDisplayName());
            }
            string toRemove;
            getline(cin,toRemove);
            Product* product = chooseProduct(choice);
            if(product!=NULL)
            {
                cout << "Not present in your cart" << endl;
            }
            else
            {
                cart.removeProducts(*product);
                cout << product -> getDisplayName() << " has been removed from the cart!"<<endl;
            }

        }
        else{
            cart.viewCart();
            if(checkout(cart))
            {
                break; 
            }
        }
    }




    

    return 0;
}

