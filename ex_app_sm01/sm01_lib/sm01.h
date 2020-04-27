/* 
 * File:   sm01.h
 * Author: Abdul Aziz
 * Company: Sciflair
 *
 * Created on 1st August, 2019
 */

#ifndef SM01_H
#define	SM01_H

#include <xc.h>             //include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//These are defined under project configuration, uncomment appropriate configuration here only if not define under project configuration
//#define SM01_WIFI     1
//#define SM01_GSM      2
//#define SM01_ETH      3
//#define SM01_MESH     4
//#define SM01_LORA     5

#define LED_IO              (LATAbits.LATA10)
#define	SW_IO               (PORTAbits.RA7)

#define	GPIO1               1
#define	GPIO2               2
//#define	GPIO3           3
//#define	GPIO4           4
#define	GPIO5               5
#define	GPIO6               6
#define	GPIO7               7
#define	GPIO8               8
#define	GPIO9               9
#define	GPIO10              10
#define	GPIO11              11
#define	GPIO12              12 
#define	GPIO13              13
#define	GPIO14              14
#define	GPIO15              15
#define	GPIO16              16

#define	GPIO1_OUT               (_LATC9)
#define	GPIO2_OUT               (_LATC8)
//#define	GPIO3_OUT           (_LATC7)
//#define	GPIO4_OUT           (_LATC6)
#define	GPIO5_OUT              (_LATB9)
#define	GPIO6_OUT               (_LATB8)
#define	GPIO7_OUT              (_LATB7)
#define	GPIO8_OUT               (_LATB14)
#define	GPIO9_OUT              (_LATA1)
#define	GPIO10_OUT              (_LATA0)
#define	GPIO11_OUT              (_LATB3)
#define	GPIO12_OUT             (_LATB2)
#define	GPIO13_OUT              (_LATB1)
#define	GPIO14_OUT              (_LATB0)
#define	GPIO15_OUT              (_LATC1)
#define	GPIO16_OUT              (_LATC0)

#define	GPIO1_TRIS               (_TRISC9)
#define	GPIO2_TRIS               (_TRISC8)
//#define	GPIO3_TRIS               (_TRISC7)
//#define	GPIO4_TRIS               (_TRISC6)
#define	GPIO5_TRIS               (_TRISB9)
#define	GPIO6_TRIS               (_TRISB8)
#define	GPIO7_TRIS               (_TRISB7)
#define	GPIO8_TRIS               (_TRISB14)
#define	GPIO9_TRIS               (_TRISA1)
#define	GPIO10_TRIS               (_TRISA0)
#define	GPIO11_TRIS               (_TRISB3)
#define	GPIO12_TRIS               (_TRISB2)
#define	GPIO13_TRIS               (_TRISB1)
#define	GPIO14_TRIS               (_TRISB0)
#define	GPIO15_TRIS               (_TRISC1)
#define	GPIO16_TRIS               (_TRISC0)

#define	GPIO1_IN               (_RC9)
#define	GPIO2_IN               (_RC8)
//#define	GPIO3_IN               (_RC7)
//#define	GPIO4_IN               (_RC6)
#define	GPIO5_IN               (_RB9)
#define	GPIO6_IN               (_RB8)
#define	GPIO7_IN               (_RB7)
#define	GPIO8_IN               (_RB14)
#define	GPIO9_IN               (_RA1)
#define	GPIO10_IN               (_RA0)
#define	GPIO11_IN               (_RB3)
#define	GPIO12_IN               (_RB2)
#define	GPIO13_IN               (_RB1)
#define	GPIO14_IN               (_RB0)
#define	GPIO15_IN               (_RC1)
#define	GPIO16_IN               (_RC0)

