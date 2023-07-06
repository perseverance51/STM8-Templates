back to [Wiki](https://github.com/gicking/STM8_templates/wiki)


Project description
=================

连续测量ADC通道0..7，在后台，通过ADC中断，获取ADC结果。

功能:
----------
- 初始化ADC，设置为连续转换模式。
- 附加ADC_EOC中断。
- 在ADC ISR中断扫描各ADC通道。
- 通过UART发送ADC结果。





back to [Wiki](https://github.com/gicking/STM8_templates/wiki)

