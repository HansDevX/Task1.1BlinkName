//Name - KAVINDU HANSAJITH KEVITIYAGALA VITHANAGE
// Student ID - 225039499
//Task - 1.1P
//Trimester - 1, 2025


const int DotBlink = 200;    // Duration of a dot in milliseconds
const int LineBlink = 600;   // Duration of a line in milliseconds
const int DotLine_Gap = 200; // Space between dots and lines within a letter
const int DotLine_Space = 900; // Space between letters

// Define Morse code patterns for each letter in my name 'KAVINDU'
const String morseCode[] = {
  "-.-",   // K Letter Morse Code
  ".-",    // A Letter Morse Code
  "...-",  // V Letter Morse Code
  "..",    // I Letter Morse Code
  "-.",    // N Letter Morse Code
  "-..",   // D Letter Morse Code
  "..-"    // U Letter Morse Code
};

bool OneTimeStop = false; //to run the code one time

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); 
}

void loop() {
  if (!OneTimeStop) {
  for (int i = 0; i < 7; i++) {     //loop throup each letter in the array
    blinkMorseCode(morseCode[i]);  // Blink each letter's Morse code
    delay(DotLine_Space); // Space between letters
  }
  delay(2000); // Pause after the full name
  OneTimeStop = true; //runs only onetime
  }
}

// Function to blink the LED based on Morse code
void blinkMorseCode(String code) {
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') { //check current character is a "."
      blinkDot();
    } else if (code[i] == '-') { //check current character a "-"
      blinkLine();
    }
    if (i < code.length() - 1) {
      delay(DotLine_Gap); // Space between dots and lines
    }
  }
}

// Function to blink a dot
void blinkDot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DotBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DotLine_Gap);
}

// Function to blink a line
void blinkLine() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LineBlink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DotLine_Gap);
}
