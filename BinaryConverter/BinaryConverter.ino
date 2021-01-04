
void setup() {
  Serial.begin(9600);
}

void loop() {
  boolean flag = true;
  if (Serial.available() > 0)
  {
    // read the incoming byte:
    long n = Serial.parseInt(SKIP_ALL);
    //    Serial.println("Processing ....");
    long t = n; double r = 0; int d = 0;
    for (int i = 0; t > 0; i++)
    {
      d = t % 10;
      t = t / 10;
      if (d > 1) {
        String c = String(d);
        Serial.println("Invalid Digit " + c + " Encountered!");
        //        Serial.print(d);
        //        Serial.println(" Encountered !");
        flag = false;
        break;
      }
      else {
        r += d * (pow(2, i));
      }
    }
    if (flag) {
      if (r != 0) {
        Serial.print(n);
        Serial.print(" In Decimal is equal to ");
        Serial.println(r,0);
        Serial.println("Done !");
      }
    }
    else
      Serial.println("The no entered is not Binary!!!!!!!!!!!!");
  }
}
