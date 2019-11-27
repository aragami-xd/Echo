using System;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Shapes;

namespace OsuTrainer
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            // create the first circle
            Circle circle = new Circle(ref gd);

            // draw the circle on the screen
            DrawCircle(ref circle);
        }

        // 2 tapping buttons
        public char Button1 { get; set; }
        public char Button2 { get; set; }

        // combo counter
        public int Combo { get; private set; }


        public void DrawCircle(ref Circle circle)
        {
            Ellipse InCircle = new Ellipse
            {
                Width = circle.CircleSize,
                Height = circle.CircleSize,
                Stroke = circle.CircleColor,

                Fill = Brushes.Transparent,
                StrokeThickness = 3
            };

            area.Children.Add(InCircle);
            Canvas.SetLeft(InCircle, circle.X);
            Canvas.SetTop(InCircle, circle.Y);

            ComboText.Text = circle.X.ToString() + " " + circle.Y.ToString();
        }

    }
}
