#include <iostream>
#include "SerializeData.h"

#define DEBUG_PRINT(msg) printf(msg);

int main() {
    int iCnt; //counter to display data 
    int serializedDataLength; // length of the array that will be sent on i2c
    double testDouble = 1.3213; // test data double
    float  testFloat = -3.5476; // test data float
    int    testInt = 255; // test data int
    char serializedDataArray[8]; // array to hold the data for the i2c
    
    // create a instance of the doubleSerializer
    i2cSerializeData doubleSerializer = i2cSerializeData(testDouble);
    
    // check the lenght of the double on this machinee
    std::cout << "Size of double: " << sizeof(double) << std::endl;
    
    // test to show that data has been transfered correctly
    printf("Initial data to be transported: %f\n",testDouble);
    serializedDataLength = doubleSerializer.getSerializedArray(serializedDataArray);
    printf("Size detected by serializer: %d\n",serializedDataLength);
    
    for(iCnt = 0; iCnt<serializedDataLength; iCnt++)
    {
        printf("0x%x, ",serializedDataArray[iCnt]&0xff);    
    }
    printf("\n%f\n",doubleSerializer.getDoubleFromSerializedArray(serializedDataArray));
    
    // create a instance of the floatSerializer
    i2cSerializeData floatSerializer = i2cSerializeData(testFloat);
    
    // check the lenght of the float on this machine
    std::cout << "Size of float: " << sizeof(float) << std::endl;
    
    // test to show that data has been transfered correctly
    printf("Initial data to be transported: %f\n",testFloat);
    serializedDataLength = floatSerializer.getSerializedArray(serializedDataArray);
    printf("Size detected by serializer: %d\n",serializedDataLength);
    
    for(iCnt = 0; iCnt<serializedDataLength; iCnt++)
    {
        printf("0x%x, ",serializedDataArray[iCnt]&0xff);    
    }
    printf("\n%f\n",floatSerializer.getFloatFromSerializedArray(serializedDataArray));
    
    // create a instance of the intSerializer
    i2cSerializeData intSerializer = i2cSerializeData(testInt);
    
    // check the lenght of the float on this machine
    std::cout << "Size of int: " << sizeof(int) << std::endl;
    
    // test to show that data has been transfered correctly
    printf("Initial data to be transported: %d\n",testInt);
    serializedDataLength = intSerializer.getSerializedArray(serializedDataArray);
    printf("Size detected by serializer: %d\n",serializedDataLength);
    
    for(iCnt = 0; iCnt<serializedDataLength; iCnt++)
    {
        printf("0x%x, ",serializedDataArray[iCnt]&0xff);    
    }
    printf("\n%d\n",intSerializer.getIntFromSerializedArray(serializedDataArray));
}

