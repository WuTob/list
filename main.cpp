#include "list.h"
#include <iostream>
#include <stdlib.h>

int main()
{
    list<int> l(1);
    l.append(2);
    l.append(4);
    l.append(3, 2);
    l.prepend(0);

    for(int i = 1; i <= l.getLenght(); i++)
    {
        std::cout << l.getData(i) << " ";
    }

    system("pause");

    return 0;
}
