#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "header.h"
using namespace std;




void create_password(char *password){
    char password1[50], password2[50];
    while (1){
        cout << "Vvedite parol: ";
        cin >> password1;
        cout << "Povtorite parol: ";
        cin >> password2;
        if (!strcmp(password1, password2)){
            int i = 0;
            for (i; i < 50; i++) password[i] = password1[i];
            break;
        }
        else cout << "Ne verno!\n";
    }
}



void Sign_up(char* teachers_filename){
    teacher a;
    a.subject = get_subject();
    int res = -1;
    ///Ввод логина и проверка на наличие
    while (res != 0){

        get_login(a.login);
        int res = is_teacher_login_exist(a.login, teachers_filename);
        if (res != 0) cout << "Tagoy login uze est!\n";
        else break;
    }

    get_groups(a.groups);

    create_password(a.password);

    append_data(teachers_filename, a);
}
