#include "CUI.hxx"

void CUI::initialize(const sf::Font& font){
  sf::Text titleText;
  titleText.setFont(font);
  titleText.setString("Noted");
  titleText.setCharacterSize(100);
  int textWidth = titleText.getLocalBounds().width;
  int textXPos = 960 - textWidth/2;
  titleText.setPosition(textXPos,0);
  //titleText.setPosition(500,500);


  m_drawables.push_back(titleText);
  return;
}

void CUI::print() const{
  for(auto & text : m_drawables){
    std::string str = text.getString();
    std::cout<<str<<std::endl;
  }
  return;
}

