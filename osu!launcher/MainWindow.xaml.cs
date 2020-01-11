using System;
using System.IO;
using System.Windows;
using System.Windows.Shapes;
using System.Diagnostics;

namespace osu_launcher
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Launch the specified program based on the combo box next to it
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Play_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                // path to the exe file
                string pathToExe = "";

                // set the path for different programs
                if (GameModeSel.SelectedItem.ToString() == "osu!")
                {
                    pathToExe = "D:\\osu!\\osu!.exe";
                }
                else if (GameModeSel.SelectedItem.ToString() == "osu!trainer")
                {
                    pathToExe = "C:\\Users\\Rogue\\source\\repos\\Echo\\bin\\Release-windows\\osu!trainer\\osu!trainer.exe";
                }

                // set the working directory, launch path then launch the program
                ProcessStartInfo startInfo = new ProcessStartInfo();
                startInfo.WorkingDirectory = System.IO.Path.GetDirectoryName(pathToExe);
                startInfo.FileName = pathToExe;

                Process LaunchProcess = Process.Start(startInfo);
            }
            catch(Exception exc)
            {
                Console.WriteLine(exc.Message);
            }

        }
    }
}