#define	GPIO5_ANS              (_ANSB9)
#define	GPIO8_ANS                (_ANSB14)
#define	GPIO9_ANS                (_ANSA1)
#define	GPIO10_ANS               (_ANSA0)
#define	GPIO11_ANS               (_ANSB3)
#define	GPIO12_ANS               (_ANSB2)
#define	GPIO13_ANS               (_ANSB1)
#define	GPIO14_ANS               (_ANSB0)
#define	GPIO15_ANS               (_ANSC1)
#define	GPIO16_ANS               (_ANSC0)

#define LOW     0
#define HIGH    1

#define OUTPUT      0
#define INPUT       1
//#define INPUT_PU  2
//#define INPUT_PD  3
#define ANALOG    4
//#define PWM       5

#define SM01_MODE_AUTO      1
#define SM01_MODE_MANUAL    0

#define EZCOM_QOS_0         0
#define EZCOM_QOS_1         1
#define EZCOM_QOS_2         2

typedef struct 
{
    uint8_t Second;
    uint8_t Minute;
    uint8_t Hour;
    uint8_t WeekDay;
    uint8_t Date;
    uint8_t Month;
    uint8_t Year;
} TIME;

/*********************************************************************/
/** Library Functions for SM01 Module                               **/
/*********************************************************************/

/**
 * Sets the GPIO pin mode
 * @param pin GPIO pin number
 * @param mode pin mode INPUT, OUTPUT or ANALOG
 */
void GPIO_Mode(uint8_t pin, uint8_t mode);

/**
 * Reads the GPIO pin
 * @param pin GPIO pin number
 * @return value of the pin
 */
uint16_t GPIO_Read(uint8_t pin);

/**
 * Write to the GPIO pin
 * @param pin GPIO pin number
 * @param val value to write 0 or 1
 */
void GPIO_Write(uint8_t pin, uint16_t val);

////////////////////////////////////////////////////////////////////////////////

/**
 * Open I2C1 Module 
 * @return true if opened successfully, else return false
 */
bool I2C1_Open(void);

/**
 * Close I2C1 Module
 */
void I2C1_Close(void);

/**
 * Perform complete I2C transfer on I2C1 module, this include generating start 
 * condition, transmit data (if txLen > 0), receive data if (rxLen > 0) and 
 * generate a stop condition at the end.
 * @param address slave device address to perform transfer on(read or write bits
 * are inserted accordingly inside this function)  
 * @param data pointer to data buffer, data from this buffer is transmitted if 
 * txLen > 0, after performing transfer, if rxLen > 0 then received data will be
 * copied on it. make sure the size of buffer is >= txLen and rxLen.
 * @param txLen number of bytes to transmit from data buffer to I2C slave.
 * @param rxLen number of bytes to receive from I2C slave to data buffer.
 * @return total number of bytes transfered. on successful transfer this should 
 * be equal to txLen + rxLen. device address byte after start and repeated are 
 * not accounted in this    
 */
uint16_t I2C1_Transfer(uint8_t address, uint8_t* data, uint8_t txLen, uint16_t rxLen);

////////////////////////////////////////////////////////////////////////////////

/**
 * This function open the SPI module
 * @return true if success, else false if failed or module is already opened
 */
bool SPI_Open(void);

/**
 * This function closes the SPI module
 */
void SPI_Close(void);

/**
 * This function reads the array of bytes from SPI module
 * @param data pointer to destination buffer
 * @param len number of bytes to read from SPI port
 * @return total number of bytes successfully read
 */
uint16_t SPI_Read(uint8_t *data, uint16_t len);

/**
 * This function writes array of bytes to SPI module
 * @param data The data array to be written on SPI
 * @param len number of bytes to write on SPI module
 * @return total number of bytes successfully written
 */
uint16_t SPI_Write(uint8_t *data, uint16_t len);

////////////////////////////////////////////////////////////////////////////////

/**
 * this function open the UART1 port of the module 
 * @param baudRate UART baud rate to open the port 
 * @return true if success or false if failed or already opened
 */
bool UART1_Open(uint32_t baudRate);

/**
 * This function close the UART1 port
 */
