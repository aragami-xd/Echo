using System;
using System.Windows.Shapes;

namespace WpfApp1
{
    public class Circle
    {
        public Circle()
        {
            Ellipse circle = new Ellipse();
            Radius = 20;
            Color[0] = 51;
            Color[1] = 167;
            Color[2] = 255;
            Color[3] = 180;

            CircleNumber++;
            Number = CircleNumber;
            if (CircleNumber > 10)
            {
                CircleNumber = 0;
            }
        }

        private static int CircleNumber = 0;

        /// <summary>
        ///     radius, number on the circle, color, x and y
        /// </summary>
        public int Radius { get; set; }
        public int Number { get; set; }
        public int[4] Color { get; set; }
        public int PosX { get; set; }
        public int PosY { get; set; }
        

    }
}

