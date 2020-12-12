cmake_minimum_required(VERSION 3.12)
project(projekt_final)

set(CMAKE_CXX_STANDARD 14)

set(GCC_COVERAGE_COMPILE_FLAGS "-framework OpenGL -I/usr/local/include -L/usr/local/lib -lglfw -pthread  -lglfw -ldl -lglut -lglew -lSOIL -lassimp ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

include_directories(.)
include_directories(models)

add_executable(projekt_final
        Application.cpp
        Application.h
        Camera.cpp
        Camera.h
        Controller.cpp
        Controller.h
        Object.cpp
        Object.h
        Light.cpp
        Light.h
        main.cpp
        opengl_helper.h
        Shader.cpp
        Shader.h
        ShaderLoader.cpp
        ShaderLoader.h OnChangeCameraSubject.h OnChangeCameraObserver.h OnChangeLightSubject.h OnChangeLightObserver.h Scene.cpp Scene.h InputKeyboard.cpp InputKeyboard.h InputMouse.cpp InputMouse.h MeshManager.cpp MeshManager.h Mesh.cpp Mesh.h Vertex.cpp Vertex.h Texture.cpp Texture.h Drawable.cpp Drawable.h Model.cpp Model.h SkyBox.cpp SkyBox.h LightManager.cpp LightManager.h)
