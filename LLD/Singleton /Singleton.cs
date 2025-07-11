using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace MyConsoleApp
{
    public class Singleton
    {
        private static Singleton instance;
        private static readonly object lockObj = new object();
        private Singleton()
        {

        }

        public static Singleton GetInstance()
        {
            if (instance == null)
            {
                lock (lockObj)
                {
                    instance = new Singleton();
                }
                
            }
            return instance;
        }
        
        
    }
}

// Singleton s1 = Singleton.GetInstance();
// Singleton s2 = Singleton.GetInstance();
// Console.WriteLine(object.ReferenceEquals(s1, s2)); 
