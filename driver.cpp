#include "URL.hpp"
#include "URL.cpp"
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char** argv)
{
    //char url_link[1000] = "https://api.hearthstonejson.com/v1/25770/enUS/cards.json";
    
    URL u1 = new URL(“http://www.google.com");
    URL u2 = new URL(“http://www.yahoo.com");
    Cout << u1.getContents() << endl;
    Cout << u2.getContents() << endl;

    return 0;
}