void UART1_CLose(void); ///////////////???????????????????????????????????????????????????????????????????????????????

/**
 * This function returns the number of bytes that can be written to TX FIFO
 * Note: at the movement FIFO is not implemented for transmission so this function
 * always return 0xffff.
 * @return Returns the number of data bytes free in TX FIFO
 */
uint16_t UART1_Writable(void);

/**
 * This function write array of bytes to UART1 port
 * @param  buf The data array to be written on UART1
 * @param  len The length of data array
 * @return Returns number of bytes actually written 
 */
uint16_t UART1_Write(const uint8_t* buf, uint16_t len);

/**
 * This function write string to UART1 port
 * @param  str The string to be written on UART1
 * @return Returns number of bytes actually written 
 */
uint16_t UART1_WriteStr(const char* str);

/**
 * This function write line to UART1 port (string terminated with CR LF)
 * @param str The string to be written on UART1
 * @return Returns number of bytes actually written 
 */
uint16_t UART1_WriteLn(const char* str);

/**
 * This function blocks until all pending bytes to transmit have been sent
 */
void UART1_Flush(void);

/**
 * This function returns the number of bytes that can be read from the UART1 RX FIFO
 * @return Returns the number of data bytes available in RX FIFO
 */
uint16_t UART1_Readable(void);

/**
 * This function reads an array of bytes from the UART1 RX FIFO. 
 * @param buf pointer to destination buffer array
 * @param len array length to read from UART1 RX FIFO 
 * @return Returns the number of bytes actually read. 
 */
uint16_t UART1_Read(uint8_t *buf, uint16_t len);

/**
 * This function reads an array of bytes from the UART1 RX FIFO 
 * without removing it from there. 
 * @param buf pointer to destination buffer array
 * @param len array length to read from RX FIFO 
 * @return Returns the number of bytes actually read. 
 */
uint16_t UART1_Peek(uint8_t *buf, uint16_t len);

/**
 * This function finds the given block of bytes in RX FIFO
 * @param buf array of bytes to find match
 * @param len length of array
 * @return Returns the index position in buffer, or 0xFFFF if not found
 */
uint16_t UART1_Find(const uint8_t *buf, uint16_t len);

/**
 * This function find for a string in RX FIFO
 * @param str string to search for
 * @return Returns the index position in buffer, or 0xFFFF if not found
 */
uint16_t UART1_FindStr(const char *str);

////////////////////////////////////////////////////////////////////////////////

/**
 * Callback function, called by stack on configuration update from SM01 utilities
 */
void SM01_OnAppConfigUpdate(void);

/**
 * Callback function, called by stack on Application Variable update from SM01 utilities
 */
void SM01_OnAppVariableUpdate(void);

////////////////////////////////////////////////////////////////////////////////

/**
 * This function perform SM01 hardware and all internal stack  initialisation
 * @param module module id, module will perform internal verification against this id
 * @param mode operation mode, SM01_MODE_AUTO or SM01_MODE_MANUAL
 */
void SM01_Init(uint8_t module, uint8_t mode);

/**
 * This function performs internal task of SM01 Module, such as such as 
 * communication task and all internal functionality of module. 
 * This function is called automatically in SM01_AUTO mode, by Timer Interrupt of Tick Module.
 * In SM01_MANUAL mode, this function must be called periodically to ensure proper functionality of SM01 stack
 * @return Always returns 0 in this implementation 
 */
int16_t SM01_ProcessTasks(void);

/**
 * This function puts the SM01 Module to sleep
 * Any enabled interrupt will cause the module to wake from sleep
 * @param sec Number of seconds module stays in sleep, module will automatically wake after this time
 * Note: minimum acceptable time is 3 sec. 
 */
void SM01_Sleep(uint32_t sec);

/**
 * Save the current configurations to flash
 */
void SM01_SaveConfig(void);

/**
 * Load the configurations form flash
 */
void SM01_ReadConfig(void);

