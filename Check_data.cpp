#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "header.h"
using namespace std;




int is_teacher_login_exist(char* login, char* teachers_filename){

    vector <teacher> teachers;
    int len = get_people(teachers, teachers_filename), i = 0;

    for (i; i < len; i++){
        if (!strcmp(teachers[i].login, login)) return 1;
    }

    return 0;
}


int is_student_login_exist(char* login, char* students_filename){

    vector <student> students;
    int len = get_people(students, students_filename), i = 0;

    for (i; i < len; i++){
        if (!strcmp(students[i].login, login)) return 1;
    }

    return 0;
}



int check_data_students(char *login, char *password, char* students_filename){

    vector <student> students;
    int len = get_people(students, students_filename), i, flag = 0;


    for (i = 0; i < len; i++){
        if (!strcmp(students[i].login, login) && !strcmp(students[i].password, password)){
            flag = 1;
            break;
        }
    }

    if (flag == 1) return i;
    else return -1;
}


int check_data_teachers(char *login, char *password, char* teachers_filename){

    vector <teacher> teachers;

    ///len = get_people(teachers, teachers_filename) - сохраняет в len длину массива, в teachers массив с учителями.
    int len = get_people(teachers, teachers_filename), i, flag = 0;


    for (i = 0; i < len; i++){
        if (!strcmp(teachers[i].login, login) && !strcmp(teachers[i].password, password)){
            flag = 1;
            break;
        }
    }

    if (flag == 1) return i;
    else return -1;
}


int is_group_exist(int *arr, int group){
    int i = 0;
    while (arr[i]) {
        if (arr[i] == group) return 1;
        i++;
    }
    return 0;
}
