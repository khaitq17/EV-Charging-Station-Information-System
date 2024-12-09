/***************************************************************************
 * @file    sensor.h
 * @brief   Declare functions and structure related to sensor
 * @details This file contains functions and structure declaration related  
 *          to sensor, include calibration and data collection from the sensor.
 * @version 1.0
 * @date    2024-10-15
 * @author  Tran Quang Khai
 ***************************************************************************/
#ifndef SENSOR_H
#define SENSOR_H

/**************************************************************************
 * @struct  SensorData
 * @details This struct includes sensor data of temperature, current, voltage.
 **************************************************************************/
typedef struct {
    int temperature;    /* Temperature (°C) */
    int current;        /* Current (A) */
    int voltage;        /* Voltage (V) */
} SensorData;

/**************************************************************************
 * @brief   calibrateTemperature
 * @param   sensor      Pointer to sensor that want to calibrate temparature data
 * @param   tempOffset  Offset value to calibrate temperature data 
 * @return  None
 **************************************************************************/
void calibrateTemperature(SensorData *sensor, int tempOffset);

/**************************************************************************
 * @brief   calibrateCurrent
 * @param   sensor          Pointer to sensor that want to calibrate current data
 * @param   currentOffset   Offset value to calibrate current data 
 * @return  None
 **************************************************************************/
void calibrateCurrent(SensorData *sensor, int currentOffset);

/**************************************************************************
 * @brief   calibrateVoltage
 * @param   sensor          Pointer to sensor that want to calibrate voltage data
 * @param   voltageOffset   Offset value to calibrate voltage data 
 * @return  None
 **************************************************************************/
void calibrateVoltage(SensorData *sensor, int voltageOffset);

#endif /* SENSOR_H */