/**
 * This function sets custom configuration to be saved on flash.
 * If required, This function should be called only once at application startup.  
 * @param var pointer to custom configuration variable, array or structure
 * @param size size of the configuration variable, array or structure
 */
void SM01_AppConfig(uint8_t* var, uint16_t size);

/**
 * This function sets custom variable to be identified by stack and provide access to SM01 utilities
 * @param var pointer to custom variable, array or structure
 * @param size size of the variable, array or structure
 */
void SM01_AppVariable(uint8_t* var, uint16_t size);

/**
 * Get Device ID of Module
 * @return 32 bit device id 
 */
uint32_t SM01_GetDeviceID(void);

/**
 * This function get the VCC Voltage Levels of MCU
 * @return Voltage Level in milli volts
 */
uint16_t SM01_GetVcc(void);

/**
 * This function gets the Vbat voltage levels (external battery for RTC)
 * Supply Vcc are used to compute accurate Vbat, for this reason it is advisable to call SM01_GetVcc() 
 * to get a updated copy of Vcc internally.
 * @return Voltage Level in milli volts
 */
uint16_t SM01_GetVBat(void);

/**
 * This function gets the MCU Die Temperature
 * Supply Vcc are used to compute accurate Temperature, for this reason it is advisable to call SM01_GetVcc() 
 * to get a updated copy of Vcc internally.
 * @return Temperature in °C
 */
int8_t SM01_GetTemp(void);

/**
 * This function get the number of seconds elapsed since last powerup/rest
 * @return total number of seconds past
 */
uint32_t SM01_UpTime(void);

////////////////////////////////////////////////////////////////////////////////

/**
 * Retrieves the current Tick value, allowing timing and
   measurement code to be written in a non-blocking fashion.  This function
   retrieves the least significant 32 bits of the internal tick counter,
   and is useful for measuring time increments ranging from a few
   microseconds to a few minutes.  
 * @return Lower 32 bits of the current Tick value.
 */
uint32_t Tick(void);

/**
 * Get the total tick counts since last tick
 * @param lastTick Last tick value 
 * @return elapsed ticks since lastTick
 */
uint32_t TickCount(uint32_t lastTick);

/**
 * Compare the time past since last tick (max supported time is about 258 second at clock speed of 16 Mhz)
 * @param lastTick Last tick value 
 * @param msTime time in milli seconds 
 * @return returns true if specified time has been past, otherwise false
 */
bool TickCompare(uint32_t lastTick, uint32_t msTime);

/**
 * Retrieves the current Tick value and compute elapsed milli seconds 
   since lastTick.
 * @param lastTick last tick value to compare with current tick value.
 * @return elapsed milli seconds since lastTick
 */
uint32_t TickElapsed(uint32_t lastTick);

/**
* Wait for the specified time in milli seconds in a blocking loop doing nothing.
* @param msTime Number of milli seconds to wait.
*/
void TickWait(uint32_t msTime);

/**
* Wait for the specified time in micro seconds in a blocking loop doing nothing.
* @param usTime Number of micro seconds to wait.
*/
void TickWait_us(uint32_t usTime);

/**
 * This function get the number of ticks per second. this is typically the same
 * value as the device clock frequency.
 * @return number of ticks per second
 */
uint32_t Tick_sec(void);

////////////////////////////////////////////////////////////////////////////////

/**
 * This function reads current time from RTC clock
 * @return Time structure from RTC clock
 */
TIME RTC_Read(void);

/**
 * This function writes new time to RTC clock.
 * @param time Time structure to write on RTC clock
 */
void RTC_Write(TIME time);

/**
 * This function read coordinated universal time from RTC
 * @return Returns current coordinated universal time
 */
uint32_t RTC_ReadUTC(void);

/**
 * This function writes coordinated universal time to RTC
 * @param time coordinated universal time
 */
void RTC_WriteUTC(uint32_t time);

///////////////////////////////////////////////////////////////////////////////

