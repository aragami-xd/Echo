using System;
using System.Windows.Input;
using System.Windows;
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
            Combo = 0;
            Area = (int)gd.ColumnDefinitions[2].ActualWidth;

            // create the first circle
            Circle circle1 = new Circle(ref gd);

            // get the ellipse drawn from the circle and add it into the canvas
            // the outer circle must be added in first otherwise it'll overlap the outer circle mouse control
            (Ellipse, Ellipse) ellipseCircle = circle1.DrawCircle();
            area.Children.Add(ellipseCircle.Item2);
            area.Children.Add(ellipseCircle.Item1);

            // subscribe the first circle (innerCircle) to the TapCircle event
            ellipseCircle.Item1.MouseDown += TapCircle;

        }

        // 2 tapping buttons
        public char Button1 { get; set; }
        public char Button2 { get; set; }

        // combo counter
        public int Combo { get; set; }

        public int Area { get; private set; }

        private void TapCircle(object sender, MouseButtonEventArgs e)
        {
            Combo++;
            ComboText.Text = Combo.ToString() + "x";
        }

    }
}
