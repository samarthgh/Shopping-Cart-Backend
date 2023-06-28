#include <string>
#include <unordered_map>
using namespace std;
class Item;
class Cart;

class Product
{
    int id;
    string name;
    int price;

public:
    Product()
    {

    }
    Product(int id, string name, int price)
    {
        this -> id = id;
        this -> name = name;
        this -> price = price;
    }
    string getDisplayName()
    {
        return (name + " : ₹ " + to_string(price)+"\n");
    }
    friend class Item;
    friend class Cart;
    string getName()
    {
        return name;
    }
};

class Item{


    Product product;
    int quantity;

public:
    Item(){}
    Item(Product p, int q):product(p),quantity(q){}
    int getItemPrice()
    {
        return quantity*product.price;
    }

    string getItemInfo(){
        return (to_string(quantity) + " x " + product.name + " ₹ " +  to_string(getItemPrice()) + "\n");
    }
    friend class Cart; 

};

class Cart{
    unordered_map <int,Item> items;
    public:
    void addProducts(Product product)
    {
        if(items.count(product.id) == 0)
        {
            Item newItem(product,1);
            items[product.id] = newItem;
        }
        else
        {
            items[product.id].quantity ++;
        }
    }

    void removeProducts(Product product)
    {
        if(items.count(product.id) == 0)
        {
            return;
        }
        else
        {
            items[product.id].quantity --;
        }
    }

    int getTotal()
    {
        int total = 0;
        for(auto itemPair : items)
        {
            auto item = itemPair.second;
            total += item.getItemPrice();
        }
        return total;
    }

    string viewCart()
    {
        if(items.empty())
        {
            return "Cart is empty";
        }
        string itemizedList;
        int cart_total = getTotal();

        for(auto itemPair : items)
        {
            auto item = itemPair.second;
            itemizedList.append(item.getItemInfo());
        }
        
        return itemizedList+ "\n Total amount : Rs. " + to_string(cart_total) + '\n';
    }

    bool isEmpty()
    {
        return items.empty();
    }



};
