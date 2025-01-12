#include "product.h"
class book :
	public product
{
public:	// parametrized constructor for book class
	book(string name, string language, string genre, int stock, double price, string code, string publisher, string ISBN)	// parametrized constructor declaration
		:product(name,language,genre,"book",stock,price,code),_publisher(publisher),_ISBN(ISBN)
	{}
		
	void display()	//display function for book class
	{
		product::display();
		cout << "Publisher: " << _publisher << endl;
		cout << "ISBN: " << _ISBN << endl;
	}
	



private:
    string _publisher, _ISBN;	//private data values besides the base class data's
};

