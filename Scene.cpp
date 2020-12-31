//
// Created by Matěj Hloušek on 09/12/2020.
//
#include "Scene.h"
#include "Application.h"


Scene::Scene() {
    compileShaders();
    mshManager = new MeshManager;


    texture = new Texture("test.png");
    texture2 = new Texture("wall.png");


    skybox = new SkyBox(skybox_shader);

    terrain = new Terrain(terrain_shader,100,100,glm::vec3(0, 0, 0));


    camera = new Camera;
    light = new Light(lambert, mshManager, LightType::Point);
    light2 = new Light(20, 0, -50, LightType::Spotlight);
    light2->disable();

    light3 = new Light(20, 0, -50, LightType::Directional);
    light3->setPositionDirection(glm::vec3( 2, 2, 2));

    lights.push_back(light);
    lights.push_back(light2);
    lights.push_back(light3);

    phong->updateLights(lights);

    light->registerObserver((OnChangeLightObserver*)phong);
    light2->registerObserver((OnChangeLightObserver*)phong);
    light3->registerObserver((OnChangeLightObserver*)phong);


    camera->registerObserver((OnChangeCameraObserver*)lambert);
    camera->registerObserver((OnChangeCameraObserver*)phong);
    camera->registerObserver((OnChangeCameraObserver*)skybox_shader);
    camera->registerObserver((OnChangeCameraObserver*)terrain_shader);

    camera->registerObserver(skybox);

    //mshManager->setObj("tree", new Model("models/pine.lwo"));



    mshManager->setMesh("sphere", new Mesh(GL_TRIANGLES, sphereVertices, sphereCount,"sphere"));
    mshManager->setMesh("worker", new Mesh(GL_TRIANGLES, workerVertices, workerCount,"worker"));
    mshManager->setMesh("box", new Mesh(GL_TRIANGLES, boxVertices, boxCount,"box"));
    mshManager->setMesh("suzi", new Mesh(GL_TRIANGLES, suziVertices, suziCount,"suzi"));
    //mshManager->setMesh("jumper", new Mesh(GL_TRIANGLES, jumpVertices, jumpCount,"jumper"));
    //mshManager->setMesh("plane", new Mesh(GL_TRIANGLES, plane , 10));

    //objects.push_back(new Object(new Model("../models/fels.3ds"), phong, glm::vec3(0, 2, 0), glm::vec3(1, 1, 1)));
    //objects.push_back(new Object(new Model("../models/pine.lwo"), phong, glm::vec3(0, 2, 0), glm::vec3(1, 1, 1)));
    //objects.push_back(new Object(new Model("../models/blender/cube.obj"), phong, texture, glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
    Object* boxik = new Object(new Model("../models/obj/cube.obj"), phong, texture2, glm::vec3(0, 1, 0), glm::vec3(5, 5, 1));

    vector<glm::vec2> points = { glm::vec2(0,1), glm::vec2(5, 1),  glm::vec2(1,5),  glm::vec2(1,0)};



    //boxik->setCurve(new BezierCurve(glm::vec3(8.f, 2.f, 5.f), glm::vec3( 2.f, 2.f, -5.f), glm::vec3(-3.f, 2.f, 2.f), glm::vec3(-8.f, 2.f, 1.f)));
    objects.push_back(boxik);
   // objects.push_back(new Object(new Model("../models/blender/test.obj"), phong, texture, glm::vec3(0, 0, 0), glm::vec3(0.4, 0.4, 0.4)));


    //objects.push_back(new Object(mshManager->getMesh("sphere"), phong,texture, glm::vec3(0, 2, 0), glm::vec3(1, 1, 1)));
    //objects.push_back(new Object(mshManager->getMesh("worker"), phong_bez_txt, glm::vec3(0, -2, 0), glm::vec3(1, 1, 1)));
    //objects.push_back(new Object(mshManager->getMesh("box"), phong,texture, glm::vec3(-3, 0, 2), glm::vec3(1, 1, 1)));
    //objects.push_back(new Object(mshManager->getMesh("jumper"), phong, glm::vec3(-2, 0, 0), glm::vec3(1, 1, 1)));
    //objects.push_back(new Object(mshManager->getMesh("suzi"), phong, glm::vec3(2, 0, 0), glm::vec3(1, 1, 1)));
    //objects.push_back(new Object(mshManager->getMesh("plane"), phong, glm::vec3(0, -3, 0), glm::vec3(100, 1, 1)));



    camera->notifyObserver();
    light->notifyObserver();

}

