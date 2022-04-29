/*Брянцев Всеволод Александрович, 61 группа
С клавиатуры вводится информация об итогах последней экзаменационной сессии. Эта информация включает в себя:
1) целое число n - количество студентов; 2) n объединенных в структуру данных:
<имя><фамилия> <оценка> <оценка> <оценка> <оценка> <оценка>
где <имя>, <фамилия> - символьные строки, содержащие не более 20 символов, оценка за экзамен - десятичная цифра из диапазона '2'..'5'.
Требуется сформировать массив структур, в котором каждый элемент массива содержит фамилию студента и его средний балл, причем элементы
располагаются в порядке, обратном следования при вводе, и вывести этот массив на экран.
Вывести также фамилии и оценки студентов, имеющих наибольшее количество неудовлетворительных оценок.
*/

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

struct student //структура, в которой будет храниться информация о студенте (имя, фамилия, оценки)
{
    string name;
    string surname;
    string marks;
};

struct student_output //структура, в которой будет храниться информация о студенте (фамилия) и его средняя оценка
{
    string surname;
    double average_mark = 0.0;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n; //кол-во студентов
    int max_poor = 0; //максимальное количество неудовлетворительных оценок

    //ввод данных
    cout << "Введите количество студентов: "; cin >> n;
    student* students = new student[n]; //входной массив структур
    for (int i = 0; i < n; i++)
    {
        cout << "Введите данные " << i + 1 << "-го студента (имя, фамилия, оценки подряд без пробелов): " << endl;
        cin >> students[i].name;
        cin >> students[i].surname;
        cin >> students[i].marks;
        int counter = 0;
        for (int j = 0; j < students[i].marks.size(); j++)
        {
            if (students[i].marks[j] == '2')
            {
                counter++;
            }
        }
        if (counter > max_poor)
        {
            max_poor = counter;
        }
    }

    student_output* students_output = new student_output[n]; //выходной массив структур
    //заполнение выходного массива в порядке, обратном заполнению входного массива
    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--)
    {
        students_output[i].surname = students[j].surname;
        double sum_marks = 0.0;
        for (int a = 0; a < students[j].marks.size(); a++)
        {
            sum_marks += (students[j].marks[a] - '0');
        }
        students_output[i].average_mark = sum_marks / students[j].marks.size();
    }
    //вывод выходного массива
    cout << endl << "Фамилии и средние баллы студентов: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << students_output[i].surname << " " << students_output[i].average_mark << endl;
    }
    //вывод дополнительного условия
    cout << endl << "Студенты с наибольшим количеством неудовлетворительных оценок: " << endl;
    for (int i = 0; i < n; i++)
    {
        int counter = 0;
        for (int j = 0; j < students[i].marks.size(); j++)
        {
            if (students[i].marks[j] == '2')
            {
                counter++;
            }
        }
        if (counter == max_poor)
        {
            cout << students[i].surname << " " << students[i].marks << endl;
        }
    }
}
