#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>

void print(char* str);
void print(std::string str);
int input();

class hero
{
public:
    hero() {
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
    void set_level(int level) {
        this->level = level;
    }
    int get_level()
    {
        return level;
    }
private:
    int ten_degree(int degree) {
        int value = 1;
        for (int i = 0; i < degree; i++) {
            value *= 10;
        }
        return value;
    }

    int string_to_int(std::string level_string) {
        int level_int = 0;
        int length = level_string.length();
        for (int i = length, degree = 0; i > 0; i--, degree++) {
            level_int += (level_string[i - 1] - 48) * ten_degree(degree);
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



class story_point {
public:
    int number = 1;
    char text[5000] = {};
     void set_story_from_file(int number) {

        char ch_number1 = (48 + number);
        std::stringstream compare1;
        compare1 << "<" << ch_number1 << ">";
        char info1[10] = {};
        compare1 >> info1;


        char ch_number2 = (48 + number + 1);
        std::stringstream compare2;
        compare2 << "<" << ch_number2 << ">";
        char info2[10] = {};
        compare2 >> info2;




        std::ifstream in;
        in.open("story_points.txt");
        if (in) {
            memset(&text, 0, 5000);
            bool in_story = false;
            while (!in.eof()) {
                char buffer[100] = {};
                in.getline(buffer, 1000);
                if (in_story && strcmp(buffer, info2)) {
                    strcat_s(text, buffer);
                    strcat_s(text, "\n");
                }
                if (in_story && !strcmp(buffer, info2)) {
                    break;
                }
                if (!strcmp(buffer, info1)) {
                    in_story = true;
                }


            }
        }
        in.close();
    }
     void set_story(int input_number) {
         number = input_number;
         set_story_from_file(input_number);
     }
     void next_point() {
         number+= 1;
         set_story(number);
     }
};

int main() {
    story_point point;
    point.set_story(2);
    print (point.text);
    point.next_point();
    print(point.text);
    system("pause");
    return 0;
}


int input()
{
    setlocale(LC_ALL, "Russian");
    int a;

    do
    {
        while (!(std::cin >> a))
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            print("Вы должны ввести число 1 или 2.");
        }
        if (a != 1 && a != 2)
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            print("Вы должны ввести число 1 или 2.");
        }

    } while (a != 1 && a != 2);
    return a;
}

void print(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        std::cout << str[i];
        Sleep(80);
    }
}
void print(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        std::cout << str[i];
        Sleep(80);
    }
}
