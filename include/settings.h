/***************************************************************************
 * @file    settings.h
 * @brief   Declare functions and structure related to settings station
 * @details This file contains functions and structure declaration related  
 *          to settings station, include configure, reset, display station
 *          setting.
 * @version 1.0
 * @date    2024-10-15
 * @author  Tran Quang Khai
 ***************************************************************************/
#ifndef __SETTINGS_H
#define __SETTINGS_H

typedef struct {
    int maxPower;               // Maximum power (kW)
    int maxTime;                // Maximum time (minutes)
    int temperatureThreshold;   // Temperature warning threshold (°C)
} StationSettings;

/**************************************************************************
 * @brief   configureStation
 * @param   settings        Pointer to station that want to setting
 * @param   maxPower        Maximum power want to setting           
 * @param   maxTime         Maximum duration want to setting
 * @param   tempThreshold   Temperature threshold want to setting
 * @return  None
 **************************************************************************/
void configureStation(StationSettings *settings, int maxPower, int maxTime, int temperatureThreshold);

/**************************************************************************
 * @brief   resetStationSettings
 * @param   settings    Pointer to station that want to setting
 * @return  None
 **************************************************************************/
void resetStationSettings(StationSettings *settings);

/**************************************************************************
 * @brief   displayStationSettings
 * @param   settings    Pointer to station that want to setting
 * @return  None
 **************************************************************************/
void displayStationSettings(const StationSettings *settings);

#endif /* __SETTINGS_H */