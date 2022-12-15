#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list> 

//Part 1
int main(){
  std::ifstream aocInputTxt("./input.txt");
  if(aocInputTxt.is_open()){
    std::string lnText;
    int currElfIdx = 0;
    int maxAmountOfCalories;
    std::vector<int> caloriesPerElf(1, 0);
    while(std::getline(aocInputTxt, lnText)){
      if(!lnText.empty()){
        caloriesPerElf[currElfIdx] += std::stoi(lnText);
      } else {
        caloriesPerElf.push_back(0);
        currElfIdx++;
      }
    }
    std::cout << *std::max_element(caloriesPerElf.begin(), caloriesPerElf.end()) << std::endl;
  }
  return 0;
}
// Part 2
int main(){
  std::ifstream aocInputTxt("./input.txt");
  if(aocInputTxt.is_open()){
    std::string lnText;
    int currElfIdx = 0;
    int elvesCarryingTheMostCaloriesAmount = 3;
    int maxAmountOfCalories;
    std::vector<int> caloriesPerElf(1, 0);
    while(std::getline(aocInputTxt, lnText)){
      if(!lnText.empty()){
        caloriesPerElf[currElfIdx] += std::stoi(lnText);
      } else {
        caloriesPerElf.push_back(0);
        currElfIdx++;
      }
    }
    int totalTopElvesCalories = 0;
    for(int i = 0; i < elvesCarryingTheMostCaloriesAmount; i++) {
      int indexOfMaxElement = std::distance(caloriesPerElf.begin(), std::max_element(caloriesPerElf.begin(), caloriesPerElf.end()));
      totalTopElvesCalories += caloriesPerElf[indexOfMaxElement];
      caloriesPerElf.erase(caloriesPerElf.begin() + indexOfMaxElement);
    }
    std::cout << totalTopElvesCalories << std::endl;
  }
  return 0;
}
