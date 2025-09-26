#include <stdio.h>
#include <sys/param.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_err.h"
#include "esp_log.h"
#include "driver/i2s_pdm.h"
#include "driver/gpio.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "protocol_examples_common.h"

//tags
static const char *I2S_TAG = "I2S";
static const char *UDP_TAG = "UDP";
static const char *MAIN_TAG = "MAIN";

//macros
#define DMA_BUF_NUM 
#define DMA_BUF_SIZE

/****** inicio da configuracao i2s *******/

i2s_chan_handle_t rx_handle; //handler pra canal i2s

i2s_chan_config_t chan_cfg =
{
    .id = I2S_NUM_0,
    .role = I2S_ROLE_MASTER,
    .dma_desc_num = DMA_BUF_NUM,
    .dma_frame_num = DMA_BUF_SIZE,
    .auto_clear = false,
};

i2s_new_channel(&chan_cfg, NULL, &rx_handle); //criar canal i2s

i2s_pdm_rx_gpio_config_t pdm_rx_cfg = 
{
    .clk_cfg = I2S_PDM_RX_CLK_DEFAULT_CONFIG(44100),
    .slot_cfg = I2S_PDM_RX_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO),
    .gpio_cfg =
    {
        .clk = GPIO_NUM_18,
        .din = GPIO_NUM_19,
        .invert_flags =
        {
            .clk_inv = false,
        }
    }
};

i2s_channel_init_pdm_rx_mode(rx_handle, &pdm_rx_cfg);