/**
 * This function reads an array of bytes from the SPI Flash module.
 * @param address Address on flash memory location to start reading from
 * @param data Data array to store data that has been read
 * @param len Length of data to read
 */
void ExFlash_Read(uint32_t address, uint8_t *data, uint16_t len);

/**
 * This function writes an array of bytes to the SPI flash memory.  When the
 * address pointer crosses a sector boundary (and has more data to write),
 * the next sector will automatically be erased.  
 * @param address Address on flash memory location to start write
 * @param data The data array to write to the next memory location
 * @param len The length of the data to be written
 */
void ExFlash_Write(uint32_t address, uint8_t *data, uint16_t len);

///////////////////////////////////////////////////////////////////////////////

#if defined(SM01_WIFI) || defined(SM01_GSM) || defined(SM01_ETH)
/**
 * This function sets the server configuration
 * @param adr address of the ezCom server 
 * @param port port number of the ezCom server
 * @param pid project id for the server
 * @param auth authorization key for the server
 * @return return true if successfully accepted, or false if invalid or wrong parameters 
 */
bool EZCOM_SetServerConfig(const char* adr, uint16_t port, uint32_t pid, const char* auth);
#else
/**
 * This function sets the network security key
 * @param auth authorization key for the server
 * @return return true if successfully accepted, or false if invalid or wrong parameters 
 */
bool EZCOM_SetNetworkKey(const char* auth);

#endif
/**
 * This function set trace option (Reports internal operations on console) 
 * @param  opt Reporting option, 0= disable, 1 = info , 2 = TX/RX, 3 = info + TX/RX
 */
void EZCOM_SetTrace(uint8_t opt);

/**
 * This function set the keep alive time for the connection
 * @param t time in steps of 10 seconds, (1=10 Seconds, 2=20 Seconds and so on,
 * set to 0 for non persistent connection/ or sleeping devices
 */
void EZCOM_KeepAlive(uint8_t t);

/**
 * This function executes internal tasks of stack, in SM01_MODE_AUTO mode this 
 * function is called internally by stack, you should only call this periodically in
 * SM01_MODE_MANUAL mode to keep the stack running
 */
void EZCOM_ProcessTasks(void);

/**
 * This function checks if the device is connected with cloud (EzCom Server) 
 * @return return true if the device is connected with cloud, other wise it returns false.
 */
bool EZCOM_IsConnected(void);

/**
 * This function checks if the ezCom Module is opened
 * @return return true if the module is opened, otherwise it returns false.
 */
bool EZCOM_IsOpened(void);

/**
 * Opens ezCom Module and connect to the cloud (EzCom Server) 
 * This function assign task to establish connection and returns immediately, call EZCOM_IsConnected
 * to check if connection is established.
 * @return returns false if the module is already connected, otherwise returns true
 */
bool EZCOM_Open(void);

/**
 * Subscribe the device to a topic, this should be called once at application startup
 * @param topicID topic id to subscribe
 * @param opt subscribe options
 * @return Returns true if subscribed successfully, or false if failed or reached max subscriptions.
 */
bool EZCOM_Subscribe(uint32_t topicID, uint8_t opt);

/**
 * Send a message string on topic or to a device.
 * @param topic Topic id for the message
 * @param msg message to be sent 
 * @param broadcast true if this message is a broadcast for all subscribed devices 
 * @param qos Required Quality of Service. 0=No acknowledge, 1=Acknowledge by Server,  2=Acknowledge by device
 * @return Returns true if message sent successfully or false if failed
 */
bool EZCOM_Publish(uint32_t topic, char * msg, bool broadcast, uint8_t qos);

/**
 * This function close the ezCom Module
 */
void EZCOM_Close(void);

