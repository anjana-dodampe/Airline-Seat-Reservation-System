#include <iostream>
#include <algorithm>
#include <cstring>

int main()
{
    char text[250] = "Hello!";
    std::cout<<text;
    char del = 'l';
    std::remove(text,text + strlen(text) + 1,del);
    std::cout << text;
}