Scene::~Scene() {

    delete light;
    delete light2;
    delete camera;

    delete mshManager;
    delete texture;

    for (unsigned int i = 0; i < objects.size(); i++)
        delete objects[i];

    delete this;
}


void Scene::compileShaders() {

    skybox_shader = new Shader("../shaders/Skybox-VS.glsl", "../shaders/Skybox-FS.glsl");
    lambert = new Shader("../shaders/Lambert-VS.glsl", "../shaders/Lambert-FS.glsl");
    phong = new Shader("../shaders/Phong-VS.glsl", "../shaders/Phong-FS.glsl");
    phong_bez_txt = new Shader("../shaders/Phong-VS-function.glsl", "../shaders/Phong-FS-function.glsl");
    terrain_shader = new Shader("../shaders/Terrain-VS.glsl", "../shaders/Terrain-FS.glsl");

}

void Scene::drawObj() {
    glClearStencil(0x00);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glStencilFunc(GL_ALWAYS, 0, 0xFF);
    glClearColor(0, 0, 0, 1);


    //glStencilFunc(GL_ALWAYS, 2, 0xFF);
    //glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

   // Allow data to be written to the stencil buffer.
   //glStencilMask(0xFF);
    updateLight(light);

    skybox->drawSkybox();
    light->draw();
    //terrain->draw();

    for (unsigned int i = 0; i < objects.size(); i++){
        glStencilFunc(GL_ALWAYS, i+1, 0xFF);
        objects[i]->draw();
    }
    glStencilFunc(GL_ALWAYS, 0, 0xFF);

}

void Scene::updatePositionObj() {
    for (unsigned int i = 0; i < objects.size(); i++){
        objects[i]->move();
    }

    if(light2->isOn()){
        glm::vec3 cam_direction = getCamera()->getCenter();
        glm::vec3 cam_position = getCamera()->getEye();
        getLight(2)->setPositionDirection(cam_direction);
        getLight(2)->setPositionSource(cam_position);
    }
}


void Scene::addObj(bool plant)
{
    int width = 800, height = 600;
    GLint x = (GLint)InputMouse::getInputMouse()->mouseCursor.x;
    GLint y = (GLint)InputMouse::getInputMouse()->mouseCursor.y;


    GLbyte color[4];
    GLfloat depth;
    GLint newy = height - y;

    GLint index = 0;

    glReadPixels(x, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
    glReadPixels(x, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
    glReadPixels(x, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);
    printf("Clicked on pixel %d, %d, color % 02hhx % 02hhx % 02hhx % 02hhx, depth %f, stencil index %u\n", x, newy, color[0], color[1], color[2], color[3], depth, index);


    if (plant == true)
    {
        glm::vec3 screenX = glm::vec3(x, newy, depth);
        glm::mat4 view = getCamera()->getView();
        glm::mat4 projection = getCamera()->getProjection();
        glm::vec4 viewPort = glm::vec4(0, 0, width, height);
        glm::vec3 pos = glm::unProject(screenX, view, projection, viewPort);
        objects.push_back(new Object(mshManager->getMesh("box"), phong, glm::vec3(pos.x, pos.y, pos.z), glm::vec3(1, 1, 1)));
        printf("unProject[%f, %f, %f]\n", pos.x, pos.y, pos.z);
    }
}

void Scene::delObj()
{
    int x = InputMouse::getInputMouse()->mouseCursor.x;
    int y = InputMouse::getInputMouse()->mouseCursor.y;
    int newy = (int)Application::height - InputMouse::getInputMouse()->mouseCursor.y;
    glReadPixels(x, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

    printf("delete object - [%d, %d, %d, obj %d]\n", x, y, newy, index);

    if (index != 0 && objects.size() != 0)
    {
        //objects.erase(objects.begin() + index - 1);
    }
}

void Scene::moveObj(glm::vec3 position)
{
   // if (index != 0)
     //   objects[index - 1]->setPosition(position);
}

void Scene::rotObj(float rotateX)
{
   // if (index != 0)
     //   objects[index - 1]->rotate(rotateX);
}




void Scene::updateLight(Light* light) {
    phong->updateLights(lights);
}
Camera* Scene::getCamera() {
    return camera;
}

Light* Scene::getLight(int i) {
    if(i == 1) return light;
    if(i == 2) return light2;
    if(i == 3) return light3;

    return light;
}
MeshManager* Scene::getObjMan()
{
    return mshManager;
}