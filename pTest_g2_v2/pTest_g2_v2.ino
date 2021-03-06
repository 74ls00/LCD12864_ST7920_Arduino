#include <U8g2lib.h> //U8g2 2.27.6

#include <Wire.h>
//#include <Time.h>
#include "RTClib.h" //RTClib 1.2.1 https://github.com/adafruit/RTClib

#include "fonts/Fonts.h" 

//U8G2_ST7920_128X64_F_8080 u8g2(U8G2_R0, 5, 6, 7, 8, 9, 10, 11, 12, /*en=*/ 18 /* A4 */, U8X8_PIN_NONE, /*rs=*/ 17 /* A3 */, /*rst=*/ 15 /* A1 */);  // R/W соединить с общим
//U8G2_ST7920_128X64_F_8080 u8g2(U8G2_R0, 12,11,10,9,8,7,6,5, 18,U8X8_PIN_NONE,17,15); // nano
U8G2_ST7920_128X64_F_8080 u8g2(U8G2_R0, 9,8,7,6,5,4,3,2, 16,U8X8_PIN_NONE,17,15); // pro mini

RTC_DS1307 rtc; // "rtc" используется в начале функций, которые прилагаются с библиотекой
//int displayrtc = 1234 ;



 byte  lup = 0; // циклы отрисовки экрана
 
//int val = 0 ;
//float adcv = 0.00 ;
float vmax = 55.0 ; // максимальное напряжение измерения
int vvalue = 0 ;
float vout = 0.0 ;

/* ---------------------------------------------------------------------------------------------- */

void setup(void) {
  u8g2.begin();

pinMode(A0, INPUT);
//analogReference(INTERNAL); // выбираем внутреннее опорное напряжение 1.1В


//1307
//Запуск секундного выхода часов
/*Wire.beginTransmission(0x68);
Wire.write(0x7);
Wire.write(0x10);
Wire.endTransmission();
*/

//rtc.adjust(DateTime(2020, 10, 19,      6, 42,0 )); // задаём год/ месяц/ дата/ часы/ минуты/ секунды


} // End void setup
/* ---------------------------------------------------------------------------------------------- */


