#include "model.h"

#include <raylib.h>
#include <iostream>

void s21::_Model::initBasics() {
  model3d = LoadModel("./3dobjects/man.obj");
  getMeshCount("./3dobjects/man.obj");
}

void s21::_Model::initBasics(const char* path) {
  model3d = LoadModel(path);
  getMeshCount(path);
}

void s21::_Model::getMeshCount(const char* path) {
  f_cnt = 0;
  v_cnt = 0;

  FILE* file = fopen(path, "r");
  if (file == NULL) return;

  char* line = NULL;
  size_t linecap = 0;

  while (getline(&line, &linecap, file) > 0) {
    if (line[0] == 'v') {
      v_cnt++;
    }
    if (line[0] == 'f') {
      f_cnt++;
    }
  }
  fclose(file);
  free(line);
}

Model s21::_Model::getModel() { return model3d; }

void s21::_Model::setModelPos(char axis, float value) {
  switch (axis) {
    case 'x':
      model_pos.x = value;
      break;
    case 'y':
      model_pos.y = value;
      break;
    case 'z':
      model_pos.z = value;
      break;
  }
}

void s21::_Model::setModelRot(char axis, float value) {
  switch (axis) {
    case 'x':
      model_rot.x = value;
      break;
    case 'y':
      model_rot.y = value;
      break;
    case 'z':
      model_rot.z = value;
      break;
  }
}

Vector3 s21::_Model::getModelPos() { return model_pos; }

Vector3 s21::_Model::getModelRot() { return model_rot; }

uint32_t s21::_Model::getVCnt() { return v_cnt; }

uint32_t s21::_Model::getFCnt() { return f_cnt; }
