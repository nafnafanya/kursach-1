#include <iostream>
#include <fstream>
#include <string>


void savePlayerLevelInFile( int level){
    const std::string file_name = "player_level.txt";
    std::ofstream fs;
    fs.open(file_name);
    fs << level;
    fs.close();
}


std::string readFilePlayerLevel(){
    std::string level;
    const std::string file_name = "player_level.txt";
    std::ifstream  fs;
    fs.open(file_name);
    fs >> level;
    fs.close();
    return level;
}


int main() {
    savePlayerLevelInFile(345345);
    std::cout<<readFilePlayerLevel();
    return 0;
}
