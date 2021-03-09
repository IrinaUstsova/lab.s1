#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct subject
{
    string name_of_subject;
    int grade = 0;
};

struct student
{
    string name;
    vector<subject> sub_vector;
};

ostream& operator <<(ostream& out, const vector<subject>& vec)
{
    for (auto& element : vec)
    {
        out << element.name_of_subject << ";";
        out << element.grade << ";";
    }
        return out;
}

ostream& operator <<(ostream& out, const vector<student>& stud)
{
    for (auto& element : stud)
    {
        out << element.name << ";";
        out << element.sub_vector << endl;
    }
    return out;
}

istream& operator << (istream& in, const vector<student>& stud_2)
{
    string "text.txt"_str;
    getline ("text.txt", "text.txt"_str,'\0');
    for (student& stud_2: stud_2)
    {
        getline(in, stud_2.name);
    }
    return in;
}

istream& operator << (istream& in, const vector<subject>& stud_1)
{
    string "text.txt"_str;
    getline ("text.txt", "text.txt"_str,'\0');
    for (subject& stud_1: stud_1)
    {
        getline(in, stud_1.name_of_subject);
        getline(in, stud_1.grade);
    }
    return in;
}

bool sorting (student stud1, student stud2)
{
    if (stud1.name > stud2.name)
        return false;
    else
        return true;
}

int main()
{
    vector<student>students(3);
    string sub[4]={"maths", "english", "chemistry", "physics"};
    for (int i=0; i<3; i++)
    {
        cout << "enter a name:";
        cin >> students[i].name;
        students[i].sub_vector.resize(4);
        for(int j=0; j<4; j++)
        {
            students[i].sub_vector[j].name_of_subject=sub[j];
            cout << sub[j] << ": ";
            cin >> students[i].sub_vector[j].grade;
        }
    }
    sort(students.begin(), students.end(), sorting);
    for (int i=0; i<3; i++)
    {
        cout << students[i].name << endl;
    }

    ofstream file("text.txt");
    //file.open("text.txt", ios::out);
    if(file.is_open())
    {
        file << students;
    }
    file.close();

    int badst=0;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (students[i].sub_vector[j].grade < 3)
            {
                cout << students[i].name << endl;
                badst++;
                break;
            }
        }
    }
    cout<<badst;

    //file.open("text.txt", ios::out);
    //if(file.is_open())
    //{
     //   file << students;
    //}

    return 0;
}