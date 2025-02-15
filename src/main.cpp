#include "../lib/lib.h"

helper _helper;
secret _secret;

using namespace std;

string getCode();

int main()
{
    const char *greeting = "../assets/greeting.txt";
    const char *win = "../assets/win.txt";
    const char *cheat = "../assets/cheat.txt";

    char force_option = 'n';

    while (tolower(force_option) == 'n')
    {
        string input_code = getCode();

        bool attempt = _secret.is_secret_code(input_code);

        if (!attempt)
        {
            cout << "Wrong answer. Do you wan't to force your way to the secret code? (n/y): ";
            cin >> force_option;

            if (tolower(force_option) == 'y')
            {
                force _force;
                _force.execute();
                _helper.print_txt(cheat);
                force_option = 'n';
            }
        }
        else
        {
            // To do: special message to Mike.
            // Repository URL.
            // Private key to clone it.

            // system("cls");
            _helper.print_txt(win);
            return 0;
        }
    }

    return 0;
}

string getCode()
{
    const char *clue = "../assets/clue.txt";
    string input;

    _helper.print_txt(clue);

    bool is_valid_input = false;

    while (!is_valid_input)
    {
        cout << "Code: ";
        cin >> input;

        is_valid_input = _helper.is_valid(input);
    }

    return input;
}
