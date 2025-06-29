#include <iostream>

int main(int argc, char *argv[]) {
  int x = 4;

  auto y = [&r = x, x = x + 1]() -> int {
    r += 2;
    return x * x;
  }(); // updates ::x to 6 and initializes y to 25.
  // ********** ↑
  //  EQAUL TO   |
  // ********** ↓
  // auto y = [&r = x, z = x + 1]() -> int {
  //   r += 2;
  //   return z * z;
  // }(); // updates ::x to 6 and initializes y to 25, by init a 'z' with 5

  std::cout << "y = " << y << std::endl;
  std::cout << "x = " << x << std::endl;
  return 0;
}
