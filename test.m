[a,b] = bladerf_open()
[q,w,e,r] = bladerf_fw_version(b)
[g,h] = bladerf_rx(b, bladerf.FORMAT_SC16_Q12, 1024*16)
plot(h(:,1)+j*h(:,2))
bladerf_close(b)