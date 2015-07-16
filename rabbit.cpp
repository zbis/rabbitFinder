
const int buzzerPin = 8;
const int detecteurMouvementPin = 9;

void setup() 
{
  //Setup pour le buzzer
  pinMode(buzzerPin, OUTPUT);
  
  //Setup pour le détecteur de mouvement
  pinMode(detecteurMouvementPin, INPUT);
  digitalWrite(detecteurMouvementPin, LOW);
}

void loop(){
  
     //Si il y a une détection de mouvement, alors lancer la musique
     if(digitalRead(detecteurMouvementPin) == HIGH){ 
       playMusic();
     }
}

  #define tone_C 1911
  #define tone_C1 1804
  #define tone_D 1703
  #define tone_Eb 1607
  #define tone_E 1517
  #define tone_F 1432
  #define tone_F1 1352
  #define tone_G 1276
  #define tone_Ab 1204
  #define tone_A 1136
  #define tone_Bb 1073
  #define tone_B 1012
  #define tone_c 955
  #define tone_c1 902
  #define tone_d 851
  #define tone_eb 803
  #define tone_e 758
  #define tone_f 716
  #define tone_f1 676
  #define tone_g 638
  #define tone_ab 602
  #define tone_a 568
  #define tone_bb 536
  #define tone_b 506
  #define tone_p 0  //pause

  long vel = 20000;
  int music_m[] = {tone_G, tone_E, tone_D, tone_C, tone_D, tone_E, tone_G, tone_E, tone_D, tone_C, tone_D, tone_E, tone_D, tone_E,tone_G, tone_E, tone_G, tone_A, tone_E, tone_A, tone_G, tone_E, tone_D, tone_C};
  int music_r[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 16};


//Musique 
void playMusic(){

  const int LEN = (sizeof(music_r) + 1) / 4;
  for (int i=0; i < LEN; i++){
    int tom = music_m[i];
    int tempo = music_r[i];
    long tvalue = tempo * vel;
    tocar(tom, tvalue);
    delayMicroseconds(1000); //pause between notes
  }  
}
void tocar(int tom, long tempo_value){
  long tempo_gasto = 0;
  while (tempo_gasto < tempo_value && tempo_value < 640000){ // enters an infinite loop when tempo_value is a big value
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(tom / 2);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(tom/2);
    tempo_gasto += tom;
  }
}
