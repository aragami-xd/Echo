1. Circle class
- overview: the circle appears on the screen to be clicked

- attributes directly affect the difficulty:
	- ApproachRate (AR) - float: scaling with ApproachTime to see how long the circle will appear before it "should" be clicked (an outer ring that gets smaller and smaller until it touches the circle, which is when to tap it)
	- CircleSize (CS) - float: scaling with CircleRadius to see how big the circle is

- Pos - int[2]: position of the circle on the screen. this will be set to random in the constructor

- visual attributes:
	- CircleColor - System.Drawing.Color: color of the circle, based on rgba attribute. default set to light blue color
	- RingSize - float: pretty much double the radius of CircleSize, which will get smaller and smaller until it touches the circle
	- Number - int: number on the circle

- static attributes:
	- approachTime - static System.TimeSpan: the default approach time to scale with AR. set to 4500ms so AR10 will be 450ms, which matches with the game
	- circleRadius - int: the default size of the circle to scale with CS. the size will be scale with display resolution
	- circleNumber - int: controls the number appears on the circle
