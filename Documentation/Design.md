A very "detailed" design documentation for Osu!Trainer

Welcome to Osu!Trainer. This is a mouse training game, based on the old but popular rhythm game "Osu!". The original game features pre-made beatmaps that you can play by tapping circles and sliders at every beat of the song. Unlike the original game, this "spinoff" will feature circles only, placing at pseudo random location, serve as a mouse aim training range for the actual game. Have fun!
Get the game here: https://osu.ppy.sh 

Osu! players can skip some of the definition below. If you have never played Osu! before, I recommend checking out these gameplay videos below:
- "Example" gameplay: https://www.youtube.com/watch?v=XBazptIllrE
- Cookiezi's iconic play (Blue Zenith HR): https://www.youtube.com/watch?v=UYNpkDrCWtA
- WhiteCat's current world record play (Team Magma and Aqua Leader theme HDDTHR): https://www.youtube.com/watch?v=AXOBMpSpsPU
- Idke's previous WR gameplay (Cry Thunder): https://www.youtube.com/watch?v=sloVkCVE_DI
- Rafis's previous WR gameplay (Necro Fantasia HDDT): https://www.youtube.com/watch?v=M6SPs67ZPGw

With the introduction in mind, here comes the actual design documentation. Refer to the draw.io file included for the diagram (open it on draw.io)

1. Circle class
- Circle will contain all the details necessary to generate the circle on the screen. The Core and shaders will handle all of the commands necessary to draw the circle
- Field variables:
	+ x,y: `int`: coordinate of the circle on the screen (possibly the center of the circle)
	+ approachRate (abbr. "AR"): `float`: scaling rate for scaleAR (below). This determine how fast (or how long) the circle will appear on the screen until it should be pressed before disappearing. A ring will get smaller and smaller until it touches the inner circle, whcih is when the user should press
	+ circleSize (abbr. "CS"): `float`: scaling rate for ScaleCS (below). This determine how big the circle and the ring will be
	+ overallDifficulty (abbr. "OD"): `float`: determine how hard it is to tap accurateyly by setting tigher 300, 100 and 50 timing
	+ scaleAR: `static int`: the default approach time when AR = 1 (AR1 for short). Set to 4500ms to match with AR10 450ms in the game
	+ scaleCS: `static int`: the default circle size for CS1. Set to a circle radius half the height of the screen
	+ animationLength: `int`: the time it takes for the ring to approach the circle = `scaleCS / AR`. This is different from circle appear length, which is the total amount of time the circle appears on the screen, which is slightly longer than that
	+ threeHundred: `int`: the timespan during which tapping the circle will yield 300 score (best) = `± animationLength / 30`
	+ oneHundred: `int`: similar to 300, yield 100 score, less tight timing required = `± animationLength / 10` 
	+ fifty: `int`: similar to 100, yield 50 score, less tight timing required = `± animationLength / 5`. Tapping outside of this range will be a miss 
	+ circleRadius: `int`: the radius of the circle = `scaleCS / CS`
	+ ringRadius: `int`: the initial radius of the ring = `circleRadius * 2`
	+ circleColor: `Color`: the color of the circle, based on rgba attribute (custom Color class below)
- Functions:
	+ Set(); Get(): x,y
	+ Set(); Get(): AR, CS, OD: Set() these 2 variables will also setup the animationLength, 300, 100, 50, circleRadius, ringRadius, while Get() only returns the variables themselves
	+ Get(): animationLength, 300, 100, 50, circleRadius, ringRadius: these variables are read-only, set up inside the Set() AR, CS functions
	+ GetCircleAppearLength(): circle will appear for an extra time after the animation has finished = `animationLength + fifty`
	+ Set(), Create(), Get() circleColor: Set() will set the color based on an existing color, Create() will create a color based on 4 rgba attribute then set the circle color, Get() will just get the color


2. Core class
- Core class will handle all of the animations of the game (a Beatmap class below will handle the creation of the beatmaps)
- 