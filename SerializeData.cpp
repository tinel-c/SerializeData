#include <iostream>
#include "SerializeData.h"

#define DEBUG_PRINT(msg) printf(msg);

union unionConverter32Bit{
    int intType;
    float floatType;
    char charType[4];
};

union unionConverter64Bit{
    double doubleType;
    char charType[8];
};


i2cSerializeData::i2cSerializeData(){ DEBUG_PRINT("there is no default constructor");}

i2cSerializeData::i2cSerializeData(double doubleData)
{
    DEBUG_PRINT("Double constructor triggered ------------------ \n");
    if(sizeof(double) == 8)
    {
        int iCnt = 0;
        unionConverter64Bit unionConvertInstance;
        unionConvertInstance.doubleType = doubleData;
        serializedData = new char(8);
        for(iCnt = 0; iCnt < 8; iCnt++)
        {
            serializedData[iCnt] = unionConvertInstance.charType[iCnt];
        }
        serializedDataLength = 8;
    }
}

i2cSerializeData::i2cSerializeData(float floatData)
{
    DEBUG_PRINT("Float constructor triggered ------------------ \n");
    if(sizeof(float) == 4)
    {
        int iCnt = 0;
        unionConverter32Bit unionConvertInstance;
        unionConvertInstance.floatType = floatData;
        serializedData = new char(4);
        for(iCnt = 0; iCnt < 4; iCnt++)
        {
            serializedData[iCnt] = unionConvertInstance.charType[iCnt];
        }
        serializedDataLength = 4;
    }
}

i2cSerializeData::i2cSerializeData(int intData)
{
    DEBUG_PRINT("Float constructor triggered ------------------ \n");
    if(sizeof(int) == 4)
    {
        int iCnt = 0;
        unionConverter32Bit unionConvertInstance;
        unionConvertInstance.intType = intData;
        serializedData = new char(4);
        for(iCnt = 0; iCnt < 4; iCnt++)
        {
            serializedData[iCnt] = unionConvertInstance.charType[iCnt];
        }
        serializedDataLength = 4;
    }
}

//Distructor
i2cSerializeData::~i2cSerializeData() 
{
    DEBUG_PRINT("Destructor triggered ------------------ \n");
    delete(serializedData);
}

// returns the legth of the array and the array
int i2cSerializeData::getSerializedArray(char *serializedDataArray) 
{
    int iCnt;
    for(iCnt = 0; iCnt < serializedDataLength; iCnt++)
    {
        serializedDataArray[iCnt] = serializedData[iCnt];
    }
    return serializedDataLength;
}
double i2cSerializeData::getDoubleFromSerializedArray(char *serializedDataArray)
{
    unionConverter64Bit unionConvertInstance;
    if(sizeof(double) == 8)
    {
        for(int iCnt = 0; iCnt < 8; iCnt++)
        {
             unionConvertInstance.charType[iCnt] = serializedDataArray[iCnt];
        }
    }
    return unionConvertInstance.doubleType;
}

float i2cSerializeData::getFloatFromSerializedArray(char *serializedDataArray)
{
    unionConverter32Bit unionConvertInstance;
    if(sizeof(float) == 4)
    {
        for(int iCnt = 0; iCnt < 4; iCnt++)
        {
             unionConvertInstance.charType[iCnt] = serializedDataArray[iCnt];
        }
    }
    return unionConvertInstance.floatType;
}

int i2cSerializeData::getIntFromSerializedArray(char *serializedDataArray)
{
    unionConverter32Bit unionConvertInstance;
    if(sizeof(int) == 4)
    {
        for(int iCnt = 0; iCnt < 4; iCnt++)
        {
             unionConvertInstance.charType[iCnt] = serializedDataArray[iCnt];
        }
    }
    return unionConvertInstance.intType;
}

