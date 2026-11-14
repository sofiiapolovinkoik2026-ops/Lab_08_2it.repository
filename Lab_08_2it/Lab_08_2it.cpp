// Програма ітераційним способом вилучає всі пробіли, які розташовані
// між словом та наступним за ним знаком пунктуації.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Перевірка, чи є символ знаком пунктуації
bool IsPunct(char c)
{
    const char punct[] = ".,!?;:-()\"'";
    for (int i = 0; punct[i] != '\0'; i++)
        if (c == punct[i])
            return true;
    return false;
}

// Вилучення пробілів між словом і знаком пунктуації
char* RemoveSpaces(char* dest, const char* str)
{
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            int k = i;
            while (str[k] == ' ')
                k++;

            bool afterWord = (j > 0 && dest[j - 1] != ' ' && !IsPunct(dest[j - 1]));
            bool beforePunct = (str[k] != '\0' && IsPunct(str[k]));

            if (afterWord && beforePunct)
                i = k; // Пропускаємо пробіли
            else
                while (i < k)
                    dest[j++] = str[i++]; // Залишаємо пробіли
        }
        else
        {
            dest[j++] = str[i++];
        }
    }
    dest[j] = '\0';
    return dest;
}

int main()
{
    char str[151];
    cout << "Enter string:" << endl;
    cin.getline(str, 150);

    char dest[151];
    RemoveSpaces(dest, str);
    cout << "Modified string: " << dest << endl;

    return 0;
}