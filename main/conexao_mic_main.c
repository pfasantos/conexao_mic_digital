#include <stdio.h>
#include <sys/param.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_system.h"
#include "esp_err.h"
#include "esp_log.h"

// tags
static const char *I2S_TAG = "I2S";
static const char *UDP_TAG = "UDP";
static const char *MAIN_TAG = "MAIN";

#include "driver/i2s_std.h"
#include "driver/gpio.h"

i2s_chan_handle_t rx_handle;

//configuracao do canal i2s

i2s_chan_config_t chan_cfg = {
    .id = I2S_NUM_AUTO,
    .role = I2S_ROLE_MASTER,
    .dma_desc_num = DMA_BUF_NUM,
    .dma_frame_num = DMA_BUF_SIZE,
    .auto_clear = false,
};