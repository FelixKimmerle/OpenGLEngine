#include <GL/glew.h>
#include "DisplayManager.hpp"
#include <SFML/OpenGL.hpp>
#include <iostream>
#define WIDTH 1280
#define HEIGHT 720

DisplayManager::DisplayManager()
{
}

DisplayManager::~DisplayManager()
{
}

void DisplayManager::create()
{

    sf::ContextSettings settingsx(24,8);
    m_Window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "OpenGL", sf::Style::Default, settingsx);
    m_Window.setVerticalSyncEnabled(true);

    sf::ContextSettings settings = m_Window.getSettings();

    std::cout << "depth bits: " << settings.depthBits << std::endl;
    std::cout << "stencil bits: " << settings.stencilBits << std::endl;
    std::cout << "antialiasing level: " << settings.antialiasingLevel << std::endl;
    std::cout << "version: " << settings.majorVersion << "." << settings.minorVersion << std::endl;

    glewExperimental = GL_TRUE;
    glewInit();

    glViewport(0, 0, WIDTH, HEIGHT);
}
void DisplayManager::update()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_Window.close();
        }
        else if (event.type == sf::Event::Resized)
        {
            glViewport(0, 0, event.size.width, event.size.height);
        }
    }
    m_Window.display();
}
bool DisplayManager::isOpen()
{
    return m_Window.isOpen();
}

float DisplayManager::GetAspectRatio()const
{
    sf::Vector2u size = m_Window.getSize();
    return size.x / size.y;
}