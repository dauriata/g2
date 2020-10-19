/*
 * settings_workbee1015.h - Workbee 1015 CNC
 */

/***********************************************************************/
/**** Workbee 1000 x 1500 profile ******************************************/
/***********************************************************************/

// ***> NOTE: The init message must be a single line with no CRs or LFs
#define INIT_MESSAGE "Initializing configs to Workbee 1015 profile"

//**** GLOBAL / GENERAL SETTINGS ******************************************************

// Machine configuration settings

#define JUNCTION_INTEGRATION_TIME   0.75                    // cornering - between 0.10 and 2.00 (higher is faster)
#define CHORDAL_TOLERANCE           0.01                    // chordal tolerance for arcs (in mm)

#define SOFT_LIMIT_ENABLE           1                       // 0=off, 1=on
#define HARD_LIMIT_ENABLE           1                       // 0=off, 1=on
#define SAFETY_INTERLOCK_ENABLE     0                       // 0=off, 1=on

#define SPINDLE_ENABLE_POLARITY     1                       // 0=active low, 1=active high
#define SPINDLE_DIR_POLARITY        0                       // 0=clockwise is low, 1=clockwise is high
#define SPINDLE_PAUSE_ON_HOLD       true
#define SPINDLE_DWELL_TIME          1.0

#define COOLANT_MIST_POLARITY       1                       // 0=active low, 1=active high
#define COOLANT_FLOOD_POLARITY      1                       // 0=active low, 1=active high
#define COOLANT_PAUSE_ON_HOLD       false

// Communications and reporting settings

#define USB_SERIAL_PORTS_EXPOSED	1						// 1=single endpoint usb, 2=dual endpoint usb
#define COMM_MODE                   JSON_MODE               // one of: TEXT_MODE, JSON_MODE
#define XIO_ENABLE_FLOW_CONTROL     FLOW_CONTROL_OFF        // FLOW_CONTROL_OFF, FLOW_CONTROL_RTS

#define TEXT_VERBOSITY              TV_VERBOSE              // one of: TV_SILENT, TV_VERBOSE
#define JSON_VERBOSITY              JV_MESSAGES             // one of: JV_SILENT, JV_FOOTER, JV_CONFIGS, JV_MESSAGES, JV_LINENUM, JV_VERBOSE
#define QUEUE_REPORT_VERBOSITY      QR_OFF                  // one of: QR_OFF, QR_SINGLE, QR_TRIPLE

#define STATUS_REPORT_VERBOSITY     SR_FILTERED             // one of: SR_OFF, SR_FILTERED, SR_VERBOSE

#define STATUS_REPORT_MIN_MS        100                     // milliseconds - enforces a viable minimum
#define STATUS_REPORT_INTERVAL_MS   250                     // milliseconds - set $SV=0 to disable

//#define STATUS_REPORT_DEFAULTS "line","posx","posy","posz","posa","feed","vel","unit","coor","dist","admo","frmo","momo","stat"
#define STATUS_REPORT_DEFAULTS "line","posx","posy","posz","feed","vel","momo","stat"

// Alternate SRs that report in drawable units
//#define STATUS_REPORT_DEFAULTS "line","vel","mpox","mpoy","mpoz","mpoa","coor","ofsa","ofsx","ofsy","ofsz","dist","unit","stat","homz","homy","homx","momo"
//#define STATUS_REPORT_DEFAULTS "_ts1","_cs1","_es1","_xs1","_fe1","line","posx","posy","posz","vel","stat"

// Gcode startup defaults
#define GCODE_DEFAULT_UNITS         MILLIMETERS             // MILLIMETERS or INCHES
#define GCODE_DEFAULT_PLANE         CANON_PLANE_XY          // CANON_PLANE_XY, CANON_PLANE_XZ, or CANON_PLANE_YZ
#define GCODE_DEFAULT_COORD_SYSTEM  G54                     // G54, G55, G56, G57, G58 or G59
#define GCODE_DEFAULT_PATH_CONTROL  PATH_CONTINUOUS
#define GCODE_DEFAULT_DISTANCE_MODE ABSOLUTE_DISTANCE_MODE

