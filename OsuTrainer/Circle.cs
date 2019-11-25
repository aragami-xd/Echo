using System;
using System.Drawing;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

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
        public Circle(ref Grid GameArea)
        {
            // setup the default values for the circle
            // size of the game area
            int area = (int)GameArea.ColumnDefinitions[2].ActualWidth;

            // circle size
            CircleSize = 800 / 10;

            // random circle position: x,y
            Random rand = new Random();
            X = rand.Next(0, area);
            Y = rand.Next(0, area);

            // circle number
            Number = circleNumber++;
            if (circleNumber > 10)
            {
                circleNumber = 0;
            }

            // circle color
            CircleColor = Brushes.LightCyan;


            // create the ellipses
            // the inner circle
            circle = new Ellipse()
            {
                Fill = Brushes.Transparent,
                Stroke = CircleColor,
                StrokeThickness = CircleSize / 12,
                Width = CircleSize,
                Height = CircleSize
            };

            // the outer ring (initial size)
            ring = new Ellipse()
            {
                Fill = Brushes.Transparent,
                Stroke = Brushes.White,
                StrokeThickness = CircleSize / 20,
                Width = CircleSize * 2,
                Height = CircleSize * 2
            };
        }

        // ellipse object
        public Ellipse circle { get; private set; }
        public Ellipse ring { get; private set; }

        // all of the circle attributes
        // attributes directly affect the difficulty of the game: approach rate and circle size (used for scaling, not actual value)
        public double ApproachRate { get; private set; }
        public double CircleSize { get; private set; }

        // position of the circle
        public int X { get; private set; }
        public int Y { get; private set; }

        // visual attribute: circle radius, the outer ring radius, color and number on the circle
        public Brush CircleColor { get; private set; }
        public int Number { get; private set; }

        // static variables: approach time, and circle number
        private static readonly TimeSpan approachRate = TimeSpan.FromMilliseconds(4500);
        private static int circleNumber = 0;


        // functions
        public ( Ellipse, Ellipse ) DrawCircle()
        {
            return ( circle, ring );
        }

        public void EraseCircle()
        {
            circle.Visibility = System.Windows.Visibility.Collapsed;
            ring.Visibility = System.Windows.Visibility.Collapsed;
        }
    }
}

