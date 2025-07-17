#include <iostream>
#include <vector>
#include <fstream>
#include "Task_one.h"

int main()
{
    std::vector<int> v = {1,2,3};
    int& wichtig = v[2];
    std::cout << wichtig << std::endl;
    wichtig++;
    std::cout << wichtig << std::endl;
    v.push_back(10);
    std::cout << wichtig;
}
