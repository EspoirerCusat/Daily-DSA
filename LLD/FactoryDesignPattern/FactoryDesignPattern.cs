using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace MyConsoleApp
{
    public interface IOss
    {
        void Show();
    }

    public class WindowsOs : IOss
    {
        public void Show()
        {
            Console.WriteLine("In windows!!");
        }
    }
    public class MacOs : IOss
    {
        public void Show()
        {
            Console.WriteLine("In MacOs!!");
        }
    }
    public class FactoryDesignPattern
    {
        public static IOss GetFactory(string type)
        {
            if (type == "windows")
            {
                return new WindowsOs();
            }

            return new MacOs();
    
        }
        public static void Main(string[] args)
        {
            var factory = GetFactory("windows");
            factory.Show();
        }
    }
}
