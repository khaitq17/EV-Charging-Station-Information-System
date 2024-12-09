/***************************************************************************
 * @file    charging_station.h
 * @brief   Declare functions and structure related to charging station
 * @details This file contains functions and structure declaration related  
 *          to charging station, include initialize station, start and stop 
 *          charging, display status.
 * @version 1.0
 * @date    2024-10-15
 * @author  Tran Quang Khai
 ***************************************************************************/
#ifndef CHARGING_STATION_H
#define CHARGING_STATION_H

/**************************************************************************
 * Define maximum charging history to store and display
 **************************************************************************/
#define MAX_HISTORY 5

/**************************************************************************
 * @struct  ChargingHistory
 * @details This struct is used for store charging history information, 
 *          include charging time, charging status, charging power and 
 *          charging energy.
 **************************************************************************/
typedef struct {
    char time[20];      /* Charging time */    
    char status[20];    /* Charging status */    
    int power;          /* Charging power */ 
    double energy;      /* Charging energy */
} ChargingHistory;

/**************************************************************************
 * @enum    ChargingStatus
 * @details This enum defines 2 charging status: Not charging or Charging.
 **************************************************************************/
typedef enum {
    NOT_CHARGING,   /* Not charging status */
    CHARGING        /* Charging status */
} ChargingStatus;

/**************************************************************************
 * @struct  ChargingStation
 * @details This struct includes necessary information of a charging station.
 **************************************************************************/
typedef struct {
    int power;                              /* Charging power (kW) */
    int timeRemaining;                      /* Time remaining (minutes) */
    ChargingStatus status;                  /* Charging status */
    int temperature;                        /* Station temperature (°C) */
    ChargingHistory history[MAX_HISTORY];   /* Array stores recent charging history */
    int historyCount;                       /* Number of stored charging history */
} ChargingStation;

/**************************************************************************
 * @brief   initChargingStation
 * @param   station   Pointer to charging station that want to initialize 
 * @return  None
 **************************************************************************/
void initChargingStation(ChargingStation *station);

/**************************************************************************
 * @brief   startCharging
 * @param   station Pointer to charging station that want to start charging
 * @param   power   Charging power that set to charging station
 * @param   time    Charging time that set to charging station     
 * @return  None
 **************************************************************************/
void startCharging(ChargingStation *station, int power, int time);

/**************************************************************************
 * @brief   stopCharging
 * @param   station Pointer to charging station that want to stop charging 
 * @return  None
 **************************************************************************/
void stopCharging(ChargingStation *station);

/**************************************************************************
 * @brief   displayStationStatus
 * @param   station Pointer to charging station that want to display status  
 * @return  None
 **************************************************************************/
void displayStationStatus(const ChargingStation *station);

/**************************************************************************
 * @brief   logChargingSession
 * @param   station Pointer to charging station that want to log charging session
 * @param   time    Time of this charging session
 * @param   status  Status of this charging session
 * @param   power   Power of this charging session
 * @param   energy  Energy of this charging session   
 * @return  None
 **************************************************************************/
void logChargingSession(ChargingStation *station, const char *time, const char *status, const int power, const double energy);

#endif /* CHARGING_STATION_H */