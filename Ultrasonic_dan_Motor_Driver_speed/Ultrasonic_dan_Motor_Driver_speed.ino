#include <NewPing.h>

#define JARAK_MAKSIMAL 20 // Maksimal JaangkauanJarak

#define T_DEPAN  22  // Hubungkan ke pin TRIGGER 
#define E_DEPAN  23  // Hubungkan ke pin ECHO 
NewPing JARAK_DEPAN(T_DEPAN, E_DEPAN, JARAK_MAKSIMAL); // NewPing setup of pins and maximum distance.

#define T_KANAN_DEPAN  24 // Hubungkan ke pin TRIGGER 
#define E_KANAN_DEPAN  25  // Hubungkan ke pin ECHO 
NewPing JARAK_KANAN_DEPAN(T_KANAN_DEPAN, E_KANAN_DEPAN, JARAK_MAKSIMAL); // NewPing setup of pins and maximum distance.

#define T_KANAN  42 // Hubungkan ke pin TRIGGER 
#define E_KANAN  43  // Hubungkan ke pin ECHO 
NewPing JARAK_KANAN(T_KANAN, E_KANAN, JARAK_MAKSIMAL); // NewPing setup of pins and maximum distance.

#define T_KANAN_BLAKANG  28 // Hubungkan ke pin TRIGGER 
#define E_KANAN_BLAKANG  29  // Hubungkan ke pin ECHO 
NewPing JARAK_KANAN_BLAKANG(T_KANAN_BLAKANG, E_KANAN_BLAKANG, JARAK_MAKSIMAL); // NewPing setup of pins and maximum distance.

#define T_KIRI_DEPAN  34 // Hubungkan ke pin TRIGGER 
#define E_KIRI_DEPAN  35  // Hubungkan ke pin ECHO 
NewPing JARAK_KIRI_DEPAN(T_KIRI_DEPAN, E_KIRI_DEPAN, JARAK_MAKSIMAL); // NewPing setup of pins and maximum distance.

#define T_KIRI  44 // Hubungkan ke pin TRIGGER 
#define E_KIRI  45  // Hubungkan ke pin ECHO 
NewPing JARAK_KIRI(T_KIRI, E_KIRI, JARAK_MAKSIMAL); // NewPing setup of pins and maximum distance.

#define T_KIRI_BLAKANG  46 // Hubungkan ke pin TRIGGER 
#define E_KIRI_BLAKANG  47  // Hubungkan ke pin ECHO 
NewPing JARAK_KIRI_BLAKANG(T_KIRI_BLAKANG, E_KIRI_BLAKANG, JARAK_MAKSIMAL); // NewPing setup of pins and maximum distance.

#define T_BLAKANG  32 // Hubungkan ke pin TRIGGER 
#define E_BLAKANG  33  // Hubungkan ke pin ECHO 
NewPing JARAK_BLAKANG(T_BLAKANG, E_BLAKANG, JARAK_MAKSIMAL); // NewPing setup of pins and maximum distance.


// inialisasi pin untuk motor kanan-kiri
const int motor1 = 2;
const int motor2 = 3;
const int motor3 = 4;
const int motor4 = 5;


// ------ program default/setting awal ------ //
void setup()
{
 // inialisasi status I/O masing2 pin
 pinMode(motor1, OUTPUT);
 pinMode(motor2, OUTPUT);
 pinMode(motor3, OUTPUT);
 pinMode(motor4, OUTPUT);
 Serial.begin(115200);
}
// ----- program utama, looping/berulang terus-menerus ------ //
void loop(){
  BACASENSOR();
}

