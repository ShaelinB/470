using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports; //for serial

public class demo : MonoBehaviour
{

    SerialPort dataStream;

    //helper variales for setting up the stream
    public string serialPort = "COM3";
    public int baud = 9600;

    //string to hold the data we recieve from the Arduino
    private string receivedString;

    //help us to move the cube later
    public Transform moveableCube;

    // Start is called before the first frame update
    void Start()
    {
        dataStream = new SerialPort(serialPort, baud);
        dataStream.Open(); //Open the stream
    }

    // Update is called once per frame
    void Update()
    {
        receivedString = dataStream.ReadLine();
        Debug.Log(receivedString);

        string[] substrings = receivedString.Split(',');
        Debug.Log("substring length: " + substrings.Length);

        //check to see if there is more than one element
        if (substrings.Length > 1)
        {
            //Should print the "hi" in the console
            Debug.Log(substrings[0]);

            //grab my mapped pos data
            float newX = float.Parse(substrings[2]);
            newX = newX / 100.0f; //scale to get that decimal precision

            //move the cube
            moveableCube.Translate(newX * Time.deltaTime, 0, 0);
        }

        dataStream.ReadExisting();

        if (moveableCube.localPosition.x < 0)
        {
            Debug.Log("turn light on");
            dataStream.Write("1");
        }
        else
        {
            Debug.Log("turn light off");
            dataStream.Write("0");
        }
    }
}
