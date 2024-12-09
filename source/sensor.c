/***************************************************************************
 * @file    sensor.c
 * @brief   Define functions related to sensor
 * @details This file contains functions definition related to sensor, 
 *          include calibration and data collection from the sensor.
 * @version 1.0
 * @date    2024-10-15
 * @author  Tran Quang Khai
 ***************************************************************************/
#include "sensor.h"
#include "utils.h"

/**************************************************************************
 * @brief   calibrateTemperature
 * @details This function calibrates temparature data from sensor.
 * @param   sensor      Pointer to sensor that want to calibrate temparature data
 * @param   tempOffset  Offset value to calibrate temperature data 
 * @return  None
 **************************************************************************/
void calibrateTemperature(SensorData *sensor, int tempOffset){
    sensor->temperature += tempOffset;
    logEvent("Temperature sensor calibrated.\n");
    printf("Temperature sensor calibrated.\n");
}

/**************************************************************************
 * @brief   calibrateCurrent
 * @details This function calibrates current data from sensor.
 * @param   sensor          Pointer to sensor that want to calibrate current data
 * @param   currentOffset   Offset value to calibrate current data 
 * @return  None
 **************************************************************************/
void calibrateCurrent(SensorData *sensor, int currentOffset){
    sensor->current += currentOffset;
    logEvent("Current sensor calibrated.\n");
    printf("Current sensor calibrated.\n");
}

/**************************************************************************
 * @brief   calibrateVoltage
 * @details This function calibrates voltage data from sensor.
 * @param   sensor          Pointer to sensor that want to calibrate voltage data
 * @param   voltageOffset   Offset value to calibrate voltage data 
 * @return  None
 **************************************************************************/
void calibrateVoltage(SensorData *sensor, int voltageOffset){
    sensor->voltage += voltageOffset;
    logEvent("Voltage sensor calibrated.\n");
    printf("Voltage sensor calibrated.\n");
}