void BACASENSOR(){
  int SENSOR_DEPAN=JARAK_DEPAN.ping_cm();
  int SENSOR_BLAKANG=JARAK_BLAKANG.ping_cm();
  int SENSOR_KANAN_DEPAN=JARAK_KANAN_DEPAN.ping_cm();
  int SENSOR_KANAN=JARAK_KANAN.ping_cm();
  int SENSOR_KANAN_BLAKANG=JARAK_KANAN_BLAKANG.ping_cm();
  int SENSOR_KIRI_DEPAN=JARAK_KIRI_DEPAN.ping_cm();
  int SENSOR_KIRI=JARAK_KIRI.ping_cm();
  int SENSOR_KIRI_BLAKANG=JARAK_KIRI_BLAKANG.ping_cm();
  
  Serial.print("SENSOR DEPAN:");Serial.print(SENSOR_DEPAN);Serial.print(" | ");Serial.print("SENSOR BLAKANG:");Serial.print(SENSOR_BLAKANG);
  Serial.println();
  Serial.print("SENSOR KANAN DEPAN:");Serial.print(SENSOR_KANAN_DEPAN);Serial.print(" | ");Serial.print("SENSOR KANAN:");Serial.print(SENSOR_KANAN);Serial.print(" | ");Serial.print("SENSOR KANAN BLAKANG:");Serial.print(SENSOR_KANAN_BLAKANG);
  Serial.println();
  Serial.print("SENSOR KIRI DEPAN:");Serial.print(SENSOR_KIRI_DEPAN);Serial.print(" | ");Serial.print("SENSOR KIRI:");Serial.print(SENSOR_KIRI);Serial.print(" | ");Serial.print("SENSOR KIRI BLAKANG:");Serial.print(SENSOR_KIRI_BLAKANG);
  Serial.println();
  //delay(500);
  
  int BATAS_HALANGAN=15; // BATAS JARAK UNTUK SENSOR _ SETTING SESUAI KEINGINAN
  
  if(SENSOR_DEPAN<=BATAS_HALANGAN && SENSOR_DEPAN!=0){
    MUNDUR();
  }
  else if(SENSOR_BLAKANG<=BATAS_HALANGAN && SENSOR_BLAKANG!=0){
    MAJU();
  }
   else if(SENSOR_KANAN<=BATAS_HALANGAN && SENSOR_KANAN!=0){
    KIRI();
  }
  else if(SENSOR_KIRI<=BATAS_HALANGAN && SENSOR_KIRI!=0){
    KANAN();
  }
  else if(SENSOR_KIRI_DEPAN<=BATAS_HALANGAN && SENSOR_KIRI_DEPAN!=0){
    KANAN();
  }
   else if(SENSOR_KIRI_BLAKANG<=BATAS_HALANGAN && SENSOR_KIRI_BLAKANG!=0){
    KANAN();
  }
  else if(SENSOR_KANAN<=BATAS_HALANGAN && SENSOR_KANAN!=0){
    KIRI();
  }
  else if(SENSOR_KANAN_DEPAN<=BATAS_HALANGAN && SENSOR_KANAN_DEPAN!=0){
    KIRI();
  }
   else if(SENSOR_KANAN_BLAKANG<=BATAS_HALANGAN && SENSOR_KANAN_BLAKANG!=0){
    KIRI();
  }else if(SENSOR_DEPAN<=BATAS_HALANGAN && SENSOR_KANAN_DEPAN<=BATAS_HALANGAN && SENSOR_DEPAN!=0 && SENSOR_KANAN_DEPAN!=0){
    KIRI();
  }else if(SENSOR_DEPAN<=BATAS_HALANGAN && SENSOR_KIRI_DEPAN<=BATAS_HALANGAN && SENSOR_DEPAN!=0 && SENSOR_KIRI_DEPAN!=0){
    KANAN();
  }else if(SENSOR_KANAN<=BATAS_HALANGAN && SENSOR_KANAN_DEPAN<=BATAS_HALANGAN && SENSOR_KANAN!=0 && SENSOR_KANAN_DEPAN!=0){
    KIRI();
  }else if(SENSOR_KANAN<=BATAS_HALANGAN && SENSOR_KANAN_BLAKANG<=BATAS_HALANGAN && SENSOR_KANAN!=0 && SENSOR_KANAN_BLAKANG!=0){
    KIRI();
  }else if(SENSOR_KIRI<=BATAS_HALANGAN && SENSOR_KIRI_DEPAN<=BATAS_HALANGAN && SENSOR_KIRI!=0 && SENSOR_KIRI_DEPAN!=0){
    KANAN();
  }else if(SENSOR_KIRI<=BATAS_HALANGAN && SENSOR_KIRI_BLAKANG<=BATAS_HALANGAN && SENSOR_KIRI!=0 && SENSOR_KIRI_BLAKANG!=0){
    KANAN();
  }else if(SENSOR_BLAKANG<=BATAS_HALANGAN && SENSOR_KANAN_BLAKANG<=BATAS_HALANGAN && SENSOR_BLAKANG!=0 && SENSOR_KANAN_BLAKANG!=0){
    KIRI();
  }else if(SENSOR_BLAKANG<=BATAS_HALANGAN && SENSOR_KIRI_BLAKANG<=BATAS_HALANGAN && SENSOR_BLAKANG!=0 && SENSOR_KIRI_BLAKANG!=0){
    KANAN();
  }
  else{
    MAJU();
  }
  

  
  }

void MAJU()
{
 // jalan maju
 digitalWrite(motor1, LOW);
 digitalWrite(motor2, HIGH);
 digitalWrite(motor4, LOW);
 digitalWrite(motor3, HIGH);
}

void MUNDUR()
{
 // jalan maju
 digitalWrite(motor1, HIGH);
 digitalWrite(motor2, LOW);
 digitalWrite(motor4, HIGH);
 digitalWrite(motor3, LOW);
}

void KANAN()
{
 // jalan maju
 digitalWrite(motor1, LOW);
 digitalWrite(motor2, HIGH);
 digitalWrite(motor4, HIGH);
 digitalWrite(motor3, LOW);
}

void KIRI()
{
 // jalan maju
 digitalWrite(motor1, HIGH);
 digitalWrite(motor2, LOW);
 digitalWrite(motor4, LOW);
 digitalWrite(motor3, HIGH);
}

void BERHENTI()
{
 // jalan maju
 digitalWrite(motor1, LOW);
 digitalWrite(motor2, LOW);
 digitalWrite(motor4, LOW);
 digitalWrite(motor3, LOW);
}
