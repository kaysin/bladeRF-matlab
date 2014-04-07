BLADERF_PATH = 'C:\Program Files (x86)\bladeRF\'

ARCH='x86';
if (strcmp(computer('arch'), 'win64'))
    ARCH='x64';
end
ARCH
src = { ...
'calibrate_dc', 'close', 'enable_module', 'fw_version', 'get_bandwidth', 'get_frequency', ...
'get_lna_gain', 'get_lpf_mode', 'get_rxvga1', 'get_rxvga2', 'get_sampling', 'get_txvga1', ...
'get_txvga2', 'load_fpga', 'open', 'rx', 'select_band', 'set_bandwidth', ...
'set_frequency', 'set_lna_gain', 'set_loopback', 'set_lpf_mode', 'set_rxvga1', ...
'set_rxvga2', 'set_sample_rate', 'set_sampling', 'set_txvga1', 'set_txvga2' };

for i = 1:size(src,2),
    eval(sprintf('mex bladerf_%s.c -I''%s\\include'' -Iinclude -L''%s\\lib\\%s'' -L''%s\\%s'' -lbladeRF', char(src(i)), BLADERF_PATH, BLADERF_PATH, ARCH, BLADERF_PATH, ARCH))
end
