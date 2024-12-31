#include <iostream>
#include <exception>
#include <SFML/Graphics.hpp>

#include "CUI.hxx"
#include "CTextInputBox.hxx"

sf::Font loadFont(const std::string path){
  sf::Font font;
  if(!font.loadFromFile(path)){
    throw std::invalid_argument("Key not found");
  }
  return font;
}

int main(){

  // Create the main window
  const std::pair<int,int> windowSize(1920, 1080);
  sf::RenderWindow window(sf::VideoMode(windowSize.first, windowSize.second), "SFML window");
  window.setFramerateLimit(30);
 
  // Load a sprite to display
  /*sf::Texture texture;
  if(!texture.loadFromFile("resources/spriteSheet.bmp")){
    std::cout<<"load from file to texture failed"<<std::endl;
    return -1;
  }
  sf::Sprite sprite(texture);*/
 
  // Create a graphical text to display
  const std::string fontPath = "resources/Playfair_Display/PlayfairDisplay-VariableFont_wght.ttf";
  const sf::Font font = loadFont(fontPath);

  CUI ui;
  ui.initialize(font);
  //ui.print();

  CTextInputBox textBox(font, sf::Vector2f(1000,600), sf::Vector2f((1920-1000)/2, 200));
  
  // Start the loop
  while (window.isOpen())
    {
      sf::Event event;
      // Process events
      while (window.pollEvent(event))
        {
	  // Close window: exit
	  if (event.type == sf::Event::Closed)
	    window.close();

	  if(event.type == sf::Event::TextEntered){
	    textBox.addCharacter(event.text.unicode);
	  }
        }
 
      // Clear screen
      window.clear();

      textBox.renderText();

      // Draw the UI
      window.draw(ui);
      window.draw(textBox);
 
      // Update the window
      window.display();
    }


  return 0;
}
