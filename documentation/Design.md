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

### __Main classes__
#### 1. Object class
- Object is an individual gameplay element
- Field variables:
	+ `x,y`: *float*: coordinate of the circle on the screen (possibly the center of the circle)
	<br></br>
	+ `approachRate` (abbr. "AR"): *float*: scaling rate for scaleAR (below). This determine how fast (or how long) the circle will appear on the screen until it should be pressed before disappearing. A ring will get smaller and smaller until it touches the inner circle, which is when the user should press
	+ `circleSize` (abbr. "CS"): *float*: scaling rate for ScaleCS (below). This determine how big the circle and the ring will be
	+ `overallDifficulty` (abbr. "OD"): *float*: determine how hard it is to tap accurateyly by setting tigher 300, 100 and 50 timing
	<br></br>
	+ `scaleAR`: *static int*: the default approach time when AR = 1 (AR1 for short). Set to 4500ms to match with AR10 450ms in the game
	+ `scaleCS`: *static int*: the default circle size for CS1. Set to a circle radius half the height of the screen
	<br></br>
	+ `objectRadius`: *float*: render radius of the object
	<br></br>
	+ `animationLength`: *int*: the time it takes for the ring to approach the circle based on *scaleAR* and *AR*. This is different from circle appear length, which is the total amount of time the circle appears on the screen, which is slightly longer than that
	+ `threeHundred`: *int*: the timespan during which tapping the circle will yield 300 score (best)
	+ `oneHundred`: *int*: similar to 300, yield 100 score, less tight timing required
	+ `fifty`: *int*: similar to 100, yield 50 score, less tight timing required. Tapping outside of this range will be a miss 

- Public functions:

#### 2. Circle class: inherit Object
- Circle will contain all the details necessary to generate the circle on the screen
- Field variables:
	+ `animationTime`: *int*: when the animation will start for the circle, in ms
	+ `beatTime`: *int*: beat of the circle
	+ `endTime`: when the latest time the circle will disappear
	<br></br>
	+ `circleColor`: *Color*: the color of the circle, based on rgba attribute
- Public functions:

#### 3. Slider class: inherit Object
- Slider will contain all the details necessary to generate the slider on the screen
- Field variables:
	+ `animationTime`: *int*: when the animation will start for the slider, in ms
	+ `beatStartTime`: *int*: starting beat of the slider
	+ `beatEndTime`: *int*: ending beat of the slider
	+ `beatTickTime`: *vector<int>*: ticks of the slider
	+ `endTime`: *int*: when the slider disappear
	<br></br>
	+ 
- Public functions:


#### 4. Core class
- Core class is responsible for calling the right function to render the objects on the display, as well as other background calculations
- Field variables:
	+ `allCircle`: *list<Circle**>: every circle in the beatmap
	+ `allSlider`: *list<Slider**>: every slider in the beatmap
	<br></br>
	+ `hp`: *int*: "health" of the player. Maximum 100. HP Drain (HP) will determines how fast this health reduces and how much player will gain (or lose if miss) when tapping a circle. Of course, running out of health means lose. HP will always reduce gradually
	+ `score`: *int*: total score of the player. While this scoring system is vastly simplified from the original game, it doesn't matter anyways, it's just there for fun (literally)
	`score of a circle = Circle::GetScore() * combo`
	+ `accuracy`: *float*: determines how accurate the player's tapping is. 300 yield perfect accuracy, 100 yield 75% and 50 yield 50%. miss is 0%. Total accuracy will be the average of each circle up till that point
	+ `combo`: *int*: literally how many circles have been hit in a row without a miss. This is also vastly simplified from the original game due to the lack of sliders
	<br></br>
	+ `time`: *static int*: time in milliseconds, determines how it is into the map (so 1m32s into the map will be 92000ms). This will be used to draw the circle and calculate the score at that moment
- Functions:
	+ `CreateCircle()`: *void*: initialize a circle using existing parameters and add it into the back of the circle list
	+ `DeleteCircle()`: *void*: delete the first circle in the list. This function is triggered when a circle is supposed to go out of scope
	<br></br>
	+ `AnimatePerCircle()`: *void*: call the openGL shader to render the circe on the screen
	+ `AnimateAllCircle()`: *void* loop through every circle in the list and call the `AnimatePerCircle()` function to draw each circle individually
	<br></br>
	+ `AnimateComboText()`: *void*: render the combo text on the bottom left of the screen
	+ `AnimateAccText()`: *void*: render the accuracy and score text on the top right of the screen
	+ `AnimateHealthBar()`: *void*: render the health bar on the top left of the screen
	+ `Draw()`: *void*: setup and call all the animate functions above to render the entire screen

### __Micsellenous classes and structs__
#### 1. Color class
- `R,G,B,A`: *float*: color of the circle
- OpenGL uses vec4 (vector length 4) as color vector
- The file contains several pre-defined colors (mostly bright colors)

#### 2. Attribute class
- For easier beatmap setup purposes
