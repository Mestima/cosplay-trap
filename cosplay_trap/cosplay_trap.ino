#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define RELAY1 7 // High level trigger
#define RELAY2 6 // Low level trigger

struct state {
  bool relay_one = 0;
  bool relay_two = 0;
};

state st;
void setup() {
  pinMode(IN1, INPUT);
  pinMode(IN2, INPUT);
  pinMode(IN3, INPUT);
  pinMode(IN4, INPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
}

void loop() {
  if (digitalRead(IN1) == HIGH) {
    st.relay_one = 1;
    st.relay_two = 1;
  } else if (digitalRead(IN2) == HIGH) {
    st.relay_one = 0;
    st.relay_two = 0;
  } else if (digitalRead(IN3) == HIGH) {
    st.relay_two = 1;
  } else if (digitalRead(IN4) == HIGH) {
    st.relay_two = 0;
  }

  if (st.relay_one == true) {
    digitalWrite(RELAY1, HIGH);
  } else {
    digitalWrite(RELAY1, LOW);
  }

  if (st.relay_two == true) {
    digitalWrite(RELAY2, LOW);
  } else {
    digitalWrite(RELAY2, HIGH);
  }
}
