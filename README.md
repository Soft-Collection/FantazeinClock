[![WiFi Clock](http://img.youtube.com/vi/7PD3VRXfQwY/0.jpg)](http://www.youtube.com/watch?v=7PD3VRXfQwY "WiFi Clock")

# WiFi Clock
Simple clock that updates via WiFi

## Parts
| Qty | Product                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   | Description               |
| --- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------|
|1 | [NodeMCU V3](https://www.aliexpress.us/item/3256804779991845.html?spm=a2g0o.productlist.main.3.6e5brnqlrnqleO&algo_pvid=b0f9d125-4cce-40fa-8514-527170428ee6&aem_p4p_detail=202301261223563746798722575250028718823&algo_exp_id=b0f9d125-4cce-40fa-8514-527170428ee6-1&pdp_ext_f=%7B%22sku_id%22%3A%2212000031182808085%22%7D&pdp_npi=2%40dis%21USD%212.2%212.09%21%21%21%21%21%402145288516747646363254748d0761%2112000031182808085%21sea&curPageLogUid=XRvdpqbiUtEJ&ad_pvid=202301261223563746798722575250028718823_2&ad_pvid=202301261223563746798722575250028718823_2)                                                                                                                                                           | Main board                |
|1 | [TM-1637](https://www.aliexpress.com/item/1005003947103358.html?spm=a2g0o.productlist.main.5.2c1f54efabdjQw&algo_pvid=3a7beeb0-bfc2-45bb-9f4b-5e0a09c89a8d&aem_p4p_detail=202301030955189596255770804560001502397&algo_exp_id=3a7beeb0-bfc2-45bb-9f4b-5e0a09c89a8d-2&pdp_ext_f=%7B%22sku_id%22%3A%2212000027537145198%22%7D&pdp_npi=2%40dis%21ILS%212.51%212.51%21%21%21%21%21%402100b69816727685187147254d0787%2112000027537145198%21sea&curPageLogUid=76aEuJp2I9M5&ad_pvid=202301030955189596255770804560001502397_3&ad_pvid=202301030955189596255770804560001502397_3) | Digital LED Display Module |

## Notes
In the file Config.h you must set:
```
//Your WiFi SSID and Password
#define STASSID "YourSSID"
#define STAPSK  "YourPassword"
```
```
//Your Time Zone
#define MYTZ YourTimeZone
```
[See all time zones here](https://github.com/esp8266/Arduino/blob/master/cores/esp8266/TZ.h)

Set desired **upload_port** in the file **platformio.ini** file.

## Connection Diagram
![Connection Diagram](Images/Connection%20Diagram.png)
