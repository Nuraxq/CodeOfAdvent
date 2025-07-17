#pragma once

#ifndef TASK_ONE_H
#define TASK_ONE_H
#include <vector>
#include <fstream>
#include <algorithm>
#include <ranges>
#include <iostream>
#include <map>

class FileError : public std::runtime_error {
public:
    explicit FileError(const std::string& message)
        : std::runtime_error(message){}
};

class Task_one {
  private:
      std::vector<int> list_l;
      std::vector<int> list_r;
      int result_ = 0;

  public:

    void read_file();
    int solve();
    int solve_2();
    int solve_2_quick();
};



#endif //TASK_ONE_H
