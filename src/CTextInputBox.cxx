#include "CTextInputBox.hxx"

CTextInputBox::CTextInputBox(const sf::Font& font, const sf::Vector2f size, const sf::Vector2f position){
  bgRect.setSize(size);
  bgRect.setPosition(position);

  bgRect.setOutlineColor(sf::Color::Red);
  bgRect.setOutlineThickness(5);
  bgRect.setFillColor(sf::Color::White);

  rawString = "hello";
  
  //Text has max width of 900, max depth of 500?
  sf::Vector2f textOrigin(bgRect.getPosition());
  renderedText.setFont(font);
  renderedText.setPosition(textOrigin + sf::Vector2f(50,50));
  renderedText.setCharacterSize(30);
  renderedText.setString(rawString);
  renderedText.setFillColor(sf::Color::Black);
  renderedText.setOutlineColor(sf::Color::Black);
  //textLines.push_back(text);
  
}

void CTextInputBox::addCharacter(const sf::String inputText){
  char in = inputText.toAnsiString()[0];
  // This might be better handled as a char*, weirdly
  if (in == '\b'){
    if(rawString.empty()){
      return;
    }
    rawString.erase(rawString.size()-1, 1);
    return;
  }
  rawString.push_back(in);
}

std::vector<std::string> CTextInputBox::split(const std::string in) const {
  std::vector<std::string> out;
  std::size_t startPos = 0;
  std::size_t pos = 0;
  std::string subStr;
  //std::cout<<"in = "<<in<<std::endl;
  //int i=0;
  while(pos != std::string::npos){
    std::size_t pos = in.find(' ', startPos);
    //std::cout<<"pos = "<<pos<<std::endl;
    subStr = in.substr(startPos, pos-startPos);

    //std::cout<<"substr = "<<subStr<<std::endl;

    if(!subStr.empty()) out.push_back(subStr);
    if(pos == std::string::npos){
      break;
    }
    
    startPos = pos+1;
  }
  //std::cout<<"hi3"<<std::endl;
  return out;
}

void CTextInputBox::renderText() {
  //std::size_t lastNewline = str.find_last_of('\n');
  std::vector<std::string> wordVec = split(rawString);

  //for(auto & word : wordVec){
  //  std::cout<<word<<std::endl;
  //}
  
  sf::Text candidate = renderedText;
  std::string toBeRendered = "";
  std::string nextLine = "";
  std::string tryLine;
  for(auto & word : wordVec){
    tryLine = nextLine + ' ' + word;
    candidate.setString(tryLine);
    if(candidate.getLocalBounds().width < 900){
      nextLine = tryLine;
    }
    else{
      toBeRendered += nextLine + '\n';
      nextLine = word;
    }
  }
  toBeRendered += nextLine;
  renderedText.setString(toBeRendered);
  return;
}



