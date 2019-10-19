#pragma once
#include <SFML/Window.hpp>

class DisplayManager
{
private:
  sf::Window m_Window;

public:
  DisplayManager();
  ~DisplayManager();
  void create();
  void update();
  bool isOpen();
  float GetAspectRatio()const;
};