/**
 * This the the ezcom on recevice call back function, it is called every time 
 * message is received b stack
 * @param deviceid Device id of sender for broadcast or gateway id for indirect 
 * messages or device id of this device in case of direct messages 
 * @param topic Topic id on which message is sent
 * @param msg Message payload
 * @param msglen Message length
 * @return return with true to acknowledge successful reception of message, otherwise false
 */
bool EZCOM_OnReceive(uint32_t deviceid, uint32_t topic, uint8_t* msg, uint16_t msglen);


#if defined(SM01_WIFI) || defined(SM01_GSM) || defined(SM01_ETH)
    /**
     * Set trace options to reports internal operations on console 
     * @param  opt Reporting option, 0= disable, 1 = enable
     */
    void TCP_SetTrace(uint8_t opt);

    /**
     * Process TCP stack internal tasks
     */
    void TCP_ProcessTasks(void);
    /**
     * This function Opens TCP Connection, it is a non blocking function.
     * Connection is opened later by stack tasks, call TCP_IsOpened() 
     * to check connection opening state.  
     * @param host Pointer to host address 
     * @param port TCP port number 
     * @return returns true request is accepted, otherwise false
     */
    bool TCP_Open(const char* host, uint16_t port);

    /**
     * This function checks if the TCP connection is opened
     * @return Returns true if connection is opened, otherwise false
     */
    bool TCP_IsOpened(void);

    /**
     * This function Closes the TCP Connection
     */
    void TCP_Close(void);

    /**
     * This function returns the number of bytes that can be written to TCP Tx buffer
     * @return Returns the number of data bytes free in TCP Tx buffer
     */
    uint16_t TCP_Writable(void);

    /**
     * This function write array of bytes to TCP Tx buffer
     * @param  buf The data array to be written on TCP Tx buffer
     * @param  len The length of data array
     * @return Returns number of bytes actually written 
     */
    uint16_t TCP_Write(const uint8_t* buf, uint16_t len);

    /**
     * This function write string to TCP Tx buffer
     * @param  str The string to be written on TCP Tx buffer
     * @return Returns number of bytes actually written 
     */
    uint16_t TCP_WriteStr(const char* str);

    /**
     * This function write line to TCP Tx buffer (string terminated with CR LF)
     * @param str The string to be written on TCP Tx buffer
     * @return Returns number of bytes actually written 
     */
    uint16_t TCP_WriteLn(const char* str);

    /**
     * This function blocks until all pending bytes to transmit have been sent
     */
    void TCP_Flush(void);

    /**
     * This function returns the number of bytes that can be read from the TCP Rx buffer
     * @return Returns the number of data bytes available in TCP Rx buffer
     */
    uint16_t TCP_Readable(void);

    /**
     * This function reads an array of bytes from the TCP Rx buffer
     * @param buf pointer to destination buffer array
     * @param len array length to read from TCP Rx buffer
     * @return Returns the number of bytes actually read. 
     */
    uint16_t TCP_Read(uint8_t* buf, uint16_t len);

    /**
     * This function reads an array of bytes from the TCP Rx buffer
     * without removing it from there. 
     * @param buf pointer to destination buffer array
     * @param len array length to read from TCP Rx buffer
     * @return Returns the number of bytes actually read. 
     */
    uint16_t TCP_Peek(uint8_t* buf, uint16_t len);

    /**
     * This function finds the given block of bytes in TCP Rx buffer
     * @param buf array of bytes to find match
     * @param len length of array
     * @return Returns the index position in buffer, or 0xFFFF if not found
     */
    uint16_t TCP_Find(const uint8_t* buf, uint16_t len);

    /**
     * This function find for a string in TCP Rx buffer
     * @param str string to search for
     * @return Returns the index position in buffer, or 0xFFFF if not found
     */
    uint16_t TCP_FindStr(const char* str);

#endif


