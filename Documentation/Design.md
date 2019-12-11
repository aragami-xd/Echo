A very *detailed* design documentation for Osu!Trainer
___
Welcome to Osu!Trainer. This is a mouse training game, based on the old but popular rhythm game [Osu!](https://osu.ppy.sh). The original game features pre-made beatmaps that you can play by tapping circles and sliders at every beat of the song
Unlike the original game, this *__spinoff__* will feature circles only, placing at pseudo random location, serve as a mouse aim training range for the actual game
For further instructions, check out the osu! [wiki](https://osu.ppy.sh/help/wiki/Game_Modes/osu!) page. Have fun!
Get the game [here](https://osu.ppy.sh) (osu.ppy.sh) 

Osu! players can skip some of the definition below. If you have never played Osu! before, I recommend checking out these gameplay videos below:
- "Example" gameplay: https://www.youtube.com/watch?v=XBazptIllrE
- Cookiezi's iconic gameplay (Blue Zenith HR): https://www.youtube.com/watch?v=UYNpkDrCWtA
- WhiteCat's current world record gameplay (Team Magma and Aqua Leader theme HDDTHR): https://www.youtube.com/watch?v=AXOBMpSpsPU
- Idke's previous WR gameplay (Cry Thunder): https://www.youtube.com/watch?v=sloVkCVE_DI
- Rafis's previous WR gameplay (Necro Fantasia HDDT): https://www.youtube.com/watch?v=M6SPs67ZPGw
***
With the introduction in mind, here comes the actual design documentation. Refer to the *draw.io* file included for the diagram (open it on [draw.io](https://draw.io))

#### Main classes
##### 1. Circle class
- Circle will contain all the details necessary to generate the circle on the screen. The Core and shaders will handle all of the commands necessary to draw the circle
- Field variables:
	+ `x,y`: *float*: coordinate of the circle on the screen (possibly the center of the circle)
	+ `approachRate` (abbr. "AR"): *float*: scaling rate for scaleAR (below). This determine how fast (or how long) the circle will appear on the screen until it should be pressed before disappearing. A ring will get smaller and smaller until it touches the inner circle, which is when the user should press
	+ `circleSize` (abbr. "CS"): *float*: scaling rate for ScaleCS (below). This determine how big the circle and the ring will be
	+ `overallDifficulty` (abbr. "OD"): *float*: determine how hard it is to tap accurateyly by setting tigher 300, 100 and 50 timing
	+ `scaleAR`: *static int*: the default approach time when AR = 1 (AR1 for short). Set to 4500ms to match with AR10 450ms in the game
	+ `scaleCS`: *static int*: the default circle size for CS1. Set to a circle radius half the height of the screen
	+ `animationLength`: *int*: the time it takes for the ring to approach the circle based on *scaleAR* and *AR*. This is different from circle appear length, which is the total amount of time the circle appears on the screen, which is slightly longer than that
	+ `threeHundred`: *int*: the timespan during which tapping the circle will yield 300 score (best)
	+ `oneHundred`: *int*: similar to 300, yield 100 score, less tight timing required
	+ `fifty`: *int*: similar to 100, yield 50 score, less tight timing required. Tapping outside of this range will be a miss 
	+ `animationTime`: *int*: the time that the animation will start for the circle, in ms
	+ `beatTime`: *int*: the timestamp of the beat of that circle
	+ `endTime`: when the latest time the circle will disappear
	+ `circleRadius`: *int*: the radius of the circle = `scaleCS / CS`
	+ `ringRadius`: *int*: the initial radius of the ring = `circleRadius * 2`
	+ `circleColor`: *Color*: the color of the circle, based on rgba attribute (custom Color class below)
- Functions:
	+ `Set()`, `Get()`: *x, y, AR, CS, OD, beatTime, color*
	+ `Get()`: *score, circleRadius, ringRadius*: these variables are read-only and set automatically inside the object
	+ `CreateCircle()`: *void*: this function will use the public set attributes above to set all the attributes of the circle

##### 2. Core class
- Core class will handle all of the animations of the game (a Beatmap class below will handle the creation of the beatmaps)
- Core class will also handle the calculation of the score during the gameplay (not the difficulty of the map, which is handled by the Beatmap class)
- Field variables:
	+ `Window`: *GLFWwindow**: reference to the main window of the game, which is initiallized inside `main.cpp`
	+ `circle`: *list<Circle**>: the circles on the screen at a certain moment. Very slow maps (*nights of nights*) or very fast maps (*basically every UNDEAD CORPORATION map*) may have more than 1 circle appear on the screen at the same time
	+ `circleTime`: *int*: the timestamp of the next beat (i.e. when the next ring touches the next circle)
	+ `animationTime`: *int*: when the next circle will start to appear
	+ `x,y`: *float*: coordinate of the next circle on the screen
	+ `hp`: *int*: "health" of the player. Maximum 100. HP Drain (HP) will determines how fast this health reduces and how much player will gain (or lose if miss) when tapping a circle. Of course, running out of health means lose. HP will always reduce gradually
	+ `score`: *int*: total score of the player. While this scoring system is vastly simplified from the original game, it doesn't matter anyways, it's just there for fun (literally)
	`score of a circle = Circle::GetScore() * combo`
	+ `accuracy`: *float*: determines how accurate the player's tapping is. 300 yield perfect accuracy, 100 yield 75% and 50 yield 50%. miss is 0%. Total accuracy will be the average of each circle up till that point
	+ `combo`: *int*: literally how many circles have been hit in a row without a miss. This is also vastly simplified from the original game due to the lack of sliders
	+ `time`: *static int*: time in milliseconds, determines how it is into the map (so 1m32s into the map will be 92000ms). This will be used to draw the circle and calculate the score at that moment
- Functions:
	+ `MapInit()`: *void*: initialize a map by open the map's text file, read the first line and initialize the data needed to create the first circle. Afterwards read the next line
	+ `MapParser()`: *void*: if `time` < `animationTime` then do nothing. Else, using the data from the last line (read from the last function call) to create a new circle. Afterwards read the next line
	+ `CreateCircle()`: *void*: initialize a circle using existing parameters and add it into the back of the circle list
	+ `DeleteCircle()`: *void*: delete the first circle in the list. This function is triggered when a circle is supposed to go out of scope
	+ `AnimatePerCircle()`: *void*: call the openGL shader to render the circe on the screen
	+ `AnimateAllCircle()`: *void* loop through every circle in the list and call the `AnimatePerCircle()` function to draw each circle individually
	+ `AnimateComboText()`: *void*: render the combo text on the bottom left of the screen
	+ `AnimateAccText()`: *void*: render the accuracy and score text on the top right of the screen
	+ `AnimateHealthBar()`: *void*: render the health bar on the top left of the screen
	+ `Draw()`: *void*: setup and call all the animate functions above to render the entire screen

#### Micsellenous classes and structs
##### 1. Color class
- Saving color as `R,G,B,A` attributes for easier color construction for OpenGL `vec4`
- Since OpenGL only accept value from *0.0f* to *1.0f*, the setters for these variables will go through a parser that convert from 255 scale to 1.0 scale

##### 2. Attribute class
- For easier beatmap setup purposes
