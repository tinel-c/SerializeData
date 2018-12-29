#ifndef SerializeData_h
#define SerializeData_h


class i2cSerializeData {
    private:
    char *serializedData;
    char serializedDataLength;
    public:
    //Constructor
    i2cSerializeData();
    i2cSerializeData(double doubleData);
    i2cSerializeData(float floatData);
    i2cSerializeData(int intData);
    //Distructor
    ~i2cSerializeData();
    // returns the legth of the array and the array
    int getSerializedArray(char *serializedDataArray);
    double getDoubleFromSerializedArray(char *serializedDataArray);
    float getFloatFromSerializedArray(char *serializedDataArray);
    int getIntFromSerializedArray(char *serializedDataArray);
};


#endif
