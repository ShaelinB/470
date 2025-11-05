using System.IO.Ports;
using UnityEngine;

public class Arduino : MonoBehaviour
{
    SerialPort arduinoPort = new SerialPort("COM3", 9600);
    public Transform pancake;
    public float flipHeight = 2f; //how high the pancake jumps
    public float flipSpeed = 5f;  //speed of the flip animation

    private bool isFlipping = false;
    private Vector3 originalPosition;
    private Vector3 targetPosition;

    private bool lastFlipState = false; // track previous flip state

    void Start()
    {
        originalPosition = pancake.position;

        arduinoPort.Open();
    }

    void Update()
    {
        //makes sure the port is open and has data to read
        if ( arduinoPort.IsOpen && arduinoPort.BytesToRead > 0 )
        {
            //seperates the data
            string message = arduinoPort.ReadLine().Trim();
            string[] values = message.Split(',');

            //checks if it's all the data
            if (values.Length >= 2)
            {
                //gets the flipped status
                bool flipped = values[0] == "1";
                int xValue = int.Parse(values[1]);

                //print info
                Debug.Log("Flipped: " + flipped + ", X: " + xValue);

                //trigger flip
                if (flipped && !lastFlipState && !isFlipping)
                {
                    StartFlip();
                }

                lastFlipState = flipped;
            }
        }

        //pancake moving up and down
        if (isFlipping)
        {
            pancake.position = Vector3.Lerp(pancake.position, targetPosition, Time.deltaTime * flipSpeed);

            if (Vector3.Distance(pancake.position, targetPosition) < 0.05f)
            {
                //switches direction
                if (targetPosition.y > originalPosition.y)
                    targetPosition = originalPosition;
                else
                    isFlipping = false;
            }
        }
    }

    void StartFlip()
    {
        targetPosition = originalPosition + Vector3.up * flipHeight;
        isFlipping = true;
    }

    private void OnApplicationQuit()
    {
        if (arduinoPort.IsOpen)
            arduinoPort.Close();
    }
}
