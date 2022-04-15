
#define _TASK_MICRO_RES
#include <TaskScheduler.h>
 
#define pin1 3
#define pin2 5
#define pin3 6
#define pin4 9
#define pin5 10

 
void led1_blink();
void led2_blink();
void led3_blink();
void led4_blink();
void led5_blink();
 
Scheduler runner;
 
//Task Blink_LED1(225, TASK_FOREVER, &led1_blink);
//Task Blink_LED2(127, TASK_FOREVER, &led2_blink);
//Task Blink_LED3(63, TASK_FOREVER, &led3_blink);
//Task Blink_LED4(180L , TASK_FOREVER, &led4_blink);
//Task Blink_LED5(80L, TASK_FOREVER, &led5_blink);

Task Blink_LED1(175, TASK_FOREVER, &led1_blink);
Task Blink_LED2(25, TASK_FOREVER, &led2_blink);
Task Blink_LED3(125L, TASK_FOREVER, &led3_blink);
Task Blink_LED4(65L, TASK_FOREVER, &led4_blink);
Task Blink_LED5(30L, TASK_FOREVER, &led5_blink);
 
bool statusLED1 = false;
bool statusLED2 = false;
bool statusLED3 = false;
bool statusLED4 = false;
bool statusLED5 = false;
 
void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
 
  runner.addTask(Blink_LED1);
  runner.addTask(Blink_LED2);
  runner.addTask(Blink_LED3);
  runner.addTask(Blink_LED4);
  runner.addTask(Blink_LED5);
 
  Blink_LED1.enable();
  Blink_LED2.enable();
  Blink_LED3.enable();
  Blink_LED4.enable();
  Blink_LED5.enable();
}
 
void loop() {
  runner.execute();
}
 
void led1_blink() {
  statusLED1 = !statusLED1;
  digitalWrite(pin1, statusLED1);
}
 
void led2_blink() {
  statusLED2 = !statusLED2;
  digitalWrite(pin2, statusLED2);
}

void led3_blink() {
  statusLED3 = !statusLED3;
  digitalWrite(pin3, statusLED3);
}
 
void led4_blink() {
  statusLED4 = !statusLED4;
  digitalWrite(pin4, statusLED4);
}

void led5_blink() {
  statusLED5 = !statusLED5;
  digitalWrite(pin5, statusLED5);
}
