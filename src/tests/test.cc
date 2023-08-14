#include "test.h"

int main() {
  InitWindow(800, 600, "test");
  testing::InitGoogleTest();
  RUN_ALL_TESTS();
  CloseWindow();
  return 0;
}

namespace {
TEST(ModelTest, InitBasic) {
  s21::_Model model;
  model.initBasics();
  EXPECT_NE(model.getModel().meshCount, 0);
}

TEST(ModelTest, InitWithFile) {
  s21::_Model model;
  model.initBasics("./3dobjects/man.obj");
  EXPECT_NE(model.getModel().meshCount, 0);
}

TEST(ModelTest, ModelPos) {
  s21::_Model model;
  model.setModelPos('x', 5.0f);
  EXPECT_FLOAT_EQ(model.getModelPos().x, 5.0f);
}

TEST(ModelTest, ModelRot) {
  s21::_Model model;
  model.setModelRot('y', 90.0f);
  EXPECT_FLOAT_EQ(model.getModelRot().y, 90.0f);
}

TEST(ModelTest, VertexCount) {
  s21::_Model model;
  model.initBasics("./3dobjects/man.obj");
  EXPECT_NE(model.getVCnt(), 0);
}

TEST(ModelTest, FaceCount) {
  s21::_Model model;
  model.initBasics("./3dobjects/man.obj");
  EXPECT_NE(model.getFCnt(), 0);
}

}  // namespace