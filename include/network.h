/***************************************************************************
 * @file    network.h
 * @brief   Declare functions and structure related to network
 * @details This file contains functions and structure declaration related  
 *          to network, include check network connection, display status.
 * @version 1.0
 * @date    2024-10-15
 * @author  Tran Quang Khai
 ***************************************************************************/
#ifndef NETWORK_H
#define NETWORK_H

/**************************************************************************
 * @enum    ConnectionStatus
 * @details This enum defines 2 network connection status: Disconnected or Connected
 **************************************************************************/
typedef enum {
    NETWORK_DISCONNECTED,   /* Network disconnected status */
    NETWORK_CONNECTED       /* Network connected status */
} ConnectionStatus;

/**************************************************************************
 * @struct  NetworkStatus
 * @details This struct includes information of network status.
 **************************************************************************/
typedef struct {
    int signalStrength;         /* Signal strength (dBm) */ 
    int latency;                /* Network latency (ms) */ 
    ConnectionStatus status;    /* Connection status */ 
} NetworkStatus;

/**************************************************************************
 * @brief   checkNetworkConnection
 * @param   network   Pointer to network that want to check connection 
 * @return  ConnectionStatus
 *          Return NETWORK_DISCONNECTED if network status is disconnected
 *                 NETWORK_CONNECTED if network status is connected
 **************************************************************************/
ConnectionStatus checkNetworkConnection(NetworkStatus *network);

/**************************************************************************
 * @brief   displayNetworkStatus
 * @param   network   Pointer to network that want to display status  
 * @return  None
 **************************************************************************/
void displayNetworkStatus(NetworkStatus *network);

#endif /* NETWORK_H */