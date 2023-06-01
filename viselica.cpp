#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>

using namespace std;

class Game
{
private:
    string arr[10] = { "kitten", "garbage", "spider", "calculus", "probability", "mimic", "rusnya", "gorilla", "commie", "avantgarde"};
    string arr2[7] =
    {
        {
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      /   \\           $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\           $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\           $\n"
        "        |             $\n"
        "       / \\            $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    }
    };
    string word, word2, letters;
    int pop; 
    int i; 
public:
    Game()
    {
        word = arr[rand() % 10];
        word2 = NewWord(word);
        pop = 7;
        i = 0;
    }
    string NewWord(string wword)
    {
        // функция замены символов в исходной строке
        string word2 = wword;
        for (int i = 0; i < wword.size(); i++)
        {
            replace(word2.begin(), word2.end(), wword[i], '_');
        }
        return word2;
    }
    bool Inclusion(string wword, char symbol)
    {
        // функция проверки символа на вхождения
        bool ident = true;
        for (int i = 0; i < wword.size(); i++)
        {
            if (symbol == wword[i])
            {
                ident = true;
                break;
            }
            else ident = false;
        }
        return ident;
    }
    string Replacement(string wword, char symbol, string wword2)
    {
        // замена символов в слове
        for (int i = 0; i < wword.size(); i++)
        {
            if (wword[i] == symbol) wword2[i] = symbol;
        }
        word2 = wword2;
        return word2;
    }
    void NewGame()
    {
        // игровой процесс
        auto start = chrono::high_resolution_clock::now();
        do
        {
            cout << "Введите символ (на английском): ";
            char c;
            cin >> c;
            letters += c;
            if (Inclusion(word2, c)) cout << "Введите другой символ!\n"; // проверка, был ли ли символ введён до этого
            else if (!Inclusion(word2, c))
            {
                // проверка на вхождение символа в слово
                if (Inclusion(word, c))
                {
                    word2 = Replacement(word, c, word2);
                    cout << "Вы угадали! Слово: " << word2 << endl;
                }
                if (!Inclusion(word, c))
                {
                    pop--;
                    cout << arr2[i] << endl;
                    cout << "Вы не угадали! У вас осталось " << pop << " попыток" << endl;
                    i++;
                }
            }
        } while ((pop > 0) ^ !Inclusion(word2, '_'));
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float> time = end - start;
        if (pop == 0)
        {
            cout << "Вы проиграли!" << endl;
            cout << "Статистика: кол-во попыток - " << letters.size() << ", время игры - " << time.count() << " секунд, искомое слово - " << word << ", буквы - " << letters << endl;
        }
        if (!Inclusion(word2, '_'))
        {
            cout << "Вы победили!" << endl;
            cout << "Статистика: кол-во попыток - " << letters.size() << ", время игры - " << time.count() << " секунд, искомое слово - " << word << ", буквы - " << letters << endl;
        }
    }
    ~Game()
    {
        word = "";
        word2 = "";
        pop = 0;
        i = 0;
        letters = "";
    }
};

int main()
{
    srand(time(NULL));C:\Users\Mcint
    setlocale(LC_ALL, "ru");
    bool gameoff = true;
    do
    {
        Game game;
        game.NewGame();
        cout << "Хотите сыграть ещё раз (1, 0)?: ";
        cin >> gameoff;
    } while (gameoff);
    return 0;
}