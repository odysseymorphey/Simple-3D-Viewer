#include "view.h"

#include <raylib.h>
#include <iostream>

void s21::View::startApp() {
  InitWindow(1280, 720, "3D Viewer");

  controller->initBasics();

  Camera camera;
  camera.position = (Vector3){20.0f, 20.0f, 20.0f};
  camera.target = (Vector3){0.0f, 10.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  // MODEL POSITION
  float mp_x = 0.0f;
  float mp_y = 0.0f;
  float mp_z = 0.0f;

  // MODEL ROTATION
  float mr_x = 0.0f;
  float mr_y = 0.0f;
  float mr_z = 0.0f;
  float tensen = 0.0f;

  // MODEL SCALE
  float mscale = 1.0f;

  std::ostringstream s;
  s << "Vertices count: " << controller->getVCnt() << '\n'
    << "Faces count: " << controller->getFCnt() << std::endl;

  while (!WindowShouldClose()) {
    if (IsFileDropped()) {
      FilePathList droppedFiles = LoadDroppedFiles();
      if (droppedFiles.count == 1) {
        if (IsFileExtension(droppedFiles.paths[0], ".obj")) {
          UnloadModel(controller->getModel());
          controller->initBasics(droppedFiles.paths[0]);
        }
      }
    }

    if (IsKeyPressed(KEY_ONE)) {
      camera.projection = CAMERA_PERSPECTIVE;
    }

    if (IsKeyPressed(KEY_TWO)) {
      camera.projection = CAMERA_ORTHOGRAPHIC;
    }

    UpdateCameraPro(&camera, (Vector3){0.0f, 0.0f, 0.0f},
                    (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);

    mp_x = GuiSlider((Rectangle){50, 40, 192, 24}, "Move X", "", mp_x, -60.0f,
                     60.0f);
    controller->setModelPos('x', mp_x);
    mp_y = GuiSlider((Rectangle){50, 70, 192, 24}, "Move Y", "", mp_y, -60.0f,
                     60.0f);
    controller->setModelPos('y', mp_y);
    mp_z = GuiSlider((Rectangle){50, 100, 192, 24}, "Move Z", "", mp_z, -60.0f,
                     60.0f);
    controller->setModelPos('z', mp_z);

    mr_x = GuiSlider((Rectangle){50, 140, 192, 24}, "Rotate X", "", mr_x, 0.0f,
                     360.0f);
    controller->setModelRot('x', mr_x);
    mr_y = GuiSlider((Rectangle){50, 170, 192, 24}, "Rotate Y", "", mr_y, 0.0f,
                     360.0f);
    controller->setModelRot('y', mr_y);
    mr_z = GuiSlider((Rectangle){50, 200, 192, 24}, "Rotate Z", "", mr_z, 0.0f,
                     360.0f);
    controller->setModelRot('z', mr_z);
    tensen = GuiSlider((Rectangle){50, 230, 192, 24}, "Tensen", "", tensen,
                       0.0f, 360.0f);

    mscale = GuiSlider((Rectangle){1050, 130, 192, 24}, "Scale", "", mscale,
                       0.01f, 5.0f);

    BeginDrawing();

    ClearBackground(BLACK);

    BeginMode3D(camera);
    DrawModelWiresEx(controller->getModel(), controller->getModelPos(),
                     controller->getModelRot(), tensen,
                     (Vector3){mscale, mscale, mscale}, BLUE);
    EndMode3D();

    DrawText("Drag & drop model to load mesh", 10, 10, 20, GRAY);
    DrawText(s.str().c_str(), 10, 260, 10, GRAY);

    EndDrawing();
  }

  CloseWindow();
}