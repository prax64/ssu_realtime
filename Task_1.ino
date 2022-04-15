#include <TaskScheduler.h>
 
#define pin1 5
#define pin2 6
 
void led1_blink();
void led2_blink();
 
Scheduler runner;
 
Task Blink_LED1(500, TASK_FOREVER, &led1_blink);
Task Blink_LED2(1000, TASK_FOREVER, &led2_blink);
 
bool statusLED = false;
 
void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
 
  runner.addTask(Blink_LED1);
  runner.addTask(Blink_LED2);
 
  Blink_LED2.enable();
  Blink_LED2.enable();
}
 
void loop() {
  runner.execute();
}
 
void led1_blink() {
  statusLED = !statusLED;
  digitalWrite(pin1, statusLED);
}
 
void led2_blink() {
  statusLED = !statusLED;
  digitalWrite(pin2, statusLED);
}