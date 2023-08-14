#include "controller.h"
#include <raylib.h>

void s21::Controller::initBasics() {
    model->initBasics();
}

void s21::Controller::initBasics(const char* path) {
    model->initBasics(path);
}

Model s21::Controller::getModel() {
    return model->getModel();
}

void s21::Controller::setModelPos(char axis, float value) {
    model->setModelPos(axis, value);
}

void s21::Controller::setModelRot(char axis, float value) {
    model->setModelRot(axis, value);
}


Vector3 s21::Controller::getModelPos() {
    return model->getModelPos();
}

Vector3 s21::Controller::getModelRot() {
    return model->getModelRot();
}

uint32_t s21::Controller::getVCnt() {
    return model->getVCnt();
}

uint32_t s21::Controller::getFCnt() {
    return model->getFCnt();
}
