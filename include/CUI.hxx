#ifndef CUI_HXX
#define CUI_HXX

#include <vector>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class CUI : public sf::Drawable{
public:
  //CUI();
  void initialize(const sf::Font& font);
  void print() const;

private:
  std::vector<sf::Text> m_drawables;
 
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
    for(auto & text : m_drawables){
      target.draw(text, states);
    }
  }
};


#endif
