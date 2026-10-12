#include <iostream>
#include <vector>

using namespace std;

class Product {
    public: 
        string name;
        int price;

        Product(string name, int price){
            this->name = name;
            this->price = price;
        }
};

class ShoppingCart {
    
    public:
        vector<Product *> products;
        void addProductToCart(Product * p){
            products.push_back(p);
        }

        int calculateTotalPrice(){
            int totalPrice = 0;

            for(auto product : products){
                totalPrice += product->price;
            }

            return totalPrice;
        }
};

// Abstract Class to follow the OCP Principle
class CartStorage {
    public:
        virtual void save(ShoppingCart * cart) = 0;
};

// Concrete Class to save cart as draft
class SaveAsDraft : public CartStorage {
    public:
        void save(ShoppingCart * cart){
            cout << "Saving cart as draft with total price " << cart->calculateTotalPrice() << endl;
        }
};

// Concrete Class to save cart as JSON in DB
class SaveAsJsonInDB : public CartStorage {
    public:
        void save(ShoppingCart * cart){
            string json = "{";
            for(auto product : cart->products){
                json += "\"" + product->name + "\": " + to_string(product->price) + ",";
            }
            json += "}";

            cout << "Saving cart as JSON in DB: " << json << endl;
        }
};


// Voilation of OCP Principle
// class CartStorage {
//     private:
//         ShoppingCart * cart;

//     public:
//         // Save cart as draft
//         void saveAsDraft(ShoppingCart * cart){
//             if(cart->products.size() > 0){
//                 cout << "Saving cart as draft with total price " << cart->calculateTotalPrice() << endl;
//             }
//             else{
//                 cout << "No products in cart to save as draft" << endl;
//             }
//         }

//         void saveAsJosnInDB(ShoppingCart * cart){
//             string json = "{";
//             for(auto product : cart->products){
//                 json += "\"" + product->name + "\": " + to_string(product->price) + ",";
//             }
//             json += "}";
//             cout << "Saving cart as JSON in DB: " << json << endl;
//         }
// };

class CartInvoicePrinter {
    private:
        ShoppingCart * cart;

    public:
        void printInvoice(ShoppingCart * cart){

            for(auto product : cart->products){
                cout << product->name << " - " << product->price << endl;
            }

            cout << "Total price: " << cart->calculateTotalPrice() << endl;
        }
};

int main(){
    Product * pt = new Product("Headphones", 80);
    ShoppingCart * sc = new ShoppingCart();
    
    // Adding product to cart
    sc->addProductToCart(pt);
    // OR Directly adding product to cart
    sc->addProductToCart(new Product("Milk", 35));

    // Calculating total price
    cout << "Total price: " << sc->calculateTotalPrice() << endl;

    
    // Saving cart as draft object
    SaveAsDraft * sda = new SaveAsDraft();
    // Saving cart as JSON in DB object
    SaveAsJsonInDB * sjid = new SaveAsJsonInDB();

    // Saving cart as draft
    sda->save(sc);
    // Saving cart as JSON in DB
    sjid->save(sc);

    CartInvoicePrinter * cip = new CartInvoicePrinter();
    cip->printInvoice(sc);

    return 0;
}