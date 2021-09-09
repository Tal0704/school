#include <c8051f340>

void delay_ms(int ms);
void Init_Device();

sbit sw1 = P2 ^ 0;
sbit sw2 = P2 ^ 1;

void main()
{
    char hexCodes[] = {0x7E, 0x30, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};
    sw1 = sw2 = 1;

    while (1)
    {
        if (!sw1)
            // up
            for (int i = 0; i < 9; i++)
            {
                P1 = hexCodes[i];
                delay_ms(500);
            }
        else
        {
            if (sw2)
                // down
                for (int i = 9; i >= 0; i--)
                {
                    P1 = hexCodes[i];
                    delay_ms(500);
                }
            else
                // off
                P1 = 0x00;
        }
    }
}