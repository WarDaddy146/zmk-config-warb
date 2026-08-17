#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <lvgl.h>

static const struct device *mpu_dev;

lv_obj_t *zmk_display_status_screen(void) {
    mpu_dev = DEVICE_DT_GET(DT_NODELABEL(mpu6050));

    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_t *label = lv_label_create(screen);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    if (mpu_dev && device_is_ready(mpu_dev)) {
        lv_label_set_text(label, "MPU6050\nONLINE");
    } else {
        lv_label_set_text(label, "MPU6050\nOFFLINE");
    }

    return screen;
}