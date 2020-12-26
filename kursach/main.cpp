#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>
int story_amount=9;
void print(char* str);
void print(std::string str);
int input();
void hello();

class hero
{
public:
    hero() {
        set_level(readLevel());
    }
    void answerProcessing(int answer){
        if(answer==1){
            plusKarma();
        }
    }
    void plusKarma()
    {
        set_karma(karma+1);
    }
    void set_karma(int inp_karma){
        karma=inp_karma;
        saveKarma();
    }
    int get_karma()
    {
        return karma;
    }
    void plusLevel()
    {
        level += 1;
        saveLevel();

    }
    void set_level(int level) {
        this->level = level;
        saveLevel();
    }
    int get_level()
    {
        return level;
    }
private:
    int karma = 0;

    int level = 0;

    int readLevel() {
        const std::string file_name = "player_level.txt";
        std::ifstream  fs;
        fs.open(file_name);
        fs >> level;
        fs.close();

        return level;
    }

    void saveLevel() {
        const std::string file_name = "player_level.txt";
        std::ofstream fs;
        fs.open(file_name);
        fs << level;
        fs.close();
    }
    int readKarma() {
        const std::string file_name = "player_karma.txt";
        std::ifstream  fs;
        fs.open(file_name);
        fs >> karma;
        fs.close();
        return karma;
    }

    void saveKarma() {
        const std::string file_name = "player_karma.txt";
        std::ofstream fs;
        fs.open(file_name);
        fs << karma;
        fs.close();
    }
};



class story_point {
    int number = 1;
    char text[5000] = {};
    void set_story_from_file(int number) { //"<52>"
        char ch_number1 = (48 + number);
        std::stringstream compare1;
        compare1 << "<" << ch_number1 << ">";
        char info1[10] = {};
        compare1 >> info1; //<number>


        char ch_number2 = (48 + number + 1);
        std::stringstream compare2;
        compare2 << "<" << ch_number2 << ">";
        char info2[10] = {};
        compare2 >> info2;//<number+1> <10>

        std::ifstream in;
        in.open("story_points.txt");
        if (in) {
            memset(&text, 0, 5000);
            bool in_story = false;
            while (!in.eof()) {

                char buffer[1000] = {};
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
public:
    int get_number(){
        return number;
    }
    void set_story(int input_number) {
        number = input_number;
        set_story_from_file(input_number);
    }

    void set_ending(int ending_number){


        char ch_ending_number = (48 + ending_number);
        std::stringstream compare;
        compare << "ending" << ch_ending_number<<".txt";
        char file_name[20] = {};
        compare >> file_name;
        std::ifstream in;
        in.open(file_name);
        while (!in.eof()) {
            char buffer[1000] = {};
            in.getline(buffer, 500);
            strcat_s(text, buffer);
            strcat_s(text, "\n");
        }

        in.close();
        number=1;
    }

    void next_point() {
        number+= 1;
        set_story(number);
    }
    void print(){
        ::print((const char *)text);

    }
private:



};
void dialog(){

    hero hero{};
    story_point storyPoint{};

    while(1) {

        while (storyPoint.get_number() <= story_amount) {
            storyPoint.set_story(hero.get_level());
            storyPoint.print();
            int answer = input();
            if (answer==0){
                return;
            }
            hero.answerProcessing(answer);
            hero.plusLevel();
            storyPoint.next_point();
        }
        if (2 * hero.get_karma() > story_amount) {
            hero.set_level(1);
            hero.set_karma(0);
            storyPoint.set_ending(1);
            storyPoint.print();
            return;
        } else {
            hero.set_karma(0);//because story says that
            hero.set_level(1);//because story says that
            storyPoint.set_ending(2);//because story says that
            storyPoint.print();
        }
    }
}
int main() {
    hello();
    dialog();
    return 1;
}

void print(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        std::cout << str[i];
        Sleep(80);
    }
    std::cout<<std::endl;
}
void print(const std::string str) {
    for (int i = 0; i < str.length(); i++) {
        std::cout << str[i];
        Sleep(80);
    }
    std::cout<<std::endl;

}

int input()
{
    char answer[10];
    while(!(std::cin >> answer)){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        print((const char *)"You should type 1 or 2.\n");


    }
    if(strcmp(answer, "1") && strcmp(answer, "0") && strcmp(answer, "exit") ){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        print((const char *)"You should type 1 or 2.\n");
        input();
    }
    if(!strcmp(answer, "exit")){
        return 0;
    }
    if(answer[0]='1') {
        return 1;
    }
    if(answer[0]='2') {
        return 2;
    }

}
void hello(){
    print((const char *)"Hi! Welcome to this game! =)");
    print((const char *)"Get ready to feel all that feels hero of this story.");
    print((const char *)"\n");
    Sleep(1000);
}
