#pragma once
#include "product.h"
class movie :
    public product
{    
    public:
                // parametrized constructor declaration for movie class
    movie(string name, string language, string genre, int stock, double price, string code, string subtitles, string audio_language,string starring_1, string starring_2, string starring_3,string director_1,string director_2)	// parametrized constructor declaration
    :product(name, language, genre, "movie", stock, price, code),_subtitles(subtitles), _audio_language(audio_language), _starring_1(starring_1),_starring_2(starring_2),_starring_3(starring_3), _director_1(director_1), _director_2(director_2) {}
    
    void display()  //display function for movie class
    {
        product::display();     
            cout << "Subtitles: " <<_subtitles<< endl;
            cout << "Audio language: " <<_audio_language<< endl;
            cout << "Starring(s): " << _starring_1<<endl;
            if (!_starring_2.empty())
                cout <<_starring_2<<endl;
            if (!_starring_3.empty())
                cout <<_starring_3<<endl;
            cout << "Director(s): " << _director_1<<endl;
            if (!_director_2.empty())
                cout << _director_2<<endl;
    }







private:    //private data values besides the base class data's
    string _subtitles,_audio_language, _starring_1, _starring_2, _starring_3,_director_1, _director_2;
};

