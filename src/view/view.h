#ifndef SRC_VIEW_H_
#define SRC_VIEW_H_

#include <raylib.h>

#include "../controller/controller.h"
// #define RAYGUI_IMPLEMENTATION
#include <sstream>

#include "raygui.h"

namespace s21 {
/// @brief View class
/// @details This class is responsible for initializing the model and
///          getting the vertex and face count.
class View {
 public:
  /// @brief Construct a new View object
  /// @param c
  View(Controller* c) : controller(c){};
  /// @brief Start the application
  void startApp();

 private:
  Controller* controller;
};
}  // namespace s21

#endif  // SRC_VIEW_H_