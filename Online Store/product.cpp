#include "product.h"
#include "music.h"
#include "cart.h"
#include "book.h"
#include "movie.h"

using namespace std;

cart c1;    //global cart object
vector<product>_products; //global product (vector) objecct

template<typename T>
void updateP(cart& c1, T& p_product, double nPrice)
{
	double difference = (p_product.price() - nPrice);   //we find difference to calculate total price


	p_product.setPrice(nPrice);

	c1.setTotalP(c1.totalP() - difference);     // total price lvalue

}

void initializeProducts() { //initializing products of shop
	_products.push_back(book("Red Rising", "English", "Science-Fiction", 300, 29.99, "X1", "Pierce Brown", "453223953246"));
	_products.push_back(book("Degisen Beynim", "Turkish", "Scientific",  100, 21.99, "X2", "Sinan Canan", "584334654698"));
    _products.push_back(book("Clasroom of The Elite", "English", "Drama", 75, 49.99, "X3", "Syougo Kinugasa", "546345862236"));
	_products.push_back(music("Levitating", "English", "Pop-Funk", 250, 7.99, "Y1", "Dua Lipa", "MP3", 230));
	_products.push_back(music("Venom", "English", "Hip-Hop/Rap",  500, 9.99, "Y2", "Eminem", "MP3", 295));
    _products.push_back(music("Gul Pembe", "Turkish", "Turkish Folk", 80, 4.99, "Y3", "Baris Manco", "MP3", 312));
	_products.push_back(movie("Kingsman: The Secret Service", "English", "Action",  49, 19.99, "Z1", "English", "English", "Samuel L. Jackson", "Taron Egerton", "Colin Firth", "Matthew Vaughn",""));
    _products.push_back(movie("Mission: Impossible - Fallout", "English", "Thriller", 300, 9.99, "Z2", "English", "English", "Tom Cruise", "Henry Cavill", "Ving Rhames", "Christopher McQuarrie", ""));
    _products.push_back(movie("Uncharted", "English", "Adventure", 21, 29.99, "Z3", "English", "English", "Tom Holland", "Mark Wahlberg", "Antonio Banderas", "Ruben Fleischer", ""));
}


// func to display admin menu
void dAdminMenu() {
        cout << "Admin Menu" << endl;
        cout << "1. Update product information" << endl;
        cout << "2. Exit" << endl;
}



// func to display customer menu
void dCustomerMenu() {
        cout << "Customer Menu" << endl;
        cout << "1. View Cart" << endl;
        cout << "2. Select Category" << endl;
        cout << "3. Exit" << endl;
 
}


