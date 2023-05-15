### Arduino Uno Spotify Playing Song Display
This project is a simple Arduino Uno project that displays the currently playing song on a Spotify account. It uses the Spotify API to get the currently playing song and displays it on a 16x2 i2c LCD screen.

## Example Video
https://github.com/Duoslow/Arduino_Spotify/assets/16846504/62f02af7-657f-474d-b6a9-3359162f8c9a

## Getting Started
### Prerequisites
* Arduino Uno
* 16x2 i2c LCD Screen
* Spotify API Client ID and Client Secret
  
### Installing On Arduino
1. Clone the repository
2. Open the Arduino IDE
3. Install the LiquidCrystal_I2C library
5. Open the `main.ino` file
7. Upload the code to your Arduino Uno

### Setting Up Spotify API
1. Go to the [Spotify Developer Dashboard](https://developer.spotify.com/dashboard/applications)
2. Create a new application
3. Copy the Client ID and Client Secret
4. Paste the Client ID and Client Secret into the `example_config.json` file
5. Rename the `example_config.json` file to `config.json`
6. Run the code

## Built With
* [LiquidCrystal_I2C](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) - The library used to control the LCD screen (it is also available in the Arduino IDE library manager)
* [Spotify API](https://developer.spotify.com/documentation/web-api) - The API used to get the currently playing song



