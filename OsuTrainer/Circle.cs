using System;
using System.Windows.Controls;
using System.Windows.Media;

namespace OsuTrainer
{
    public class Circle
    {
        /// <summary>
        /// * circle constructor, require passing in the size of the drawing area
        /// * the circleSize difficulty is optional, default to 5
        /// </summary>
        /// <param name="area"></param>
        /// <param name="circleSize"></param>
        public Circle(ref Grid gd)
        {
            // setup the default values for the circle

            // circle size
            CircleSize = 40;

            // random circle position: x,y
            Random rand = new Random();
            X = rand.Next(0, (int)gd.Width);
            Y = rand.Next(0, (int)gd.Height);

            // circle color
            CircleColor = Brushes.LightCyan;
        }

        // all of the circle attributes
        // attributes directly affect the difficulty of the game: approach rate and circle size (used for scaling, not actual value)
        public double CircleSize { get; set; }

        // position of the circle
        public int X { get; set; }
        public int Y { get; set; }

        // visual attribute: circle radius, the outer ring radius, color and number on the circle
        public Brush CircleColor { get; set; }

    }
}

