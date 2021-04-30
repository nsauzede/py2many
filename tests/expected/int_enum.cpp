#include "py14/runtime/builtins.h"
#include "py14/runtime/sys.h"
#include <cassert>
#include <iostream>
#include <map>

enum Colors : int {
  RED = 0,
  GREEN = 1,
  BLUE = 2,
};

enum Permissions : int {
  R = 1,
  W = 2,
  X = 16,
};

inline void show() {
  std::map<Colors, std::string> color_map =
      std::map<Colors, std::string>{{Colors::RED, std::string{"red"}},
                                    {Colors::GREEN, std::string{"green"}},
                                    {Colors::BLUE, std::string{"blue"}}};
  Colors a = Colors::GREEN;
  if (a == Colors::GREEN) {
    std::cout << std::string{"green"};
    std::cout << std::endl;
  } else {
    std::cout << std::string{"Not green"};
    std::cout << std::endl;
  }
  Permissions b = Permissions::R;
  if (b == Permissions::R) {
    std::cout << std::string{"R"};
    std::cout << std::endl;
  } else {
    std::cout << std::string{"Not R"};
    std::cout << std::endl;
  }
  assert(color_map.size() != 0);
}

int main(int argc, char **argv) {
  py14::sys::argv = std::vector<std::string>(argv, argv + argc);
  show();
}
