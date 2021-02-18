#include "URL.hpp"
#include <iostream>
#include <curl/curl.h>
using namespace std;

size_t handle_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int numbytes = size*nmemb;
    char lastchar = *((char *) ptr + numbytes - 1);
    *((char *) ptr + numbytes - 1) = '\0';
    contents.append((char *)ptr);
    contents.append(1,lastchar);
    *((char *) ptr + numbytes - 1) = lastchar;  
    return size*nmemb;
}

URL::URL(string link)
{
    this->link = link;
}

void URL::display()
{
    cout << "URL: " << this->link << endl;
}

static void URL::getContents()
{
    CURL* curl = curl_easy_init();
    if(curl) 
    {
        curl_easy_setopt(curl,CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,handle_data); 
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res == 0)
        {
            cout << contents << endl;

            string temp = "";
            for(int i = 0; i < 5; i++)
            {
                temp += contents[i];
            }
            cout << temp << endl;
        }
        else
        {
            cerr << "Error: " << res << endl;
        }
    }
}
