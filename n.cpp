#include <iostream>
#include <unistd.h>
#include <sys/utsname.h>
#include <ctime>


int main(){


    //Получение имени компьютера
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) !=0){
        printf("Ошибка");
    } else{
        printf("Имя компьютера %s\n", hostname);
    }

    //Получение имени пользователя
    char username[256];
    if (getlogin_r(username, sizeof(username)) !=0){
        printf("Ошибка");
    } else{
        printf("Имя пользователя: %s\n", username);
    }

    //Получение информации о системе
    struct utsname sysinfo;
    if (uname(&sysinfo) == 0){
        printf("Имя ОС: %s\n", sysinfo.sysname);
        printf("Имя машины: %s\n", sysinfo.nodename);
        printf("Версия ОС: %s\n", sysinfo.release);
        printf("Архитектура: %s\n", sysinfo.machine);
        printf("Релиз операционной системы: %s\n", sysinfo.version);
    } else{
        printf("Ошибка");
    }

    //Получение системных метрик
    long numProcessors = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Количество доступных процессоров: %ld\n", numProcessors);
    long stac = sysconf(_SC_THREAD_STACK_MIN);
    printf("Размер стэка: %ld\n", stac);
    long nproc = sysconf(_SC_NPROCESSORS_CONF);
    printf("Количество свободных процессоров: %ld\n", nproc);

    //Получение текущего времени
    time_t currentTime = time(nullptr);
    struct tm *localTime = localtime(&currentTime);
    printf("Текущее время: %s", asctime(localTime));



    return 0;
}






