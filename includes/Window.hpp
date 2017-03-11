#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define WIN_WIDTH 200
#define WIN_HEIGHT 100
#define WIN_TITLE "Ray Tracer"

class Window {
public:
  Window(void);
  ~Window(void);

  void putPixel(int x, int y, sf::Color color);
  void display(void);

private:
  sf::RenderWindow _window;
  sf::Image _image;
  sf::Texture _texture;
  sf::Sprite _sprite;
};