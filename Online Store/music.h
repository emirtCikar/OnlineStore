#pragma once
#include "product.h"

using namespace std;
class music :
    public product
{   public:
                // parametrized constructor declaration for music class
    music(string name, string language, string genre, int stock, double price, string code, string artist, string format, int run_time)
        :product(name,language,genre,"music",stock,price,code),_artist(artist),_format(format),_run_time(run_time) 
    {}

    void display()  //display function for music class
    {
        product::display();
        cout << "Artist: " << _artist << endl;
        cout << "Format: " << _format << endl;
        cout << "Run Time: " << _run_time << endl;
    }

private:    //private data values besides the base class data's
    string _artist,_format; 
    int _run_time;
};

