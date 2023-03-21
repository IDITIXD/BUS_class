#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;
#define N 5
struct reises
{
    int number;
    char reis[50];
    char type[50];
    char punct[50];
    float time1;
    float time2;

};

class RASPISANIE
{
    const int sz = 2;
    reises af[2];
    char punct[50];
    float time2;
public:
    RASPISANIE() {};
    ~RASPISANIE() {};
    void zapolnenie()
    {
        for (int i = 0; i < sz; ++i) {
            cout << "Пункт назначения ";
            cin >> af[i].punct;
            cout << "Номер ";
            cin >> af[i].number;
            cout << "Тип ";
            (cin >> af[i].type).get();
            cout << "время отъезда ";
            cin >> af[i].time1;
            cout << "время прибытия ";
            cin >> af[i].time2;
        }
    };

    void sort() {
        for (int i = 0; i < sz; ++i)
        {
            for (int j = i + 1; j < sz; ++j)
            {
                if (af[j].number < af[i].number)
                {
                    reises temp = af[i];
                    af[i] = af[j];
                    af[j] = temp;
                }
            }
        }
    };
    void vvod() {
        cout << "\nВведите пункт назначения: ";
        cin >> punct;
        cout << "\nВведите время: ";
        cin >> time2;
    }
    void poisk() {
        bool find = false;
        for (int i = 0; i < sz; ++i)
        {
            if (!strcmp(af[i].punct, punct))
                if (time2 > af[i].time2)
                {
                    find = true;
                    cout << "Номер рейса: " << af[i].number << '\n'
                        << "Тип самолета: " << af[i].type << '\n'
                        << "Время отъезда: " << af[i].time1 << '\n'
                        << "Время приезда: " << af[i].time2 << '\n';
                }
        }

        if (!find)
        {
            cout << "Рейсы в данный пункт назначения не найдены!" << endl;
        }
    };
};

int main()
{
    setlocale(LC_ALL, "");
    RASPISANIE RAS;
    RAS.zapolnenie();
    RAS.vvod();
    RAS.sort();
    RAS.poisk();
}
