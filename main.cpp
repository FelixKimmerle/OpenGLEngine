#include <iostream>
#include "Shaders/StaticShader.hpp"
#include "DisplayManager.hpp"
#include "Loader.hpp"
#include "Renderer.hpp"
#include "TexturedModel.hpp"

int main(int argc, char **argv)
{
    DisplayManager dpm;
    dpm.create();
    Loader loader;
    StaticShader shader;
    Renderer renderer(&dpm, &shader);

    ModelTexture texture(loader.loadTexture("stallTexture"));
    RawModel model = loader.LoadOBJ("stall2");
    TexturedModel tmodel(model, texture);
    Camera camera;
    Entity e(tmodel, glm::vec3(0, 0, -1), glm::vec3(0, 0, 0), 1);

    while (dpm.isOpen())
    {
        //e.Rotate(glm::vec3(1, 1, 0));
        //e.Move(glm::vec3(0, 0, -0.1f));
        camera.Update();
        renderer.prepare();
        shader.Use();
        shader.LoadViewMatrix(camera);
        renderer.render(e, shader);
        shader.UnUse();
        dpm.update();
        GLenum err;
        while ((err = glGetError()) != GL_NO_ERROR)
        {
            std::cerr << "OpenGL error: " << err << std::endl;
        }
    }
    return 0;
}