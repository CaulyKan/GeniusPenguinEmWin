#pragma once

// ����ֱ���޸ĸñ���, �����޸������SetOriginalMotorSpeed()
extern int iOriginalMotorSpeed;
extern int iMotorSpeedIncrement;

void SetOriginalMotorSpeed(int speed);
void DecreaseOriginalMotorSpeed();
void IncreaseOriginalMotorSpeed();