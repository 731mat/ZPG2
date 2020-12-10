//
// Created by Matěj Hloušek on 10/12/2020.
//
#include "InputMouse.h"
#include "Controller.h"
#include "Application.h"



bool InputMouse::mouseClick[10] = {};
glm::vec2 InputMouse::mouseCursor = glm::vec2(0.0f);

InputMouse::InputMouse()
{
}

InputMouse::~InputMouse()
{
}

void InputMouse::buttonClicked()
{
    if (mouseClick[1] == true)
        Application::getWindow()->getScene()->getCamera()->cursorCallback(mouseCursor.x, mouseCursor.y);
    if (mouseClick[0] == true)
        Application::getWindow()->getScene()->addObj(mouseCursor.x, mouseCursor.y);
}