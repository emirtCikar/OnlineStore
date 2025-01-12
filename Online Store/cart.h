#pragma once
#include"product.h"
using namespace std;
int i;
class cart
{
public:

	bool addProduct(product p_product) {	//adding product to cart
		if (_product.size() >= 5)
			return 0;
		_product.push_back(p_product);
		return 1;
	}

	bool removeProduct(int i) {		//removing product from cart

		if (i >= _product.size()) 
			return false;
		else
			_product.erase(_product.begin() + i);
			return true;
	}

	double totalP() {	
		double price = 0;
		for (product& p_product : _product) price = price + p_product.calculateDiscount();
		return price;
	}

	void setTotalP(double total) {	//	returning value of total price
		double _totalP = total;
	}

	void display() {	//	display func for shopping cart
		for (int i = 0; i < _product.size(); i++) {
			cout << i+1 << ". " << _product[i].name();
			cout << " - " << _product[i].calculateDiscount() <<"$"<< endl;
		}
		cout << "Total Price: " << totalP() <<"$"<< endl;
	}

	private:
	vector<product>_product;

};