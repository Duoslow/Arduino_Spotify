import serial, time, spotipy, json
import spotipy.util as util
with open('config.json') as f:
    config = json.load(f)
token = util.prompt_for_user_token(config['Spotify']['username'], config['Spotify']['scope'], config['Spotify']['client_id'], config['Spotify']['client_secret'], config['Spotify']['redirect_uri'])
spotify = spotipy.Spotify(auth=token)
arduino = serial.Serial(port=config['Arduino']['port'], baudrate=config['Arduino']['baudRate'], timeout=.1)

last_song = ''
while True:
    current_track = spotify.current_user_playing_track()
    if current_track:
        artists = ', '.join([i['name'] for i in current_track['item']['artists']])
        album = current_track['item']['album']['name']
        track = current_track['item']['name']
        now_playing = ' {} => {} '.format(artists, track)
        if now_playing != last_song:
            last_song = now_playing
            # we need to close and reopen the serial connection to clear the lcd buffer
            arduino.close() # Close serial connection to Arduino
            arduino = serial.Serial(port=config['Arduino']['port'], baudrate=config['Arduino']['baudRate'], timeout=.1) # Reopen serial connection to Arduino
        arduino.write(bytes(now_playing, 'utf-8'))
        print('Currently playing: {}'.format(now_playing))
        time.sleep(3)
    else:
        arduino.write(bytes('Nothing playing', 'utf-8'))
        print('Nothing playing')
        time.sleep(3)
    