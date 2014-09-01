uint16_t THRESHOLD = 20;

AccelerationReading previousReading = {0, 0, 0};
AccelerationReading currentReading = {0, 0, 0};

uint8_t logBuffer[1];

void setup() {

}

void loop() {

    clearLog();

    if(hasMoved()) {
        logMotion();
        Bean.sleep(7200000);
    }

    Bean.sleep(1000);

}


boolean hasMoved() {

    previousReading = currentReading;
    currentReading = Bean.getAcceleration();

    uint16_t xDiff = abs(previousReading.xAxis - currentReading.xAxis);
    uint16_t yDiff = abs(previousReading.yAxis - currentReading.yAxis);
    uint16_t zDiff = abs(previousReading.zAxis - currentReading.zAxis);

    return xDiff > THRESHOLD || yDiff > THRESHOLD || zDiff > THRESHOLD;

}


void logMotion() {

    logBuffer[0] = 1;
    Bean.setScratchData(1, logBuffer, 1);

}


void clearLog() {

    logBuffer[0] = 0;
    Bean.setScratchData(1, logBuffer, 1);

}
