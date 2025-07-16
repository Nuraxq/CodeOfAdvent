#pragma once

#ifndef TASK_ONE_H
#define TASK_ONE_H
#include <vector>
#include <fstream>


class Task_one {
  private:
      std::vector<int> left_value_;
      std::vector<int> right_value_;
      int result_ = 0;

    public:

      void read_file();
      int solve();

};



#endif //TASK_ONE_H