// *** motor settings ************************************************************************************

#define MOTOR_POWER_MODE            MOTOR_POWERED_IN_CYCLE  // default motor power mode (see cmMotorPowerMode in stepper.h)
#define MOTOR_POWER_TIMEOUT         2.00                    // motor power timeout in seconds

#define M1_MOTOR_MAP                AXIS_X                  // 1ma
#define M1_STEP_ANGLE               1.8                     // 1sa
#define M1_TRAVEL_PER_REV           8.00                    // 1tr
#define M1_MICROSTEPS               8                       // 1mi  1,2,4,8,16,32
#define M1_ENABLE_POLARITY          IO_ACTIVE_HIGH
#define M1_POLARITY                 0                      // 1po  0=normal, 1=reversed
#define M1_POWER_MODE               MOTOR_POWER_MODE        // 1pm  TRUE=low power idle enabled
#define M1_POWER_LEVEL              1.0

#define M2_MOTOR_MAP                AXIS_Y
#define M2_STEP_ANGLE               1.8
#define M2_TRAVEL_PER_REV           8.00
#define M2_MICROSTEPS               8
#define M2_ENABLE_POLARITY          IO_ACTIVE_HIGH
#define M2_POLARITY                 1
#define M2_POWER_MODE               MOTOR_POWER_MODE
#define M2_POWER_LEVEL              1.0

#define M3_MOTOR_MAP                AXIS_Y
#define M3_STEP_ANGLE               1.8
#define M3_TRAVEL_PER_REV           8.00
#define M3_MICROSTEPS               8
#define M3_ENABLE_POLARITY          IO_ACTIVE_HIGH
#define M3_POLARITY                 1
#define M3_POWER_MODE               MOTOR_POWER_MODE
#define M3_POWER_LEVEL              1.0

#define M4_MOTOR_MAP                AXIS_Z
#define M4_STEP_ANGLE               1.8
#define M4_TRAVEL_PER_REV           8.00
#define M4_MICROSTEPS               8
#define M4_ENABLE_POLARITY          IO_ACTIVE_HIGH
#define M4_POLARITY                 0
#define M4_POWER_MODE               MOTOR_POWER_MODE
#define M4_POWER_LEVEL              1.0

// *** axis settings **********************************************************************************

#define JERK_MAX                    500                     // mm/min^3 * 1,000,000
#define JERK_HOMING                 2000                    // mm/min^3 * 1,000,000
#define VELOCITY_MAX                3000                    // mm/min
#define SEARCH_VELOCITY 			1000

#define X_AXIS_MODE                 AXIS_STANDARD           // xam  see canonical_machine.h cmAxisMode for valid values
#define X_VELOCITY_MAX              VELOCITY_MAX            // xvm  G0 max velocity in mm/min
#define X_FEEDRATE_MAX              X_VELOCITY_MAX          // xfr  G1 max feed rate in mm/min
#define X_TRAVEL_MIN                0                       // xtn  minimum travel for soft limits
#define X_TRAVEL_MAX                820                     // xtm  travel between switches or crashes
#define X_JERK_MAX                  JERK_MAX                // xjm  jerk * 1,000,000  mm/min^3
#define X_JERK_HIGH_SPEED           JERK_HOMING             // xjh
#define X_HOMING_INPUT              1                       // xhi  input used for homing or 0 to disable
#define X_HOMING_DIRECTION          0                       // xhd  0=search moves negative, 1= search moves positive
#define X_SEARCH_VELOCITY           SEARCH_VELOCITY         // xsv  minus means move to minimum switch
#define X_LATCH_VELOCITY            100                     // xlv  mm/min
#define X_LATCH_BACKOFF             5                       // xlb  mm
#define X_ZERO_BACKOFF              3                       // xzb  mm

