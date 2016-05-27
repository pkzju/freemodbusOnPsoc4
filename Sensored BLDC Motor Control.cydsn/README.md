
Two Bug:

@In mbrtu.c
 /* Bug here. I have to add this ++,otherwise modbus will lose one byte when sending */
usSndBufferCount++;

@porttimer.c
/*bug(usTim1Timerout50us*2) here ! I have not find why !if you find fix it!*/
Timer_1_WritePeriod(usTim1Timerout50us*2);//there is bug ,i have to *2,otherwise modbus can not work
Timer_1_WriteCounter(usTim1Timerout50us*2);