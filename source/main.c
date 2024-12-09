/***************************************************************************
 * @file    main.c
 * @brief   Main program
 * @version 1.0
 * @date    2024-10-15
 * @author  Tran Quang Khai
 ***************************************************************************/
#include <stdio.h>
#include <string.h>
#include "charging_station.h"
#include "network.h"
#include "sensor.h"
#include "settings.h"
#include "utils.h"

/**************************************************************************
 * Main program
 **************************************************************************/
int main(){
    ChargingStation station = {.power = 0, .timeRemaining = 0, .status = NOT_CHARGING, .temperature = 25, .historyCount = 0};
    SensorData sensor = {.temperature = 0, .current = 0, .voltage = 0};
    NetworkStatus network = {.signalStrength = 0, .latency = 0, .status = NETWORK_CONNECTED};
    StationSettings settings = {.maxPower = 30, .maxTime = 60, .temperatureThreshold = 50};

    int choice, choiceInCase;
    
    do
    {   
        
        printf("+--------------------------------------------------------------+\n");
        printf("\t\tEV Charging Station Information System\n");
        printf("+--------------------------------------------------------------+\n");
        printf("1. Display station status\n");
        printf("2. Start charging\n");
        printf("3. Stop charging\n");
        printf("4. View charging history\n");
        printf("5. Setting charging station\n");
        printf("6. Check connection status\n");
        printf("7. Calibrate sensor\n");
        printf("8. Exit\n");
        printf("+--------------------------------------------------------------+\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        // 1. Display station status
        case 1:
        {   
            printf("+--------------------------------------------------------------+\n");
            // Information
            displayStationStatus(&station);

            // Network connection
            checkNetworkConnection(&network);

            // Temperature threshold warning
            if (station.temperature <= settings.temperatureThreshold) {
                printf("Warning: No warning\n");
            } else {
                printf("Warning: Temperature exceed the allowable threshold\n");
            }

            // Recent history
            if (station.historyCount > 0 ) {
                printf("Recent history:\n");

                for (int i = station.historyCount; i > station.historyCount - 3; i++) {
                    printf("- %s: %s\n", station.history[i].time, station.history[i].status);
                }
            }
            
            
            select_after_display_status:
            printf("+--------------------------------------------------------------+\n");
            printf("Press 0 to return main menu\n");
            printf("+--------------------------------------------------------------+\n");
            scanf("%d", &choiceInCase);
            switch (choiceInCase)
            {
            case 0:
                break;
            
            default:
                printf("Invalid choice. Please try again!");
                goto select_after_display_status;
            }
            break;
        }
        
        // 2. Start charging
        case 2:
        {    
            printf("+--------------------------------------------------------------+\n");
            printf("Start the charging process...\n");
            delay(3000);

            // Select power
            printf("Select charging power (kW):\n");
            printf("1. [11]   2. [30](Default)      3. [60]    4. [250]\n");
            int powerChoice, powerSelected;
            printf("Select: ");
            scanf("%d", &powerChoice);
            if(powerChoice == 1) {
                powerSelected = 11;
            } else if (powerChoice == 3) {
                powerSelected = 60;
            } else if (powerChoice == 4) {
                powerSelected = 250;
            } else powerSelected = 30;
            delay(2000);

            // Select time
            printf("Select charging time (minutes):\n");
            printf("1. [30]     2. [60](Default)    3. [90]     4. [120]\n");
            int timeChoice, timeSelected;
            printf("Select: ");
            scanf("%d", &timeChoice);
            if(timeChoice == 1) {
                timeSelected = 30;
            } else if (timeChoice == 3) {
                timeSelected = 90;
            } else if (timeChoice == 4) {
                timeSelected = 120;
            } else timeSelected = 60;
            delay(2000);

            select_after_starting_charging:
            printf("+--------------------------------------------------------------+\n");
            printf("1. Start charging\n");
            printf("2. Return main menu\n");
            printf("+--------------------------------------------------------------+\n");

            printf("Enter your choice: ");
            scanf("%d", &choiceInCase);

            switch (choiceInCase)
            {
            case 1:
                startCharging(&station, powerSelected, timeSelected);
                printf("Start charging\n");
                delay(2000);
                break;

            case 2:
                break;

            default:
                printf("Invalid choice. Please try again!");
                goto select_after_starting_charging;
            }

            break;
        }
        
        // 3. Stop charging
        case 3:
        {    
            printf("+--------------------------------------------------------------+\n");
            printf("Stop the charging process...\n");
            delay(3000);
            printf("Current status: Finished\n");
            printf("Total charged energy: %d kWh\n", station.power * station.timeRemaining / 60);
            printf("Temperature: %d\n", station.temperature);
            stopCharging(&station);
            printf("+--------------------------------------------------------------+\n");
            printf("Data has been saved to the log\n");

            select_after_stop_charging:
            printf("Press 0 to return main menu\n");
            printf("+--------------------------------------------------------------+\n");
            scanf("%d", &choiceInCase);

            switch (choiceInCase)
            {
            case 0:
                break;
            
            default:
                printf("Invalid choice. Please try again!");
                goto select_after_stop_charging;
            }
            break;  
        }

        // 4. View charging history
        case 4:
        {    
            printf("+--------------------------------------------------------------+\n");
            printf("Charging history:\n");
            int stt = 1;
            for (int i = MAX_HISTORY - 1; i >= 0; i--) {
                printf("%d. Time: %s\n", stt, station.history[i].time);
                printf("   Status: %s\n", station.history[i].status);
                printf("   Power: %d kW\n", station.history[i].power);
                printf("   Energy: %.2lf kWh\n", station.history[i].energy);
                printf("+--------------------------------------------------------------+\n");
                stt++;
            }

            select_after_view_history:
            printf("Press 0 to return main menu\n");
            printf("+--------------------------------------------------------------+\n");
            scanf("%d", &choiceInCase);

            switch (choiceInCase)
            {
            case 0:
                break;

            default:
                printf("Invalid choice. Please try again!");
                goto select_after_view_history;
            }
          
            break;
        }
        
        // 5. Setting charging station
        case 5:
        {    
            printf("+--------------------------------------------------------------+\n");
            printf("Setting charging station\n");
            printf("1. Maximum power (kW): [%d]\n", settings.maxPower);
            printf("2. Maximum duration (minutes): [%d]\n", settings.maxTime);
            printf("3. Temperature threshold (°C): [%d]\n", settings.temperatureThreshold);
            printf("4. Reset settings\n");
            printf("5. Reset to default\n");
            printf("6. Return\n");
            printf("+--------------------------------------------------------------+\n");
            select_after_setting:
            printf("Enter your choice: ");
            scanf("%d", &choiceInCase);

            switch (choiceInCase)
            {
            case 4:
                int power, duration, tempThreshold;
                printf("Enter maximum power (kW): "); scanf("%d", &power);
                printf("Enter maximum duration (minutes): "); scanf("%d", &duration);
                printf("Enter temperature threshold (°C): "); scanf("%d", &tempThreshold);
                configureStation(&settings, power, duration, tempThreshold);
                printf("Reset new settings successfully\n");
                break;
            
            case 5:
                resetStationSettings(&settings);
                printf("Reset to default successfully\n");
                break;

            case 6:
                break;

            default:
                printf("Invalid choice. Please try again!");
                goto select_after_setting;
            }               

            break;
        }

        // 6. Check connection status
        case 6:
        {    
            printf("+--------------------------------------------------------------+\n");
            printf("Check network connection\n");
            displayNetworkStatus(&network);
            printf("No error detected\n");
            select_after_check_network:
            printf("+--------------------------------------------------------------+\n");
            printf("Press 0 to return main menu\n");
            printf("+--------------------------------------------------------------+\n");
            scanf("%d", &choiceInCase);

            switch (choiceInCase)
            {
            case 0:
                break;
            
            default:
                printf("Invalid choice. Please try again!");
                goto select_after_check_network;
            }
            break;
        }

        // 7. Calibrate sensor
        case 7:
        {    
            printf("+--------------------------------------------------------------+\n");
            printf("Calibrate sensor\n");
            printf("1. Temperature sensor\n");
            printf("2. Current sensor\n");
            printf("3. Voltage sensor\n");
            printf("4. Return\n");
            printf("+--------------------------------------------------------------+\n");
            calibrate_sensor:
            printf("Enter your choice: ");
            scanf("%d", &choiceInCase);

            switch (choiceInCase)
            {
            case 1:
                int tempOffset; 
                printf("Enter temperature want to calibrate: "); scanf("%d", &tempOffset);
                calibrateTemperature(&sensor, tempOffset);
                break;
            
            case 2:
                int currentOffset; 
                printf("Enter current want to calibrate: "); scanf("%d", &currentOffset);
                calibrateCurrent(&sensor, currentOffset);
                break;

            case 3:
                int voltageOffset; 
                printf("Enter voltage want to calibrate: "); scanf("%d", &voltageOffset);
                calibrateVoltage(&sensor, voltageOffset);
                break;

            case 4:
                break;

            default:
                printf("Invalid choice. Please try again!");
                goto calibrate_sensor;
            }

            break;
        }

        // Exit
        case 8:
            printf("+--------------------------------------------------------------+\n");
            printf("Exit\n");
            printf("+--------------------------------------------------------------+\n");
            break;


        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
        
    } while (choice != 8);
    
    return 0;
}