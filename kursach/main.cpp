#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>


class hero
{
public:
    hero(){
        set_level(readFilePlayerLevel());
    }
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
        savePlayerLevelInFile(level);

    }
    void set_level(int level){
        this->level=level;
    }
    int get_level()
    {
        return level;
    }
private:
    int ten_degree(int degree){
        int value = 1;
        for(int i = 0;i<degree;i++){
            value*=10;
        }
        return value;
    }

    int string_to_int(std::string level_string){
        int level_int = 0;
        int length = level_string.length();
        for (int i=length, degree=0;i>0;i--,degree++){
            level_int+=(level_string[i-1]-48)*ten_degree(degree);
        }
        return level_int;
    }
    int readFilePlayerLevel() {
        std::string level;
        const std::string file_name = "player_level.txt";
        std::ifstream  fs;
        fs.open(file_name);
        fs >> level;
        fs.close();

        return string_to_int(level);
    }

    void savePlayerLevelInFile(int level) {
        const std::string file_name = "player_level.txt";
        std::ofstream fs;
        fs.open(file_name);
        fs << level;
        fs.close();
    }
    int good = 0;
    int bad = 0;
    int level = 0;
};

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
hero Katya;
Katya.plusLevel();
std::cout<<Katya.get_level();
    return 0;

}
