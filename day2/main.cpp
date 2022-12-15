#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

struct ROCK_PAPER_SCISSORS{
  std::tuple<int, std::string, std::string> ROCK = {1, "X", "B"};
  std::tuple<int, std::string, std::string> PAPER = {2, "Y", "C"};
  std::tuple<int, std::string, std::string> SCISSORS = {3, "Z", "A"};
};

enum PLAYER_MOVES_TUPLE {
  MOVE_SCORE = 0,
  MOVE_NAME = 1,
  MOVE_LOSES_AGAINST = 2,
  MOVE_TIES_WITH = 3
};

enum POINTS {
  WIN = 6,
  LOSE = 0,
  DRAW = 3,
};

void addWordsToVec(std::string *lineToParse, const char separator, std::vector<std::string> *wordsInLine){
  std::stringstream lineStream(*lineToParse);
  std::string word;
  while(std::getline(lineStream, word, separator)){
    wordsInLine->push_back(word);
  }
};

void outcomeOfPlay (std::string opponentPlay, std::string playerPlay, int *totalPlayerScore) {
  bool hasPlayerWon = false;
  bool isDraw = false;
  std::vector<std::tuple<int, std::string, std::string, std::string>> rockPaperScissorsPlays;
  rockPaperScissorsPlays.push_back(std::make_tuple(1, "X", "B", "A")); // Rock
  rockPaperScissorsPlays.push_back(std::make_tuple(2, "Y", "C", "B")); // Paper
  rockPaperScissorsPlays.push_back(std::make_tuple(3, "Z", "A", "C")); // Scissors
  for(auto play : rockPaperScissorsPlays) {
    if(std::get<PLAYER_MOVES_TUPLE::MOVE_NAME>(play) == playerPlay){
      *totalPlayerScore += std::get<PLAYER_MOVES_TUPLE::MOVE_SCORE>(play);
      if(std::get<PLAYER_MOVES_TUPLE::MOVE_LOSES_AGAINST>(play) != opponentPlay &&
       std::get<PLAYER_MOVES_TUPLE::MOVE_TIES_WITH>(play) != opponentPlay) {
        hasPlayerWon = true;
      }
      if(std::get<PLAYER_MOVES_TUPLE::MOVE_TIES_WITH>(play) == opponentPlay){
        isDraw = true;
      }
    }
  }
  if(hasPlayerWon){
    *totalPlayerScore += POINTS::WIN;
  }
  if(isDraw) {
    *totalPlayerScore += POINTS::DRAW;
  }
};

int main(){
  std::ifstream aocInputTxt("./input.txt");
  int totalPlayerScore = 0;
  if(aocInputTxt.is_open()){
    std::string lnText;
    const char *separator = " ";
    std::vector<std::string> wordsInLine;
    while(std::getline(aocInputTxt, lnText)){
      if(!lnText.empty()){
        wordsInLine.clear();
        addWordsToVec(&lnText, *separator, &wordsInLine);
        outcomeOfPlay(wordsInLine[0], wordsInLine[1], &totalPlayerScore);
      }
    }
    std::cout << "TOTAL SCORE IS " << totalPlayerScore << std::endl;
  }
  return 0;
}