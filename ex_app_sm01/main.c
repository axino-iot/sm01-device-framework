#include <xc.h>
#include "sm01_lib/sm01.h"

int main(void)
{
    SM01_Init(SM01_MODULE_IN_USE, SM01_MODE_AUTO);
    
    while(1)
    {
        if(SW_IO == 0)
        {
            if(EZCOM_IsConnected())
            {
                printf("\r\nSending Message to Cloud...");
                if(EZCOM_Publish(3, "Hello from device", false, EZCOM_QOS_1))
                        printf("\r\nMessage Sent!");
                else printf("\r\nMessage Failed!");
            }
            else printf("\r\nCloud is not connected");
            TickWait(500);
            //SM01_Sleep(5);
        }
    }
}

bool EZCOM_OnReceive(uint32_t deviceid, uint32_t topic, uint8_t* msg, uint16_t msglen)
{
    uint16_t i;
    printf("\r\nReceived Message on topic %lu\r\nPayload:", topic);
    
    for(i=0; i<msglen; i++)
        printf("-%x", msg[i]);
    
    return true;
}
