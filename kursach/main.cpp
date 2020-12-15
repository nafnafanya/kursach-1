
#include <iostream>
#include <Windows.h>
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
private: 
    int good = 0;
    int bad = 0;
    
};

void savePlayerLevelInFile(int level) {
    const std::string file_name = "player_level.txt";
    std::ofstream fs;
    fs.open(file_name);
    fs << level;
    fs.close();
}


std::string readFilePlayerLevel() {
    std::string level;
    const std::string file_name = "player_level.txt";
    std::ifstream  fs;
    fs.open(file_name);
    fs >> level;
    fs.close();
    return level;
}

void print(char *str) {
    setlocale(0, "Russian");
    for (int i = 0; i < strlen(str) ; i++) {
        std:: cout << str[i];
        Sleep(80);
    }
}

struct story_point {
    int number;
    char text [ ];
};

int main() {
    return 0;

}


