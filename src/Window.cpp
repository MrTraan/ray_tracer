#include <Window.hpp>

Window::Window(void) {
  _window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), WIN_TITLE);
  _image.create(WIN_WIDTH, WIN_HEIGHT, sf::Color::Black);
}

Window::~Window(void) { _window.close(); }

void Window::display(void) {
  _texture.loadFromImage(_image);
  _sprite.setTexture(_texture);

  while (_window.isOpen()) {
    // Event processing
    sf::Event event;
    while (_window.pollEvent(event)) {
      // Request for closing the _window
      if (event.type == sf::Event::Closed) _window.close();
      if ((event.type == sf::Event::KeyPressed) &&
          (event.key.code == sf::Keyboard::Escape))
        _window.close();
    }
    // Clear the whole _window before rendering a new frame
    _window.clear(sf::Color::Black);
    // Draw some graphical entities
    _window.draw(_sprite);
    // End the current frame and display its contents on screen
    _window.display();
  }
}

void Window::putPixel(int x, int y, sf::Color color) {
  _image.setPixel(x, y, color);
}