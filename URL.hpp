#include <string>
#include <curl/curl.h>
using namespace std;

class URL
{
    private:
        string link;

    public:
        URL(string link);
        void display();
        static getContents();
}
