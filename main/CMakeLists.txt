idf_component_register(
    SRCS "conexao_mic_main.c"
    INCLUDE_DIRS ""        # Headers locais do main
    REQUIRES esp_driver_i2s freertos log spi_flash
    PRIV_REQUIRES esp_driver_gpio
)
