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
    const char *secret = "../assets/secret.txt";
    const char *repositoryUrl = "https://github.com/victoria-ballesteros/code_breaker";

    char force_option = 'n';
    _helper.clear_screen();
    _helper.print_txt(greeting);
    cout << endl;

    while (tolower(force_option) == 'n')
    {
        string input_code = _helper.getCode();

        bool attempt = _secret.is_secret_code(input_code);

        if (!attempt)
        {
            _helper.clear_screen();
            cout << "Wrong answer. Do you wan't to force your way to the secret code? (n/y): ";
            cin >> force_option;

            if (tolower(force_option) == 'y')
            {
                force _force;
                _force.execute();
                _helper.print_txt(cheat);
                cout << endl;
                force_option = 'n';
            }
        }
        else
        {
            _helper.clear_screen();

            _helper.print_txt(win);

            cout << endl;
            cout << "Source code: " << repositoryUrl << endl;
            cout << "Look inside and you'll find out the missing piece of the message." << endl;
            cout << endl;
            cout << "AES256 ciphertext: " << _secret.get_cipher_message() << endl;
            cout << endl;
            cout << "Key: ???" << endl;
            cout << endl;
            
            // Uncomment this to see the message.
            // _helper.clear_screen();
            // _helper.print_txt(secret);
            // cout << endl;
            // _secret.execute();
            // cout << endl;

            system("pause");
            
            return 0;
        }
    }

    return 0;
}
