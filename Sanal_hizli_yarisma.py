from js import robot
import math

sensor_data = []
sensor_data_gecici = []
index = 0
error = 0
gain = 0.1
Kp = 0.295
Kd = 0.30
Ki = 0.0003
prew_err = 0
prew_sum = []
sum_integral = 10
pid_divider = 0.95
hiz = 1.2
speed_cor = 1.15

def read_line(sd):
    max = sd[0]
    kamera_no = 0
    for m in range(0, len(sd)):
        if sd[m] > max:
            max = sd[m]
            kamera_no = m
    return kamera_no

while robot.is_ok():
    if robot.time() > 0.0 and robot.time() <= 0.85:
        robot.move(15.0)
    else:
        sensor_data = robot.camera_pixel_array()
        index = read_line(sensor_data)
        error = len(sensor_data) / 2 - index
        output = error * Kp + (error - prew_err) * Kd + Ki * sum(prew_sum)
        prew_err = error
        prew_sum.append(error)
        if len(prew_sum) == sum_integral:
            prew_sum.pop(0)
        out_pid = output / pid_divider * (-1)
        left = hiz - out_pid
        right = hiz + out_pid
        robot.move(((left + right)/2) * speed_cor)
        robot.rotate((left - right) * speed_cor)
