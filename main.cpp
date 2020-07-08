
#include <iostream>
#include <vector>

#include "LinkedList.h"
#include "V3.h"
#include "Timer.h"
#include "MyString.h"

void fillList(LinkedList<MyString>& ll, size_t n)
{
    for (int i = 0; i < n; ++i)
    {
        ll << "Hallo Welt";
    }
}

int main()
{
    LinkedList<int> ll{};
    for (int i = 0; i < 1000; ++i)
        ll << i;

    for (int& i : ll)
        std::cout << i << " ";
    std::cout << std::endl;
}