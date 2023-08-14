#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

#include <raylib.h>

#include "../model/model.h"

namespace s21 {
/// @brief Controller class
/// @details This class is responsible for initializing the model and
///          getting the vertex and face count.
class Controller {
 public:
  /// @brief Construct a new Controller object
  /// @param m
  Controller(_Model* m) : model(m){};
  /// @brief  Initialize the model
  void initBasics();
  /// @brief  Initialize the model
  /// @param path
  void initBasics(const char* path);
  /// @brief  Get the model
  /// @return Model
  Model getModel();
  /// @brief  Set the model position
  /// @param axis
  /// @param value
  void setModelPos(char axis, float value);
  /// @brief  Set the model rotation
  /// @param axis
  /// @param value
  void setModelRot(char axis, float value);
  /// @brief  Get the model position
  /// @return Vector3
  Vector3 getModelPos();
  /// @brief  Get the model rotation
  /// @return Vector3
  Vector3 getModelRot();
  /// @brief  Get the vertex count
  /// @return uint32_t
  uint32_t getVCnt();
  /// @brief  Get the face count
  /// @return uint32_t
  uint32_t getFCnt();

 private:
  _Model* model;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_H_