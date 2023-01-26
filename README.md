[![WiFi Clock](http://img.youtube.com/vi/7PD3VRXfQwY/0.jpg)](http://www.youtube.com/watch?v=7PD3VRXfQwY "WiFi Clock")

# WiFi Clock
Simple clock that updates via WiFi

## Parts
| Qty | Product                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                | Description               |
|-----|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------|
| 1   | [NodeMCU V3](https://www.aliexpress.us/item/3256804779991845.html?spm=a2g0o.productlist.main.3.6e5brnqlrnqleO&algo_pvid=b0f9d125-4cce-40fa-8514-527170428ee6&aem_p4p_detail=202301261223563746798722575250028718823&algo_exp_id=b0f9d125-4cce-40fa-8514-527170428ee6-1&pdp_ext_f=%7B%22sku_id%22%3A%2212000031182808085%22%7D&pdp_npi=2%40dis%21USD%212.2%212.09%21%21%21%21%21%402145288516747646363254748d0761%2112000031182808085%21sea&curPageLogUid=XRvdpqbiUtEJ&ad_pvid=202301261223563746798722575250028718823_2&ad_pvid=202301261223563746798722575250028718823_2)             | Main board                |
| 1   | [L298N](https://www.aliexpress.us/item/3256804825415910.html?spm=a2g0o.productlist.main.3.7681OsakOsakdC&algo_pvid=9ae4de79-73d8-4f2e-a40c-760ba9710ef8&aem_p4p_detail=202301261230132247250888060360028002644&algo_exp_id=9ae4de79-73d8-4f2e-a40c-760ba9710ef8-1&pdp_ext_f=%7B%22sku_id%22%3A%2212000031338971914%22%7D&pdp_npi=2%40dis%21USD%211.59%211.59%21%21%21%21%21%402100bbf516747650134057318d06fd%2112000031338971914%21sea&curPageLogUid=ejaBBACv1OaR&ad_pvid=202301261230132247250888060360028002644_2&ad_pvid=202301261230132247250888060360028002644_2)                 | L298N driver board module |
| 1   | [Electromagnet 12V](https://www.aliexpress.us/item/2251832127640460.html?spm=a2g0o.productlist.main.37.368aMlJxMlJxH5&algo_pvid=b7623773-26ba-4298-8898-c895f26b4522&algo_exp_id=b7623773-26ba-4298-8898-c895f26b4522-18&pdp_ext_f=%7B%22sku_id%22%3A%2212000015918718401%22%7D&pdp_npi=2%40dis%21USD%211.7%211.36%21%21%21%21%21%402100b1a616747651881395555d06f8%2112000015918718401%21sea&curPageLogUid=fcBeWcOCkWna)                                                                                                                                                               | Electromagnet 12V         |
| 1   | [Ruler](https://www.aliexpress.us/item/3256802623573226.html?spm=a2g0o.productlist.main.1.796cJFO0JFO0lx&algo_pvid=407a828a-df7d-4921-9daa-76dec7d5bce5&aem_p4p_detail=20230126123443349676883300730028862626&algo_exp_id=407a828a-df7d-4921-9daa-76dec7d5bce5-0&pdp_ext_f=%7B%22sku_id%22%3A%2212000030802946792%22%7D&pdp_npi=2%40dis%21USD%214.77%213.48%21%21%21%21%21%402145274c16747652837541409d06ca%2112000030802946792%21sea&curPageLogUid=KPPuRvuILVzc&ad_pvid=20230126123443349676883300730028862626_1&ad_pvid=20230126123443349676883300730028862626_1)                    | Ruler                     |
| 7   | [LEDs](https://www.aliexpress.us/item/3256804184188988.html?spm=a2g0o.productlist.main.21.6f91ZGXqZGXqUn&algo_pvid=f6663761-d0a2-4d7f-b6b3-e627136032a1&aem_p4p_detail=202301261236094597125657810700027955903&algo_exp_id=f6663761-d0a2-4d7f-b6b3-e627136032a1-10&pdp_ext_f=%7B%22sku_id%22%3A%2212000028939119100%22%7D&pdp_npi=2%40dis%21USD%211.75%211.66%21%21%21%21%21%402100bb6416747653696528115d073e%2112000028939119100%21sea&curPageLogUid=qJE75ogEp0Fn&ad_pvid=202301261236094597125657810700027955903_11&ad_pvid=202301261236094597125657810700027955903_11)              | LEDs                      |
| 7   | [Resistors 200 Ohm](https://www.aliexpress.us/item/3256802835223851.html?spm=a2g0o.productlist.main.23.3ce6uEqFuEqFNb&algo_pvid=7a724b68-9337-45f3-9c83-9813b4d41c29&aem_p4p_detail=202301261238523563916723801980028775663&algo_exp_id=7a724b68-9337-45f3-9c83-9813b4d41c29-11&pdp_ext_f=%7B%22sku_id%22%3A%2212000023276985642%22%7D&pdp_npi=2%40dis%21USD%218.86%214.43%21%21%21%21%21%402145280e16747655324424658d0708%2112000023276985642%21sea&curPageLogUid=t9CbGpR7yVmX&ad_pvid=202301261238523563916723801980028775663_12&ad_pvid=202301261238523563916723801980028775663_12) | Resistors 200 Ohm         |
| 1   | [Magnet](https://www.aliexpress.us/item/3256804710180362.html?spm=a2g0o.productlist.main.13.253dx2uLx2uL65&algo_pvid=6a21cb7c-5178-40d8-880e-91a5dbe4a98b&aem_p4p_detail=202301261250042644825492757300028922645&algo_exp_id=6a21cb7c-5178-40d8-880e-91a5dbe4a98b-6&pdp_ext_f=%7B%22sku_id%22%3A%2212000030933122057%22%7D&pdp_npi=2%40dis%21USD%215.11%214.34%21%21%21%21%21%402100b84516747662043786631d0753%2112000030933122057%21sea&curPageLogUid=hEjFt3fcC6gt&ad_pvid=202301261250042644825492757300028922645_7&ad_pvid=202301261250042644825492757300028922645_7)           | Magnet 20mm x 3mm         |

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
