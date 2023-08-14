#ifndef SRC_MODEL_H_
#define SRC_MODEL_H_

#include <raylib.h>

#include <fstream>

namespace s21 {
/// @brief Model class
/// @details This class is used to load 3D models and set their position and
/// rotation.
class _Model {
 public:
  /// @brief  Initialize the model
  void initBasics();
  /// @brief  Initialize the model with a file
  /// @param  path  Path to the file
  void initBasics(const char* path);
  /// @brief Get the model
  /// @return The model
  Model getModel();
  /// @brief Set the model position
  /// @param  axis  Axis to set
  /// @param  value Value to set
  void setModelPos(char axis, float value);
  /// @brief Set the model rotation
  /// @param  axis  Axis to set
  /// @param  value Value to set
  void setModelRot(char axis, float value);
  /// @brief Get the model position
  /// @return The model position
  Vector3 getModelPos();
  /// @brief Get the model rotation
  /// @return The model rotation
  Vector3 getModelRot();
  /// @brief Get the mesh count
  /// @param  path  Path to the file
  void getMeshCount(const char* path);
  /// @brief Get the vertex count
  /// @return The vertex count
  uint32_t getVCnt();
  /// @brief Get the face count
  /// @return The face count
  uint32_t getFCnt();

 private:
  Model model3d;
  Vector3 model_pos = {0.0f, 0.0f, 0.0f};
  Vector3 model_rot = {0.0f, 0.0f, 0.0f};

  uint32_t v_cnt = 0;
  uint32_t f_cnt = 0;
};
}  // namespace s21

#endif  // SRC_MODEL_H_