#if defined(SM01_WIFI)
    #if defined(SM01_MODULE_IN_USE)
        #error "only one SM01 module is allowed"
    #else
        #define SM01_MODULE_IN_USE SM01_WIFI

        /**
         * Resets the WiFi Module.
         */
        void WiFi_Reset(void);

        /**
         * Turns ON the WiFi Module
         */
        void WiFi_ON(void);

        /**
         * Turns OFF the WiFi Module
         */
        void WiFi_OFF(void);

        /**
         * Set trace options to reports internal operations on console 
         * @param  opt Reporting option, 0= disable, 1 = info , 2 = WiFi UART, 3 = info + WiFi UART
         */
        void WiFi_SetTrace(uint8_t opt);

        /**
         * Sets WiFi Connection parameters
         * @param ssid SSID of the WiFi network to join
         * @param password wifi password
         * @return return true if successfully accepted, or false if invalid or wrong parameters
         */
        bool WiFi_SetJoinConfig(const char* ssid, const char* password);

        /**
         * Process WiFi stack internal task
         */
        void WiFi_ProcessTasks(void);

        /**
         * This function check if the module is initialised and ready to accept command  
         * @return Returns true if the module is ready, otherwise it returns false.
         */
        bool WiFi_IsReady(void);

        /**
         * This Function connect the module to WiFi network, set in WiFi_SetJoinConfig function
         */
        void WiFi_Connect(void);
        /** 
         * This function check if the module is connected with WiFi network.  
         * @return Returns true if module is connected, otherwise it returns false.
         */
        bool WiFi_IsConnected(void);
        
    #endif
#endif
#if defined(SM01_GSM)
    #if defined(SM01_MODULE_IN_USE)
        #error "only one SM01 module is allowed"
    #else
        #define SM01_MODULE_IN_USE SM01_GSM
        /**
         * Resets the GSM Module.
         */
        void GSM_Reset(void);

        /**
         * Turns ON the GSM Module
         */
        void GSM_ON(void);

        /**
         * Turns OFF the GSM Module
         */
        void GSM_OFF(void);
        /**
         * Set trace options to reports internal operations on console 
         * @param  opt Reporting option, 0= disable, 1 = info , 2 = GSM UART, 3 = info + GSM UART
         */
        void GSM_SetTrace(uint8_t opt);

        /**
         * Sets GSM Connection parameters
         * @param apn APN of the mobile network
         * @return return true if successfully accepted, or false if invalid or wrong parameters
         */
        bool GSM_SetAPN(const char* apn);

        /**
         * Process GSM stack internal task
         */
        void GSM_ProcessTasks(void);
        
        /**
         * This function check if the module is initialised and ready to accept command  
         * @return Returns true if the module is ready, otherwise it returns false.
         */
        bool GSM_IsReady(void);        
        
        /**
         * Send SMS Message
         * @param phone Phone number to send message to
         * @param message message text
         * @return true if accepted or false if not ready to accept
         */
        bool GSM_SendSMS(char *phone, char *message);

        /**
         * Accept Incoming GSM Call
         * @return return true if call is tasked to accept, otherwise returns false 
         */
        bool GSM_AcceptCall(void);

        /**
         * Disconnect A GSM Call
         * @return return true call is tasked to disconnect, otherwise returns false 
         */
        bool GSM_DisconnectCall(void);    
        
        /**
         * Call back function, called on reception of modem ring and called repeatedly on each bell tone
         * until the call is picked up or disconnected    
         * @param cli caller id number
         * @param count counts of rings, this number will be keep increasing until the call is picked up or disconnected   
         */

        void GSM_OnCalling(char* cli, uint8_t count);

        /**
         * Callback function called on reception of SMS 
         * @param phone phone number of the sender
         * @param message received message
         */
        void GSM_OnReceiveSMS(char* phone, char* message);
        
    #endif
#endif
#if defined(SM01_ETH)
    #if defined(SM01_MODULE_IN_USE)
        #error "only one SM01 module is allowed"
    #else
        #define SM01_MODULE_IN_USE SM01_ETH
    #endif
#endif

