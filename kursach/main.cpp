
#include <iostream>
#include <fstream>
#include <string>
  
  
class hero 
{
public:
    void plusGood()
    {
        good += 1;
    }
    int get_good()
    {
        return good;
    }
    void plusBad()
    {
        bad += 1;
    }
    int get_bad()
    {
        return bad;
    }
    void plusLevel()
    {
        level += 1;
    }
    int get_level()
    {
        return level;
    }
private: 
    int good = 0;
    int bad = 0;
    int level =0;
    
};

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
    return 0;
}
