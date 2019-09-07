///////////////////////////
//  global delcarations  //
///////////////////////////

#define STM32_board_LED PA1

//Tuning parameters/settings is explained in this video: https://youtu.be/ys-YpOaA2ME
#define variable_1_to_adjust pid_p_gain_roll   
#define variable_2_to_adjust pid_i_gain_roll  
#define variable_3_to_adjust pid_d_gain_roll  

//#define DEBUG                   // to activate debug code
//#define DEBUG_CHG
//#define DEBUG_LOOP
//#define DEBUG_ISR


extern class TwoWire HWire;

extern const uint8_t gyro_address;
extern const uint8_t baro_address;
extern const uint8_t compass_address;

extern float pid_p_gain_roll;
extern float pid_i_gain_roll;
extern float pid_d_gain_roll;
extern int pid_max_roll;

extern float pid_p_gain_pitch;
extern float pid_i_gain_pitch;
extern float pid_d_gain_pitch;
extern int pid_max_pitch;

extern float pid_p_gain_yaw;
extern float pid_i_gain_yaw;
extern float pid_d_gain_yaw; 
extern int pid_max_yaw;
extern float battery_compensation;

extern float pid_p_gain_altitude;
extern float pid_i_gain_altitude; 
extern float pid_d_gain_altitude;
extern int pid_max_altitude;
extern float gps_p_gain; 
extern float gps_d_gain;

extern float declination;

extern int16_t manual_takeoff_throttle;
extern int16_t motor_idle_speed;

extern uint8_t last_channel_1, last_channel_2, last_channel_3, last_channel_4;
extern uint8_t check_byte, flip32, start;
extern uint8_t error, error_counter, error_led;
extern uint8_t flight_mode, flight_mode_counter, flight_mode_led;
extern uint8_t takeoff_detected, manual_altitude_change;
extern uint8_t telemetry_send_byte, telemetry_bit_counter, telemetry_loop_counter;
extern uint8_t channel_select_counter;
extern uint8_t level_calibration_on;

extern uint32_t telemetry_buffer_byte;

extern int16_t esc_1, esc_2, esc_3, esc_4;
extern int16_t manual_throttle;
extern int16_t throttle, takeoff_throttle, cal_int;
extern int16_t temperature, count_var;
extern int16_t acc_x, acc_y, acc_z;
extern int16_t gyro_pitch, gyro_roll, gyro_yaw;

extern int32_t channel_1, channel_1_start, channel_1_base, pid_roll_setpoint_base;
extern int32_t channel_2, channel_2_start, channel_2_base, pid_pitch_setpoint_base;
extern int32_t channel_3, channel_4, channel_5, channel_6, channel_7, channel_8;
extern int32_t channel_3_start,channel_4_start,channel_5_start,channel_6_start,channel_7_start,channel_8_start;
extern int32_t measured_time, measured_time_start, receiver_watchdog;
extern int32_t acc_total_vector, acc_total_vector_at_start;
extern int32_t gyro_roll_cal, gyro_pitch_cal, gyro_yaw_cal;
extern int16_t acc_roll_cal_value;
extern int16_t acc_pitch_cal_value;
extern int32_t acc_z_average_short_total, acc_z_average_long_total, acc_z_average_total ;
extern int16_t acc_z_average_short[26], acc_z_average_long[51];

extern uint8_t acc_z_average_short_rotating_mem_location, acc_z_average_long_rotating_mem_location;

extern int32_t acc_alt_integrated;

extern uint32_t loop_timer, error_timer, flight_mode_timer;
extern uint32_t delay_micros_timer;

extern float roll_level_adjust, pitch_level_adjust;
extern float pid_error_temp;
extern float pid_i_mem_roll, pid_roll_setpoint, gyro_roll_input, pid_output_roll, pid_last_roll_d_error;
extern float pid_i_mem_pitch, pid_pitch_setpoint, gyro_pitch_input, pid_output_pitch, pid_last_pitch_d_error;
extern float pid_i_mem_yaw, pid_yaw_setpoint, gyro_yaw_input, pid_output_yaw, pid_last_yaw_d_error;
extern float angle_roll_acc, angle_pitch_acc, angle_pitch, angle_roll, angle_yaw;
extern float battery_voltage, dummy_float;
extern float low_battery_warning;

//Compass variables
extern uint8_t compass_calibration_on, heading_lock;
extern int16_t compass_x, compass_y, compass_z;
extern int16_t compass_cal_values[6];
extern float compass_x_horizontal, compass_y_horizontal, actual_compass_heading;
extern float compass_scale_y, compass_scale_z;
extern int16_t compass_offset_x, compass_offset_y, compass_offset_z;
extern float course_a, course_b, course_c, base_course_mirrored, actual_course_mirrored;
extern float course_lock_heading, heading_lock_course_deviation;