#if defined(SM01_MESH)
    #if defined(SM01_MODULE_IN_USE)
        #error "only one SM01 module is allowed"
    #else
        #define SM01_MODULE_IN_USE SM01_MESH
    #endif

     /**
     * This function turn on the mesh module
     * @return returns true if success or else false 
     */
    bool Mesh_ON(void);

    /**
     * This function turns off the mesh module
     * @return returns true if success or else false 
     */
    bool Mesh_OFF(void);

    /**
     * This function set trace option (Reports internal operations on console) 
     * @param  opt Reporting option, 0= disable, 1 = info , 2 = TX/RX, 3 = info + TX/RX
     */
    void Mesh_SetTrace(uint8_t opt);
    
    /**
     * This function checks if module powered is ready to use 
     * @return returns true if ready or else false 
     */
    bool Mesh_IsReady(void);
        
    /**
     * This function set the operating channel number for Mesh radio
     * @param channel Channel number from 11 to 25
     * @return true if channel is set successfully, else return false
     */        
    bool Mesh_SetChannel(uint8_t channel);

    /**
     * this function sets the network role of the device 
     * @param role network role (0=End device, 1= coordinator, 2= coordinator capable)
     * @return true if role is set successfully, else return false
     */
    bool Mesh_SetNetworkRole(uint8_t role);    
#endif
    
#if defined(SM01_LORA)
    #if defined(SM01_MODULE_IN_USE)
        #error "only one SM01 module is allowed"
    #else
        #define SM01_MODULE_IN_USE SM01_LORA
    #endif
    /**
     * Resets the LoRa Module.
     */
    void LoRa_Reset(void);

    /**
     * Turns ON the LoRa Module
     */
    void LoRa_ON(void);

    /**
     * Turns OFF the LoRa Module
     */
    void LoRa_OFF(void);

    /**
     * Set trace options to reports internal operations on console 
     * @param  opt Reporting option, 0= disable, 1 = info , 2 = WiFi UART, 3 = info + WiFi UART
     */
    void LoRa_SetTrace(uint8_t opt);
    
    /**
     * Configure LoRa Radio
     * @param freq Frequency of Radio
     * @param bw Bandwidth of radio
     * @param sf spreading factor of radio
     */
    void LoRa_Config(uint32_t freq, uint16_t bw, uint8_t sf);
    
    /**
     * Configure Over the Air activation parameters for LoRaWAN
     * @param devEUI Device EUI
     * @param appEUI Application EUI
     * @param appKey Application Key
     * @return true if successfully accepted, or else return false
     */
    bool LoRaWAN_Config_OTAA(const char* devEUI, const char* appEUI, const char* appKey);

    /**
     * Configure activation by personalization parameters for LoRaWAN
     * @param devAddr Device address
     * @param nwkSKey Network session key
     * @param appSKey Application session key
     * @return 
     */
    bool LoRaWAN_Config_ABP(const char* devAddr, const char* nwkSKey, const char* appSKey);

    /**
     * Send LoraWAN Message
     * @param port Port Number
     * @param data The payload data to be send
     * @param len Length of the payload data
     * @param isCnf True for conformed messages and false for unconfirmed messages
     * @return true if sent successfully or false if failed
     */
    bool LoRaWAN_Send(uint8_t port, uint8_t *data, uint8_t len, bool isCnf);
    
    /**
     * This is a callback function, called when LoRaWAN down-link message is received
     * Received messages are only buffered during transmission inside LoRaWAN_Send function,
     * due to the procedure Gateway delivers all down-link messages followed by an up-link 
     * transmission,this function is only called from inside LoRaWAN_Send function
     * @param port Port number for received message
     * @param data The received payload data 
     * @param len Length of the payload data
     */    
    void LoRaWAN_OnReceive(uint8_t port, uint8_t *data, uint8_t len);
    
#endif

#if !defined(SM01_MODULE_IN_USE) 
    #error "one of the SM01 module must be defined"
#endif
    
#endif	/* SM01_H */

