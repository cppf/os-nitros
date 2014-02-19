#include <os.h>

bag_Define(byte, 16);
bag_16byte Bag;

void setup()
{
  Serial.begin(9600);
  bag_Push(Bag, 1);
  bag_Push(Bag, 2);
  bag_Pop(Bag);
}

void loop()
{
  Serial.print(bag_Count(Bag));
  Serial.print("  ");
  Serial.print(bag_PeekFront(Bag));
  Serial.println("  ");
}
