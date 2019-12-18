


#include "U8glib.h"
U8GLIB_ST7920_128X64_4X u8g(10);



void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  //u8g.setFont(u8g_font_fur17n); //km/h
  //u8g.setFont(u8g_font_10x20_78_79);
 // u8g.setPrintPos(45, 17); 
  // call procedure from base class, http://arduino.cc/en/Serial/Print
  //u8g.print("AaBbCcDdАаБбВвГг");

  //u8g.setFont(u8g_font_fur17n); 
    u8g.setFont(u8g_font_ncenR18); 


  //u8g.setPrintPos(45, 18); u8g.print("25"); //km/h
  //u8g.setPrintPos(26, 18); u8g.print("25.4"); //km/h

  float ran1= random(1,30);
  ran1=ran1*100; ran1= ran1/1000;
  //ran1=tab(ran1/10),1
     u8g.setPrintPos(26, 18); u8g.print(ran1); //km/h
    
  u8g.setPrintPos(45, 40); u8g.print("35"); //w*h/km
  u8g.drawHLine(74, 9, 11);
  u8g.drawHLine(73, 31, 13);  u8g.drawHLine(79, 26, 1);
  u8g.setFont(u8g_font_6x10); 
  //u8g.setPrintPos(74, 8); u8g.print("Km"); u8g.setPrintPos(77, 18); u8g.print("h");  
    u8g.setPrintPos(74, 8); u8g.print("Lx"); u8g.setPrintPos(77, 18); u8g.print("t");  
  //u8g.setPrintPos(73, 30); u8g.print("W"); u8g.setPrintPos(81, 30); u8g.print("h"); u8g.setPrintPos(74, 40); u8g.print("Km");
    u8g.setPrintPos(73, 30); u8g.print("P"); u8g.setPrintPos(81, 30); u8g.print("t"); u8g.setPrintPos(74, 40); u8g.print("Lx");


// нижняя, верхняя, левая
u8g.drawHLine(0, 63,42); u8g.drawHLine(0, 42, 42); u8g.drawVLine(0, 42, 21); 
u8g.drawVLine(46, 49, 8); // плюс, и верхний, и нижний
u8g.drawHLine(46-5, 49, 5); u8g.drawHLine(46-5, 56, 5);
u8g.drawVLine(41, 43, 6); u8g.drawVLine(41, 43+14, 6); 

//u8g.setFont(u8g_font_7x13r); u8g.setPrintPos(8, 54); u8g.print("KMhW");u8g.print("%");
u8g.setFont(u8g_font_7x13Br); u8g.setPrintPos(8, 54); u8g.print("200");u8g.print("%");

u8g.setFont(u8g_font_04b_03b); 
u8g.setPrintPos(3, 61); u8g.print("52.1");u8g.print("v");

//u8g.setPrintPos(25, 61); u8g.print("50");u8g.print("C°");
u8g.setPrintPos(25, 61); u8g.print(random(30,60));u8g.print("C°");

//u8g.setPrintPos(0, 35); u8g.print("5W.h/Km");



u8g.setFont(u8g_font_6x12); 
u8g.setPrintPos(58, 52); u8g.print("20.4");u8g.print(" A");
u8g.setPrintPos(50, 52); u8g.print("M");
u8g.setPrintPos(58, 61); u8g.print("3.25");u8g.print("A");
u8g.setPrintPos(50, 61); u8g.print("E");






  u8g.setFont(u8g_font_10x20_78_79);
  u8g.setPrintPos(0, 35); 
 // u8g.print("IiJjKkLlMm");
  //u8g.print("1234567890");
 // u8g.print("лмнопА");

  u8g.setFont(u8g_font_10x20_78_79);
  u8g.setPrintPos(0, 50); 
  //u8g.print("QqRrSsTtUuVvWw"); 
  //u8g.print("абвгдеёжзик"); 

}


void setup(void) {
  // flip screen, if required
  // u8g.setRot180();
}

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(300);
}
