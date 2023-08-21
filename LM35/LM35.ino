int LM = A0;// chân analog kết nối cảm biến LM35
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int reading = analogRead(LM);// đọc giá trị từ cảm biến
  float voltage = reading*5.0/1024.0;// tính ra giá trị hiệu điện thế
  float temp = voltage*100.0;// tính ra giá trị độ C
  // cứ mỗi 10mV = 1 độ C
  Serial.println(temp);
}