void draw(void) {

//debug
// u8g2.setFont(u8x8_font_5x7_r); u8g2.setCursor(0, 10); u8g2.print(lup);
//u8g2.setFont(u8g2_font_micro_mr);  u8g2.drawStr(15,20,lup);
u8g2.setFont(u8g_font_04b_03b);
//u8g2.setFont(u8g2_font_04b_03b_1BB2B29C);


//u8g2.setFont(u8g2_font_04b_03b);

 vvalue = analogRead(A0);
 vout = (vvalue * vmax) / 1024.0 ;
 u8g2.setCursor(0, 10);u8g2.print(vout);

  
  // graphic commands to redraw the complete screen should be placed here  
  //u8g2.setFont(u8g2_font_fur17n); //km/h
  //u8g2.setFont(u8g2_font_10x20_78_79);
 // u8g2.setCursor(45, 17); 
  // call procedure from base class, http://arduino.cc/en/Serial/Print
  //u8g2.print("AaBbCcDdАаБбВвГг");


//region скорость/расход
u8g2.setFont(  u8g2_font_18d  ); // u8g2_font_ncenB18_te
u8g2.setCursor(26, 18); u8g2.print("25.4");  u8g2.print("/"); //km/h   //u8g2.setCursor(45, 18); u8g2.print("25"); //km/h

  float ran1 = random(1,30);
  ran1=ran1*100; ran1= ran1/1000;
  //ran1=tab(ran1/10),1
    // u8g2.setCursor(26, 18); u8g2.print("v:");u8g2.print(ran1); //km/h
       //   u8g2.setCursor(40, 18);u8g2.print(ran1); //km/h
          
         //u8g2.drawStr(40,18,ran1); //km/h
    
 // u8g2.setCursor(45, 40); u8g2.print("f");
 // u8g2.setCursor(45+12, 40); u8g2.print("35"); //w*h/km
    u8g2.setCursor(45, 40); u8g2.print("35"); //w*h/km
  
 // u8g2.drawHLine(74, 9, 11);
  //u8g2.drawHLine(73, 31, 13);  u8g2.drawHLine(79, 26, 1);
  
 // u8g2.setFont(u8g2_font_5x7_tr); 


//u8g2.setFont(u8g2_font_6x10_tf); 
//u8g2.setFont(u8g2_font_siji_t_6x10); 

//u8g2.setCursor(74, 8); u8g2.print("km"); u8g2.setCursor(77, 18); u8g2.print("h");  
//u8g2.setCursor(73, 30); u8g2.print("W"); u8g2.setCursor(81, 30); u8g2.print("h"); u8g2.setCursor(74, 40); u8g2.print("km");
    //u8g2.setCursor(74, 8); u8g2.print("Lx"); u8g2.setCursor(77, 18); u8g2.print("t");  
  //u8g2.setCursor(73, 30); u8g2.print("W"); u8g2.setCursor(81, 30); u8g2.print("h"); u8g2.setCursor(74, 40); u8g2.print("Km");
    //u8g2.setCursor(73, 30); u8g2.print("P"); u8g2.setCursor(81, 30); u8g2.print("t"); u8g2.setCursor(74, 40); u8g2.print("Lx");
//end region скорость/расход


//region батарея
// нижняя, верхняя, левая
u8g2.drawHLine(0, 63,42); u8g2.drawHLine(0, 42, 42); u8g2.drawVLine(0, 42, 21); 
u8g2.drawVLine(46, 49, 8); // плюс, и верхний, и нижний
u8g2.drawHLine(46-5, 49, 5); u8g2.drawHLine(46-5, 56, 5);
u8g2.drawVLine(41, 43, 6); u8g2.drawVLine(41, 43+14, 6); 

//u8g2.setFont(u8g2_font_7x13r); u8g2.setCursor(8, 54); u8g2.print("KMhW");u8g2.print("%");

u8g2.setFont(u8g2_font_7x13B); u8g2.setCursor(8, 54); u8g2.print("200");u8g2.print("%"); //! 15002 48%
//u8g2.setFont(u8g2_font_pxplusibmcga_8u ); u8g2.setCursor(8, 54); u8g2.print("200");u8g2.print("%"); //15536 50%
//u8g2.setFont(u8g2_font_7x13B_tr); u8g2.setCursor(8, 54); u8g2.print("200");u8g2.print("%"); //! 15808 51%
//u8g2.setFont(u8g2_font_7x13B_mr); u8g2.setCursor(8, 54); u8g2.print("200");u8g2.print("%"); //! 16130 52%
//u8g2.setFont(u8g2_font_7x13B_tf); u8g2.setCursor(8, 54); u8g2.print("200");u8g2.print("%"); //! 16986 55%
//u8g2.setFont(u8g2_font_7x13B_mf); u8g2.setCursor(8, 54); u8g2.print("200");u8g2.print("%"); //! 17690 57%



// напряжение и температура батареи
// u8g2_font_04b_03b https://github.com/olikraus/u8g2lib/wiki/fontgroup04
// u8g2_font_orgv01r https://github.com/olikraus/u8g2lib/wiki/fontgrouporgdot
// - u8g2_font_baby v ° https://github.com/olikraus/u8g2lib/wiki/fontgroupfontstruct
//u8g2.setFont(u8g2_font_04b_03b); 
//u8g2.setCursor(3, 61); u8g2.print("52.9");u8g2.print("V");

//!
//u8g2.setFont(u8g2_font_blipfest_07_tr); 
//u8g2.setFont(u8g2_font_trixel_square_tr  ); 
//u8g2.setFont(u8g2_font_trixel_square_tf ); 
u8g2.setFont(u8g_font_04b_03b  );

float ran2 = random(311,611)/1;
// ran2 = ran2 / 10

u8g2.setCursor(3, 61); u8g2.print(ran2); u8g2.print("V");

//u8g2.setCursor(25, 61); u8g2.print("150");u8g2.print("C°");


//if (lup == 1) {


//u8g2.setCursor(25, 61); u8g2.print(ran2);u8g2.print("C°");
//}



//u8g2.setCursor(0, 35); u8g2.print("5W.h/Km");


//region токи
u8g2.setFont(u8g2_font_6x12_tr); 
u8g2.setCursor(58, 52); u8g2.print("20.4");u8g2.print(" A");
u8g2.setCursor(50, 52); u8g2.print("M"); //ток мотора
u8g2.setCursor(58, 61); u8g2.print("3.25");u8g2.print("A");
u8g2.setCursor(50, 61); u8g2.print("E"); //ток электроники
//end region токи




//  u8g2.setFont(u8g2_font_10x20_78_79);
  u8g2.setCursor(0, 35); 
 // u8g2.print("IiJjKkLlMm");
  //u8g2.print("1234567890");
 // u8g2.print("лмнопА");

//  u8g2.setFont(u8g2_font_10x20_78_79);
  // ! u8g2.setCursor(0, 50); 
  //u8g2.print("QqRrSsTtUuVvWw"); 
  //u8g2.print("абвгдеёжзик"); 



// 1307
   DateTime now = rtc.now();

//u8g2.setFont(u8g2_font_chroma48medium8_8u);
u8g2.setFont(u8g2_font_7d); //u8g2_font_blipfest_07_tr

//u8g2.setCursor(110, 62); u8g2.print("2019");
u8g2.setCursor(88, 64); u8g2.print(now.year());
u8g2.setCursor(108, 64); u8g2.print(".");

//u8g2.setCursor(110, 55); u8g2.print("12");
u8g2.setCursor(109, 64); u8g2.print(now.month());
//u8g2.setCursor(95, 28); u8g2.print("23:59:00");


u8g2.setCursor(117, 64); u8g2.print(".");
//u8g2.setCursor(119, 64); u8g2.print("32");
u8g2.setCursor(120, 64); u8g2.print(now.day());

u8g2.setCursor(95, 55); u8g2.print(now.hour()); u8g2.print(":");
//u8g2.setCursor(95, 55); u8g2.print("23");
//u8g2.setCursor(105, 55); 



//u8g2.setCursor(107, 55); 
u8g2.print(now.minute()); 
//u8g2.print("16");

//u8g2.setCursor(117, 55);
u8g2.print(":");
//u8g2.setCursor(119, 55); 
u8g2.print(now.second());


// батарейки СЦ установлены 2020.10.18
   
// end 1307






} // End void draw



/* ---------------------------------------------------------------------------------------------- */

void loop(void) {


  
  // picture loop
  u8g2.firstPage();  
  do {
    draw();
// timertc();
  } while( u8g2.nextPage() );
  
  // rebuild the picture after some delay

lup = lup+1 ;
if (lup > 10) lup = 0;




  
  delay(100);
} //End void loop

/* ---------------------------------------------------------------------------------------------- */
