const int buzzer = 9;
unsigned long startTime;                 // 按鈕被按下的起始時間

unsigned long duration;                  // 持續時間

 

const int toneTable[7][5]={

    { 66, 131, 262, 523, 1046},  // C Do

    { 74, 147, 294, 587, 1175},  // D Re

    { 83, 165, 330, 659, 1318},  // E Mi

    { 88, 175, 349, 698, 1397},  // F Fa

    { 98, 196, 392, 784, 1568},  // G So

    {110, 220, 440, 880, 1760},  // A La

    {124, 247, 494, 988, 1976}   // B Si

};

char toneName[]="CDEFGAB";

char beeTone[]="GEEFDDCDEFGGGGEEFDDCEGGEDDDDDEFEEEEEFGGEEFDDCEGGC";

char starTone[]="CCGGAAGFFEEDDCGGFFEEDGGFFEEDCCGGAAGFFEEDDC";

int beeBeat[]={

    1,1,2, 1,1,2, 1,1,1,1,1,1,2,

    1,1,2, 1,1,2, 1,1,1,1,4,

    1,1,1,1,1,1,2, 1,1,1,1,1,1,2,

    1,1,2, 1,1,2, 1,1,1,1,4

};

int starBeat[]={

    1,1,1,1,1,1,2, 1,1,1,1,1,1,2,

    1,1,1,1,1,1,2, 1,1,1,1,1,1,2,

    1,1,1,1,1,1,2, 1,1,1,1,1,1,2

};

 

int getTone(char symbol) {

    int toneNo = 0;

    for ( int ii=0; ii<7; ii++ ) {

        if ( toneName[ii]==symbol ) {

            toneNo = ii;

            break;

        }

    }

    return toneNo;

}

 

void setup() {

    pinMode(buzzer,OUTPUT);

    noTone(buzzer);

  Serial.begin(9600);                    // 開啟 Serial port, 通訊速率為 9600 bps

  Serial.println("Press and release button now");

}

 

void loop() {

    int ii, length, toneNo;

    int duration;

   startTime = millis(); 

//    // bee
//
//    length = sizeof(beeTone)-1;
//
//    for ( ii=0; ii<length; ii++ ) {
//
//        toneNo = getTone(beeTone[ii]);
//
//        duration = beeBeat[ii]*333;
//
//        tone(buzzer,toneTable[toneNo][3]);
//
//        delay(duration);
//
//        noTone(buzzer);
//
//    }

    delay(2000);
    
    // star

    length = sizeof(starTone)-1;

    for ( ii=0; ii<length; ii++ ) {

        toneNo = getTone(starTone[ii]);

        duration = starBeat[ii]*333;

        tone(buzzer,toneTable[toneNo][3]);

        delay(duration);

        noTone(buzzer);

    }

    noTone(buzzer);

    delay(2000);


    duration = millis() - startTime;         // 計算按鈕被按了多久

    Serial.print("duration: ");              // 印出 duration 的內容

    Serial.print(duration);

    Serial.println(" microseconds");

}