int main() {
    initializeProducts();   //To initialize products which are existing
    int n1, n2,n3,n4;
    start:
	cout << "Welcome to our online store. Enter the character defined for the admin login. Press any key to continue as a customer..." << endl;
    char userT; //we use a char value to denote user type
    cin >> userT;

    if (userT == '*') {      // Admin user panel
        s1:
        dAdminMenu();
        cin >> n1;
        
  
        if (n1 == 1)    // product category menu
        {
            s2:
            cout << "1. Books" << endl;
            cout << "2. Music" << endl;
            cout << "3. Movies" << endl;
            cout << "4.Exit" << endl;
            cin >> n2;
            cout << "View List:" << endl;


            
            if (n2 == 1)
            {

                for (int i = 0; i < 3; i++) {   //viewing book products
                    cout << i << ". " << _products[i].name() << endl;
                    _products[i].display();
                    cout << endl;
                }

                cout << "Select a product by index: ";
                int i1;
                cin >> i1;

                if (i1 >= 3) {
                    cout << "There is no such product index!" << endl;
                    
                }

                cout << "1. Update stock" << endl;
                cout << "2. Update price" << endl;
                cout << "3. Exit" << endl;

                cin >> n3;
                if (n3 == 1)    // updating stock
                {
                    cout << "Enter the new stock value: ";
                    int stock;
                    cin >> stock;
                    _products[i1].setStock(stock);  // to return data of stock by public func
                    cout << "Stock of selected product has been updated" << endl;
                    goto s1;
                }

                else if (n3 == 2)   // updating price
                {
                    cout << "Enter the new price value: ";
                    double price;
                    cin >> price;
                    updateP(c1, _products[i1], price);
                    cout << "Price of selected product has been updated" << endl;
                    goto s1;
                }

                else if (n3 == 3)
                {
                    goto s2;
                }

                else
                    cout << "Invalid choice!!!" << endl;
            }

            else if (n2 == 2)
            {
                for (int i = 3; i < 6; i++) {   //viewing movie products
                    cout << i << ". " << _products[i].name() << endl;
                    _products[i].display();
                    cout << endl;
                }

                cout << "Select a product by index: ";
                int i1;
                cin >> i1;

                if (i1 >= 6) {
                    cout << "There is no such product index!" << endl;
                
                }
                
                cout << "1. Update stock" << endl;
                cout << "2. Update price" << endl;
                cout << "3. Exit" << endl;

                cin >> n3;
                if (n3 == 1)    // updating stock
                {
                    cout << "Enter the new stock value: ";
                    int stock;
                    cin >> stock;
                    _products[i1].setStock(stock);  // to return data of stock by public func
                    cout << "Stock of selected product has been updated" << endl;
                    goto s1;    // to turn back
                }

                else if (n3 == 2)   // updating price
                {
                    cout << "Enter the new price value: ";
                    double price;
                    cin >> price;
                    updateP(c1, _products[i1], price);
                    cout << "Price of selected product has been updated" << endl;
                    goto s1;    // to turn back
                }

                else if (n3 == 3)
                {
                    goto s2;    // to turn back
                }

                else
                    cout << "Invalid choice!!!" << endl;
            }

            else if (n2 == 3)
            {
                for (int i = 6; i < 9; i++) {   //viewing music products
                    cout << i << ". " << _products[i].name() << endl;
                    _products[i].display();
                    cout << endl;
                }

                cout << "Select a product by index: ";
                int i1;
                cin >> i1;

                if (i1 >= 9) {
                    cout << "There is no such product index!" << endl;
                    
                }
                
                cout << "1. Update stock" << endl;
                cout << "2. Update price" << endl;
                cout << "3. Exit" << endl;

                cin >> n3;
                if (n3 == 1)    // updating stock
                {
                    cout << "Enter the new stock value: ";
                    int stock;
                    cin >> stock;
                    _products[i1].setStock(stock);  // to return data of stock by public func
                    cout << "Stock of selected product has been updated" << endl;
                    goto s1;    // to turn back
                }

                else if (n3 == 2)   // updating price
                {
                    cout << "Enter the new price value: ";
                    double price;
                    cin >> price;
                    updateP(c1, _products[i1], price);
                    cout << "Price of selected product has been updated" << endl;
                    goto s1;    // to turn back
                }

                else if (n3 == 3)
                {
                    goto s2;    // to turn back
                }

                else
                    cout << "Invalid choice!!!" << endl;
            }
            else if (n2==4)
            {
                goto s1;    // to turn back
            }

            else
                cout << "Invalid choice!!!" << endl;
        }
        else if (n1 == 2)
        {
            goto start;     // to return start
        }
        else
            cout << "Invalid choice!!!" << endl;
    }









    else {        // Customer user panel
        p0:
        dCustomerMenu();
        cin >> n2;

        if (n2 == 1)
        {
            c1.display();   //to view products in cart
            goto p0;
        }
        else if (n2 == 2)       // product category menu
        {
            p1:         
            cout << "1. Books" << endl;     
            cout << "2. Music" << endl;
            cout << "3. Movies" << endl;
            cout << "4.Exit" << endl;
            cin >> n3;
            
            if (n3==1)
            {
                r1:
                cout << "1. Select Product" << endl;
                cout << "2. Exit" << endl;
                cin >> n4;
                if (n4==1)          // selecting product 
                {
                    for (int i = 0; i < 3; i++) {
                    if (_products[i].category() == "book") {
                        cout << i << ". " << _products[i].name() << endl;
                        _products[i].display();
                        cout << endl;
                        }
                    }               // adding product to cart
                    cout << "Enter the index of product add to cart: ";
                    int i;
                    cin >> i;
                    if (i >= _products.size() || _products[i].category() != "book") {
                        cout << "Invalid product index!" << endl;
                        goto r1;
                    }
                    
                    if (!c1.addProduct(_products[i])) {
                        cout << "There is no space in cart!" << endl;
                        }
                    else {
                        cout << "A product has been added to cart" << endl;
                    }
                    goto p0;
                }
                else if (n4==2)
                {
                    goto p1;    // to turn back
                }
                else
                
                    cout << "Invalid choice!!!" << endl;
              
            }

            else if (n3 == 2)
            {
            r2:
                cout << "1. Select Product" << endl;
                cout << "2. Exit" << endl;
                cin >> n4;
                if (n4 == 1)        // selecting product
                {
                    for (int i = 3; i < 6; i++) {
                        if (_products[i].category() == "music") {
                            cout << i << ". " << _products[i].name() << endl;
                            _products[i].display();
                            cout << endl;
                        }
                    }               // adding product to cart
                    cout << "Enter the index of product add to cart: ";
                    int i;
                    cin >> i;
                    if (i >= _products.size() || _products[i].category() != "music") {
                        cout << "Invalid product index!" << endl;
                        goto r2;
                    }
                
                    if (!c1.addProduct(_products[i])) {
                        cout << "There is no space in cart!" << endl;
                    }
                    else {
                        cout << "A product has been added to cart" << endl;
                    }
                    goto p0;
                }
                else if (n4 == 2)
                {
                    goto p1;
                }
                else

                    cout << "Invalid choice!!!" << endl;
            }

            else if (n3 == 3)
            {
            r3:
                cout << "1. Select Product" << endl;
                cout << "2. Exit" << endl;
                cin >> n4;
                if (n4 == 1)        // selecting product
                {
                    for (int i = 6; i < 9; i++) {
                        if (_products[i].category() == "movie") {
                            cout << i << ". " << _products[i].name() << endl;
                            _products[i].display();
                            cout << endl;
                        }
                    }               // adding product to cart
                    cout << "Enter the index of product add to cart: ";
                    int i;
                    cin >> i;
                    if (i >= _products.size() || _products[i].category() != "movie") {
                        cout << "Invalid product index!" << endl;
                        goto r3;
                    }
                
                    if (!c1.addProduct(_products[i])) {
                        cout << "There is no space in cart!" << endl;
                    }
                    else {
                        cout << "A product has been added to cart" << endl;
                    }
                    goto p0;
                }
                else if (n4 == 2)
                {
                    goto p1;    // to turn back
                }
                else
                    cout << "Invalid choice!!!" << endl;
            }

            else if (n3 == 4)
            {
                goto p0;    // to turn back
            }

            else
                cout << "Invalid choice!!!" << endl;

        }

        else if (n2 == 3)
        {
            goto start; // to return start
        }
        else
            cout << "Invalid choice!!!" << endl;
    }

    return 0;
}










