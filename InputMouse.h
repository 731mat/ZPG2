//
// Created by Matěj Hloušek on 10/12/2020.
//

#ifndef PROJEKT_FINAL_INPUTMOUSE_H
#define PROJEKT_FINAL_INPUTMOUSE_H

//Include GLM
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr


class InputMouse
{
private:
public:
    InputMouse();
    ~InputMouse();
    static bool mouseClick[];
    static glm::vec2 mouseCursor;
    static void buttonClicked();
};



#endif //PROJEKT_FINAL_INPUTMOUSE_H
