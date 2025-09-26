idf_component_register(
    SRCS "conexao_mic_main.c"
    INCLUDE_DIRS "."
    REQUIRES
        driver
        freertos
        esp_system
        esp_event
        esp_netif
        nvs_flash
        lwip
        protocol_examples_common
)
