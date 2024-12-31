#ifndef CTEXTINPUTBOX_HXX
#define CTEXTINPUTBOX_HXX

#include <vector>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>


class CTextInputBox : public sf::Drawable{
public:
  CTextInputBox(const sf::Font& font, const sf::Vector2f size, const sf::Vector2f position);
  void addCharacter(const sf::String inputText);
  void renderText();

  //This doesn't belong here
  std::vector<std::string> split(const std::string in) const;


  
private:
  sf::RectangleShape bgRect;

  std::string rawString;
  sf::Text renderedText;

  //std::vector<sf::Text> textLines;
  
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
    target.draw(bgRect, states);
    target.draw(renderedText);
    //for(auto & line : textLines){
    //  target.draw(line, states);
    //}
  }
};


#endif
