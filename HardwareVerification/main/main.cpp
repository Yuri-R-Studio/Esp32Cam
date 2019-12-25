
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <string>
#include <sstream>
#include <esp_attr.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <chrono>
#include <memory>
#include <string>
#include <sstream>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#include "Hardware.h"
#include "Tests.h"
#include "Logger.h"
#include "Rng.h"
#include "CircularBuffer.h"
#include <cstring>

void executetMenu(char Test)
{
	switch (Test)
	{

	case 't':
	case 'T':
		ToggleFlashLed();
		break;
	case 'r':
	case 'R':
		SoftwareResetTest();
		break;
	case 'f':
	case 'F':
		PutCpuToSleep();
		break;
	case 'c':
	case 'C':
		TestSpiffs();
		break;
		break;
	case 'z':
	case 'Z':
		TestSdCard();
		break;
	default:
		break;
	}

	printf("\n");
	printf("Main menu:\n");
	printf("----------\n");
	printf("[T] - Toggle Flash Led\n");
	printf("[R] - Software Reset Test\n");
	printf("[F] - Deep Sleep for 5 Seconds.\n");
	printf("[C] - Test SPIFFS\n");
	printf("[Z] - Test SdCard\n");
}

extern "C" void app_main(void)
{
	Hal::Hardware::Instance();
	printf("\n");
	printf("Hardware Verification for ESP32\n");
	printf("\n");
 
	char test = 0;
	
	while (1)
	{
		executetMenu(test);
		test = 0;
		while (test == 0)
		{
			scanf("%c", &test);
			vTaskDelay(10);
		}
	}
}
