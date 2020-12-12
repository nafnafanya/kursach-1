
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
private: 
    int good = 0;
    int bad = 0;
    
};

int input()
{
    setlocale(LC_ALL, "Russian");
    int a;
    std::cin.clear();
    do
    {
        while (!(std::cin >> a))
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Вы должны ввести число 1 или 2." << std::endl;
        }
        if (a != 1 && a != 2)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Вы должны ввести число 1 или 2." << std::endl;
        }

    } while (a != 1 && a != 2);
    return a;
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
