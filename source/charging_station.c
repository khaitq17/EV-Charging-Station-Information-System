/***************************************************************************
 * @file    charging_station.c
 * @brief   Define functions related to charging station
 * @details This file contains functions definition related to charging 
 *          station, include initialize station, start and stop charging,
 *          display status.
 * @version 1.0
 * @date    2024-10-15
 * @author  Tran Quang Khai
 ***************************************************************************/
#include <stdio.h>
#include "charging_station.h"
#include "network.h"
#include "utils.h"
#include <string.h>

/**************************************************************************
 * @brief   initChargingStation
 * @details This function initializes initial information for a charging station.
 * @param   station   Pointer to charging station that want to initialize 
 * @return  None
 **************************************************************************/
void initChargingStation(ChargingStation *station) {
    station->power = 0;
    station->timeRemaining = 0;
    station->status = NOT_CHARGING;
    station->temperature = 25;
    logEvent("Charging station initialized.\n");
}

/**************************************************************************
 * @brief   startCharging
 * @details This function starts charging process of a charging station.
 * @param   station Pointer to charging station that want to start charging
 * @param   power   Charging power that set to charging station
 * @param   time    Charging time that set to charging station     
 * @return  None
 **************************************************************************/
void startCharging(ChargingStation *station, int power, int time) {
    station->power = power;
    station->timeRemaining = time;
    station->status = CHARGING;
    logEvent("Charging started.\n");
}

/**************************************************************************
 * @brief   stopCharging
 * @details This function stops charging process of a charging station.
 * @param   station Pointer to charging station that want to stop charging 
 * @return  None
 **************************************************************************/
void stopCharging(ChargingStation *station) {
    char timeStr[20];
    getCurrentTime(timeStr, sizeof(timeStr));
    logChargingSession(station, timeStr, "Finished", station->power, station->power * station->timeRemaining / 60);

    station->power = 0;
    station->timeRemaining = 0;
    station->status = NOT_CHARGING;

    logEvent("Charging stopped.\n");
}

/**************************************************************************
 * @brief   displayStationStatus
 * @details This function displays charging status.
 * @param   station Pointer to charging station that want to display status  
 * @return  None
 **************************************************************************/
void displayStationStatus(const ChargingStation *station) {
    printf("Current status: %s\n", (station->status == NOT_CHARGING) ? "Not charging" : "Charging");
    printf("Charging power: %d kW\n", station->power);
    printf("Time remaining: %d minutes\n", station->timeRemaining);
}

/**************************************************************************
 * @brief   logChargingSession
 * @details This function records a charging session into history.
 * @param   station Pointer to charging station that want to log charging session
 * @param   time    Time of this charging session
 * @param   status  Status of this charging session
 * @param   power   Power of this charging session
 * @param   energy  Energy of this charging session   
 * @return  None
 **************************************************************************/
void logChargingSession(ChargingStation *station, const char *time, const char *status, const int power, const double energy) {
    if (station->historyCount < MAX_HISTORY) {
        strcpy(station->history[station->historyCount].time, time);
        strcpy(station->history[station->historyCount].status, status);
        station->history[station->historyCount].power = power;
        station->history[station->historyCount].energy = energy;
        station->historyCount++;
    } else {
        for (int i = 1; i < MAX_HISTORY; i++) {
            station->history[i - 1] = station->history[i];
        }

        strcpy(station->history[MAX_HISTORY - 1].time, time);
        strcpy(station->history[MAX_HISTORY - 1].status, status);
        station->history[MAX_HISTORY - 1].power = power;
        station->history[MAX_HISTORY - 1].energy = energy;
    }
}