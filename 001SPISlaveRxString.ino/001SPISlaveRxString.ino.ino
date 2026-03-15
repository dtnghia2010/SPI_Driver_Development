#include <SPI.h>
#include <stdint.h>

char dataBuff[500];

void SPI_SlaveInit(void)
{
    pinMode(SCK, INPUT);
    pinMode(MOSI, INPUT);
    pinMode(MISO, OUTPUT);
    pinMode(SS, INPUT);
    SPCR = (1 << SPE);
}

uint8_t SPI_SlaveReceive(void)
{
    while(!(SPSR & (1 << SPIF)));
    return SPDR;
}

void setup()
{
    Serial.begin(9600);
    SPI_SlaveInit();
    Serial.println("Slave Initialized");
}

void loop()
{
    uint8_t dataLen = 0;
    uint32_t i = 0;

    // Wait for SS to go HIGH first (idle state)
    // This ensures we start from a clean state
    while(!digitalRead(SS));

    Serial.println("Slave waiting for ss to go low");

    // Now wait for SS to go LOW (transmission starting)
    while(digitalRead(SS));

    // Receive length byte immediately
    dataLen = SPI_SlaveReceive();

    // Sanity check — length must be reasonable
    if(dataLen == 0 || dataLen > 100)
    {
        Serial.println("Invalid length, ignoring");
        return;
    }

    // Receive data bytes
    for(i = 0; i < dataLen; i++)
    {
        dataBuff[i] = SPI_SlaveReceive();
    }
    dataBuff[i] = '\0';

    // Wait for SS to go HIGH (transmission complete)
    while(!digitalRead(SS));

    // Only print AFTER transmission is fully complete
    Serial.println("Rcvd:");
    Serial.println(dataBuff);
    Serial.print("Length: ");
    Serial.println(dataLen);
}
