/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
//#include <B_LED.h>
//#include <G_LED.h>
//#include <R_LED.h>

#include "modbus/include/mb.h"
#include "modbus/include/mbport.h"

#include "fanmotor.h"

/* ----------------------- Defines ------------------------------------------*/

/* ----------------------- Static variables ---------------------------------*/

struct FanMotor m_motor;

extern _Bool YILIDA;//手操器开关 0：关；1：开 --> 波特率：9600   停止位：1    校验位：无

int main()
{
  
    CyGlobalIntDisable;
    
    eMBErrorCode  eStatus;
    
    m_motor.m_initSetttings.m_dryHighPower = 200;
    m_motor.m_motorController.m_nowpower = 100;
    m_motor.m_motorController.m_targetpower = 99;
    m_motor.m_motorController.m_speedFbk = 300;
    m_motor.m_motorController.m_speedRef = 250;
    
    YILIDA = 1;//手操器开关
    
    eStatus = eMBInit( MB_RTU, 0x01, 1, 9600, MB_PAR_NONE );//modbus 初始化

    eStatus = eMBEnable(  );//modbus 开启

    CyGlobalIntEnable;
    for(;;)
    {
        
       eMBPoll(  );//modbus 查询
    }
}


/*****
*数据打包函数
*谨慎改动
******/
eMBErrorCode
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    
    if( (usAddress >= g_mSettingsRegisterAddress) &&
        (usAddress <= g_mPIParaRegisterAddress) )
    {
        switch ( eMode )
        {
            /* Pass current register values to the protocol stack. */
        case MB_REG_READ:
            if( (usAddress == g_mSettingsRegisterAddress) && (usNRegs == g_mSettingsRegisterCount) )
            {               
                USHORT *__pucTempBufer = (USHORT*)&m_motor.m_initSetttings;

                while( usNRegs > 0 ){
                    *pucRegBuffer++ = ( unsigned char )( *__pucTempBufer >> 8 );
                    *pucRegBuffer++ = ( unsigned char )( *__pucTempBufer & 0xFF );
                    __pucTempBufer++;
                    usNRegs--;
                }
            }
            else if( (usAddress == g_mControllerRegisterAddress) && (usNRegs == g_mRatedRegisterCount) )
            {
                USHORT *__pucTempBufer = (USHORT*)&m_motor.m_motorController;
                while( usNRegs > 0 ){
                    *pucRegBuffer++ = ( unsigned char )( *__pucTempBufer >> 8 );
                    *pucRegBuffer++ = ( unsigned char )( *__pucTempBufer & 0xFF );
                    __pucTempBufer++;
                    usNRegs--;
                }
            }
            else if( (usAddress == g_mRealTimeRegisterAddress) && (usNRegs <= g_mRealTimeRegisterMoreCount) )
            {
                USHORT *__pucTempBufer = (USHORT*)&m_motor.m_motorController;
                __pucTempBufer += g_mRatedRegisterCount;
                while( usNRegs > 0 ){
                    *pucRegBuffer++ = ( unsigned char )( *__pucTempBufer >> 8 );
                    *pucRegBuffer++ = ( unsigned char )( *__pucTempBufer & 0xFF );
                    __pucTempBufer++;
                    usNRegs--;
                }
            }
            else if( (usAddress == g_mPIParaRegisterAddress) && (usNRegs <= g_mPIParaRegisterMoreCount) )
            {
                USHORT *__pucTempBufer = (USHORT*)&m_motor.m_PIPara;
                while( usNRegs > 0 ){
                    *pucRegBuffer++ = ( unsigned char )( *__pucTempBufer >> 8 );
                    *pucRegBuffer++ = ( unsigned char )( *__pucTempBufer & 0xFF );
                    __pucTempBufer++;
                    usNRegs--;
                }
            }
            else
                eStatus = MB_ENOREG;
            break;

            /* Update current register values with new values from the
             * protocol stack. */
        case MB_REG_WRITE:
            if( (usAddress == g_mSettingsRegisterAddress) && (usNRegs == g_mSettingsRegisterCount) )
            {
                USHORT *__pucTempBufer = (USHORT*)&m_motor.m_initSetttings;
                while( usNRegs > 0 ){
                    *__pucTempBufer = *pucRegBuffer++ << 8;
                    *__pucTempBufer |= *pucRegBuffer++;
                    __pucTempBufer++;
                    usNRegs--;
                }
            }
            else if( (usAddress == g_mControllerRegisterAddress) && (usNRegs == g_mRatedRegisterCount) )
            {
                USHORT *__pucTempBufer = (USHORT*)&m_motor.m_motorController;
                while( usNRegs > 0 ){
                    *__pucTempBufer = *pucRegBuffer++ << 8;
                    *__pucTempBufer |= *pucRegBuffer++;
                    __pucTempBufer++;
                    usNRegs--;
                }
            }
            else if( (usAddress == g_mRealTimeRegisterAddress) && (usNRegs <= g_mRealTimeRegisterMoreCount) )
            {
                USHORT *__pucTempBufer = (USHORT*)&m_motor.m_motorController;
                __pucTempBufer += g_mRatedRegisterCount << 1;
                while( usNRegs > 0 ){
                    *__pucTempBufer = *pucRegBuffer++ << 8;
                    *__pucTempBufer |= *pucRegBuffer++;
                    __pucTempBufer++;
                    usNRegs--;
                }
            }
            else if( (usAddress == g_mPIParaRegisterAddress) && (usNRegs <= g_mPIParaRegisterMoreCount) )
            {
                USHORT *__pucTempBufer = (USHORT*)&m_motor.m_PIPara;
                while( usNRegs > 0 ){
                    *__pucTempBufer = *pucRegBuffer++ << 8;
                    *__pucTempBufer |= *pucRegBuffer++;
                    __pucTempBufer++;
                    usNRegs--;
                }
            }
            else
                eStatus = MB_ENOREG;
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }
    return eStatus;
}


/* [] END OF FILE */
