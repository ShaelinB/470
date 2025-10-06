
  // import the serial library
  import processing.serial.*;

  // create an instance of the serial library
  Serial myPort;

  // create an instance of PImage
  PImage logo;

  // a variable to hold the background color
  int bgcolor = 0;

  void setup() {
    size(1, 1);
    surface.setResizable(true);
    // set the color mode to Hue/Saturation/Brightness
    colorMode(HSB, 255);

    // load the Arduino logo into the PImage instance
    logo = loadImage("https://support.arduino.cc/hc/article_attachments/12415993577116.png");

    // make the window the same size as the image
    surface.setSize(logo.width + 100, logo.height + 100);

    // print a list of available serial ports to the Processing status window
    println("Available serial ports:");
    println(Serial.list()); //<>//

    // Tell the serial object the information it needs to communicate with the
    // Arduino. Change Serial.list()[0] to the correct port corresponding to
    // your Arduino board.  The last parameter (e.g. 9600) is the speed of the
    // communication.  It has to correspond to the value passed to
    // Serial.begin() in your Arduino sketch.
    myPort = new Serial(this, "COM3", 9600);

    // If you know the name of the port used by the Arduino board, you can
    // specify it directly like this.
    // port = new Serial(this, "COM1", 9600);
  }

  void draw() {

    // if there is information in the serial port
    if ( myPort.available() > 0) {
      // read the value and store it in a variable
      bgcolor = myPort.read();

      // print the value to the status window
      println(bgcolor);
    }

    // Draw the background. the variable bgcolor contains the Hue, determined by
    // the value from the serial port
    background(bgcolor, 255, 255);

    // draw the Arduino logo
    image(logo, 0, 0);
  }
