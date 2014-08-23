void setup() {

}

void loop() {

    uint8_t buffer[2];
    
    uint16_t reading = Bean.getAccelerationZ();
    
    buffer[0] = reading & 0xFF;
    buffer[1] = reading >> 8;    

    Bean.setScratchData(1, buffer, 2);

    Bean.sleep(3000);

}