//Pressure variables.
extern float pid_error_gain_altitude, pid_throttle_gain_altitude;
extern uint16_t C[7];
extern uint8_t barometer_counter, temperature_counter, average_temperature_mem_location;
extern int64_t OFF, OFF_C2, SENS, SENS_C1, P;
extern uint32_t raw_pressure, raw_temperature, temp, raw_temperature_rotating_memory[6], raw_average_temperature_total;
extern float actual_pressure, actual_pressure_slow, actual_pressure_fast, actual_pressure_diff;
extern float ground_pressure, altutude_hold_pressure, return_to_home_decrease;
extern int32_t dT, dT_C5;

//Altitude PID variables
extern float pid_i_mem_altitude, pid_altitude_setpoint, pid_altitude_input, pid_output_altitude, pid_last_altitude_d_error;
extern uint8_t parachute_rotating_mem_location;
extern int32_t parachute_buffer[35], parachute_throttle;
extern float pressure_parachute_previous;
extern int32_t pressure_rotating_mem[50], pressure_total_avarage;
extern uint8_t pressure_rotating_mem_location;
extern float pressure_rotating_mem_actual;

//GPS variables
extern uint8_t read_serial_byte, incomming_message[100], number_used_sats, fix_type;
extern uint8_t waypoint_set, latitude_north, longiude_east ;
extern uint16_t message_counter;
extern int16_t gps_add_counter;
extern int32_t l_lat_gps, l_lon_gps, lat_gps_previous, lon_gps_previous;
extern int32_t lat_gps_actual, lon_gps_actual, l_lat_waypoint, l_lon_waypoint;
extern float gps_pitch_adjust_north, gps_pitch_adjust, gps_roll_adjust_north, gps_roll_adjust;
extern float lat_gps_loop_add, lon_gps_loop_add, lat_gps_add, lon_gps_add;
extern uint8_t new_line_found, new_gps_data_available, new_gps_data_counter;
extern uint8_t gps_rotating_mem_location, return_to_home_step;
extern int32_t gps_lat_total_avarage, gps_lon_total_avarage;
extern int32_t gps_lat_rotating_mem[40], gps_lon_rotating_mem[40];
extern int32_t gps_lat_error, gps_lon_error;
extern int32_t gps_lat_error_previous, gps_lon_error_previous;
extern uint32_t gps_watchdog_timer;

extern float l_lon_gps_float_adjust, l_lat_gps_float_adjust, gps_man_adjust_heading;
extern float return_to_home_lat_factor, return_to_home_lon_factor, return_to_home_move_factor;
extern uint8_t home_point_recorded;
extern int32_t lat_gps_home, lon_gps_home;

//Software Serial data input handling
extern uint8_t si_check_byte;
//uint8_t temp_byte;
extern int8_t si_rising_edge_set;
extern int16_t si_time_array[200];
extern int8_t si_print_flag;
extern uint8_t si_time_array_counter, si_time_array_counter_2, si_received_bytes_counter;
extern uint8_t si_received_bytes[30], si_level, si_byte_counter, new_waypoint_available;
extern int32_t wp_lat_gps, wp_lon_gps;
extern int32_t si_measured_time, si_measured_time_start, si_last_input_change, si_last_input_change_previous;

//Fly waypoints
extern uint8_t fly_to_new_waypoint, fly_to_new_waypoint_step, waypoint_monitor;
extern float fly_to_waypoint_move_factor, fly_to_waypoint_lat_factor, fly_to_waypoint_lon_factor;

//Adjust settings online
extern uint32_t setting_adjust_timer;
extern uint16_t setting_click_counter;
extern uint8_t previous_channel_6;
extern float adjustable_setting_1, adjustable_setting_2, adjustable_setting_3;

//forward declarations
void handler_channel_1(void);
void timer_setup(void);
void read_barometer(void);
void calculate_pid(void);
void calibrate_compass(void); 
void calibrate_level(void);
void change_settings(void);
void gyro_setup(void);
void gyro_signalen(void);
void calibrate_gyro(void);
void red_led(int8_t level);
void green_led(int8_t level);
void blue_led(int8_t level);
void error_signal(void);
void flight_mode_signal(void); 
void read_compass() ;
void setup_compass() ;
void gps_setup(void);
void read_gps(void);
void return_to_home(void);
void send_telemetry_data(void);
void start_stop_takeoff(void);
void vertical_acceleration_calculations(void);
float course_deviation(float course_b, float course_c);
void si_translate_bytes(void);
void Serial_input_handler(void);
void fly_waypoints(void);