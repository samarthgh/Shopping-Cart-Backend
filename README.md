# Shopping Cart Backend Project

This is a terminal-based shopping cart backend project written in C++. It allows users to add products, remove products, view the cart, and proceed to checkout. The project utilizes classes and implements the necessary functionality for managing a shopping cart.

## Installation

1. Clone the repository:

```shell
git clone https://github.com/your-username/shopping-cart.git
```

2. Navigate to the project directory:

```shell
cd shopping-cart
```

3. Compile the source code:

```shell
g++ main.cpp datamodel.cpp -o shopping-cart
```

4. Run the program:

```shell
./shopping-cart
```

## Usage

Upon running the program, you will be presented with a menu of actions to choose from. The available actions are as follows:

- `(a)dd an item`: Allows you to add a product to the shopping cart. You will be prompted to enter the name of the product you wish to add.

- `(v)iew item`: Displays the contents of the shopping cart, including the quantity of each item and the total amount.

- `(r)emove`: Allows you to remove a product from the shopping cart. You will be prompted to enter the name of the product you wish to remove.

- `(c)heck out`: Proceeds to the checkout process. You will be asked to pay in cash. If the payment is sufficient, the program will display the change and a thank you message. Otherwise, it will inform you that the payment is not enough.

To navigate the menu, simply enter the corresponding letter for the desired action and press Enter.

## Data Model

The project includes a `datamodel.h` file that defines the classes used for product, item, and the shopping cart. These classes are utilized in the main program (`main.cpp`) to manage the shopping cart operations. The `datamodel.h` file is responsible for defining the following classes:

- `Product`: Represents a product with an ID, name, and price. It provides methods to retrieve the product name and display its information.

- `Item`: Represents an item in the shopping cart. It consists of a product and a quantity. The class provides methods to calculate the item price and retrieve information about the item.

- `Cart`: Represents the shopping cart and manages the collection of items. It utilizes an unordered map to store items by their product IDs. The class provides methods to add products to the cart, remove products from the cart, calculate the total price, view the cart contents, and check if the cart is empty.
