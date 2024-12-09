/***************************************************************************
 * @file    utils.c
 * @brief   Define functions related to utils
 * @details This file contains functions definition related to utils, 
 *          include logging, time processing, and string processing.
 * @version 1.0
 * @date    2024-10-15
 * @author  Tran Quang Khai
 ***************************************************************************/
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**************************************************************************
 * @brief   logEvent
 * @details This function writes event to the log.
 * @param   event   Pointer to event that want to write to the log  
 * @return  None
 **************************************************************************/
void logEvent(const char *event) {
    FILE *log_file = fopen("logs/charging_log.txt", "a");

    if (log_file == NULL) {
        printf("Error: Can not open file!\n");
        return;
    }

    char time_buffer[20];
    getCurrentTime(time_buffer, sizeof(time_buffer));

    // Ghi su kien kem thoi gian vao log
    fprintf(log_file, "- [%s]: %s\n", time_buffer, event);

    fclose(log_file);
}

/**************************************************************************
 * @brief   getCurrentTime
 * @details This function gets current time and formats it as string.
 * @param   buffer      Pointer to buffer store current time
 * @param   bufferSize  Buffer size 
 * @return  None
 **************************************************************************/
void getCurrentTime(char *buffer, int bufferSize) {
    time_t rawTime;
    struct tm *timeInfo;

    time(&rawTime); // Lay thoi gian hien tai
    timeInfo = localtime(&rawTime); // Chuyen doi thoi gian thanh cau truc tm

    // Dinh dang thoi gian thanh chuoi "HH:MM DD/MM/YY"
    strftime(buffer, bufferSize, "%H:%M %d/%m/%Y", timeInfo);
}

/**************************************************************************
 * @brief   delay
 * @details This function delays time in millisecond.
 * @param   milliseconds    Delay time
 * @return  None
 **************************************************************************/
void delay(int milliseconds){
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while ((now - then) < pause)
        now = clock();
}