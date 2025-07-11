using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace MyConsoleApp
{
    public class PaypalPaymentGateway
    {
        public void sendMoney(string to, string from, string amount)
        {
            Console.WriteLine("to => " + to + " from => "  + from + " amount => " + amount);
        }
    }
}
