#include <stdio.h>
#include <iostream>
#include <stdint.h>
using namespace std;

int main()
{

	int yaw;
	float pwm_out;
	float value = 0.0898;  // 1 do thuc te bang bao nhieu so voi pwm

                        // (13 - 5)  / (359 - 270) = 8 / 89 = 0.0898
	while(1)
    {

	cin >> yaw;

        if (yaw > 270 && yaw < 360)
		{
			pwm_out = 5 + (yaw - 270) * value;
		}
		else if ( yaw >= 0 && yaw < 90)
		{
			pwm_out = 13 + (yaw - 0) * value;
		} else
		{
		    pwm_out = 13;
		}

	printf("pwm_out: %f \n", pwm_out);
    }


	return 0;
}
