classdef bladerf
    properties (Constant = true)
    FORMAT_SC16_Q12 = 0;
       
    ERR_UNEXPECTED = -1;
    ERR_RANGE = -2;
    ERR_INVAL = -3;
    ERR_MEM = -4;
    ERR_IO = -5;
    ERR_TIMEOUT = -6;
    ERR_NODEV = -7;
    ERR_UNSUPPORTED = -8;
    ERR_MISALIGNED = -9;

    BACKEND_ANY = 0;
    BACKEND_LINUX = 1;
    BACKEND_LIBUSB =2;

    DEVICE_SPEED_UNKNOWN = 0;
    DEVICE_SPEED_HIGH = 1;
    DEVICE_SPEED_SUPER = 2;

    SERIAL_LENGTH = 33;

    FPGA_UNKNOWN = 0;
    FPGA_40KLE = 40;
    FPGA_115KLE = 115;

    SAMPLING_UNKNOWN = 0;
    SAMPLING_INTERNAL = 1;
    SAMPLING_EXTERNAL = 2;

    LNA_GAIN_UNKNOWN = 0;
    LNA_GAIN_BYPASS = 1;
    LNA_GAIN_MID = 2;
    LNA_GAIN_MAX = 3;

    LPF_NORMAL = 0;
    LPF_BYPASSED = 1;
    LPF_DISABLED = 2;

    MODULE_RX = 0;
    MODULE_TX = 1;

    DC_CAL_LPF_TUNING = 0;
    DC_CAL_TX_LPF = 1;
    DC_CAL_RX_LPF = 2;
    DC_CAL_RXVGA2 = 3;

    LB_BB_LPF = 0;
    LB_BB_VGA2 = 1;
    LB_BB_OP = 2;
    LB_RF_LNA_START = 3;
    LB_RF_LNA1 = 4;
    LB_RF_LNA2 = 5;
    LB_RF_LNA3 = 6;
    LB_NONE = 7;

    LOG_LEVEL_VERBOSE = 0;
    LOG_LEVEL_DEBUG = 1;
    LOG_LEVEL_INFO = 2;
    LOG_LEVEL_WARNING = 3;
    LOG_LEVEL_ERROR = 4;
    LOG_LEVEL_CRITICAL = 5;

    end
end
