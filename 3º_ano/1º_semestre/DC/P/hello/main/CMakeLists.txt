idf_component_register(SRCS "aula1_ADC.c"  
                       PRIV_REQUIRES spi_flash esp_driver_gpio esp_driver_ledc esp_adc
                       INCLUDE_DIRS ""
                       )
