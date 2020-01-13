using System;
using System.Windows;
using System.Diagnostics;
using System.Collections.Generic;

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
                ProcessStartInfo startInfo = new ProcessStartInfo
                {
                    WorkingDirectory = System.IO.Path.GetDirectoryName(pathToExe),
                    FileName = pathToExe
                };
                Process LaunchProcess = Process.Start(startInfo);
            }
            catch(Exception exc)
            {
                Console.WriteLine(exc.Message);
            }
        }

        /// <summary>
        /// collapse the play button when the user scrolls down (to a certain point)
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void MainWindowStack_ScrollChanged(object sender, System.Windows.Controls.ScrollChangedEventArgs e)
        {
            Resources["PlayButtonHeight"] = 150 * (MainWindowStack.VerticalOffset / MainWindowStack.Height);
            Console.WriteLine(Resources["PlayButtonHeight"]);
        }
    }

    class PlayerStat
    {
        public Tuple<String, int> PlayCount { get; set; }
        public Tuple<String, int> PP { get; set; }
        public Tuple<String, float> Accuracy { get; set; }
    }
}
