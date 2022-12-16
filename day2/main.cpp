#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

// enum PLAYER_MOVES_TUPLE {
//   MOVE_SCORE = 0,
//   MOVE_NAME = 1,
//   MOVE_LOSES_AGAINST = 2,
//   MOVE_TIES_WITH = 3
// };

// enum POINTS {
//   WIN = 6,
//   LOSE = 0,
//   DRAW = 3,
// };

// void addWordsToVec(std::string *lineToParse, const char separator, std::vector<std::string> *wordsInLine){
//   std::stringstream lineStream(*lineToParse);
//   std::string word;
//   while(std::getline(lineStream, word, separator)){
//     wordsInLine->push_back(word);
//   }
// };

// void outcomeOfPlay (std::string opponentPlay, std::string playerPlay, int *totalPlayerScore) {
//   bool hasPlayerWon = false;
//   bool isDraw = false;
//   std::vector<std::tuple<int, std::string, std::string, std::string>> rockPaperScissorsPlays;
//   rockPaperScissorsPlays.push_back(std::make_tuple(1, "X", "B", "A")); // Rock
//   rockPaperScissorsPlays.push_back(std::make_tuple(2, "Y", "C", "B")); // Paper
//   rockPaperScissorsPlays.push_back(std::make_tuple(3, "Z", "A", "C")); // Scissors
//   for(auto play : rockPaperScissorsPlays) {
//     if(std::get<PLAYER_MOVES_TUPLE::MOVE_NAME>(play) == playerPlay){
//       *totalPlayerScore += std::get<PLAYER_MOVES_TUPLE::MOVE_SCORE>(play);
//       if(std::get<PLAYER_MOVES_TUPLE::MOVE_LOSES_AGAINST>(play) != opponentPlay &&
//        std::get<PLAYER_MOVES_TUPLE::MOVE_TIES_WITH>(play) != opponentPlay) {
//         hasPlayerWon = true;
//       }
//       if(std::get<PLAYER_MOVES_TUPLE::MOVE_TIES_WITH>(play) == opponentPlay){
//         isDraw = true;
//       }
//     }
//   }
//   if(hasPlayerWon){
//     *totalPlayerScore += POINTS::WIN;
//   }
//   if(isDraw) {
//     *totalPlayerScore += POINTS::DRAW;
//   }
// };

// int main(){
//   std::ifstream aocInputTxt("./input.txt");
//   int totalPlayerScore = 0;
//   if(aocInputTxt.is_open()){
//     std::string lnText;
//     const char *separator = " ";
//     std::vector<std::string> wordsInLine;
//     while(std::getline(aocInputTxt, lnText)){
//       if(!lnText.empty()){
//         wordsInLine.clear();
//         addWordsToVec(&lnText, *separator, &wordsInLine);
//         outcomeOfPlay(wordsInLine[0], wordsInLine[1], &totalPlayerScore);
//       }
//     }
//     std::cout << "TOTAL SCORE IS " << totalPlayerScore << std::endl;
//   }
//   return 0;
// }


//Part 2

// X means I need to lose
// Y means I have to draw
// Z means I have to win

enum POINTS {
  WIN = 6,
  LOSE = 0,
  DRAW = 3,
};

enum SCORE_BASED_ON_OPPONENT_MOVE{
  OPPONENT_MOVE = 0,
  WIN_MOVE_SCORE = 1,
  LOSE_MOVE_SCORE = 2,
  DRAW_MOVE_SCORE = 3,
};

void addWordsToVec(std::string *lineToParse, const char separator, std::vector<std::string> *wordsInLine){
  std::stringstream lineStream(*lineToParse);
  std::string word;
  while(std::getline(lineStream, word, separator)){
    wordsInLine->push_back(word);
  }
};

void outcomeOfPlay (std::string opponentPlay, std::string endResultOfPlay, int *totalPlayerScore) {
  int hasToWin = endResultOfPlay == "Z";
  int hasToDraw = endResultOfPlay == "Y";
  std::vector<std::tuple<std::string, int, int, int>> moveScoreBasedOnOpponentsMove;
  // A is ROCK, B is PAPER, C is SCISSORS 
  moveScoreBasedOnOpponentsMove.push_back(std::make_tuple("A", 2, 3, 1));
  moveScoreBasedOnOpponentsMove.push_back(std::make_tuple("B", 3, 1, 2));
  moveScoreBasedOnOpponentsMove.push_back(std::make_tuple("C", 1, 2, 3));
  for(auto play : moveScoreBasedOnOpponentsMove) {
    if(opponentPlay == std::get<SCORE_BASED_ON_OPPONENT_MOVE::OPPONENT_MOVE>(play)){
      if(hasToWin) {
        *totalPlayerScore += std::get<SCORE_BASED_ON_OPPONENT_MOVE::WIN_MOVE_SCORE>(play) + POINTS::WIN;
        break;
      }
      if(hasToDraw){
        *totalPlayerScore += std::get<SCORE_BASED_ON_OPPONENT_MOVE::DRAW_MOVE_SCORE>(play) + POINTS::DRAW;
        break;
      }
      *totalPlayerScore += std::get<SCORE_BASED_ON_OPPONENT_MOVE::LOSE_MOVE_SCORE>(play) + POINTS::LOSE;   
    }
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