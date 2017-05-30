#ifndef SOUNDS_H
#define SOUNDS_H
//************************* Sound Settings *****************************//
#define WAVBAUDRATE 57600
// 0 = full volume, 255 off (after 64 inaudible) <== mp3Triger
// 10 = max, -70 min
#define DEFAULT_VOLUME_MIN -70
#define DEFAULT_VOLUME_MAX 10
#define DEFAULT_VOLUME -20

#define CONTROLLER_CONNECTED 1

#define GEN_SND_START 1 //bb8 gen chit chat
#define GEN_SND_END 25

#define CHAT_SND_START 26 //bb8 oh sounds
#define CHAT_SND_END 32

#define HAPPY_SND_START 51 //happy sassy
#define HAPPY_SND_END 58

#define SAD_SND_START 75  //sad
#define SAD_SND_END 80

#define HUM_SND_START 130  //bb8 is purr
#define HUM_SND_END 134

#define SCREAM_SND_START 135 //scream
#define SCREAM_SND_END 152

#define LEIA_SND_START 161  //movie sounds
#define LEIA_SND_END 166

#define PROC_SND_START 165  //YEP
#define PROC_SND_END 166

#define WHISTLE_SND_START 101 //toy sounds
#define WHISTLE_SND_END 105

#define YEP 165

#define AUTO_SND_START 1
#define AUTO_SND_END 50

#define SW_SND_THEME 190
#define EMPIRE_SND_THEME 192
#define CANTINA_SND_THEME 191
#define SW_CHORUS_THEME 193

#define MUS_THRILLER 203
#define RANDOM_MUS_START 179
#define RANDOM_MUS_END 187

#define HOLIDAY_MUS_START 350
#define HOLIDAY_MUS_END 352

#define R2THEME_MUS_START 176
#define R2THEME_MUS_END 179

#define DOODOO_SND 161
#define OVERHERE_SND 162
#define PATROL_SND 163
#define ANNOYED_SND 164

#define IMPERIAL_SIREN 138

#define BG_MUS_START 255

#endif //SOUNDS_H

