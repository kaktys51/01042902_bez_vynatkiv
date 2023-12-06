#include <iostream>
#include <ctime>

using namespace std;
class MyArray
{
private:

public:
    int row;
    int col;
    int** arr;
    MyArray(int row, int col)
    {
        this->row = row;
        this->col = col;
        arr = new int* [row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand() % 90 + 10;
            }
        }
    }
    ~MyArray()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] arr[i];
            cout << "�������� ���'��� ��� ����� !" << endl;
        }
        delete[] arr;
        cout << "�������� ���'��� ��� ������ ��������� !" << endl;
    }
    void show_arr()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    friend void show_result(MyArray a1, MyArray a2);
};
void show_result(MyArray* a1, MyArray* a2)
{
    for (int i = 0; i < a1->row; i++)
    {
        for (int j = 0; j < a1->col; j++)
        {
            cout << a1->arr[i][j] + a2->arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    system("chcp 1251>nul");
    srand(time(nullptr));
    int r1, r2, c1, c2;
    do
    {
        cout << "ʳ������ ����� ����� �������: ";
        cin >> r1;
        cout << "ʳ������ �������� ����� �������: ";
        cin >> c1;
        cout << "ʳ������ ����� ����� �������: ";
        cin >> r2;
        cout << "ʳ������ �������� ����� �������: ";
        cin >> c2;
        cout << endl;

        if (r1 != r2) { cout << "�������. ʳ������ ����� ������� ������ !" << endl; }
        if (c1 != c2) { cout << "�������. ʳ������ �������� ������� ������ !" << endl; }

    } while (r1 != r2 || c1 != c2);

    MyArray a1(r1, c1);
    a1.show_arr();
    MyArray a2(r2, c2);
    a2.show_arr();
    show_result(&a1, &a2);
    cout << "������� ������ !" << endl;

    cout << "��������� ������� ��������" << endl;
    return 0;
}