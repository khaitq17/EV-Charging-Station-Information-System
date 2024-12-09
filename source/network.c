/***************************************************************************
 * @file    network.c
 * @brief   Define functions related to network
 * @details This file contains functions definition related to network, 
 *          include check network connection, display status.
 * @version 1.0
 * @date    2024-10-15
 * @author  Tran Quang Khai
 ***************************************************************************/
#include <stdio.h>
#include "network.h"
#include "utils.h"

/**************************************************************************
 * @brief   checkNetworkConnection
 * @details This function checks network connection status.
 * @param   network   Pointer to network that want to check connection 
 * @return  ConnectionStatus
 *          Return NETWORK_DISCONNECTED if network status is disconnected
 *                 NETWORK_CONNECTED if network status is connected
 **************************************************************************/
ConnectionStatus checkNetworkConnection(NetworkStatus *network) {
    logEvent("Connection status checked.\n");
    if (network->signalStrength > -90 && network->latency < 100) {
        printf("Connection status: Stable connection\n");
        return NETWORK_CONNECTED;
    }
    
    printf("Connection status: Lost connection\n");
    return NETWORK_DISCONNECTED;
}

/**************************************************************************
 * @brief   displayNetworkStatus
 * @details This function displays network status.
 * @param   network   Pointer to network that want to display status  
 * @return  None
 **************************************************************************/
void displayNetworkStatus(NetworkStatus *network) {
    if (checkNetworkConnection(network) == NETWORK_CONNECTED) {
        printf("Connection status: Stable connection\n");
    } else {
        printf("Connection status: Lost connection\n");
    }

    if (network->signalStrength > -70) {
        printf("Signal strength: Good\n");
    } else {
        printf("Signal strength: Poor\n");
    }
    
    printf("Latency: %d\n", network->latency);
}