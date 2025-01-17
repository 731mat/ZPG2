//
// Created by Matěj Hloušek on 10/12/2020.
//

#include "InputKeyboard.h"
#include "Controller.h"
#include "Application.h"


bool InputKeyboard::keys[1024] = {};


InputKeyboard::InputKeyboard()
{
}

InputKeyboard::~InputKeyboard()
{
}

void InputKeyboard::keysClicked() {
    if (keys[87] == true)
    {
        Application::getWindow()->getScene()->getCamera()->moveForward();
    }
    if (keys[83] == true)
    {
        Application::getWindow()->getScene()->getCamera()->moveBack();
    }
    if (keys[65] == true)
    {
        Application::getWindow()->getScene()->getCamera()->moveRight();
    }
    if (keys[68] == true)
        Application::getWindow()->getScene()->getCamera()->moveLeft();

    if (keys[81] == true)
        Application::getWindow()->getScene()->getCamera()->moveUp();
    if (keys[69] == true)
        Application::getWindow()->getScene()->getCamera()->moveDown();

    if (keys[264] == true)
    {
        Application::getWindow()->getScene()->getLight(1)->move(glm::vec3(0.0f, -0.5f, 0.0f));
    }
    if (keys[265] == true)
    {
        Application::getWindow()->getScene()->getLight(1)->move(glm::vec3(0.0f, 0.5f, 0.0f));
    }
    if (keys[263] == true)
    {
        Application::getWindow()->getScene()->getLight(1)->move(glm::vec3(-0.5f, 0.0f, 0.0f));
    }
    if (keys[262] == true)
    {
        Application::getWindow()->getScene()->getLight(1)->move(glm::vec3(0.5f, 0.0f, 0.0f));
    }
    if (keys[77] == true)
    {
        Application::getWindow()->getScene()->getLight(1)->move(glm::vec3(0.0f, 0.0f, 0.5f));
    }
    if (keys[78] == true)
    {
        Application::getWindow()->getScene()->getLight(1)->move(glm::vec3(0.0f, 0.0f, -0.5f));
    }
    if (keys[80] == true)
    {
        Application::getWindow()->getScene()->addObj(true);
    }
    if (keys[79] == true)
    {
        Application::getWindow()->getScene()->delObj();
    }
    /*if (keys[73] == true)
    {
        Application::getWindow()->getScene()->moveObj();
    }*/


    // pohyb svetla U
    if (keys[85] == true)
    {
        if(Application::getWindow()->getScene()->getLight(2)->isOn())
            Application::getWindow()->getScene()->getLight(2)->disable();
        else
            Application::getWindow()->getScene()->getLight(2)->enable();

    }


    if (keys[71] == true)
    {
        Application::getWindow()->getScene()->moveObj(glm::vec3(0.0f, -0.5f, 0.0f));
    }
    if (keys[84] == true)
    {
        Application::getWindow()->getScene()->moveObj(glm::vec3(0.0f, 0.5f, 0.0f));
    }
    if (keys[70] == true)
    {
        Application::getWindow()->getScene()->moveObj(glm::vec3(-0.5f, 0.0f, 0.0f));
    }
    if (keys[72] == true)
    {
        Application::getWindow()->getScene()->moveObj(glm::vec3(0.5f, 0.0f, 0.0f));
    }
    if (keys[82] == true)
    {
        Application::getWindow()->getScene()->moveObj(glm::vec3(0.0f, 0.0f, -0.5f));
    }
    if (keys[89] == true)
    {
        Application::getWindow()->getScene()->moveObj(glm::vec3(0.0f, 0.0f, 0.5f));
    }

}
