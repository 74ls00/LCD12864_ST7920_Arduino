rem example
rem bdfconv_2_22.exe -v -f 1 -m "32-127" ../bdf/helvB18.bdf -o helvb18_tf.c  -n u8g2_font_helvB18_tf -d ../bdf/helvB18.bdf
rem type helvb18_tf.c
cls

set "bdfconv_2_22=G:\home\Documents\Projects\0-Electronics\E-bike\0-Display\u8g2\tools\font\bdfconv\bdfconv_2_22.exe"

rem set font_name=u8g2_font_18d
rem set font_name=u8g2_font_7d
rem set font_name=u8g_font_04b_03b
 set font_name=u8g2_font_7x13B



set "file_c=G:\home\Documents\Projects\0-Electronics\E-bike\0-Display\LCD12864_ST7920_u8g2\pTest_g2_v2\font_arduino-1.8.13p\%font_name%.c"

rem set "font_bdf=G:\home\Documents\Projects\0-Electronics\E-bike\0-Display\LCD12864_ST7920_u8g2\pTest_g2_v2\font_arduino-1.8.13p\ncenB18m.bdf"
rem set "font_bdf=G:\home\Documents\Projects\0-Electronics\E-bike\0-Display\LCD12864_ST7920_u8g2\pTest_g2_v2\font_arduino-1.8.13p\u8g2_font_7d.bdf"
set "font_bdf=G:\home\Documents\Projects\0-Electronics\E-bike\0-Display\LCD12864_ST7920_u8g2\pTest_g2_v2\font_arduino-1.8.13p\%font_name%.bdf"


del "%file_c%"


rem 46-102
rem %bdfconv_2_22% -v -f 1 -m "46-58" %font_bdf% -o %file_c%  -n %font_name%
rem u8g_font_04b_03b 46-86 
rem u8g2_font_7x13B num % 25-39 37-57
%bdfconv_2_22% -v -f 1 -m "37-57" %font_bdf% -o %file_c%  -n %font_name%


rem pause

rem set "file_c=G:\home\Documents\Projects\0-Electronics\E-bike\0-Display\LCD12864_ST7920_u8g2\pTest_g2\font\helvb18_tf.c"


rem bdfconv_2_22.exe -v -f 1 -m "32-127" ../bdf/helvB18.bdf -o helvb18_tf.c  -n u8g2_font_helvB18_tf -d ../bdf/helvB18.bdf
