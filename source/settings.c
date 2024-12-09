/***************************************************************************
 * @file    settings.c
 * @brief   Define functions related to settings station
 * @details This file contains functions definition related to settings station, 
 *          include configure, reset, display station setting.
 * @version 1.0
 * @date    2024-10-15
 * @author  Tran Quang Khai
 ***************************************************************************/
#include "settings.h"
#include "utils.h"

/**************************************************************************
 * @brief   configureStation
 * @details This function configures charging station setting.
 * @param   settings        Pointer to station that want to setting
 * @param   maxPower        Maximum power want to setting           
 * @param   maxTime         Maximum duration want to setting
 * @param   tempThreshold   Temperature threshold want to setting
 * @return  None
 **************************************************************************/
void configureStation(StationSettings *settings, int maxPower, int maxTime, int tempThreshold){
    settings->maxPower = maxPower;
    settings->maxTime = maxTime;
    settings->temperatureThreshold = tempThreshold;
    logEvent("Station settings configured.\n");
}

/**************************************************************************
 * @brief   resetStationSettings
 * @details This function resets charging station setting.
 * @param   settings    Pointer to station that want to setting
 * @return  None
 **************************************************************************/
void resetStationSettings(StationSettings *settings){
    settings->maxPower = 30;
    settings->maxTime = 60;
    settings->temperatureThreshold = 50;
    logEvent("Station settings reset to default.\n");
}

/**************************************************************************
 * @brief   displayStationSettings
 * @details This function displays settings of the charging station.
 * @param   settings    Pointer to station that want to setting
 * @return  None
 **************************************************************************/
void displayStationSettings(const StationSettings *settings){
    printf("Maximum power: %d kW\n", settings->maxPower);
    printf("Maximum charging time: %d minutes\n", settings->maxTime);
    printf("Temperature threshold: %d °C\n", settings->temperatureThreshold);
}