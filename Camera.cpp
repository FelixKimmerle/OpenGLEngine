#include "Camera.hpp"
#include <SFML/Window.hpp>

Camera::Camera(/* args */) : position(0), rotation(0)
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        position.z -= 0.02f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        position.z += 0.02f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        position.x -= 0.02f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        position.x += 0.02f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        position.y += 0.02f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        position.y -= 0.02f;
    }
}
