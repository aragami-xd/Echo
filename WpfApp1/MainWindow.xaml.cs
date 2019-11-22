using System.Windows;
using System.Windows.Input;
using System.Windows.Controls;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            CircleCounter = 0;
        }

        //  the default canvas of the game
        public Canvas DrawingArea = new Canvas();

        // number of circles clicked
        private int CircleCounter { get; set; }

        // erase the circle when it's pressed and create another one
        private void Ellipse_MouseDown(object sender, MouseButtonEventArgs e)
        {
            //Ellipse1.Visibility = Visibility.Collapsed;
            CircleCounter++;
            CircleClicked.Text = CircleCounter.ToString();
        }

    }
}
