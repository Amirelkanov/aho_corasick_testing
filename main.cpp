#include <iostream>

int classifier(int n) {
    int num = 1;
    if (n == 0) {
        return 0;
    }
    if (n % 2 == 0) {
        num += 1;
    }
    if (n < 0) {
        num -= 1;
    } else {
        num += 2;
    }

    return num;
}

int main() {
  classifier(0);
  classifier(2);
  std::cout << "halo";
  return 0;
}

