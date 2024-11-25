#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define led 2

uint8_t led_level = 0;

esp_err_t init_led(void);
esp_err_t blink_led(void);

void app_main(void)
{
    init_led();

    while(1){

        vTaskDelay(200/portTICK_PERIOD_MS);
        blink_led();
        printf("Led level: %u\n", led_level);
        
    }
}

esp_err_t init_led(){
    gpio_reset_pin(led);
    gpio_set_direction(led,GPIO_MODE_OUTPUT);
    return ESP_OK;
}

esp_err_t blink_led(){
    led_level = !led_level;
    gpio_set_level(led,led_level);
    return ESP_OK;
}