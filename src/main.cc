#include "main.h"

using namespace s21;

int main() {
  _Model m;
  Controller c(&m);
  View v(&c);
  v.startApp();

  return 0;
}