#define Y_AXIS_MODE                 AXIS_STANDARD
#define Y_VELOCITY_MAX              VELOCITY_MAX
#define Y_FEEDRATE_MAX              Y_VELOCITY_MAX
#define Y_TRAVEL_MIN                0
#define Y_TRAVEL_MAX                1230
#define Y_JERK_MAX                  JERK_MAX
#define Y_JERK_HIGH_SPEED           JERK_HOMING
#define Y_HOMING_INPUT              3
#define Y_HOMING_DIRECTION          0
#define Y_SEARCH_VELOCITY           SEARCH_VELOCITY
#define Y_LATCH_VELOCITY            100
#define Y_LATCH_BACKOFF             5
#define Y_ZERO_BACKOFF              3

#define Z_AXIS_MODE                 AXIS_STANDARD
#define Z_VELOCITY_MAX              1500
#define Z_FEEDRATE_MAX              Z_VELOCITY_MAX
#define Z_TRAVEL_MAX                0
#define Z_TRAVEL_MIN                -146
#define Z_JERK_MAX                  500
#define Z_JERK_HIGH_SPEED           JERK_HOMING
#define Z_HOMING_INPUT              5
#define Z_HOMING_DIRECTION          1
#define Z_SEARCH_VELOCITY           SEARCH_VELOCITY
#define Z_LATCH_VELOCITY            100
#define Z_LATCH_BACKOFF             5
#define Z_ZERO_BACKOFF              3

//*** Input / output settings ***
/*
    IO_MODE_DISABLED
    IO_ACTIVE_LOW    aka NORMALLY_OPEN
    IO_ACTIVE_HIGH   aka NORMALLY_CLOSED

    INPUT_ACTION_NONE
    INPUT_ACTION_STOP
    INPUT_ACTION_FAST_STOP
    INPUT_ACTION_HALT
    INPUT_ACTION_RESET

    INPUT_FUNCTION_NONE
    INPUT_FUNCTION_LIMIT
    INPUT_FUNCTION_INTERLOCK
    INPUT_FUNCTION_SHUTDOWN
    INPUT_FUNCTION_PANIC
*/
// Xmin on v9 board
#define DI1_MODE                    NORMALLY_CLOSED
// #define DI1_ACTION                  INPUT_ACTION_NONE
#define DI1_ACTION                  INPUT_ACTION_STOP
#define DI1_FUNCTION                INPUT_FUNCTION_LIMIT

// Xmax
#define DI2_MODE                    NORMALLY_CLOSED
// #define DI2_ACTION                  INPUT_ACTION_NONE
#define DI2_ACTION                  INPUT_ACTION_STOP
#define DI2_FUNCTION                INPUT_FUNCTION_LIMIT

// Ymin
#define DI3_MODE                    NORMALLY_CLOSED
// #define DI3_ACTION                  INPUT_ACTION_NONE
#define DI3_ACTION                  INPUT_ACTION_STOP
#define DI3_FUNCTION                INPUT_FUNCTION_LIMIT

// Ymax
#define DI4_MODE                    NORMALLY_CLOSED
// #define DI4_ACTION                  INPUT_ACTION_NONE
#define DI4_ACTION                  INPUT_ACTION_STOP
#define DI4_FUNCTION                INPUT_FUNCTION_LIMIT

// Zmax
#define DI5_MODE                    NORMALLY_CLOSED
// #define DI5_ACTION                  INPUT_ACTION_NONE
#define DI5_ACTION                  INPUT_ACTION_STOP
#define DI5_FUNCTION                INPUT_FUNCTION_LIMIT

// Zmin Z probe
#define DI6_MODE                    NORMALLY_OPEN
#define DI6_ACTION                  INPUT_ACTION_NONE
#define DI6_FUNCTION                INPUT_FUNCTION_PROBE

// FeedHold input
#define DI7_MODE                    NORMALLY_CLOSED
#define DI7_ACTION                  INPUT_ACTION_STOP
#define DI7_FUNCTION                INPUT_FUNCTION_NONE

// Fast FeedHold input
#define DI8_MODE                    NORMALLY_OPEN
#define DI8_ACTION                  INPUT_ACTION_FAST_STOP
#define DI8_FUNCTION                INPUT_FUNCTION_NONE

